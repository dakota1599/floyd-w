num = 1

all:
	gcc-13 -fopenmp -w main.c -o main
	./main $(num)

par:
	gcc-13 -fopenmp -w parallel.c -o para
	./para $(num)