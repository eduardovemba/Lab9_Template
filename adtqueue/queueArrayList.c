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
    QueueElem *elements;
    int capacity;
    int size;
    int front;
    int rear;
} QueueImpl;


PtQueue queueCreate() {
    PtQueue queue = (PtQueue)malloc(sizeof(QueueImpl));
    if (queue == NULL) return NULL;

    queue->elements = (QueueElem*)calloc(INITIAL_CAPACITY, sizeof(QueueElem));
    if (queue->elements == NULL) {
        free(queue);
        return NULL;
    }

    queue->capacity = INITIAL_CAPACITY;
    queue->size = 0;
    queue->front = 0;
    queue->rear = -1;

    return queue;
}


int queueDestroy(PtQueue *ptQueue) {
    if (ptQueue == NULL || *ptQueue == NULL) return QUEUE_NULL;

    PtQueue queue = *ptQueue;
    free(queue->elements);
    free(queue);
    *ptQueue = NULL;

    return QUEUE_OK;
}


int queueEnqueue(PtQueue queue, QueueElem elem) {
    if (queue == NULL) return QUEUE_NULL;

    if (queue->size == queue->capacity) {
        int newCapacity = queue->capacity * 2;
        QueueElem *newArray = (QueueElem*) realloc(queue->elements, newCapacity * sizeof(QueueElem));
        if (newArray == NULL) return QUEUE_NO_MEMORY;

        queue->elements = newArray;
        queue->capacity = newCapacity;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear] = elem;
    queue->size++;

    return QUEUE_OK;
}

int queueDequeue(PtQueue queue, QueueElem *ptElem) {
    if (queue == NULL) return QUEUE_NULL;

    if (queue->size == 0) return QUEUE_EMPTY;

    *ptElem = queue->elements[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return QUEUE_OK;
}

int queueFront(PtQueue queue, QueueElem *ptElem) {
    if (queue == NULL) return QUEUE_NULL;

    if (queue->size == 0) return QUEUE_EMPTY;

    *ptElem = queue->elements[queue->front];

    return QUEUE_OK;
}

int queueSize(PtQueue queue, int *ptSize) {
    if (queue == NULL) return QUEUE_NULL;

    *ptSize = queue->size;
    return QUEUE_OK;
}


bool queueIsEmpty(PtQueue queue) {
    if (queue == NULL) return true;

    return (queue->size == 0);
}


int queueClear(PtQueue queue) {
    if (queue == NULL) return QUEUE_NULL;

    queue->size = 0;
    queue->front = 0;
    queue->rear = -1;

    return QUEUE_OK;
}


void queuePrint(PtQueue queue) {
    if (queue == NULL) {
        printf("(Queue NULL)\n");
    } else if (queueIsEmpty(queue)) {
        printf("(Queue Empty)\n");
    } else {
        printf("Queue contents (front to rear): \n");
        int index = queue->front;
        for (int i = 0; i < queue->size; i++) {
            // Função fictícia para imprimir elementos da fila
            queueElemPrint(queue->elements[index]);
            index = (index + 1) % queue->capacity;
        }
        printf("--- rear --- \n");
    }
    printf("\n");
}


