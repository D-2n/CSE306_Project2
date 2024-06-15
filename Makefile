CXX = g++

CXXFLAGS = -Wall -Iclasses -Ifunctions

SRCDIRS = . classes functions lbfgs


SOURCES := $(wildcard $(addsuffix /*.cpp,$(SRCDIRS)))

OBJECTS := $(SOURCES:.cpp=.o)


TARGET = fluid

all: $(TARGET)


$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<


clean:
	rm -f $(TARGET) $(OBJECTS)


.PHONY: all clean
