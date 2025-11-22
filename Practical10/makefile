
ofiles = main.o  call.o call_center.o call_handler.o incoming.o missed.o 

gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp call.h call_center.h call_handler.h incoming.h missed.h exceptions.h
	$(gpp_o) main.cpp

call.o: call.cpp call.h
	$(gpp_o) call.cpp

call_handler.o: call_handler.cpp call_handler.h call.h
	$(gpp_o) call_handler.cpp

call_center.o: call_center.cpp call_center.h call.h call_handler.h incoming.h missed.h exceptions.h
	$(gpp_o) call_center.cpp 

missed.o: missed.cpp missed.h call_handler.h exceptions.h
	$(gpp_o) missed.cpp

incoming.o: incoming.cpp incoming.h call_handler.h exceptions.h
	$(gpp_o) incoming.cpp


run: main
	./main

clean:
	rm -f *.o main
