/**
 * @file Permutations of Strings.c
 * @author Mohmaed Reda (mhmdreda99@github.com)
 * @brief Strings are usually ordered in lexicographical order.
 *  That means they are ordered by comparing their leftmost different characters. For example,  because .
 *  Also  because . If one string is an exact prefix of the other it is lexicographically smaller, e.g., .
 Given an array of strings sorted in lexicographical order, print all of its permutations in strict lexicographical order.
  If two permutations look the same, only print one of them. See the 'note' below for an example.
 complete the function next_permutation which generates the permutations in the described order.

  For example, s=[ab ,bc,cd]. The six permutations in correct order are:

 ab bc cd
 ab cd bc
 bc ab cd
 bc cd ab
 cd ab bc
 cd bc ab
 * @version 0.1
 * @date 2020-11-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief 
 * 
 * @param n 
 * @param s 
 * @return int 
 */
int next_permutation(int n, char **s)
{
    int i =n-1 ;
    while (i>0 && strcmp(s[i-1], s[i])>=0 ) {
     i--;
    }
	if (i<=0) return 0;
    int j =n-1 ;
    while (j>0 && strcmp(s[i-1], s[j])>=0 ) {
     j--;
    }
    // start swapping
    char *temp= s[i-1];
    s[i-1]=s[j];
    s[j]=temp ;
    // reverse now
    j=n-1 ;
    while (j>i) 
    {
        temp=s[i] ;
        s[i]=s[j] ;
        s[j]=temp ;
        i++ ;
        j--;
     
    }
    return 1;
}
int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}