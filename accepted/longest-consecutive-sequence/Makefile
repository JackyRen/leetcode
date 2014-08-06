target=elf-bin

all: main

run: main
	./${target}

main: main.cpp solution.h
	g++ -std=c++11 main.cpp -o ${target}