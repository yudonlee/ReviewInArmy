omok:: omok_main.o omok.o 
	g++ -o omok omok_main.o omok.o 
omok_main.o: omok_main.cc
	g++ -c omok_main.cc
omok.o : omok.cc
	g++ -c omok.cc 

clean:
	rm omok omok_main.o omok.o
