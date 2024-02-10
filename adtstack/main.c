/**
 * @file main.c
 * 
 * @brief Provides an example program that uses the
 * ADT Stack. Please note that the StackElem type
 * must be defined as 'int'.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include <time.h>

#define STRESS_TEST_SIZE 100000

void testLIFO(PtStack stack);
void testStress(PtStack stack);

int main() {
    PtStack stack = stackCreate();
    if(stack == NULL) {
        printf("Could not create the stack. \n");
        return EXIT_FAILURE;
    }

    //test LIFO twice - make sure implementation works
    //after being emptied.
    testLIFO(stack);
    testLIFO(stack);

    //stress test - useful for comparing different implementations
    testStress(stack);

    stackDestroy(&stack);

    return EXIT_SUCCESS;
}

void testLIFO(PtStack stack) {
    stackPrint(stack);

    //Test LIFO behavior (visually from output)
    char examples[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    for(int i=0; i<sizeof(examples)/sizeof(char); i++) {
        char ex = examples[i];
        printf("Pushing %c ...", ex);
        stackPush(stack, ex);

        char top;
        stackPeek(stack, &top);
        int size;
        stackSize(stack, &size);
        printf("-> %c at top of stack (size = %d).\n", top, size);
    }

    stackPrint(stack);

    while(!stackIsEmpty(stack)) {
        char pop;
        stackPop(stack, &pop);
        
        int size;
        stackSize(stack, &size);
        printf("Popped %c from stack -> (resulting size = %d).\n", pop, size);
    }

    stackPrint(stack);
}

void testStress(PtStack stack) {
    printf("\nStress testing with %d elements... \n", STRESS_TEST_SIZE);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    /* Do the work. */
    for(int i=0; i<STRESS_TEST_SIZE; i++) {
        int error_code = stackPush(stack, 'a');
        if(error_code != STACK_OK) {
            printf("Stopping because an error ocurred... Code: %d \n", error_code);
            break;
        }
    }

    while(!stackIsEmpty(stack)) {
        char pop;
        stackPop(stack, &pop);       
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("-- Time taken: %lf seconds \n", cpu_time_used);
}