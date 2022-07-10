#include "transpose.h"

/* The naive transpose function as a reference. */
void transpose_naive(int n, int blocksize, int *dst, int *src) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            dst[y + x * n] = src[x + y * n];
        }
    }
}

/* Implement cache blocking below. You should NOT assume that n is a
 * multiple of the block size. */
void transpose_blocking(int n, int blocksize, int *dst, int *src) {
    // YOUR CODE HERE
	int block_w = blocksize / 4;
	int block_size =( n-1 ) / block_w + 1;
	for(int b_x =0;b_x<block_size; b_x++)
		for(int b_y=0;b_y<block_size;b_y++)  // select the block
		{
			int start_x = block_w*b_x,start_y = block_w*b_y;
			int end_x = start_x + block_w, end_y = block_w + start_y;
			if(end_x>=n) end_x  = n;
			if(end_y>=n) end_y  = n;
			for(int x=start_x; x< end_x;x++)
  				for(int y=start_y; y<end_y;y++)
					{
					dst[y + x * n] = src[x + y * n];
					}
		}
}
