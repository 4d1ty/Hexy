# Compiler
CXX = g++
CXXFLAGS = -Wall -g -std=c++20

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Detect OS and set target
ifeq ($(OS),Windows_NT)
    TARGET = $(BUILD_DIR)/hexy.exe
else
    TARGET = $(BUILD_DIR)/hexy
endif

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Compile source files into build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(BUILD_DIR)/*
