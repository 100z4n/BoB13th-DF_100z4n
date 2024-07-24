CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRCS = add-nbo.cpp
OBJS = 

TARGET = add-nbo

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJS)
