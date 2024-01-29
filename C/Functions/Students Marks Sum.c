/**
 * @file Students Marks Sum.c
 * @author Mohmaed Reda (mhmdreda99@github.com)
 * @brief You are given an array of integers,marks , denoting the marks scored by students in a class.
The alternating elements , marks0 ,marks2 ,marks 4  and so on denote the marks of boys.
Similarly,marks1 ,marks3 ,marks 5  and so on denote the marks of girls.
The array name,marks , works as a pointer which stores the base address of that array. In other words,  contains the address where  is stored in the memory.
For example, let  and  stores 0x7fff9575c05f. Then, 0x7fff9575c05f is the memory address of
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
 * the function, marks_summation(int* marks, char gender, int number_of_students) which returns the total sum of:
  marks of boys if gendre=b
  marks of girls if gendre=g
 * @param marks   works as a pointer which stores the base address of that array
 * @param number_of_students hold the number of students and contains the address where  marks is stored in the memory.
 * @param gender hold the gender value might be g(girls) or b (boys)
 * @return int  the output should contain the sum of all the aternate elements in marks 
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