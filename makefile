CXX = g++
CXXFLAG = -std=c++17 -O2
SOURCE_NAME = demangle.cpp
SOURCE_OUT = demangle

all:
	$(CXX) $(CXXFLAG) -o $(SOURCE_OUT) $(SOURCE_NAME)

