reply_admin:: reply_admin_main.o reply_admin.o 
	g++ -o reply_admin reply_admin_main.o reply_admin.o 
reply_admin_main.o: reply_admin_main.cc
	g++ -c reply_admin_main.cc
reply_admin.o : reply_admin.cc
	g++ -c reply_admin.cc 

clean:
	rm reply_admin reply_admin_main.o reply_admin.o
