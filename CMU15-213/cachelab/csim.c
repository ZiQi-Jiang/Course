/*
 * csim.c - cache simulator
 *
 * Author:ziqi Jiang
 * August 27th, 2021
 */
#include "cachelab.h"
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h> //atoi function
#include <stdio.h>
#include <string.h>
struct globalArgs
{
    int help;
    int verbose;
    int setbits;
    int Associativity;
    int blockbits;
    char *tracefile;

} args;

struct Metric
{
    int hit;
    int miss;
    int eviction;
} metric;

typedef struct Cache
/* We don't need the char* data attribute,
 * because it is not included in the test file.
 */
{
    int valid;        /* valid bit 0/1 */
    unsigned int tag; /* tag */
    /* char* data; */
    unsigned long LRU_time; /* Last update time for LRU */
} cache_block;

cache_block *cache; /* Cache */
FILE *fp;           /* trace file */
unsigned long int tag_mask = 0, set_mask = 0, block_mask = 0;
int BUF_SIZE = 64;
void printHelp()
{
    puts("Usage: ./csim [-hv] -s <num> -E <num> -b <num> -t <file>\n"
         "Options:\n"
         "  -h         Print this help message.\n"
         "  -v         Optional verbose flag.\n"
         "  -s <num>   Number of set index bits.\n"
         "  -E <num>   Number of lines per set.\n"
         "  -b <num>   Number of block offset bits.\n"
         "  -t <file>  Trace file.\n"
         "\n"
         "Examples:\n"
         "  linux>  ./csim -s 4 -E 1 -b 4 -t traces/yi.trace\n"
         "  linux>  ./csim -v -s 8 -E 2 -b 4 -t traces/yi.trace");
}

void Init()
{
    /* Init cache as 1-d array */
    int blocksize = 1ULL << args.blockbits;
    int sets = 1ULL << args.setbits;
    int ways = args.Associativity;
    int cache_block_num = sets * ways;
    cache = (cache_block *)malloc(sizeof(cache_block) * cache_block_num);
    memset(cache, 0, sizeof(*cache));

    /* Init File ptr */
    fp = fopen(args.tracefile, "r");

    /* Init masks */
    block_mask = blocksize - 1;
    set_mask = ((1ULL << (args.setbits + args.blockbits)) - 1) ^ block_mask;
    tag_mask = 0xffffffffffffffff - set_mask - block_mask;
}

unsigned long getTag(unsigned long addr)
{
    return (addr & tag_mask) >> (args.setbits + args.blockbits);
}
unsigned long getIndex(unsigned long addr)
{
    return (addr & set_mask) >> (args.blockbits);
}

/* Access Memory, 0->hit, 1->cold miss, 2->miss */
int accessMemory(unsigned long addr, char type, int size, int time)
{
    unsigned long tag = getTag(addr);
    unsigned long index = getIndex(addr);
    int first_empty = -1;      /*  First empty slot */
    int lru_time = 0x7fffffff; /* Last time victim used in this set */
    int lru_pos = -1;          /*  Position of victim in this set */
    int base = index * args.Associativity;
    /* Loop through set */
    int i;
    for (i = 0; i < args.Associativity; i++)
    {
        if (cache[base + i].tag == tag && cache[base + i].valid)
        {
            /* Update the last visited time */
            cache[base + i].LRU_time = time;
            if (args.verbose)
            {
                printf("hit ");
                /* If type is M, second access also hits */
                if (type == 'M')
                    printf("hit");
                printf("\n");
            }
            return 0; /* return hit */
        }
        else if (cache[base + i].valid == 0 && first_empty == -1)
            first_empty = i;

        else if (cache[base + i].valid && cache[base + i].LRU_time < lru_time && cache[base + i].tag != tag)
        {
            lru_time = cache[base + i].LRU_time;
            lru_pos = i;
        }
    }
    /* First, if there is an empty slot,use it */
    if (first_empty != -1)
    {
        /* Cold miss */
        cache[base + first_empty].valid = 1;
        cache[base + first_empty].LRU_time = time;
        cache[base + first_empty].tag = tag;
        if (args.verbose)
        {
            printf("miss ");
            if (type == 'M')
                printf("hit");
            printf("\n");
        }
        return 1;
    }

    /* Capacity miss, need eviction  */
    else
    {
        cache[base + lru_pos].LRU_time = time;
        cache[base + lru_pos].tag = tag;
        if (args.verbose)
        {
            printf("miss eviction ");
            if (type == 'M')
                printf("hit");
            printf("\n");
        }
        return 2;
    }

    return -1; /* you should not reach this line. */
}
void runTest()
{
    char buf[BUF_SIZE];
    /* Parse Line */
    metric.hit = metric.eviction = metric.miss = 0;
    unsigned long addr;
    int size;
    char type;
    int time = 0;
    while (fgets(buf, BUF_SIZE, fp))
    {
        if (buf[0] == 'I')
            continue;
        int delimiter = 0;
        while (buf[delimiter] != ',')
            delimiter++;
        buf[delimiter] = 0;
        type = buf[1];
        addr = strtol(buf + 3, NULL, 16);
        size = atoi(buf + delimiter + 1);
        if (args.verbose)
            printf("%c %lx,%d ", type, addr, size);
        switch (accessMemory(addr, type, size, time++))
        {
        case 0:
            metric.hit++;
            break;
        case 1:
            metric.miss++;
            break;
        case 2:
            metric.miss++;
            metric.eviction++;
            break;
        default:
            break;
        }
        if (type == 'M')
            metric.hit++;
        /* If type is M, second ref(Store op) must hit */
    }
    return;
}
void argumentParse(int argc, char **argv)
{
    int opt = 0;
    args.Associativity = args.blockbits = args.setbits = -1;
    args.help = args.verbose = 0;
    args.tracefile = NULL;
    while ((opt = getopt(argc, argv, "hvs:E:b:t:")) != -1)
    {
        // printf("%d ", opt);

        switch (opt)
        {
        case 'v':
            args.verbose = 1;
            break;

        case 'E':
            args.Associativity = atoi(optarg);
            break;

        case 'b':
            args.blockbits = atoi(optarg);
            break;
        case 's':
            args.setbits = atoi(optarg);
            break;
        case 't':
            args.tracefile = optarg;
            break;
        case '?':
        /*  fall through */
        case 'h':
            printHelp();
            break;

        default:
            /* You won't actually get here. */
            break;
        }
    }
    // printf("s:%d b:%d e:%d file:%s", args.setbits, args.blockbits, args.Associativity, args.tracefile);
    /* Check for mandatory options and constrains */
    if (args.setbits <= 0 || args.Associativity <= 0 ||
        args.blockbits <= 0 || args.tracefile == NULL)
    {

        printf("%s: Missing required command line argument or some argument is invalid.\n", argv[0]);
        printHelp();
        return;
    }
    return;
}

void Free()
{
    free(cache);
    fclose(fp);
    return;
}
int main(int argc, char *argv[])
{

    argumentParse(argc, argv);
    Init();
    runTest();
    Free();
    printSummary(metric.hit, metric.miss, metric.eviction);
    return 0;
}
