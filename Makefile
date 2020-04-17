GoFish: go_fish.o player.o deck.o card.o
	g++ -std=c++11 -g -Wall -o GoFish go_fish.o player.o deck.o card.o
go_fish.o: go_fish.cpp player.h deck.h card.h
	g++ -std=c++11 -g -Wall -c go_fish.cpp
player.o: player.cpp player.h deck.h card.h
	g++ -std=c++11 -g -Wall -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -std=c++11 -g -Wall -c deck.cpp
card.o: card.cpp card.h
	g++ -std=c++11 -g -Wall -c card.cpp