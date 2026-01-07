CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

BIN = bin
TARGET = $(BIN)/testListArray

SRC = testListArray.cpp
HDR = List.h ListArray.h

all: $(TARGET)

$(TARGET): $(SRC) $(HDR)
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -rf $(BIN) *.gch

