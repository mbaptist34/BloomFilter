CFLAGS+=  -Wall -Wextra -Wpedantic -O2 -g
CC = g++

main: bloomDriver

bloomDriver: murmur.o Bloom.o bloomDriver.o

clean:
	touch a.o
	touch a.out
	rm *.o
	rm *.out
