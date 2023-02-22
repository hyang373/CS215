HEADERS = term.h TermSortingList.h
SOURCES = $(HEADERS:.h=.cpp)
OBJECTS = $(HEADERS:.h=.o)
MAINSOURCE = Lab8.cpp
MAINOBJ = $(MAINSOURCE:.cpp=.o)
EXEC = Lab8
$(EXEC): $(OBJECTS) $(MAINOBJ)
	g++ $^ -o $@

%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@

clean:
	rm -i *.o
	rm -I `find ./ -type f -executable`
