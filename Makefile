game: main.cpp Ball.o
	g++ -o game main.cpp Ball.cpp -lraylib -lm -lpthread -ldl -lrt

Ball.o: Ball.h Ball.cpp
	g++ -c Ball.cpp

clean:
	rm *.o game