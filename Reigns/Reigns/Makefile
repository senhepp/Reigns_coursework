CC	=	g++

SRC	=	src\main.cpp src\class_art.cpp src\screen_saver.cpp \
		src\interaction_cards.cpp src\faction.cpp

INC = 	-I include

LIB =	-l sfml-graphics -l sfml-window -l sfml-system -l sfml-audio \
		-l opengl32 -l freetype -l winmm -l gdi32 -l openal32 \
		-l FLAC -l vorbisenc -l vorbisfile -l vorbis -l ogg

FLAG=	-Wall -Wextra -Werror -Wpedantic

all:
	$(CC) $(SRC) $(INC) -L lib $(LIB) -o Reigns.exe