# Makefile

# compiler
CXX = g++

# compiler flags
CXXFLAGS = -Wall -std=c++11 -Wextra

# executable name
TARGET = legendaryGame

# source files
SRCS = *.cpp

# object files
OBJS = $(SRCS:.cpp = .o)

# header files
HEADERS = *.h

# compile the whole game
.PHONY: all

all: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	./$(TARGET)

# rule to compile source files into object files
# $< means the first prerequisite (the corresponding cpp file
# $@ is the corresponding target name
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# testing here

# # game depends on inventory, shop, daymanager, weather
# game: Game.cpp Inventory.cpp Shop.cpp DayManager.cpp Weather.cpp
# 	g++ -Wall -std=c++11 -Wextra Game.cpp Inventory.cpp Shop.cpp DayManager.cpp Weather.cpp -o game

# DayManager.o: DayManager.cpp DayManager.h

# MainMenu.o: MainMenu.cpp MainMenu.h



# # testDayManager depends on dayManager only
# testDayManager: testDayManager.cpp DayManager.cpp DayManager.h
# 	g++ -Wall -std=c++11 -Wextra testDayManager.cpp DayManager.cpp -o testDayManager.out
# 	./testDayManager

clean:
	rm -f *.o $(TARGET)




# # the Person.o object file needs recompiled if Person.cpp or Person.h changes
# Person.o: Person.cpp Person.h
# 	g++ -c Person.cpp -o Person.o

# # the driver.o object file needs recompiled if driver.cpp or Person.h changes
# driver.o: driver.cpp Person.h
# 	g++ -c driver.cpp -o driver.o

# # clean removes all object files and the compiled executable
# clean:
# 	rm -f *.o driver

# # clean rule (remove executable files)
# .PHONY: clean

# clean:
# 	rm -f *.o legendaryGame