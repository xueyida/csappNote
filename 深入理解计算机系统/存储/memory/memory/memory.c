#include <stdlib.h>
#include "memory.h"


// ����һ����ά���鲢���г�ʼ����������ڴ����ģ�£�
void createMemoryData(int row, int col, struct MemoryStruct* myMemory) {


	int total = sizeof(int) * row * col;

	myMemory->memoryData = (int*)malloc(total);

	int count = 0;




	myMemory->memoryData = (int*)malloc(row * col * sizeof(int));   //�����ڴ�ռ�
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			myMemory->memoryData[i * col + j] = count;
			count++;
		}
	}

}