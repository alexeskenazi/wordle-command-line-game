CXX = g++
CXXFLAGS = -Wall -g -std=c++11


# Specify the target
all: wordle

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
wordle : wordle.o
	$(CXX) $(CXXFLAGS) wordle.o -o wordle 

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o wordle

run: clean wordle
	./wordle
