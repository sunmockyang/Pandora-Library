CC = g++
CC_FLAGS = -w
EXE = a5
OBJ = AdultPatron.o Book.o ChildPatron.o Library.o main.o Menu.o Name.o Patron.o PDeque.o PLSControl.o Storage.o Map.o

$(EXE): $(OBJ)
	$(CC) $(OBJ) Server.o -o $(EXE)

# Compiler for the necessary object files 
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

clean:
	rm -f $(EXE) $(OBJ)

package: clean
	tar -cf ../COMP2404_A4_SunmockYang.tar *.h *.cpp Server.o Makefile README

test: clean $(EXE)
	./$(EXE) < tests/ListPatrons
	./$(EXE) < tests/ViewEntireCollection
	./$(EXE) < tests/AddRemoveAdultPatron
	./$(EXE) < tests/AddRemoveChildPatron
	./$(EXE) < tests/PatronMenu
	./$(EXE) < tests/DependentCheckout