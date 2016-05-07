driver.out: Project5.o City.o HashItem.o PrimaryHashTable.o SecondaryHashTable.o
	g++ -ansi -Wall Project5.o City.o HashItem.o PrimaryHashTable.o SecondaryHashTable.o -o Project5.out

driver.o: Project5.cpp City.cpp HashItem.cpp PrimaryHashTable.cpp SecondaryHashTable.cpp
	g++ -ansi -Wall -c Project5.cpp City.cpp HashItem.cpp PrimaryHashTable.cpp SecondaryHashTable.cpp

clean:
	rm -f *.o *.out *~ *.gch

run:
	./Project5.out $(INPUT)