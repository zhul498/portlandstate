CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -g

# Executable name
TARGET = race

# Source files (update if needed)

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp file into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET) *~ \#*

ZIP_FILE = $(USER)_cs302_program3.zip
zip: clean
	zip -r $(ZIP_FILE) *.cpp *.h makefile
