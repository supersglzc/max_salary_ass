#include "max_salary.h"

int main(){
	srand(time(NULL));
	while(1){
		int a[4];
		printf("The number list is: ");
		for(int i = 0; i < 4; i ++){
			a[i] = rand() % 100;
			printf("%d ", a[i]);
		}
		printf("\n");
		int result1 = 0;
		int n = 4;
		naive(a, n, n, &result1);
    		int result2 = greedy(a, n, n);
		    		
   		if (result1 == result2){
     			printf("OK\n");
			printf("The maximum salary is %d\n", result2);
		}
    		else{
      			printf("Wrong answer: correct=%d, got instead=%d\n", result1, result2);
	  		exit(0);
		}
	}

}
