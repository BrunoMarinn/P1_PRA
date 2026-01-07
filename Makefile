CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

BIN = bin
TARGET_TEST = $(BIN)/testListArray
TARGET_MAIN = $(BIN)/main

TEST_SRC = testListArray.cpp

MAIN_SRC = main.cpp Circle.cpp Rectangle.cpp Square.cpp Drawing.cpp

MAIN_HDR = List.h ListArray.h Node.h ListLinked.h Point2D.h Shape.h Circle.h Rectangle.h Square.h Drawing.h

all: $(TARGET_TEST) $(TARGET_MAIN)

$(TARGET_TEST): $(TEST_SRC) List.h ListArray.h
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -o $(TARGET_TEST) $(TEST_SRC)

$(TARGET_MAIN): $(MAIN_SRC) $(MAIN_HDR)
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -o $(TARGET_MAIN) $(MAIN_SRC)

clean:
	rm -rf $(BIN) *.o *.gch

