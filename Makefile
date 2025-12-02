# Compiler
CXX = g++
CXXFLAGS = -Iinclude -std=c++17

# Source files
SRC = $(wildcard src/*.cpp)

# Executable name
TARGET = library_app.exe

# Default target
all: $(TARGET)

# Build executable from all sources
$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean up executable
clean:
	del $(TARGET)
