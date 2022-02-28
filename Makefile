all: chess
chess : chessviz.cpp
	gcc -Wall -Werror -o chess chessviz.cpp
clear:
	rm chessviz
run:
	./chessviz
