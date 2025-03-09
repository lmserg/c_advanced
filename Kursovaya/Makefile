
all: prog

prog: main.o calc.o
	gcc -Wall -Wextra -o prog main.o calc.o

main.o: main.c
	gcc -c -o main.o main.c

calc.o: calc.c
	gcc -c -o calc.o calc.c

clean:
	rm -f *.o
	rm -f prog.exe
