driver.out: Project5.o City.o PrimaryTable.o SecondaryTable.o
	g++ -ansi -Wall Project5.o City.o PrimaryTable.o SecondaryTable.o -o Project5.out

driver.o: Project5.cpp City.cpp PrimaryTable.cpp SecondaryTable.cpp	
	g++ -ansi -Wall -c Project5.cpp City.cpp PrimaryTable.cpp SecondaryTable.cpp

clean:
	rm -f *.o *.out *~ *.gch

run:
	./Project5.out $(FILE)