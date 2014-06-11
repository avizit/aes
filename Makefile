CXX=g++
GTEST=gtest-1.7.0
CFLAGS=-Wall

all: main

main : main.cpp aes.o byte.o word32.o
	${CXX} -o main main.cpp aes.o byte.o word32.o



.cpp.o:
	$(CXX) $(CFLAGS)  -c -o $@ $< 


clean:
	rm -f *.o main
