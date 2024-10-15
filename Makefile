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
SRCS = Main.cpp Animal.cpp DayManager.cpp Dog.cpp Game.cpp GrownAnimal.cpp Inventory.cpp Item.cpp MainMenu.cpp Plant.cpp Seed.cpp Shop.cpp ValidNumberCheck.cpp Weather.cpp YoungAnimal.cpp

# object files
OBJS = $(SRCS:.cpp = .o)

# header files
HEADERS = Animal.h DayManager.h Dog.h Game.h GrownAnimal.h Inventory.h Item.h MainMenu.h Plant.h Seed.h Shop.h ValidNumberCheck.h Weather.h YoungAnimal.h

# target to build the program
all: $(TARGET)

# target to compile the program and create the executable target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# rule to compile source files into object files
# $< means the first prerequisite (the corresponding cpp file)
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
	rm -f *.o $(TARGET)

# target to run executable target
run: $(TARGET)
	./$(TARGET)

# source files for testing (include all *.cpp afterwards - couldnt compile now)
SOURCE_HEADER = TestDayManager.h TestValidNumberCheck.h TestMainMenu.h
SOURCE_CPP = Test.cpp Animal.cpp DayManager.cpp Dog.cpp Game.cpp GrownAnimal.cpp Inventory.cpp Item.cpp MainMenu.cpp Plant.cpp Seed.cpp Shop.cpp ValidNumberCheck.cpp Weather.cpp YoungAnimal.cpp

# target to run the main testing file with normal flags
test: $(SOURCE_HEADER) $(SOURCE_CPP)
	@g++ -Wall -Wextra -std=c++11 $(SOURCE_CPP) -o test
	@./test
	@rm -f test *.txt

# PHONY targets to avoid conflicts with files
.PHONY: all debug release clean run test