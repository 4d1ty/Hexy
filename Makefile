# Compiler
CXX = g++
CXXFLAGS = -Wall -g -std=c++20

# Source files
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

# Detect OS and set target
ifeq ($(OS),Windows_NT)
    TARGET = hexy.exe
else
    TARGET = hexy
endif

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(TARGET)
