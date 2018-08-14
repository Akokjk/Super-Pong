SRCE    = *.cpp *.hpp
FLAGS   = -std=c++11 
libs    = -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-network-s -lsfml-system-s -lopengl32 -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg -lws2_32 -lwinmm -lgdi32
SFML    =  -IX:/SFML_S/CompliedSFML/include -LX:/SFML_S/CompliedSFML/lib
all:
	g++ $(FLAGS) -o test -DSFML_STATIC $(SRCE) $(SFML) $(libs)