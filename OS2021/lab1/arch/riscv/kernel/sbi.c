#include "types.h"
#include "sbi.h"

/*
struct sbiret sbi_ecall(int ext, int fid, uint64 arg0,
			            uint64 arg1, uint64 arg2,
			            uint64 arg3, uint64 arg4,
			            uint64 arg5) 
{
	struct sbiret res;
    // unimplemented           
	__asm__ volatile("add a7,a0,x0 \n\t"
					 "add a6,a1,x0 \n\t"
					 "add a0,a2,x0 \n\t"
					: :[a1]"r"(ext), [a2]"r"(fid), [a3]"r"(arg0):
					 );
	__asm__ volatile("ecall");
		//[a7]"r"(ext),[a6]"r"(fid),[a0]"r"(arg0),[a1]"r"(arg1),[a2]"r"(arg2),[a3]"r"(arg3),[a4]"r"(arg4),[a5]"r"(arg5):
		
	__asm__ volatile("add %[a2],a0,x0 \n\t"
					 "add %[a3],a1,x0 \n\t"
					 :[a2] "=r"(res.error), [a3]"=r"(res.value)::
					 );

	return res;
}
*/
struct sbiret sbi_ecall(int ext, int fid, uint64 arg0, 
						uint64 arg1, uint64 arg2,
						uint64 arg3, uint64 arg4,
						uint64 arg5)
{
	struct sbiret res;
	register uint64 a0 asm("a0") = arg0;
	register uint64 a1 asm("a1") = arg1; register uint64 a2 asm("a2") = arg2;
	register uint64 a3 asm("a3") = arg3;
	register uint64 a4 asm("a4") = arg4;
	register uint64 a5 asm("a5") = arg5;
	register uint64 a6 asm("a6") = (uint64)fid;
	register uint64 a7 asm("a7") = (uint64)ext;
	
	asm volatile ("ecall"
				: "+r"(a0),"+r"(a1)
				: "r"(a2), "r"(a3),"r"(a4),"r"(a5),"r"(a6),"r"(a7)
				: "memory"
	);
	res.error = a0;
	res.value = a1;
	return res;
}


