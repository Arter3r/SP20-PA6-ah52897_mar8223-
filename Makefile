GoFish: card_demo.o player.o deck.o card.o
	g++ -std=c++11 -g -Wall -o GoFish card_demo.o player.o deck.o card.o
card_demo.o: card_demo.cpp player.h deck.h card.h
	g++ -std=c++11 -g -Wall -c card_demo.cpp
player.o: player.cpp player.h deck.h card.h
	g++ -std=c++11 -g -Wall -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -std=c++11 -g -Wall -c deck.cpp
card.o: card.cpp card.h
	g++ -std=c++11 -g -Wall -c card.cpp