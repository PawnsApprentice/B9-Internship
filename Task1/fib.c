#include <stdio.h>
#include <stdlib.h>
#include "fib.h"

Node* addFunc(void* arg1, void* arg2)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if(arg1 == NULL)
    {
        node->type = FIB;
        node->value = *(int*)arg2;
        return node;
    }
    else if(arg2 == NULL)
    {
        node->type = FIB;
        node->value = *(int*)arg1;
        return node;
    }
    else if(arg1 == NULL && arg2==NULL)
    {
        printf("\n Both arguments cannot be null");
        exit(EXIT_FAILURE);
    }
    int val1 =  *(int*)arg1;
    int val2 =  *(int*)arg2;
    int result = val1+ val2;
    node->type = ADD;
    node->value = result;
    return node;
}

Node* subFunc(void* arg1, void* arg2)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if(arg1 == NULL)
    {
        node->type = FIB;
        node->value = *(int*)arg2;
        return node;
    }
    else if(arg2 == NULL)
    {
        node->type = FIB;
        node->value = *(int*)arg1;
        return node;
    }
    else if(arg1 == NULL && arg2==NULL)
    {
        printf("\n Both arguments cannot be null");
        exit(EXIT_FAILURE);
    }
    int val1 =  *(int*)arg1;
    int val2 =  *(int*)arg2;
    int result = val1-val2;

    node->type = SUB;


    node->value = result;
    return node;
}

Node* mulFunc(void* arg1, void* arg2)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if(arg1 == NULL)
    {
        node->type = FIB;
        node->value = *(int*)arg2;
        return node;
    }
    else if(arg2 == NULL)
    {
        node->type = FIB;
        node->value = *(int*)arg1;
        return node;
    }
    else if(arg1 == NULL && arg2==NULL)
    {
        printf("\n Both arguments cannot be null");
        exit(EXIT_FAILURE);
    }
    int val1 = *(int*)arg1;
    int val2 = *(int*)arg2;
    int result = val1 * val2;
    node->type = MUL;
    node->value = result;
    return node;
}

Node* divFunc(void* arg1, void* arg2)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if(arg1 == NULL)
    {
        node->type = FIB;
        node->value = *(int*)arg2;
        return node;
    }
    else if(arg2 == NULL)
    {
        node->type = FIB;
        node->value = *(int*)arg1;
        return node;
    }
    else if(arg1 == NULL && arg2==NULL)
    {
        printf("\n Both arguments cannot be null");
        exit(EXIT_FAILURE);
    }
    int val1 = *(int*)arg1;
    int val2 = *(int*)arg2;
    if(val2 == 0)
    {
        printf("\nCannot divide by Zero");
        exit(EXIT_FAILURE);
    }
    int result = val1 / val2;
    node->type = DIV;
    node->value = result;
    return node;
}


Node* (*makeFunc(TypeTag type))(void*, void*)
{
    switch (type)
    {
    case ADD:
        return &addFunc;
    case SUB:
        return &subFunc;
    case MUL:
        return &mulFunc;
    case DIV:
        return &divFunc;
    default:
        printf("\n Invalid type tag");
        exit(EXIT_FAILURE);
    }
}


int getFibonacci(Node* param)
{
    // Check if the value is greater than or equal to 1
    if (param->value < 1)
    {
        printf("Error: Fibonacci Index Value must be greater than or equal to 1\n");
        exit(EXIT_FAILURE);
    }

    param->value = param->value-1;
    // Initialize the Fibonacci array
    int fibArr[param->value + 1];
    for (int i = 0; i <= param->value; i++)
    {
        fibArr[i] = 0;
    }

    // Set the first two elements of the array
    fibArr[0] = 0;
    fibArr[1] = 1;

    // Compute the rest of the Fibonacci sequence
    for (int i = 2; i <= param->value; i++)
    {
        fibArr[i] = fibArr[i - 1] + fibArr[i - 2];
    }

    // Return the Fibonacci number at the specified index
    return fibArr[param->value];
}

void calc(Node *node)
{
    if (node == NULL)
    {
        printf("\nNode cannot be printed since it is NULL");
        exit(EXIT_FAILURE);

    }
    switch (node->type)
    {
    case ADD:
        printf("add : %d\n", node->value);
        break;
    case SUB:
        printf("sub : %d\n", node->value);
        break;
    case MUL:
        printf("mul : %d\n", node->value);
        break;
    case DIV:
        printf("div : %d\n", node->value);
        break;
    case FIB:
        {
            int fibVal = getFibonacci(node);
            printf("fib = %d\n", fibVal);
            break;
        }
    default:
        printf("\n Invalid type tag");
        exit(EXIT_FAILURE);
    }
}

int main()
{
    //ASSUMPTION: IF ANY PARAMS TO THE MAKEFUNC METHOD HAS A NULL IN IT
    //IT IS ASSUMED TO BE A FIB TYPE FOR THE CALC FUNCTION
    int a = 10, b = 6;
    Node* add = (*makeFunc(ADD))(&a, &b);
    int c = 5, d = 4;
    Node* mul = (*makeFunc(MUL))(&c, &d);
    Node* sub = (*makeFunc(SUB))(&mul->value, &add->value);
//  int temp = 3;
//  Node* div = (*makeFunc(DIV))(&sub->value, &temp);
    Node *fibo = (*makeFunc(SUB))(&sub->value, NULL);


    calc(add);
    calc(mul);
    calc(sub);
//  calc(div);
    calc(fibo);

    free(add);
    free(mul);
    free(sub);
//  free(div);
    free(fibo);
    return 0;
}
