CC = gcc 
CFLAGS = -Wall -Wextra -std=c11 -Isrc

SRC = src/main.c src/scene.c src/player.c src/utils.c
OBJ = $(SRC:src/%.c=build/%.o)

TARGET = build/game

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p build
	$(CC) $(OBJ) -o $(TARGET)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
