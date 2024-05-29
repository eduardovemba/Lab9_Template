/**
 * @file stackArrayList.c
 * 
 * @brief Provides an implementation of the ADT Stack with an array list
 * as the underlying data structure.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "stack.h" 
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 20

typedef struct stackImpl { 
    StackElem *elements;   
    int capacity;     
    int size;      
} StackImpl;

static bool ensureCapacity(PtStack stack) {
    if (stack->size == stack->capacity) {
        int newCapacity = stack->capacity * 2;
        StackElem* newArray = (StackElem*) realloc( stack->elements, 
                                newCapacity * sizeof(StackElem) );
        
        if(newArray == NULL) return false; 

        stack->elements = newArray;
        stack->capacity = newCapacity;
    }
    
    return true;
}

PtStack stackCreate() {
    PtStack stack = (PtStack)malloc(sizeof(StackImpl));
    if (stack == NULL) return NULL;

    stack->elements = (StackElem*)calloc(INITIAL_CAPACITY,
                        sizeof(StackElem));

    if (stack->elements == NULL) {
        free(stack);
        return NULL;	
    }

    stack->size = 0;
    stack->capacity = INITIAL_CAPACITY;

    return stack;
}

int stackDestroy(PtStack *ptStack) {
    PtStack stack = (*ptStack);
    if (stack == NULL) return STACK_NULL;

    free(stack->elements);
    free(stack);

    *ptStack = NULL;

    return STACK_OK;
}

int stackPush(PtStack stack, StackElem elem) {
    if (stack == NULL) return STACK_NULL;
    
    if(!ensureCapacity(stack)) return STACK_NO_MEMORY;

    // Desloca os elementos para a direita
    for (int i = stack->size; i > 0; i--) {
        stack->elements[i] = stack->elements[i - 1];
    }

    // Insere o novo elemento no topo da pilha
    stack->elements[0] = elem;
    stack->size++;

    return STACK_OK;
}

int stackPop(PtStack stack, StackElem *ptElem) {
    if (stack == NULL) return STACK_NULL;

    if (stack->size == 0) return STACK_EMPTY;

    // Pega o elemento do topo da pilha
    *ptElem = stack->elements[0];

    // Desloca os elementos para a esquerda
    for (int i = 0; i < stack->size - 1; i++) {
        stack->elements[i] = stack->elements[i + 1];
    }

    stack->size--;

    return STACK_OK;
}


int stackPeek(PtStack stack, StackElem *ptElem) {
    if (stack == NULL) return STACK_NULL;

    if (stack->size == 0) return STACK_EMPTY;

    *ptElem = stack->elements[0];

    return STACK_OK;
}


int stackSize(PtStack stack, int *ptSize) {
    if (stack == NULL) return STACK_NULL;

    *ptSize = stack->size;

    return STACK_OK;
}

bool stackIsEmpty(PtStack stack) {
    if (stack == NULL) return true;

    return (stack->size == 0);
}

int stackClear(PtStack stack) {
    if (stack == NULL) return STACK_NULL;

    stack->size = 0;

    return STACK_OK;
}

void stackPrint(PtStack stack) {
    if (stack == NULL) {
        printf("(Stack NULL)\n");
    } else if (stackIsEmpty(stack)) {
        printf("(Stack Empty)\n");
    } else {
        printf("Stack contents (top to bottom): \n");
        for (int i = 0; i < stack->size; i++) {
            // Função fictícia para imprimir elementos da pilha
            stackElemPrint(stack->elements[i]);
        }
        printf("--- bottom --- \n");
    }
    printf("\n");
}


