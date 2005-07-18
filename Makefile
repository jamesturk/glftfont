test: test.cpp GLFT_Font.cpp
	g++ GLFT_Font.cpp test.cpp -o test -Wall -pedantic -lglfw -lGL -lfreetype `freetype-config --cflags`
