#ifndef RECURRENCE_H
#define RECURRENCE_H

/*
 * @brief   Calculates the piecewise recurrence using recursive approach
 *          F(n) = F(n-3) + F(n -2) where F(0) = 0, F(1) = 1, and F(2) = 2.
 * @return  An Int result of the calculation.
 * @arg     n: the value of n in the piecewise recurrence relation.
*/
int recursive(int n);

/*
 * @brief   Calculates the piecewise recurrence using an iterative approach
 *          F(n) = F(n-3) + F(n -2) where F(0) = 0, F(1) = 1, and F(2) = 2.
 * @return  An Int result of the calculation.
 * @arg     n: the value of n in the piecewise recurrence relation.
*/
int iterative(int n);

/*
 * @brief   Calculates the piecewise recurrence using a dp approach
 *          F(n) = F(n-3) + F(n -2) where F(0) = 0, F(1) = 1, and F(2) = 2.
 * @return  An Int result of the calculation.
 * @arg     n: the value of n in the piecewise recurrence relation.
*/
int dynamic(int n);

#endif
