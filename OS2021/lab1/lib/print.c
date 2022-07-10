#include "print.h"
#include "sbi.h"

void puts(char *s) {
    // unimplemented
	int i=0;
	while(s[i])
	{
	sbi_ecall(0x1, 0, s[i], 0, 0,0, 0, 0);
	i++;
	}

	return ;
}

void puti(int x) {
    // unimplemented
	int length=0, tmp = x;
	int scale = 1,i;
	if (x<0)
	{
		sbi_ecall(0x1, 0, '-', 0, 0, 0, 0, 0);
		puti( -x );
		return ;

	}
	while(x)
	{
		x = x/10;
		length++;
	}
	x = tmp;
	length = length>0?length:1;
	for( i=1;i<length;i++) scale = scale*10;

	for(i=1;i<=length;i++)
	{
	sbi_ecall(0x1,0,x/scale+'0',0,0,0,0,0);
		x = x%scale;
		scale = scale/10;
	}
	return ;
}
