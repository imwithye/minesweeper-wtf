all:
	make mine

clean:
	rm -rf *.o
	rm -rf mine

mine:	mine.o
	$(CC) -lncurses -o mine mine.o

mine.o:	mine.c CONSTANT.h start_scene.h
	$(CC) -c mine.c
