UNAME := $(shell uname)

ifeq ($(UNAME), Darwix)
	GL := -framework OpenGL
else
	GL := -lGL -lXrandr
endif

test: test.cpp GLFT_Font.cpp
	g++ GLFT_Font.cpp test.cpp -o test -Wall -pedantic -lglfw $(GL) -lfreetype -pthread `freetype-config --cflags` 

glftfont.tar.gz: 
	tar -czf glftfont.tar.gz GLFT_Font.cpp GLFT_Font.hpp index.html README test.cpp Makefile
