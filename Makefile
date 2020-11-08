NAME_LN:= lem-in
FILE_LN:= lem_in read read_help out_map out_pathes links_rooms get_shortest_path get_shortest_path_help fill_rooms fill_rooms_help delete_edges clear calc_steps calc_steps_help bellman_ford

LFTDIR:=./libft
PFDIR:=./ft_printf

COMPILER:=clang
SRCPATH:=srcs/
HDRPATH:=includes/
IFLAGS:=-I $(HDRPATH) -I $(LFTDIR)/include
LFLAGS:=-L $(LFTDIR) -lft
PFFLAGS:=-L $(PFDIR) -lftprintf
CFLAGS:=-Wall -Wextra -Werror $(IFLAGS)

SRC_LN:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILE_LN)))
OBJ_LN = $(CCHPATH)$(SRC_LN:.c=.o)

all: $(NAME_LN)

$(NAME_LN): $(OBJ_LN)
	@cd $(LFTDIR) && $(MAKE)
	@cd $(PFDIR) && $(MAKE)
	@$(COMPILER) $(CFLAGS) $(OBJ_LN) -o $(NAME_LN) $(LFLAGS) $(PFFLAGS)

clean:
	@rm -f $(OBJ_LN)
	@cd $(LFTDIR) && $(MAKE) clean
	@cd $(PFDIR) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME_LN)
	@cd $(LFTDIR) && $(MAKE) fclean
	@cd $(PFDIR) && $(MAKE) fclean
	
.c.o:
	clang -Wall -Wextra -Werror -I includes/ -Ilibft -o $@ -c $<
	
re: fclean
	@$(MAKE) all

.PHONY: all clean fclean re