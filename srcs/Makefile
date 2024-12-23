CMD = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRC_CLIENT = src_client/client.c utils.c
SRC_SERVER = src_server/server.c utils.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

TARGET_CLIENT = client
TARGET_SERVER = server

HEADER = minitalk.h

all: $(TARGET_CLIENT) $(TARGET_SERVER)

$(TARGET_CLIENT): $(OBJ_CLIENT)
	$(CMD) $(CFLAGS) -o $@ $^

$(TARGET_SERVER) : $(OBJ_SERVER)
	$(CMD) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CMD) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	rm -f $(TARGET_CLIENT) $(TARGET_SERVER)

re: fclean all

.PHONY: all clean fclean re

