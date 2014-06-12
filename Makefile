CXX=g++
GTEST_DIR=./gtest-1.7.0
CFLAGS=-Wall -Wfatal-errors
INCLUDE_DIR= ${GTEST_DIR}/include
LIB_DIR=${GTEST_DIR}/lib

all: main

main : main.o aes.o byte.o word32.o
	${CXX}  -I ${INCLUDE_DIR}  -o main main.cpp aes.o byte.o word32.o  -L ${LIB_DIR}  libgtest.a -pthread


.cpp.o:
	$(CXX)  -I ${INCLUDE_DIR} $(CFLAGS)  -c -o $@ $< 


clean:
	rm -f *.o main
