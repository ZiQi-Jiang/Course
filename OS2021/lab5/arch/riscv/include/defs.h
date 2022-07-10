#ifndef _DEFS_H
#define _DEFS_H

#define csr_read(csr)                       \
({                                          \
    register uint64 __v;                    \
	asm volatile ("csrr  %0, "#csr" "       \
	:"r"(__v)::"memory"\
                 );   \
})

#define csr_write(csr, val)                         \
({                                                  \
    uint64 __v = (uint64)(val);                     \
    asm volatile ("csrw " #csr ", %0"               \
                    : : "r" (__v)                   \
                    : "memory");                    \
})

#define PHY_START 0x0000000080000000
#define PHY_SIZE  128 * 1024 * 1024 // 128MB， QEMU 默认内存大小
#define PHY_END   (PHY_START + PHY_SIZE)

#define PGSIZE 0x1000 // 4KB
#define PGROUNDUP(addr) ( (((uint64)addr) + PGSIZE - 1) & (~(PGSIZE - 1)))
#define PGROUNDDOWN(addr) ( ((uint64)addr)  & (~(PGSIZE - 1)))



#define OPENSBI_SIZE (0x200000)

#define VM_START 0xffffffe000000000
#define VM_END   0xffffffff00000000
#define VM_SIZE  (VM_END - VM_START)

#define PA2VA_OFFSET (VM_START - PHY_START)
#define PA2VA(pa) ( ((uint64)pa) + (uint64)PA2VA_OFFSET)
#define PTE_V (1L << 0)
#define PTE_R (1L << 1)
#define PTE_W (1L << 2)
#define PTE_X (1L << 3)

#define PAGE_SHIFT 12
#define PXMASK 0x1ff
#define PXSHIFT(level) ( PAGE_SHIFT + (9*(level) ))
#define PX(level, va)  ( ( ((uint64)(va)) >> PXSHIFT(level)) & PXMASK )

// the usage of [ & PXMASK] ==> reterive the 0-9th bits and clear other bits , which is the index.

// shift a physical address to the right place for a PTE
#define PA2PTE(pa)  ((((uint64)pa) >> 12 ) << 10 )

// given a pte, get the according physical address
#define PTE2PA(pte) ((((uint64)pte) >> 10) <<12 )

// given a pte, get the flags
#define PTE_FLAGS(pte)  (((unit64)pte) & 0x3ff)

// For Lab 5
#define USER_START (0x0000000000000000) // user space start virtual address
#define USER_END   (0x0000004000000000) // user space end virtual address

#define SSTATUS_SPIE (1L << 5)
#define SSTATUS_SPP  (1L << 8)
#define SSTATUS_SUM  (1L << 18)

#endif
