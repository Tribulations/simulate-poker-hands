CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

TARGET = poker
SRC    = src/main.cpp src/Card.cpp src/Deck.cpp src/func.cpp src/functions.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)