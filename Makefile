CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wextra

all: Main

main: Main.o FileReader.o Bin.o BruteForce.o FirstFit.o NextFit.o BestFit.o
	$(CXX) $(CXXFLAGS) -o Main Main.o FileReader.o Bin.o BruteForce.o FirstFit.o NextFit.o BestFit.o

main.o: Main.cpp
	$(CXX) $(CXXFLAGS) -c Main.cpp

FileReader.o: FileReader.cpp FileReader.h
	$(CXX) $(CXXFLAGS) -c FileReader.cpp

Bin.o: Bin.cpp Bin.h
	$(CXX) $(CXXFLAGS) -c Bin.cpp

BruteForce.o: BruteForce.cpp BruteForce.h
	$(CXX) $(CXXFLAGS) -c BruteForce.cpp

FirstFit.o: FirstFit.cpp FirstFit.h
	$(CXX) $(CXXFLAGS) -c FirstFit.cpp

NextFit.o: NextFit.cpp NextFit.h
	$(CXX) $(CXXFLAGS) -c NextFit.cpp

BestFit.o: BestFit.cpp BestFit.h
	$(CXX) $(CXXFLAGS) -c BestFit.cpp

clean:
	rm -f *.o Main
