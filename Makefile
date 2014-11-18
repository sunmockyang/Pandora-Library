# Declaration of variables
CC = g++
CC_FLAGS = -w

# File names
EXEC = main
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)

package:
	tar -cf ../COMP2404_A3_SunmockYang.tar *.h *.cpp Makefile

test: clean main
	./main < tests/ListPatrons
	./main < tests/ViewEntireCollection
	./main < tests/AddRemoveAdultPatron
	./main < tests/AddRemoveChildPatron
	./main < tests/PatronMenu
	./main < tests/DependentCheckout