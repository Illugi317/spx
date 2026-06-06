build:
	gcc -Wall -Wextra -g spx.c -o spx `sdl2-config --cflags --libs`

clean:
	rm spx
