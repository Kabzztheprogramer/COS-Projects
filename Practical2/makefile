ofiles = main.o inventory.o item.o
gpp-o = g++ -c -std=c++98

main : $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp inventory.h item.h
	$(gpp-o) main.cpp
inventory.o: inventory.cpp inventory.h
	$(gpp-o) inventory.cpp

item.o: item.cpp item.h
	$(gpp-o) item.cpp

run: main
	./main

clean: 
	rm *.o main