# Makefile

# compiler
CXX = g++

# compiler flags (debug and release builds)

# Debug: no optimization (O0), with debug info (-g)
DEBUG_FLAGS = -Wall -std=c++11 -Wextra -g -O0
# Release: optimized (O3: aggresive optimization for performance) with no debug info
RELEASE_FLAGS = -Wall -std=c++11 -Wextra -O3

# BUILD type (default is release)
BUILD = release

# set compiler flags depending on build type
ifeq ($(BUILD), debug)
	CXXFLAGS = $(DEBUG_FLAGS)
else
	CXXFLAGS = $(RELEASE_FLAGS)
endif

# executable name
TARGET = legendaryGame

# source files
SRCS = *.cpp

# object files
OBJS = $(SRCS:.cpp = .o)

# header files
HEADERS = *.h

# target to build the program
all: $(TARGET)

# target to compile the program and create the executable target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# rule to compile source files into object files
# $< means the first prerequisite (the corresponding cpp file
# $@ is the corresponding target name
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# targets to specify the build type (debug or release)
debug:
	$(MAKE) BUILD=debug all

release:
	$(MAKE) BUILD=release all

# target to clean up object files and executable files
clean:
	rm -f $(OBJS) $(TARGET)

# target to run executable target
run: $(TARGET)
	./$(TARGET)

# PHONY targets to avoid conflicts with files
.PHONY: all debug release clean run

# testing here