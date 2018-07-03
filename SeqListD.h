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
