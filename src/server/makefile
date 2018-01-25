# Gilad Madmon
# Dafna Magid

a.out: compile
	g++ -o server.out *.o -pthread
	rm -f *.o

compile:
	g++ -Iinclude/ -c src/*.cpp
	
run:
	./server.out
