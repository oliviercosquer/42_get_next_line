NAME = gnl
SRCS = get_next_line \
		main ft_strlen ft_putstr \
		ft_putnbr ft_strdup ft_strcat \
		ft_bzero ft_memmove ft_strchr \
		ft_strdel ft_strsub ft_memdel \
		ft_strnew ft_strjoin

SRCS_PATH = ./srcs
INCLUDES_PATH = ./includes/
SRCS_FILES = $(patsubst %, $(SRCS_PATH)/%.c, $(SRCS))
OBJECT_FILES = $(patsubst %, %.o, $(SRCS))
CFLAGS = -Wall -Werror -Wall
CC = gcc

all: $(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) $(patsubst %, -I%, $(INCLUDES_PATH)) $(SRCS_FILES)
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJECT_FILES)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
