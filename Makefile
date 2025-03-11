# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 18:10:17 by brunogue          #+#    #+#              #
#    Updated: 2025/03/11 17:33:59 by brunogue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

SRCS_SERVER = server.c utils.c main_server.c printf/ft_printf.c printf/ft_printf_utils.c
SRCS_CLIENT = client.c utils.c printf/ft_printf.c printf/ft_printf_utils.c

SRCS_SERVER_BONUS = bonus/server_bonus.c bonus/utils.c bonus/main_server_bonus.c printf/ft_printf.c printf/ft_printf_utils.c
SRCS_CLIENT_BONUS = bonus/client_bonus.c bonus/utils.c printf/ft_printf.c printf/ft_printf_utils.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Ibonus
CC = cc

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) -o $(NAME_CLIENT_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all
