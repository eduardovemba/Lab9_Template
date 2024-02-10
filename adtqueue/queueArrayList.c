/**
 * @file queueArrayList.c
 * 
 * @brief Provides an implementation of the ADT Queue with an array list
 * as the underlying data structure.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "queue.h" 
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 20

typedef struct queueImpl {
	// TODO
} QueueImpl;


PtQueue queueCreate() {
	return NULL;
}

int queueDestroy(PtQueue *ptQueue) {
	return -1;
}

int queueEnqueue(PtQueue queue, QueueElem elem) { 
	return -1;
}

int queueDequeue(PtQueue queue, QueueElem *ptElem) { 
	return -1;
}

int queueFront(PtQueue queue, QueueElem *ptElem) { 
	return -1;
}

int queueSize(PtQueue queue, int *ptSize) {
	return -1;
}

bool queueIsEmpty(PtQueue queue) {
	return false;
}

int queueClear(PtQueue queue) {
	return -1;
}

void queuePrint(PtQueue queue) { 
	// TODO
}

