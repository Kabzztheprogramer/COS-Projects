files = main task list todo priority history manager

filesToCompile = $(patsubst %,%.cpp,$(files))

main:
	g++ -g -std=c++98 ${filesToCompile} -o main

# Target for running the compiled program
run: main
	./main

# Target to clean up object and generated files
clean:
	rm *.o *.gcov *.gcda *.gcno *.gz *.html *.css output.txt coverage.txt -f ${files}