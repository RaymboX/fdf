#PROGRAM NAME-------------------------------------------------------------------

NAME 			= 	fdf

#SYSTEM VAR---------------------------------------------------------------------

R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
C = $(shell tput -Txterm setaf 6)
W = $(shell tput -Txterm setaf 7)
Y = $(shell tput -Txterm setaf 3)
Z = $(shell tput -Txterm setaf 5)

CFLAGS 			= 	-g -Wall -Werror -Wextra
CC				= 	gcc
RM				= 	rm -rf
LIBMLX 			= 	-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
LIB_LINUX		=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
INCLUDE 		= 	-I /usr/local/include

#DIRECTORIES--------------------------------------------------------------------

SRCS_DIR 		= 	./srcs
OBJS_DIR		= 	./objs
LIBFT_DIR		= 	./libft

#FILES--------------------------------------------------------------------------

SRCS_FILES	 	= 	0000_fdf.c \
					0100_map_check.c \
					0200_map_extract.c \
					0210_vars_map_init.c \
					0300_new_image.c \
					0310_pp_fill.c \
					0311_vector_point_cal.c \
					0312_vplane2d.c \
					0320_draw_new_image.c \
					0321_draw_line_type.c \
					0322_draw_line_utils.c \
					0400_keypress_handler.c \
					0410_key_action.c \
					0411_key_action_utils.c \
					0420_hub.c

LIBFT_FILES		= 	libft.a

#FILES VAR----------------------------------------------------------------------
SRCS 			= 	$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS 			= 	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

LIBFT 			= 	$(addprefix $(LIBFT_DIR)/, $(LIBFT_FILES))

#SYSTEM RULES-------------------------------------------------------------------

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

#COMPILING RULES------------------------------------------------------------------

all : 				init $(NAME) command

init:
					@$(MAKE) -s -C $(LIBFT_DIR)
					@mkdir -p $(OBJS_DIR)

$(NAME):			$(OBJS) 
					@$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT) $(LIBMLX) -o $(NAME) $(OBJS)
					@echo "$G$(NAME) compiled$W"
					
command:
					@echo "$C\n--------------$ZMAKE RULES$C---------------"
					@echo "make norm:  norminette par dossier"
					@echo "make test:  test de parcing"
					@echo "make leaks: lance la carte 42z1.fdf avec leaks --atExit"
					@echo "\n$Y--------------$ZMAPS LIST$Y---------------"
					@echo "make 42:    ./fdf bonus/maps/42z1.fdf"
					@echo "make 4x4:   ./fdf bonus/maps/4x4color.fdf"
					@echo "make 16x16: ./fdf bonus/maps/16x16plat.fdf"
					@echo "make mars:  ./fdf bonus/maps/mars.fdf"
					@echo "make julia: ./fdf bonus/maps/julia.fdf$W"




$(LIBFT):
					@cd $(LIBFT_DIR)/ && make
					

clean:
					@$(MAKE) -s clean -C $(LIBFT_DIR)
					@$(RM) $(OBJS)
					@$(RM) $(OBJS_DIR)
					@echo "$RAll objects deleted$W"

fclean: 			clean
					@$(MAKE) -s fclean -C $(LIBFT_DIR)
					@$(RM) $(NAME)
					@echo "$R$(NAME) deleted$W"
	
re: 				fclean all

linux:
					gcc -g $(CFLAGS) $(SRCS) libft/*c $(LIB_LINUX) -o $(NAME)

#MAPS---------------------------------------------------------------------------

42:
					./fdf "bonus/maps/42z1.fdf"

4x4:
					./fdf "bonus/maps/4x4color.fdf"

16x16:
					./fdf "bonus/maps/16x16plat.fdf"

mars:
					./fdf "bonus/maps/mars.fdf"

julia:
					./fdf "bonus/maps/julia.fdf"


#TEST RULES---------------------------------------------------------------------

leaks:
					leaks --atExit -- ./fdf "bonus/maps/42z1.fdf"

norm:				clear
					@echo "\n$Y-------------libft--------------"
					@norminette $(LIBFT_DIR)
					@echo "\n$G-------------srcs---------------"
					@norminette $(SRCS_DIR)
					@echo "\n$Z-------------header-------------"
					@norminette ./header
					@echo "\n$W"

debug:
					gcc -g $(CFLAGS) $(INCLUDE) $(LIBMLX) libft/*c $(SRCS) -o $(NAME)

clear:
					@clear

vide:
					@echo "-----map vide-----"
					./fdf "bonus/maps/vide.fdf"
					@echo "\n"

error:
					@echo "-----map avec differentes longueurs d'arguments par row-----"
					./fdf "bonus/maps/error.fdf"
					@echo "\n"

nexist:
					@echo "-----map qui n'existe pas------"
					./fdf "bonus/maps/not_exist_map.fdf"
					@echo "\n"

txt_map:
					@echo "-----map terminant par .txt------"
					./fdf "bonus/maps/2x2color.txt"
					@echo "\n"

arg0:
					@echo "-----Sans argument-----"
					./fdf
					@echo "\n"

arg2:
					@echo "-----2 arguments-----"
					./fdf "bonus/maps/42.fdf" "bonus/maps/42.fdf"
					@echo "\n"

dir:
					@echo "-----directory au lieu d'un file-----"
					./fdf "bonus/maps/dir.fdf"
					@echo "\n"

entete_test:
					@echo "\n---------------------tests------------------------\n"

test:				clear entete_test arg0 arg2 nexist vide error txt_map dir



#PHONY--------------------------------------------------------------------------

.PHONY:				all clean fclean re leaks clear vide error errors arg0 arg2
.PHONY:				42 mars julia txt_map 
