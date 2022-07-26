CC=g++
LIBS=
WARNINGS=-Wall -Wextra -Wpedantic
DEBUG_FLAGS=-g

main: main.o
	${CC} ${WARNINGS} ${DEBUG_FLAGS} main.o -o main ${LIBS} 
                             
main.o: main.cpp               
	${CC} ${WARNINGS} ${DEBUG_FLAGS} -c main.cpp -o main.o 

clean: 
	rm main
	rm main.o 
