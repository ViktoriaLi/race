# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agalavan <agalavan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 21:08:39 by agalavan          #+#    #+#              #
#    Updated: 2017/12/03 21:38:40 by agalavan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace

FLAGS = -Wall -Wextra -Werror -I. -c

SRCS = 	main.c\
		add_funcs.c\
		get_line.c\

HEADER = hotrace.h

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) $(SRCS) $(HEADER)
	gcc $(OBJS) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) $<

clean:
	-rm -f $(OBJS) *.gch

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
