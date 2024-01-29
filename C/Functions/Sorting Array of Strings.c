/**
 * @file Sorting Array of Strings.c
 * @author Mohmaed Reda (mhmdreda99@github.com)
 * @brief To sort a given array of strings into lexicographically increasing order or into an order in which the string with the 
 * lowest length appears first, a sorting function with a flag indicating the type of comparison strategy can be written. The disadvantage with doing so is having to rewrite the function for every new comparison strategy.
A better implementation would be to write a sorting function that accepts a pointer to the function that compares each pair of strings. Doing this will mean only passing a pointer to the sorting function with every new comparison strategy.
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
 * function which sort the strings in lexicographically non-decreasing order
 * @param a hold a string
 * @param b hold another string that compared with a 
 * @return int return a compared string
 */
int lexicographic_sort(const char* a, const char* b){
    return strcmp(a, b);
}
/**
 * @brief 
 * to sort the strings in lexicographically non-increasing order.
 * @param a 
 * @param b 
 * @return int return strings in lexicographically non-increasing order
 */
int lexicographic_sort_reverse(const char* a, const char* b){
    return strcmp(b, a);
}
/**
 * @brief 
 * 
 * @param s var. that holds a string to be counted
 * @return int return the string number of chars.
 */
int characters_count(const char *s){
    int n = 0;
    int count[128] = {0};
    if (NULL == s){
        return -1;
    }
    while(*s != '\0'){
        if (!count[*s]){
            count[*s]++;
            n++;
        }
        s++;
    }
    return n;
}
/**
 * @brief 
 * which sort the strings in non-decreasing order of the number of distinct characters present in them. 
 * If two strings have the same number of distinct characters present in them,
 *  then the lexicographically smaller string should appear first.
 * @param a 
 * @param b 
 * @return int 
 */
int sort_by_number_of_distinct_characters(const char* a, const char* b){
    int con = characters_count(a) - characters_count(b);
    return (con ? con : lexicographic_sort(a, b));
}
/**
 * @brief 
 *  which sort the strings in non-decreasing order of their lengths. If two strings have the same length, 
 * then the lexicographically smaller string should appear first.
 * @param a 
 * @param b 
 * @return int 
 */
int sort_by_length(const char* a, const char* b) {
    int len = strlen(a) - strlen(b);
    return (len ? len : lexicographic_sort(a, b));
}
/**
 * @brief 
 *  function which sorts the strings according to a comparison function
 * @param arr  an array of strings 
 * @param len length of string array: 
 * @param cmp_func pointer to the string comparison function
 */
void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int mid = len / 2;
    int con = 0;
    while(!con){
        con = 1;
        for(int i = 0; i < len - 1; i++){
            if(cmp_func(arr[i], arr[i + 1]) > 0) {
                char *temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                con = 0;
            }
        }
    }
}


int main(void)
{
    int n;
    scanf("%d", &n);

    char** arr;
	arr = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}
