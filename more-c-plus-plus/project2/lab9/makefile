HEADERS = term.h SortingList.h autocomplete.h
OBJECTS = $(HEADERS:.h=.o)
MAINOBJ = Lab9.o
EXEC = Lab9
  
$(EXEC): $(OBJECTS) $(MAINOBJ)
	g++ $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -i *.o $(EXEC)
