objects := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

main: $(objects)
	g++ $(objects) -o main -std=c++11 -lm