# Algorithms and Abstract Data Types

## Lab 9 | Exercises + Template  

This repository was created from:

- <https://github.com/estsetubal-atad/CProgram_Template> 

Refer to the README if you have any questions about its usage.

----

**Objectives**:

- Use of the **array list** data structure to implement the *ADT Stack* and *ADT Queue*.
- Awareness of the algorithmic complexities of the operations used.

**References**:

- TP Class \[17, 18 & 20\].
- "Abstract Data Types - C Language. Bruno Silva", available on Moodle.

---

### Project Organization in VS Code

The files related to the *ADT Stack* and *ADT Queue* are located in the `stack` and `queue` folders, respectively.  

The program associated with the test of each implementation allows to verify if the respective access policy is being respected and then performs a *stress* test with the insertion and removal of `100,000` elements. This will allow you to check the required execution time and will be closely related to the algorithmic complexity of the implemented operations.  

There is a single *makefile* (see its contents) that compiles the necessary program, e.g.:

```console
$> make stack
# or
$> make queue
# to execute the compiled program, always use:
$> ./prog
```

### Level 1 - ADT Stack (Estimated Duration: 20min)

The implementation in `stackArrayList.c` is partially complete, but the implementation of the `push`, `pop`, `peek`, and `print` operations is missing, which will depend on the approach chosen to obtain the LIFO access policy. In general terms, the insertion/removal of elements must be done at the same "side" of the data structure.

1. Provide the remaining implementation of the `push`, `pop`, `peek`, and `print` functions, considering the top of the stack at the "beginning" of the data structure, i.e., index `stack->elements[0]`.

2. Compile and execute the program, checking if the LIFO access policy is being respected and the execution time of the stress test (several seconds of execution are expected!).

3. What are the algorithmic complexities of each of the implemented operations?

### Level 2 - ADT Stack (Estimated Duration: 20min)

The previous approach is not the most efficient, as observed from the results.

4. Re-implement the `push`, `pop`, `peek`, and `print` functions, but now considering the top of the stack at the "end" of the data structure, i.e., index `stack->elements[stack->size - 1]`.

5. Compile and execute the program, checking if the LIFO access policy is being respected and the execution time of the stress test (a very fast execution is expected).

6. What are the algorithmic complexities of each of the re-implemented operations? How do they relate to the new execution times of the stress test?

### Level 3 - ADT Queue (Estimated Duration: 25min)

The implementation in `queueArrayList.c` is practically empty. But note that, if we are going to use the same data structure, e.g., *array list*, then the definition of this data structure, as well as the "general" operations, e.g., `create`, `destroy`, `size`, `isEmpty`, and `clear`, are identical. 

7. Resolve the *forward declaration* when defining the content of `struct queueImpl`.

8. Implement the `create`, `destroy`, `size`, `isEmpty`, and `clear` operations.

### Level 4 - ADT Queue (Estimated Duration: 20min)

We will have to obtain a FIFO access policy with the manipulation of the *array list* data structure. In general terms, the insertion/removal of elements must be done at "opposite ends" of the data structure.

9. Implement the `enqueue`, `dequeue`, `front`, and `print` operations.

10. Compile and execute the program, checking if the FIFO access policy is being respected and the execution time of the stress test.

11. What are the algorithmic complexities of each of the implemented operations? Did you "favor" the insertion or removal of elements? 

### Level 5 - ADT Stack + Queue (Estimated Duration: 10min)

12. Check the correct management of dynamic memory in both your implementations (ADT Stack and ADT Queue), using *valgrind* for this purpose.

---

```markdown
@bruno.silva
(EOF)
``` 