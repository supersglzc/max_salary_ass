CC = gcc
CFLAGS = -Wall -std=c99

all: test

max_salary_naive.o: max_salary_naive.c max_salary.h 
	$(CC) $(CFLAGS) -c max_salary_naive.c -lm

max_salary_greedy.o: max_salary_greedy.c max_salary.h
	$(CC) $(CFLAGS) -c max_salary_greedy.c -lm
	
test.o: test.c max_salary.h
	$(CC) $(CFLAGS) -c test.c -lm 
	
test: max_salary_naive.o max_salary_greedy.o test.o
	$(CC) $(CFLAGS) -o test max_salary_naive.o max_salary_greedy.o test.o -lm

clean:
	rm *.o test
