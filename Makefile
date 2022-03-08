all: chessviz
chessviz: chessviz.cpp
	gcc -Wall -Werror -o chessviz chessviz.cpp
clear:
	rm chessviz.exe
run:
	./chessviz.exe
	
