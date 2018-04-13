# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/21 17:42:51 by agregoir          #+#    #+#              #
#    Updated: 2017/10/21 20:51:05 by agregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAG = -Wall -Wextra -Werror
OBJ_PS = $(SRC_P:.c=.o) 
OBJ_CHECK =$(SRC_CHEC:.c=.o)

SRC_CHEC = check_op_and_do_it.c checker.c init_t_pile.c op_pa_pb.c \
op_ra_rb_rr.c op_rra_rrb_rrr.c op_sa_sb_ss.c parsing.c

SRC_P = empty_pile_a.c empty_pile_b.c get_mediane.c init_t_pile.c min_max.c \
op_pa_pb.c op_ra_rb_rr.c op_rra_rrb_rrr.c op_sa_sb_ss.c parsing.c push_swap.c \
sort_three_elem.c

SRC_PS = $(addprefix ./p_s/, $(SRC_P))
SRC_CHECK = $(addprefix ./check/, $(SRC_CHEC))

all: $(NAME)

$(NAME): $(SRC_PS) $(SRC_CHECK)
	@make -C libft
	@gcc $(FLAG) -I ./check/ -I ./libft/ $(SRC_CHECK) ./libft/libft.a -o checker
	@gcc $(FLAG) -I ./p_s/ -I ./libft/ $(SRC_PS) ./libft/libft.a -o push_swap
	@echo "\033[32m[✓] \033[33m Compilation is done. \033[0m"
#	mkdir -p obj
#	mv $(OBJ_CHECK) obj
#	mv $(OBJ_PS) obj

clean:
#	rm -rf obj
	@make -C libft clean
	@echo "\033[32m[✓] \033[33m Cleaning is done. \033[0m"

fclean: clean
	@rm push_swap
	@rm checker
	@make -C libft fclean
	@echo "\033[32m[✓] \033[33m Full_cleaning is done. \033[0m"

re: fclean all

norme:
	@norminette **/**.[ch]
