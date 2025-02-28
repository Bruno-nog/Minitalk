# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 18:10:17 by brunogue          #+#    #+#              #
#    Updated: 2025/02/28 18:10:33 by brunogue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER) : $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT) : $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all