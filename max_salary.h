#ifndef MAX_SALARY_H
#define MAX_SALARY_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#define SWAP(a,b) {int temp; temp=a; a=b; b=temp;}

void print_array(int *arr, int size);
void naive(int a[], int size, int n, int * max) ;
int is_better(int n, int m);
int get_number_of_digits(int n);
int greedy(int a[], int size, int n);
#endif
