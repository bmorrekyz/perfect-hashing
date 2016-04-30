driver.out: Project5.o City.o
	g++ -ansi -Wall Project5.o City.o -o Project5.out

driver.o: Project5.cpp City.cpp	
	g++ -ansi -Wall -c Project5.cpp City.cpp

clean:
	rm -f *.o *.out *~ *.gch

run:
	./Project5.out $(INPUT)