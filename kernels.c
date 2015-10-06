/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/*
 * ECE454 Students:
 * Please fill in the following team struct
 */
team_t team = {
	"LOL",              /* Team name */

	"Ryan Kang",     /* First member full name */
	"yiming.kang@mail.utoronto.ca",  /* First member email address */

	"Zexuan Wang",                   /* Second member full name (leave blank if none) */
	"zexuan.wang@mail.utoronto.ca"                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/*
 * naive_rotate - The naive baseline version of rotate
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst)
{
	int i, j;

	for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++)
			dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/*
 * ECE 454 Students: Write your rotate functions here:
 */

/*
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version - tileSize = 1024";
void rotate(int dim, pixel *src, pixel *dst) {
	int tile_size_x, tile_size_y;
	if (dim <= 1024) {
		tile_size_x = 32;
		tile_size_y = 2;
	} else {
		tile_size_x = 16;
		tile_size_y = 2;
	}
	int i, j, x, y, i_limit, j_limit;

	for (x=0; x<dim; x+=tile_size_x){
		i_limit = (dim > x+tile_size_x) ? (x+tile_size_x) : dim;
		for (y=0; y<dim; y+=tile_size_y){
			j_limit = (dim > y+tile_size_y) ? (y+tile_size_y) : dim;
			for (j = y; j < j_limit; j++){
				for (i = x; i < i_limit; i++){
					dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
				}
			}
		}
	}
}

char rotate_three_descr[] = "tileSize = 512";
void attempt_three(int dim, pixel *src, pixel *dst) {
	if (dim < 512)
		return naive_rotate(dim, src, dst);
	int tile_num = 512;
	int tile_size = dim/tile_num;
	int i, j, x, y;

	for (x=0; x<tile_num; x++){
		int baseI = x*tile_size;
		for (y=0; y<tile_num; y++){
			int baseJ = y*tile_size;
			for (j = 0; j < tile_size; j++)
				for (i = 0; i < tile_size; i++)
					dst[RIDX(dim-1-baseJ-j, baseI+i, dim)] = src[RIDX(baseI+i, baseJ+j, dim)];
		}
	}
}

char rotate_four_descr[] = "tile with size 256";
void attempt_four(int dim, pixel *src, pixel *dst) {
	if (dim < 256)
		return naive_rotate(dim, src, dst);
	int tile_num = 256;
	int tile_size = dim/tile_num;
	int i, j, x, y;

	for (x=0; x<tile_num; x++){
		int baseI = x*tile_size;
		for (y=0; y<tile_num; y++){
			int baseJ = y*tile_size;
			for (i = 0; i < tile_size; i++)
				for (j = 0; j < tile_size; j++)
					dst[RIDX(dim-1-baseJ-j, baseI+i, dim)] = src[RIDX(baseI+i, baseJ+j, dim)];
		}
	}
}

char rotate_five_descr[] = "tile with size 128";
void attempt_five(int dim, pixel *src, pixel *dst) {
	if (dim < 128)
		return naive_rotate(dim, src, dst);
	int tile_num = 128;
	int tile_size = dim/tile_num;
	int i, j, x, y;

	for (x=0; x<tile_num; x++){
		int baseI = x*tile_size;
		for (y=0; y<tile_num; y++){
			int baseJ = y*tile_size;
			for (i = 0; i < tile_size; i++)
				for (j = 0; j < tile_size; j++)
					dst[RIDX(dim-1-baseJ-j, baseI+i, dim)] = src[RIDX(baseI+i, baseJ+j, dim)];
		}
	}
}

char rotate_six_descr[] = "tile with size 64";
void attempt_six(int dim, pixel *src, pixel *dst) {
	if (dim % 64 != 0)
		return naive_rotate(dim, src, dst);
	int tile_num = 64;
	int tile_size = dim/tile_num;
	int i, j, x, y;

	for (x=0; x<tile_num; x++){
		int baseI = x*tile_size;
		for (y=0; y<tile_num; y++){
			int baseJ = y*tile_size;
			for (i = 0; i < tile_size; i++)
				for (j = 0; j < tile_size; j++)
					dst[RIDX(dim-1-baseJ-j, baseI+i, dim)] = src[RIDX(baseI+i, baseJ+j, dim)];
		}
	}
}

char rotate_seven_descr[] = "tile with size 32";
void attempt_seven(int dim, pixel *src, pixel *dst) {
	int tile_num = 32;
	int tile_size = dim/tile_num;
	int i, j, x, y;

	for (x=0; x<tile_num; x++){
		int baseI = x*tile_size;
		for (y=0; y<tile_num; y++){
			int baseJ = y*tile_size;
			for (i = 0; i < tile_size; i++)
				for (j = 0; j < tile_size; j++)
					dst[RIDX(dim-1-baseJ-j, baseI+i, dim)] = src[RIDX(baseI+i, baseJ+j, dim)];
		}
	}
}

char rotate_eight_descr[] = "tile with size 16";
void attempt_eight(int dim, pixel *src, pixel *dst) {
	int tile_num = 16;
	int tile_size = dim/tile_num;
	int i, j, x, y;

	for (x=0; x<tile_num; x++){
		int baseI = x*tile_size;
		for (y=0; y<tile_num; y++){
			int baseJ = y*tile_size;
			for (i = 0; i < tile_size; i++)
				for (j = 0; j < tile_size; j++)
					dst[RIDX(dim-1-baseJ-j, baseI+i, dim)] = src[RIDX(baseI+i, baseJ+j, dim)];
		}
	}
}

char rotate_nine_descr[] = "tile with size 8";
void attempt_nine(int dim, pixel *src, pixel *dst) {
	int tile_num = 8;
	int tile_size = dim/tile_num;
	int i, j, x, y;

	for (x=0; x<tile_num; x++){
		int baseI = x*tile_size;
		for (y=0; y<tile_num; y++){
			int baseJ = y*tile_size;
			for (i = 0; i < tile_size; i++)
				for (j = 0; j < tile_size; j++)
					dst[RIDX(dim-1-baseJ-j, baseI+i, dim)] = src[RIDX(baseI+i, baseJ+j, dim)];
		}
	}
}

char rotate_ten_descr[] = "tile with size 4";
void attempt_ten(int dim, pixel *src, pixel *dst) {
	int tile_num = 4;
	int tile_size = dim/tile_num;
	int i, j, x, y;

	for (x=0; x<tile_num; x++){
		int baseI = x*tile_size;
		for (y=0; y<tile_num; y++){
			int baseJ = y*tile_size;
			for (i = 0; i < tile_size; i++)
				for (j = 0; j < tile_size; j++)
					dst[RIDX(dim-1-baseJ-j, baseI+i, dim)] = src[RIDX(baseI+i, baseJ+j, dim)];
		}
	}
}

char rotate_eleven_descr[] = "tile with size 2";
void attempt_eleven(int dim, pixel *src, pixel *dst) {
	int tile_num = 2;
	int tile_size = dim/tile_num;
	int i, j, x, y;

	for (x=0; x<tile_num; x++){
		int baseI = x*tile_size;
		for (y=0; y<tile_num; y++){
			int baseJ = y*tile_size;
			for (i = 0; i < tile_size; i++)
				for (j = 0; j < tile_size; j++)
					dst[RIDX(dim-1-baseJ-j, baseI+i, dim)] = src[RIDX(baseI+i, baseJ+j, dim)];
		}
	}
}

/* second attempt */
char rotate_two_descr[] = "second attempt";
int logBase2(int dim){
	int result = 1;
	while (dim != 0) {
		result++;
		dim >>=1;
	}
	return result;
}
void attempt_two(int dim, pixel *src, pixel *dst)
{
}

/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_rotate_functions()
{
	add_rotate_function(&naive_rotate, naive_rotate_descr);
	add_rotate_function(&rotate, rotate_descr);

	/* add_rotate_function(&attempt_two, rotate_two_descr); */
	add_rotate_function(&attempt_three, rotate_three_descr);
	add_rotate_function(&attempt_four, rotate_four_descr);
	add_rotate_function(&attempt_five, rotate_five_descr);
	add_rotate_function(&attempt_six, rotate_six_descr);
	add_rotate_function(&attempt_seven, rotate_seven_descr);
	add_rotate_function(&attempt_eight, rotate_eight_descr);
	add_rotate_function(&attempt_nine, rotate_nine_descr);
	add_rotate_function(&attempt_ten, rotate_ten_descr);
	add_rotate_function(&attempt_eleven, rotate_eleven_descr);

	/* ... Register additional rotate functions here */
}

