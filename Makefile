CPP = g++
CPPFLAGS = -Wall -std=c++11

TARGET = simulation
OBJS = main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp

clean:
	rm -f $(OBJS) $(TARGET)