
NAME	= lemin
CFILES	= main.c ft_process_file.c ft_edges.c ft_error_handler.c\
	ft_connect_edges.c process_routes_needed.c ft_move.c\
	lem-in.c ft_find_no_conflicts.c ft_find_best.c\
	ft_create_lemmins.c ft_move_lemmins.c ft_simulate.c\
	ft_helper_functions.c ft_map.c ft_room.c

SRC	= $(addprefix src/, $(CFILES))
OBJ	= $(SRC:src/%.c=.obj/%.o)
CFLAGS	= -Wall -Werror -Wextra
LIBFT	= -L libft -lft
INCLUDE	= -I includes

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(OBJ) $(INCLUDE) $(CFLAGS) $(LIBFT) -o $@

.obj/%.o: src/%.c
	@mkdir -p .obj/
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf .obj/
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/

re: fclean all

