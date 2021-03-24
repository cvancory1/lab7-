# makefile test

program: lab7.o
	g++ -g -std=c++11 lab7.o -o main
	./main

lab7.o: lab7.cpp
	g++ -g -std=c++11 -c lab7.cpp

clean:
	rm -f *.o
	rm -f main

com:
	git push origin master


all:
	git add -u
	git commit -m "same"
	git push origin master
	
stab:
	git add -u
	git commit -m "Stable copy"
	git push origin master

pull:
	git pull
	make
	./main

val:
	make
	valgrind ./main

check:
	make
	valgrind --leak-check=full ./main


