ofiles = main.o Library.o Book.o
gpp-o = g++ -c -std=c++98

main : $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp Library.h Book.h
	$(gpp-o) main.cpp
Library.o: Library.cpp Library.h
	$(gpp-o) Library.cpp

Book.o: Book.cpp Book.h
	$(gpp-o) Book.cpp

run: main
	./main

clean: 
	rm *.o main