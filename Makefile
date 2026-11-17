CPP = g++
CPPFLAGS = -Wall -std=c++11

TARGET = simulation
OBJS = main.o station.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp station.h
	$(CPP) $(CPPFLAGS) -c main.cpp

station.o: station.cpp station.h
	$(CPP) $(CPPFLAGS) -c station.cpp

clean:
	rm -f $(OBJS) $(TARGET)