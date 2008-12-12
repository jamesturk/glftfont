test: test.cpp GLFT_Font.cpp
	g++ GLFT_Font.cpp test.cpp -o test -Wall -pedantic -lglfw -lGL -lfreetype -pthread `freetype-config --cflags`

glftfont.tar.gz: 
	tar -czf glftfont.tar.gz GLFT_Font.cpp GLFT_Font.hpp index.html README test.cpp Makefile
