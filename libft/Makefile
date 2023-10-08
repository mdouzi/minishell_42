
NAME = libft.a
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf
CC = cc
SRC = ft_isalpha.c ft_isdigit.c  ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c  ft_strrchr.c \
ft_strncmp.c ft_memchr.c  ft_memcmp.c  ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c  ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_argprint.c ft_printf.c ft_putnbr.c ft_putnbrhex.c ft_putstr.c ft_indexchar.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $<
#can be removed because of the implicit rule of Make to compile c files to object files

clean:
	@$(RM) $(OBJ)
fclean: clean
	@$(RM) $(NAME) libft.a
re: fclean all

.PHONY: all clean fclean re
