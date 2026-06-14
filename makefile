CC = gcc 
CFLAGS = -Wall -Wextra -std=c11 -Isrc -MMD -MP

SRC = src/main.c src/scene.c src/player.c src/utils.c src/input.c
OBJ = $(SRC:src/%.c=build/%.o)
DEP = $(OBJ:.o=.d)

TARGET = build/game

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p build
	$(CC) $(OBJ) -o $(TARGET)

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

run: all
	./$(TARGET)

clean:
	rm -f $(OBJ) $(DEP) $(TARGET)
