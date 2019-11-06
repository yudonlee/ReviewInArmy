binary_search::binary_search_main.o binary_search.o 
	g++ -o binary_search binary_search_main.o binary_search.o 
binary_search_main.o: binary_search_main.cc
	g++ -c binary_search_main.cc
binary_search.o : binary_search.cc
	g++ -c binary_search.cc 

clean:
	rm binary_search binary_search_main.o binary_search.o
