SRCE    = main.hpp player.hpp ball.hpp game.hpp player.cpp ball.cpp game.cpp main.cpp
SERV 	= server.cpp
FLAGS   = -std=c++14 -Wall -Wextra -pedantic 
libs    = -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-network-s -lsfml-system-s -lopengl32 -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg -lws2_32 -lwinmm -lgdi32
SFML    =  -IX:/SFML_S/CompliedSFML/include -LX:/SFML_S/CompliedSFML/lib
all:
	del game\test.exe
	g++ $(FLAGS) -o game\test.exe -DSFML_STATIC $(SRCE) $(SFML) $(libs)
ser: 
	g++ $(FLAGS) -o server.exe -DSFML_STATIC $(SERV) $(SFML) $(libs)