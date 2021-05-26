#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>     // For INT_MIN

#define SIZE 100


typedef struct relatorio{
    int totalTranspor;
    int duracao;
    char * nomeCondutor[30];
} relatorio;


// criar uma pilha com capacidade para 100 elementos
relatorio stack[SIZE];

// Initially stack is empty 
int top = -1;


/* Function declaration to perform push and pop on stack */
void push(int pessoasTrans, char * nomeCondu, int duracao);
int  pop();


int main()
{
    int choice, data;

    while(1)
    {
        /* Menu */
        printf("------------------------------------\n");
        printf("    STACK IMPLEMENTATION PROGRAM    \n");
        printf("------------------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Size\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) 
        {
            case 1: 
                printf("Enter data to push into stack: ");
                scanf("%d", &data);
                
                // Push element to stack
                push(data, "José ne", 20);
                break;

            case 2: 
                data = pop();

                // If stack is not empty
                if (data != INT_MIN)
                    printf("Data => %d\n", data);
                break;

            case 3: 
                printf("Stack size: %d\n", top + 1);
                break;

            case 4: 
                printf("Exiting from app.\n");
                exit(0);
                break;

            default: 
                printf("Invalid choice, please try again.\n");
        }

        printf("\n\n");
    }


    return 0;
}



/**
 * Functiont to push a new element in stack.
 */
void push(int pessoasTrans, char * nomeCondu, int duracao)
{
    // Check stack overflow
    if (top >= SIZE)
    {
        printf("Stack Overflow, can't add more element element to stack.\n");
        return;
    }

    // Increase element count in stack
    top++;

    // Push element in stack
    stack[top].totalTranspor = pessoasTrans;
    strcpy(stack[top].nomeCondutor, nomeCondu);
    stack[top].duracao = duracao;

    printf("Data pushed to stack.\n");
}


/**
 * Function to pop element from top of stack.
 */
int pop()
{
    int i=0, menorTempo=0, maisTranspor=0;
    char conduMenorTempo[30], conduMaisTranspor[30];

    // Check stack underflow
    if (top < 0)
    {
        printf("Stack is empty.\n");

        // Throw empty stack error/exception
        // Since C does not have concept of exception
        // Hence return minimum integer value as error value
        // Later in code check if return value is INT_MIN, then
        // stack is empty
        return INT_MIN;
    }


    // Return stack top and decrease element count in stack
    for(;i<=top;i++){
        if (stack[top].duracao>menorTempo){
            stpcpy(conduMenorTempo, stack[top].nomeCondutor)
        }
        printf("condutor: %s, tempo: %d, pessoasTrans: %d\n", stack[top].nomeCondutor, stack[top].duracao, stack[top].totalTranspor);
    }
    return stack[top--].totalTranspor;
}