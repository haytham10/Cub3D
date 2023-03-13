# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmokhtar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 02:14:44 by hmokhtar          #+#    #+#              #
#    Updated: 2021/11/22 15:17:20 by hmokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
 ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c\
  ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c\
    ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c\
	 ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
	  ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c 

BONUS=ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
 ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

NAME = libft.a
OBJSBONUS = $(BONUS:.c=.o)
OBJS = $(SRCS:.c=.o)
CC =gcc
FLAGS =-Wall -Wextra -Werror

all : $(NAME)

%.o : %.c libft.h
	$(CC) $(FLAGS) -c $<

$(NAME):$(OBJS)
	$(CC) $(FLAGS) -c $(SRCS)
	ar cr $@ $(OBJS)

bonus: $(NAME) $(BONUS)
	$(CC) $(FLAGS) -c $(BONUS)
	ar cr $(NAME) $(OBJSBONUS) $(OBJS)

clean:
	rm -f $(OBJS) $(OBJSBONUS)

fclean: clean
		rm -f $(NAME)

re: fclean all
