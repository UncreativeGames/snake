CXX = g++
CFLAGS = -Wall -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
OBJ = main.o GameController.o Maca.o Snake.o SnakeNode.o

install: $(OBJ)
	$(CXX) $(OBJ) -o Snake $(CFLAGS)

main.o:
	$(CXX) -c main.cpp $(CFLAGS)

GameController.o:
	$(CXX) -c src/GameController.cpp $(CFLAGS)

Maca.o:
	$(CXX) -c src/Maca.cpp $(CFLAGS)

Snake.o:
	$(CXX) -c src/Snake.cpp $(CFLAGS)

SnakeNode.o:
	$(CXX) -c src/SnakeNode.cpp $(CFLAGS)

remove:
	rm *.o
	rm Snake
