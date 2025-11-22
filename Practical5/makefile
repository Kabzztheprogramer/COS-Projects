
ofiles = main.o Term.o Polynomial.o

gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp Term.h Polynomial.h
	$(gpp_o) main.cpp

Term.o: Term.cpp Term.h
	$(gpp_o) Term.cpp

Polynomial.o: Polynomial.cpp Polynomial.h Term.h
	$(gpp_o) Polynomial.cpp

run: main
	./main

clean:
	rm -f *.o main
