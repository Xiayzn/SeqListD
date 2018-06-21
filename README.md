# SeqListD
//动态顺序表

//SeqListD.h
#ifndef __SeqListD_H__
#define __SeqListD_H__

#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>

typedef int DataType;
typedef unsigned int size_t;


typedef struct SeqListD
{
	DataType* _array;
	size_t _capacity;//底层空间的大小
	size_t _size;//有效元素的个数
}SeqListD, *PSeqListD;

void SeqListDInit(PSeqListD pSeq);//初始化
int SeqListDEmpty(PSeqListD pSeq);//判定动态顺序表是否为空
int SeqListDSize(PSeqListD pSeq);//元素个数
void SeqListDPushBack(PSeqListD pSeq, DataType data);//尾插

// 检测顺序表是否需要增容 
int CheckCapacity(PSeqListD pSeq);
int SeqListDCapacity(PSeqListD pSeq);//增容
void PrintSeqListD(PSeqListD pSeq);// 打印顺序表中的元素 

// 清空顺序表中的所有元素，注意不改变底层空间的大小 
void SeqListDClear(PSeqListD pSeq);
// 销毁顺序表 
void SeqListDDestroy(PSeqListD pSeq);

#endif //__SeqListD_H__

//SeqListD.c
#include "SeqListD.h"

void SeqListDInit(PSeqListD pSeq)
{
	//动态列表为空
	if (NULL == pSeq)
		return;

	pSeq->_size = 0;
	pSeq->_capacity = 10;
	pSeq->_array = (DataType *)malloc(sizeof(DataType)*pSeq->_capacity);
	if (NULL == pSeq->_array)
	{
		assert(pSeq->_array);
		return;
	}
}

int CheckCapacity(PSeqListD pSeq)
{
	//动态列表为空
	if (SeqListDEmpty(pSeq))
		return 0;

	if (pSeq->_size >= pSeq->_capacity)
		return 1;

	return 0;
}

int SeqListDEmpty(PSeqListD pSeq)
{
	if (NULL == pSeq)
		return 1;
	
	return 0;
}

int SeqListDSize(PSeqListD pSeq)
{
	//动态顺序表为空
	if (SeqListDEmpty(pSeq))
		return -1;

	return pSeq->_size;
}

int SeqListDCapacity(PSeqListD pSeq)
{
	DataType* temp = pSeq->_array;
	//动态顺序表为空
	if (SeqListDEmpty(pSeq))
		return 0;

	pSeq->_array = realloc(pSeq->_array, (pSeq->_capacity)*sizeof(DataType)*2);

	if (NULL == pSeq)
	{
		assert(pSeq);
		pSeq->_array = temp;
		printf("增容失败\n");
		return -1;
	}

	return 1;
}
void SeqListDPushBack(PSeqListD pSeq, DataType data)
{
	//动态顺序表为空
	if (SeqListDEmpty(pSeq))
		return;
	//动态顺序是否已经满了
	if (CheckCapacity(pSeq))
		SeqListDCapacity(pSeq);

	pSeq->_array[pSeq->_size] = data;
	++pSeq->_size;

}


void PrintSeqListD(PSeqListD pSeq)
{
	size_t i = 0;
	//动态顺序表为空
	if (SeqListDEmpty(pSeq))
		return;
	if (0 == pSeq->_size)
		return;

	for (i = 0; i < pSeq->_size; ++i)
	{
		printf("%d ",pSeq->_array[i]);
	}
	printf("\n");
}

void SeqListDClear(PSeqListD pSeq)
{
	//动态顺序表为空
	if (SeqListDEmpty(pSeq))
		return;

	pSeq->_size = 0;
}

void SeqListDDestroy(PSeqListD pSeq)
{
	//动态顺序表为空
	if (SeqListDEmpty(pSeq))
		return;

	free(pSeq->_array);
}


//test.c
#include "SeqListD.h"

void TestSeqListDInit()
{
	SeqListD s;
	SeqListDInit(&s);
	SeqListDInit(NULL);
}

void TestCheckCapacity()
{
	SeqListD s;
	SeqListDInit(&s);
	CheckCapacity(&s);
	CheckCapacity(NULL);

}
void TestSeqListDSize()
{
	SeqListD s;
	SeqListDInit(&s);
	SeqListDPushBack(&s, 2);
	SeqListDPushBack(&s, 3);

	printf("%d\n", SeqListDSize(NULL));

	printf("%d\n",SeqListDSize(&s));
}
void TestSeqListDPushBack()
{
	SeqListD s;
	SeqListDInit(&s);

	SeqListDPushBack(NULL, 1);

	SeqListDPushBack(&s, 1);
	PrintSeqListD(&s);
	SeqListDPushBack(&s, 2);
	SeqListDPushBack(&s, 3);
	SeqListDPushBack(&s, 4);
	SeqListDPushBack(&s, 5);
	SeqListDPushBack(&s, 6);
	SeqListDPushBack(&s, 7);
	SeqListDPushBack(&s, 8);
	SeqListDPushBack(&s, 9);
	SeqListDPushBack(&s, 0);
	PrintSeqListD(&s);

	SeqListDPushBack(&s, 1);
	PrintSeqListD(&s);

}

void TestSeqListDClear()
{
	SeqListD s;
	SeqListDInit(&s);
	SeqListDPushBack(&s, 2);
	SeqListDPushBack(&s, 3);
	SeqListDPushBack(&s, 4);
	SeqListDPushBack(&s, 5);
	SeqListDPushBack(&s, 6);
	printf("%d\n", SeqListDSize(&s));

	SeqListDClear(NULL);
	SeqListDClear(&s);
	printf("%d\n", SeqListDSize(&s));

}

void TestSeqListDDestroy()
{
	SeqListD s;
	SeqListDInit(&s);
	SeqListDPushBack(&s, 2);
	SeqListDPushBack(&s, 3);
	SeqListDPushBack(&s, 4);
	SeqListDPushBack(&s, 5);
	SeqListDPushBack(&s, 6);
	SeqListDDestroy(&s);
}
int main()
{
	//TestSeqListDInit();
	//TestCheckCapacity();
	//TestSeqListDSize();
	//TestSeqListDPushBack();
	//TestSeqListDClear();
	TestSeqListDDestroy();
	return 0;
}
