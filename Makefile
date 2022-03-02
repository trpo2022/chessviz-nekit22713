all: chess
chess: chessviz.cpp
	gcc -Wall -Werror -o chess chessviz.cpp
clear:
	rm chess.exe
run:
	./chess.exe
	
