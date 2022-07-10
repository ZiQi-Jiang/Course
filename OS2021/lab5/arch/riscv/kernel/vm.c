#include"defs.h"
#include"types.h"
#include"string.h"
#include"mm.h"
#include"vm.h"
extern uint64 _stext,_etext,_srodata,_erodata,_ekernel;
//  ===================== part 1: setup_vm =========================
/* early_pgtbl: 用于 setup_vm 进行 1GB 的 映射。 */
uint64 early_pgtbl[512] __attribute__((__aligned__(0x1000)));

void setup_vm(void) {
    /* 
    1. 由于是进行 1GB 的映射 这里不需要使用多级页表 
    2. 将 va 的 64bit 作为如下划分： | high bit | 9 bit | 30 bit |
        high bit 可以忽略
        中间9 bit 作为 early_pgtbl 的 index
        低 30 bit 作为 页内偏移 这里注意到 30 = 9 + 9 + 12， 即我们只使用根页表， 根页表的每个 entry 都对应 1GB 的区域。 
    3. Page Table Entry 的权限 V | R | W | X 位设置为 1
    */
	
	early_pgtbl[2]   =  ( (0x80000<<10) | 0b000001111 ); // PA == VA
	// PPN[2] = 0b10 PPN[1] = PPN[0] = 000000000(9)

	early_pgtbl[384] =( (0x80000<<10) | 0b000001111 ); // PA + PA2VA_OFFSET == VA

	
	return ;
}



// ====================== part 2: setup_vm_final ========================

/* swapper_pg_dir: kernel pagetable 根目录， 在 setup_vm_final 进行映射。 */
uint64  swapper_pg_dir[512] __attribute__((__aligned__(0x1000)));

void setup_vm_final(void) {
    memset(swapper_pg_dir, 0x0, PGSIZE);

    // No OpenSBI mapping required

    // mapping kernel text X|-|R|V
	uint64 pa = PHY_START + OPENSBI_SIZE;
	uint64 text_len = _etext-_stext;
    create_mapping(swapper_pg_dir,(uint64)_stext,pa,
					text_len, PTE_X | PTE_R | PTE_V);

    // mapping kernel rodata -|-|R|V
	pa += text_len;
	uint64 rodata_len = _erodata - _srodata;
    create_mapping(swapper_pg_dir, _srodata, pa, rodata_len, PTE_R | PTE_V);

    // mapping other memory -|W|R|V
//    create_mapping(...);
	pa += rodata_len;
	uint64 memory_len = PHY_END - _ekernel;
	create_mapping(swapper_pg_dir, _ekernel,pa, memory_len, PTE_W | PTE_R | PTE_V );
    // set satp with swapper_pg_dir

	register uint64 a0 asm("a0") = (uint64)swapper_pg_dir;

	csr_write(satp,swapper_pg_dir); // defined in defs.h
   // YOUR CODE HERE

    // flush TLB
    asm volatile("sfence.vma zero, zero");
    return;
}


// NOTE: All the values in the PageTable are ADDRESS,you can view it as a POINTER.

// NOTE: the prem is ONLY used at the lowest level,which point to the physical address
uint64* walk(uint64* pgtbl, uint64 va)
{
	for( int level = 2; level > 0; level--)
	{
		
		uint64* pte = & pgtbl[PX(level, va)];// get the current level pte address.
		if(*pte & PTE_V) // valid ==> has content
			pgtbl = (uint64*)PTE2PA(*pte);
		else
		{	
			pgtbl = (uint64*)kalloc();
			memset(pgtbl, 0, PGSIZE);
			*pte = PA2PTE(pgtbl) | PTE_V;

		}
	}

	return &pgtbl[PX(0,va)];
}

/* 创建多级页表映射关系 */
void create_mapping(uint64 *pgtbl, uint64 va, uint64 pa, uint64 sz, int perm) {
    /*
    pgtbl 为根页表的基地址
    va, pa 为需要映射的虚拟地址、物理地址
    sz 为映射的大小
    perm 为映射的读写权限

    创建多级页表的时候可以使用 kalloc() 来获取一页作为页表目录
    可以使用 V bit 来判断页表项是否存在
    */
	uint64 a, last;
	uint64* pte;

	// align the start and end address of va.
	a = PGROUNDDOWN(va); 
	last = PGROUNDDOWN(va + sz - 1);
	
	while(1)
	{
		pte = walk(pgtbl, a);  //Find level 0 pte address
		*pte = PA2PTE(pa) | perm | PTE_V; // write the physical address to pte
		if(a == last) break;

		a += PGSIZE;
		pa += PGSIZE;

	}
	return ;
}
