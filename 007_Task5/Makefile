all: main.out

run: main.out
	./main.out

main.out: main.cpp module1.cpp module2.cpp
	g++ -fmodules-ts module1.cpp module2.cpp main.cpp -o main.out -x c++-system-header iostream string