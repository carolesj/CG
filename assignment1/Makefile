# using gcc compiler
CC = gcc

# output path and filename
BINARY = ./build/output

# sources directory
SRC = ./src/shapes.c ./src/transforms.c ./src/motion.c ./src/scene.c ./src/main.c
# SOIL sources
SOIL = ./src/SOIL/image_DXT.c ./src/SOIL/image_helper.c ./src/SOIL/stb_image_aug.c ./src/SOIL/SOIL.c

# includes directory
INCLUDES = ./includes
# SOIL includes
SOIL_IN = ./includes/SOIL

# libraries and flags
LIBS = -lglut -lGL -lGLU -lm
FLAGS = -g

all: compile run

compile:
	$(CC) -o $(BINARY) -I$(SOIL_IN) $(SOIL) -I$(INCLUDES) $(SRC) $(LIBS) $(FLAGS)

test:
	run clean debug

run:
	$(BINARY)

debug:
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes $(BINARY)
