game: main.cpp Ball.o Paddle.o
	g++ -o game main.cpp Ball.cpp Paddle.cpp -lraylib -lm -lpthread -ldl -lrt

Ball.o: Ball.h Ball.cpp
	g++ -c Ball.cpp

Paddle.o: Paddle.h Paddle.cpp
	g++ -c Paddle.cpp

clean:
	rm *.o game