#include "memory.h"
#ifndef _STUDENT_CONTROLLER
#define _STUDENT_CONTROLLER


// �ڴ��������صĹ�����
struct ControllerStruct {

	// ��λ���ݣ����������ڲ��л�����
	void (*locationMemoryData)(int i, int j);

	// ��λ��֮�󣬴��ڴ���ȡ����
	int (*getMemoryData)();


	// �������
	void (*setMemoryData)(int i, int j, int value);


};

void setMemoryData(int row, int col, int value, struct MemoryStruct* myMemory);

int getMemoryData(struct MemoryStruct* myMemory);


void locationMemoryData(int row, int col, struct MemoryStruct* myMemory);



struct ControllerStruct myController;

#endif



