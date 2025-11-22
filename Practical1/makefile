ofiles = main.o DynamicArrays.o testingFramework.o
gpp-o = g++ -c -std=c++98

main : $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp DynamicArrays.h testingFramework.h
	$(gpp-o) main.cpp
DynamicArrays.o: DynamicArrays.cpp DynamicArrays.h
	$(gpp-o) DynamicArrays.cpp
testingFramework.o: testingFramework.cpp testingFramework.h
	$(gpp-o) testingFramework.cpp

run: main
	./main

clean: 
	rm *.o main
