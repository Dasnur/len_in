# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atote <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/08 18:36:49 by atote             #+#    #+#              #
#    Updated: 2019/09/16 18:37:35 by atote            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILESRCS = ft_bzero ft_memset ft_strlen ft_putchar \
	   ft_putstr ft_putendl ft_putnbr ft_putchar_fd \
	   ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
	   ft_itoa ft_strsplit ft_strtrim ft_strjoin \
	   ft_strsub ft_strequ ft_strnequ ft_memalloc \
	   ft_memdel ft_strnew ft_strdel ft_strclr \
	   ft_striter ft_striteri ft_strmap ft_strmapi \
	   ft_strdup ft_strcpy ft_strncpy ft_strcat \
	   ft_strncat ft_strlcat ft_strchr ft_strrchr \
	   ft_strstr ft_strnstr ft_strcmp ft_isupper \
	   ft_isalpha ft_isdigit ft_isalnum ft_isascii \
	   ft_isprint ft_toupper ft_tolower ft_memcpy \
	   ft_memccpy ft_memmove ft_memchr ft_memcmp \
	   ft_strncmp ft_atoi ft_lstnew ft_lstdelone \
	   ft_lstdel ft_lstadd ft_lstiter ft_lstmap \
	   get_next_line

INC = libft.h
SRCPATH:=

CFLAGS:=-Wall -Wextra -Werror
SRCS = $(addprefix $(SRCPATH),$(addsuffix .c,$(FILESRCS)))
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$ gcc $(CFLAGS) -I. $(INC) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

.c.o:
	clang -Wall -Wextra -Werror -I libft.h -o $@ -c $<

re: fclean all

.PHONY: all clean fclean re