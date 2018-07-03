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
