reply_admin:: replyAdmin_main.o replyAdmin.o 
	g++ -o reply_admin replyAdmin_main.o replyAdmin.o 
replyAdmin_main.o: replyAdmin_main.cc
	g++ -c replyAdmin_main.cc
replyAdmin.o : replyAdmin.cc
	g++ -c replyAdmin.cc 

clean:
	rm reply_admin replyAdmin_main.o replyAdmin.o
