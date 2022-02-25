all: chess
chess : chessviz.cpp
	gcc -Wall -Werror -o chess chessviz.cpp
