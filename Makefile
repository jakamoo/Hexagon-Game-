target : test 

test:game_play.cpp functions.cpp functions.h
	g++ game_play.cpp functions.cpp -o test
	./test
