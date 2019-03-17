# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/10 18:47:17 by ichyzh            #+#    #+#              #
#    Updated: 2018/06/10 18:47:19 by ichyzh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in
CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRC 	= 	main.c \
			check_ants.c \
			check_link.c \
			check_room.c \
			create_path.c \
			create_que.c \
			create_route.c \
			find_start.c \
			place_one_route.c \
			print_ant.c \
			save_data.c
LIBFT 	= libft/includes
LIB 	= libft/ -lft
OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft/
	$(CC) $(CFLAGS) $(SRC) -I $(LIBFT) -L $(LIB) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	make -C libft/ clean
	rm -f $(OBJECTS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re:  fclean all