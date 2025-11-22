
ofiles = main.o colour.o mixer.o

gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp colour.h mixer.h
	$(gpp_o) main.cpp

colour.o: colour.cpp colour.h
	$(gpp_o) colour.cpp

mixer.o: mixer.cpp mixer.h colour.h
	$(gpp_o) mixer.cpp

run: main
	./main

clean:
	rm -f *.o main
