# Algoritmos e Tipos Abstratos de Dados

## Lab 9 | Exercícios + Template  

:gb: [English version](README_en.md)

Este repositório foi criado a partir de:

- <https://github.com/estsetubal-atad/CProgram_Template> 

Consulte o README se tiver dúvidas sobre a sua utilização.

----

**Objetivos**:

- Utilização da estrutura de dados **array list** para implementação do *ADT Stack* e *ADT Queue*.
- Sensibilização para as complexidades algorítmicas das operações utilizadas.

**Referências**:

- Aula TP \[17, 18 & 20\].
- “Tipos Abstratos de Dados – Linguagem C. Bruno Silva”, disponível no Moodle.

---

### Organização do projeto VS Code

Os ficheiros relativos ao *ADT Stack* e *ADT Queue* encontram-se nas pastas `stack` e `queue`, respetivamente.  

O programa associado ao teste de cada implementação permite verificar se a política de acesso respetiva está a ser respeitada e em seguida faz um teste de *stress* com a inserção e remoção de `100.000` elementos. Isto irá permitir verificar o tempo de execução necessário e estará intimamente relacionado com a complexidade algorítmica das operações implementadas.  

Existe um único *makefile* (veja o seu conteúdo) que compila o programa necessário, e.g.:

```console
$> make stack
# ou
$> make queue
# para executar o programa compilado, usamos sempre:
$> ./prog
```

### Nível 1 - ADT Stack (Duração estimada: 20min)

A implementação em `stackArrayList.c` está parcialmente completa, mas falta a implementação das operações `push`, `pop` e `peek` e `print` que dependerão da abordagem escolhida para a obtenção da política de acesso LIFO. Em traços gerais, a inserção/remoção de elementos terá de ser feita na mesma "extremidade" da estrutura de dados.

1. Forneça a restante implementação das funções `push`, `pop` e `peek` e `print`, considerando o topo da pilha no "início" da estrutura de dados, i.e., índice `stack->elements[0]`.

2. Compile e execute o programa, verificando se a política de acesso LIFO está a ser respeitada e o tempo de execução do teste de stress (esperam-se vários segundos de execução!).

3. Quais as complexidades algorítmicas de cada uma das operações implementadas?

### Nível 2 - ADT Stack (Duração estimada: 20min)

A abordagem anterior não é a mais eficiente, como se observa pelos resultados.

4. Re-Implemente as funções `push`, `pop` e `peek` e `print`, mas agora considerando o topo da pilha no "final" da estrutura de dados, i.e., índice `stack->elements[stack->size - 1]`.

5. Compile e execute o programa, verificando se a política de acesso LIFO está a ser respeitada e o tempo de execução do teste de stress (espera-se uma execução muito rápida).

6. Quais as complexidades algorítmicas de cada uma das operações re-implementadas? Como se relacionam com os novos tempos de execução do teste de stress?

### Nível 3 - ADT Queue (Duração estimada: 25min)

A implementação em `queueArrayList.c` está praticamente vazia. Mas note que, se vamos utilizar a mesma estrutura de dados, e.g., *array list*, então a definição desta estrutura de dados, assim como as operações "gerais", e.g., `create`, `destroy`, `size`, `isEmpty` e `clear` são idênticas. 

7. Resolva a *forward declaration* ao definir o conteúdo da `struct queueImpl`.

8. Implemente as operações `create`, `destroy`, `size`, `isEmpty` e `clear`.

### Nível 4 - ADT Queue (Duração estimada: 20min)

Teremos de obter uma política de acesso FIFO com a manipulação da estrutura de dados *array list*. Em traços gerais, a inserção/remoção de elementos terá de ser feita em "extremidades" opostas da estrutura de dados.

9. Implemente as operações `enqueue`, `dequeue`, `front` e `print`.

10. Compile e execute o programa, verificando se a política de acesso FIFO está a ser respeitada e o tempo de execução do teste de stress.

11. Quais as complexidades algorítmicas de cada uma das operações implementadas? "Previlegiou" a inserção ou a remoção de elementos? 

### Nível 5 - ADT Stack + Queue (Duração estimada: 10min)

12. Verifique a correta gestão de memória dinâmica em ambas as suas implementações (ADT Stack e ADT Qeueue), utilizando para esse efeito o *valgrind*.

---

```markdown
@bruno.silva
(EOF)
``` 