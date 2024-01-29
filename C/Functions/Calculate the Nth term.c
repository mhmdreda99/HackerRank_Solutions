
/**
 * @file Calculate the Nth term.c
 * @author https://github.com/mhmdreda99
 * @brief There is a series,S , where the next term is the sum of pervious three terms.
 * Given the first three terms of the seriesa,b   and c respectively, you have to output the nth term of the series using recursion.
   Recursive method for calculating nth term is given below.
   input format :
   The first line contains a single integer n .The next line contains 3 space-separated integers,a ,b , and c .
look here :
   //https://www.hackerrank.com/challenges/recursion-in-c/problem
 
 * @version 0.1
 * @date 2020-11-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief this function finds the nth term for S series
 * 
 * @param n 
 * @param a 
 * @param b 
 * @param c 
 * @return int 
 */
int find_nth_term(int n, int a, int b, int c)
{
    if(n == 1)
        return a;
    else if(n == 2)
        return b;
    else if(n == 3)
        return c;
    else
        return (n - 1) + (n - 2) + (n - 3);
}

int main()
{
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans);
    
    return 0;
}