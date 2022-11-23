# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 14:57:19 by albaud            #+#    #+#              #
#    Updated: 2022/11/08 12:52:28 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BNAME		= checker
MAIN 		= init.c push_swap.c rules.c sorting_algo/general.c sorting_algo/qsort.c sorting_algo/qsortops.c
BONUS		= init.c rules.c bonus/checker.c 
LIB 		= ../koflibc/libft.a
CC			= /usr/bin/gcc
CFLAGS		= -Wall -Wextra -Werror
MINILIBX	= -I /Library/Developer/CommandLineTools/SDKs/MacOSX12.1.sdk/usr/include -I  /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
SANITIZE	= -fsanitize=address -static-libsan

.c.o 	:
		${CC} ${CFLAGS} -I /usr/X11/include -c $< -o ${<:.c=.o}

all		: ${NAME}

$(NAME)	: ${LIB}
		${CC} ${CFLAGS} ${MINILIBX} -o ${NAME} ${MAIN} ${LIB}

$(LIB)	: 
		make -C ../koflibc

clean	:
		rm -f ${OBJS}
fclean	:	clean
		rm -f ${NAME} 
re:		fclean all

lclean	: fclean
		rm -f ${LIB}
relib	: lclean all

leak	: fclean ${LIB}
		${CC} ${CFLAGS} ${SANITIZE} ${MINILIBX} -o ${NAME} ${MAIN} ${LIB}

test500	: re
		@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc

test100	: re
		./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc

test5	: re
		./push_swap `ruby -e "puts (1..5).to_a.shuffle.join(' ')"` | wc

c		:
		find *.c */*.c */*/*.c | tr "\n"  " "
