CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		accelerated-cpp.o

LIBS =

TARGET =	accelerated-cpp

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: ch4
ch4: ch4/median.o ch4/grade.o ch4/Student_info.o
	$(CXX) -o ch4.bin ch4/main.cpp ch4/*.o
	
ch4/median.o: ch4/median.cpp
	$(CXX) -Wall -g -c ch4/median.cpp -o ch4/median.o
    
ch4/grade.o: ch4/grade.cpp
	$(CXX) -Wall -g -c ch4/grade.cpp -o ch4/grade.o
    
ch4/Student_info.o: ch4/Student_info.cpp
	$(CXX) -Wall -g -c ch4/Student_info.cpp -o ch4/Student_info.o