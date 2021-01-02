#include <stdlib.h>
#include "memory.h"
#include "controller.h"


void locationMemoryData(int row, int col, struct MemoryStruct* myMemory) {

	myMemory->rowData = malloc(sizeof(int) * MemoryCol);

	// ��һ���������� �Ȼ�ȡ��i�е����������浽������

	for (int i = 0; i < MemoryCol; i++) {
		myMemory->rowData[i] = myMemory->memoryData[MemoryCol * row + i];
	}


	//�ڶ����������� �ѵ�j�е�ֵ���浽�ڴ滺����
	myMemory->returnData = myMemory->rowData[col];

}

int getMemoryData(struct MemoryStruct* myMemory) {
	return myMemory->returnData;
}

void setMemoryData(int row, int col, int value, struct MemoryStruct* myMemory) {

	myMemory->rowData = malloc(sizeof(int) * MemoryCol);

	// ��������ڴ�ʱ�������ֵ��


	//�ڶ����������� �ѵ�j�е�ֵ���浽�ڴ滺����
	myMemory->memoryData[MemoryCol * row + col] = value;
}



struct ControllerStruct myController = {
	.locationMemoryData = locationMemoryData,
	.getMemoryData = getMemoryData,
	.setMemoryData = setMemoryData
};

