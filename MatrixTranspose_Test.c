#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BUFF_SIZE	(1024) 
uint8_t SIDE_LEN = 0;
uint8_t DataList[BUFF_SIZE];
uint8_t TransList[BUFF_SIZE];

typedef struct
{
	void (*BackWard);
	void (*Foward);
	void (*_180);
	void (*xMirror);
	void (*yMirror);
}Matrix_Method_t;


//----------------------------------------------------------------------------//
//逆时针 
void MatrixTranspose_BackWard(uint8_t *src, uint8_t *dst)
{
	uint8_t row,column;
	
	for(row = 0; row < SIDE_LEN; row ++)
	for(column = 0; column < SIDE_LEN; column ++){
		*(dst+column+row*SIDE_LEN) = *(src+(SIDE_LEN-row-1)+SIDE_LEN*column);
	}
}
//顺时针
void MatrixTranspose_Foward(uint8_t *src, uint8_t *dst)
{
	uint8_t row,column;

	for(row = 0; row < SIDE_LEN; row ++)
	for(column = 0; column < SIDE_LEN; column ++){
		*(dst+column+row*SIDE_LEN) = *(src+row+(SIDE_LEN-column-1)*SIDE_LEN);
	}
} 
//180度
void MatrixTranspose_180(uint8_t *src, uint8_t *dst)
{
	uint8_t row,column;
	
	for(row = 0; row < SIDE_LEN; row ++)
	for(column = 0; column < SIDE_LEN; column ++){
		*(dst+column+row*SIDE_LEN) = *(src+SIDE_LEN*SIDE_LEN-1-(column+row*SIDE_LEN));
	}	
}

//X轴镜像
void MatrixTranspose_xMirror(uint8_t *src, uint8_t *dst)
{
	uint8_t row,column;
	for(row = 0; row < SIDE_LEN; row ++)
	for(column = 0; column < SIDE_LEN; column ++){
		*(dst+column+row*SIDE_LEN) = *(src+(SIDE_LEN-row-1)*SIDE_LEN+column);
	}		
}

//y轴镜像 
void MatrixTranspose_yMirror(uint8_t *src, uint8_t *dst)
{
	uint8_t row,column;
	for(row = 0; row < SIDE_LEN; row ++)
	for(column = 0; column < SIDE_LEN; column ++){
		*(dst+column+row*SIDE_LEN) = *(src+(SIDE_LEN-column-1)+SIDE_LEN*row);
	}
}
//----------------------------------------------------------------------------//

void Dis_Matrix(uint8_t *src)
{
	uint8_t i, num = 0;
	for( i = 0; i < SIDE_LEN*SIDE_LEN; i ++)
	{
		printf("%4d  ", *(src+i));
		num ++;
		if( (num%SIDE_LEN) == 0)
			printf("\r\n");
	}
}

//Init data list
void Create_DataList(void)
{
	uint8_t i;
	for( i = 0; i < SIDE_LEN*SIDE_LEN; i ++)
	{
		DataList[i] = i;
	}
}

void Transpose_Test(void)
{
	Create_DataList();//Init data list
	
	printf("------------------Before----------------\r\n");
	Dis_Matrix(DataList);	
	printf("------------------After-----------------\r\n");
	//MatrixTranspose_BackWard(DataList, TransList);
	//MatrixTranspose_Foward(DataList, TransList);
	MatrixTranspose_180(DataList, TransList);
	//MatrixTranspose_xMirror(DataList, TransList);
	//MatrixTranspose_yMirror(DataList, TransList);
	
	Dis_Matrix(TransList);
}

int main(void)
{
	
	while(1)
	{
		scanf("%d",&SIDE_LEN);
		system("cls");
		Transpose_Test();
	}
	
	return 0;
}

