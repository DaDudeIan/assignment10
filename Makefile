run : 1.out 2.out 3.out
	./1.out
	./2.out
	./3.out

1.out : 1.c
	gcc -o 1.out $?

2.out : 2.c
	gcc -o 2.out $?

3.out : 3.c
	gcc -o 3.out $?

clean : 
	-rm *.out