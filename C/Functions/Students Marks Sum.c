/**
 * @file Students Marks Sum.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-11-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief 
 * 
 * @param marks 
 * @param number_of_students 
 * @param gender 
 * @return int 
 */
int marks_summation(int* marks, int number_of_students, char gender)
{
    int sum = 0;
    
    if(gender == 'b'){
        for(int i = 0; i < number_of_students; i += 2)
            sum += marks[i];
    }
    else{
        for(int i = 1; i < number_of_students; i += 2)
            sum += marks[i];
    }
    
    return sum;
}

int main()
{
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}