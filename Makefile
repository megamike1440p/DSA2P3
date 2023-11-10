CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wextra

SOURCES = main.cpp FileReader.cpp Bin.cpp BruteForce.cpp FirstFit.cpp NextFit.cpp BestFit.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: main

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o main $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) main
