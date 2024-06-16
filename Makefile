# Compiler
CXX = g++
CC = g++

# Compiler flags
CXXFLAGS = -Wall -Iclasses -Ifunctions
CFLAGS = -Wall -Ilbfgs
#LDFLAGS = # Add linker flags here if needed

# Source directories
SRCDIRS = . classes functions
CSRCDIRS = lbfgs

# Find all .cpp and .c files in the source directories
CPP_SOURCES := $(wildcard $(addsuffix /*.cpp,$(SRCDIRS)))
C_SOURCES := $(wildcard $(addsuffix /*.c,$(CSRCDIRS)))

# Object files
CPP_OBJECTS := $(CPP_SOURCES:.cpp=.o)
C_OBJECTS := $(C_SOURCES:.c=.o)

# All object files
OBJECTS := $(CPP_OBJECTS) $(C_OBJECTS)

# Dependency files
DEPS := $(CPP_OBJECTS:.o=.d) $(C_OBJECTS:.o=.d)

# Executable name
TARGET = fluid

# Default rule
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Rule to build C++ object files and generate dependencies
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c -o $@ $<

# Rule to build C object files and generate dependencies
%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c -o $@ $<

# Include dependency files
-include $(DEPS)

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJECTS) $(DEPS)

# Phony targets
.PHONY: all clean
