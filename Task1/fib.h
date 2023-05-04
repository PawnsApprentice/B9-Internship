
#ifndef FIB_H
#define FIB_H

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    ADD,
    SUB,
    MUL,
    DIV,
    FIB
} TypeTag;

typedef struct Node
{
    TypeTag type;
    int value;
} Node;

/*
 * @brief   Adds two values together and returns the result.
 * @return  A Node pointer to the result of the addition.
 * @arg     arg1: A pointer to the first value to be added.
 *          arg2: A pointer to the second value to be added.
 * @note    The caller is responsible for freeing the returned Node pointer when it is no longer needed.
*/
Node* addFunc(void* arg1, void* arg2);

/*
 * @brief   Subtracts two values and returns the result.
 * @return  A Node pointer to the result of the subtraction.
 * @arg     arg1: A pointer to the value to be subtracted from.
 *          arg2: A pointer to the value to subtract.
 * @note    The caller is responsible for freeing the returned Node pointer when it is no longer needed.
*/
Node* subFunc(void* arg1, void* arg2);

/*
 * @brief   Multiplies two values and returns the result.
 * @return  A Node pointer to the result of the multiplication.
 * @arg     arg1: A pointer to the first value to be multiplied.
 *          arg2: A pointer to the second value to be multiplied.
 * @note    The caller is responsible for freeing the returned Node pointer when it is no longer needed.
*/
Node* mulFunc(void* arg1, void* arg2);

/*
 * @brief   Divides two values and returns the result.
 * @return  A Node pointer to the result of the division.
 * @arg     arg1: A pointer to the value to be divided.
 *          arg2: A pointer to the value to divide by.
 * @note    The caller is responsible for freeing the returned Node pointer when it is no longer needed.
 *          If the second argument is zero, the function will print an error message and return NULL.
*/
Node* divFunc(void* arg1, void* arg2);

/*
 * @brief   Calculates the nth number in the Fibonacci sequence.
 * @return  The nth number in the Fibonacci sequence.
 * @arg     param: A pointer to a Node containing an integer value n.
 * @note    The function checks for values less than 1 and assumes the pattern starts
            from 0 i.e 0,1,1,2 therefore 4th index would be 2
*/
int getFibonacci(Node* param);

/*
 * @brief   Creates a function pointer for a given TypeTag value.
 * @return  A function pointer that takes two void pointers and returns a Node pointer.
 * @arg     type: A TypeTag value indicating the desired function.
 * @note    The caller is responsible for freeing the returned function pointer when it is no longer needed.
*/
Node* (*makeFunc(TypeTag type))(void*, void*);

/*
 * @brief   Evaluates a given arithmetic expression and prints the result.
 * @arg     node: A pointer to the Node that has the value and type to be printed..
*/
void calc(Node *node);

#endif // FIB_H
