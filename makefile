#	target
TARGET = snake

#	header
INCLUDE = headers/headers.h

#	directories
SRC = src/
OBJDIR = bin/obj/

#	flags
CFLAGS = -g -lncurses

#	files
SRC_FILES = main.c menu.c game.c snake_movement.c items.c

#	prefix replacement for source files
SOURCE_FILES = $(addprefix $(SRC), $(SRC_FILES))

#	create objects out of source files
OBJECTS := $(addprefix $(OBJDIR), $(SRC_FILES:c=o))


$(OBJDIR)%.o: $(SRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) -o snake $(OBJECTS) $(CFLAGS)

clean: 
	rm $(OBJECTS)