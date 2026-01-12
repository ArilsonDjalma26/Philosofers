NAME = philo
CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC = main.c \
parse.c \
init.c \
print.c \
philo_utils.c \
monitor.c \
routine.c \
simulation.c \
threads.c \
time.c \
actions.c \
ft_strlen.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all