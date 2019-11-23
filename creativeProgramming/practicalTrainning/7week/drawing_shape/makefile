drawing_shape:: drawing_shape_main.o drawing_shape.o 
	g++ -o drawing_shape drawing_shape_main.o drawing_shape.o 
drawing_shape_main.o: drawing_shape_main.cc
	g++ -c drawing_shape_main.cc
drawing_shape.o : drawing_shape.cc
	g++ -c drawing_shape.cc 

clean:
	rm drawing_shape drawing_shape_main.o drawing_shape.o
