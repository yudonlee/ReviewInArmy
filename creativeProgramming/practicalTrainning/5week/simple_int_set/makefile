simple_int_set:: simple_int_set_main.o simple_int_set.o 
	g++ -o simple_int_set simple_int_set_main.o simple_int_set.o 
simple_int_set_main.o: simple_int_set_main.cc
	g++ -c simple_int_set_main.cc
simple_int_set.o : simple_int_set.cc
	g++ -c simple_int_set.cc 

clean:
	rm simple_int_set simple_int_set_main.o simple_int_set.o
