game: main.cpp Ball.o Paddle.o ComputerPaddle.o
	g++ -o game main.cpp Ball.cpp Paddle.cpp ComputerPaddle.cpp -lraylib -lm -lpthread -ldl -lrt

Ball.o: Ball.h Ball.cpp
	g++ -c Ball.cpp

Paddle.o: Paddle.h Paddle.cpp
	g++ -c Paddle.cpp

ComputerPaddle.o: ComputerPaddle.h ComputerPaddle.cpp
	g++ -c ComputerPaddle.cpp

clean:
	rm *.o game