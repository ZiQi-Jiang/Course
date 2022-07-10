#include "csapp.h"

#define MAXARGS 128
/*  Function prototypes */

void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);

/* parseline - Parse the command line and build the argv array */

int parseline(char *buf, char **argv)
{
    char *delim; /* Points to first space delimiter */
    int argc; /* Number of args */
    int bg; /* Backgroud job? */
    buf[strlen(buf)-1] = '';
    while (*buf && (*buf == ' ')) 

}

int main()
{
    char cmdline[MAXLINE]; /* Command line */

    while(1)
    {
        
        /* Read */
        printf("> ");
        Fgets(cmdline, MAXLINE, stdin);
        if(feof(stdin))
            exit(0);
        
        /* Evaluate */
        eval(cmdline);

    }
}