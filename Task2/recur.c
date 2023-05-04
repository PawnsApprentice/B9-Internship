#include <stdio.h>
#include <stdlib.h>
#include "recur.h"


// Approach 1: Recursive solution
// Time complexity: O(2^n)
// Space complexity: O(n)
int recursive(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else
    {
        return recursive(n - 3) + recursive(n - 2);
    }
}

// Approach 2: Iterative solution
// Time complexity: O(n)
// Space complexity: O(1)
int iterative(int n)
{
    int f0 = 0, f1 = 1, f2 = 2, f3 = 0;
    if (n == 0)
    {
        return f0;
    }
    else if (n == 1)
    {
        return f1;
    }
    else if (n == 2)
    {
        return f2;
    }
    else
    {
        for (int i = 3; i <= n; i++)
        {
            f3 = f0 + f1;
            f0 = f1;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
}


// Approach 3: Dynamic programming solution
// Time complexity: O(n)
// Space complexity: O(1)
int dynamic(int n)
{
    int dp[3] = {0, 1, 2};
    if (n <= 2)
    {
        return dp[n];
    }
    else
    {
        for (int i = 3; i <= n; i++)
        {
            int temp = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = temp;
        }
        return dp[2];
    }
}

int main()
{
    // Test for the recursive solution
    printf("Recursive solution:\n");
    for (int i = 0; i <= 10; i++)
    {
        printf("F(%d) = %d\n", i, recursive(i));
    }

    // Test for the iterative solution
    printf("\nIterative solution:\n");
    for (int i = 0; i <= 10; i++)
    {
        printf("F(%d) = %d\n", i, iterative(i));
    }

    // Test for the dynamic programming solution
    printf("\nDynamic programming solution:\n");
    for (int i = 0; i <= 10; i++)
    {
        printf("F(%d) = %d\n", i, dynamic(i));
    }

    return 0;
}
