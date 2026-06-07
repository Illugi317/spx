build:
	gcc -Wall -Wextra -g -Iinclude src/* -o spx `sdl2-config --cflags --libs`

clean:
	rm spx
