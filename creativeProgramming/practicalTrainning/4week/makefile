minimal_fighter:: minimal_fighter_main.o minimal_fighter.o 
	g++ -o minimal_fighter minimal_fighter_main.o minimal_fighter.o 
minimal_fighter_main.o: minimal_fighter_main.cc
	g++ -c minimal_fighter_main.cc
minimal_fighter.o : minimal_fighter.cc
	g++ -c minimal_fighter.cc 

clean:
	rm minimal_fighter  minimal_fighter_main.o minimal_fighter.o
