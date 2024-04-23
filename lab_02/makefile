INC_DIRS := -Iexceptions -Ilist -Iiterators -Iconcepts

build:
	g++ $(INC_DIRS) -std=c++20 -o app.exe main.cpp

run:
	./app.exe

all: build run clean

clean:
	rm -rf ./*.out ./*.exe ./*.gch
