#include "max_salary.h"
#include <math.h>

int * best_arr;

void print_array(int *arr, int size){
  for (int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}
 
void naive(int a[], int size, int n, int * max) 
{ 
    if (size == 1) 
    { 
        int value = 0;
	int count = 0;
	for(int i = 0; i < n; i ++){
		count += get_number_of_digits(a[i]);
	}
	for(int i = 0; i < n; i ++){
		//printf("%d\n", count);
		//printf("%d, %d\n", a[i], (int)pow(10, count - get_number_of_digits(a[i])));
		value += a[i] * (int)pow(10, count - get_number_of_digits(a[i]));
		count -= get_number_of_digits(a[i]);
	}
	if(value > *max){
	       	*max = value;
	}
	return;	
    } 
  
    for (int i=0; i<size; i++) 
    { 
        naive(a,size-1,n, max); 
  
        // if size is odd, swap first and last element 
        if (size%2==1) {
            SWAP(a[0], a[size-1]); 
		}
        // If size is even, swap ith and last element 
        else{
            SWAP(a[i], a[size-1]);
	    }			
    } 
} 
