#include "max_salary.h"

int is_better(int n, int m){
	int length1 = get_number_of_digits(n);
	int length2 = get_number_of_digits(m);
	//printf("%d, %d\n", length1, length2);
	if (length1 == 1 && length2 == 1){
		if(n > m){
			return n;
		}else{
			return m;
		}
	}else{
		int a = n;
		int b = m;
		int c [length1];
		int d [length2];
		int count = 0;
		if(length1 == 1){
			c[0] = n;
		}else{	
			for(int i = length1; i > 0; i --){
				c[count] = a / ((int)pow(10, i - 1));
				a = a % ((int)pow(10, i - 1));
				count ++;
			}
			count = 0;
		}
		if(length2 == 1){
			d[0] = m;
		}else{
			for(int i = length2; i > 0; i --){
				d[count] = b / ((int)pow(10, i - 1));
				b = b % ((int)pow(10, i - 1));
				count ++;
			}
		}
		int k = 0;
		if(length1 > length2){
			k = length2;
		}
		else{
			k = length1;
		}
		for(int i = 0; i < k; i ++){
			if(c[i] > d[i]){
				return n;
			}else if(c[i] < d[i]){
				return m;
			}else{
				continue;
			}
		}
		if(length1 > length2){
			for(int j = length2; j < length1; j ++){
				if(c[j] > d[length2 - 1]){
					return n;
				}else if(c[j] == d[length2 - 1])
					continue;
				else
					return m;
			}
		}else{
			for(int j = length1; j < length2; j ++){
				if(d[j] > c[length1 - 1])
					return m;
				else if(d[j] == c[length1 - 1])
					continue;
				else
					return n;
			}
		}
	}
	return 0;
	
}

int get_number_of_digits(int n){
	if(n == 0){
		return 1;
	}else{
		int k = floor(log10(abs(n))) + 1;
		return k;
	}
}

int greedy(int a[], int size, int n){
	int b [n];
	int number = 0;
	for(int j = 0; j < n; j ++){
		b[j] = a[j];
		number += get_number_of_digits(a[j]);
	}
	int max = 0;
	int result = 0;
	int index = 0;
	while(n > 0){
		for(int i = 0; i < n; i ++){
			if(is_better(b[i], max) == b[i]){
				index = i;
				max = b[i];	
			}
		}
		result += b[index] * (int)pow(10, number - get_number_of_digits(b[index]));
		number -= get_number_of_digits(b[index]);
		b[index] = b[size - 1];
		b[size - 1] = 0;
		size --;
		n --;
		max = 0;
	}
	return result;
}



