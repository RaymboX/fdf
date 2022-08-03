SRCS = 			ft_atoi.c \
				ft_atol.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c \
				ft_ltoa.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_nbr10tohex.c \
				ft_pow.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				get_next_line.c \
				ft_isspace.c \
				ft_ptrlen.c \
				ft_atoi_base.c \
				progress_bar.c \
				rad_rc2_deg_conversion.c \
				create_trgb.c

R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
C = $(shell tput -Txterm setaf 6)
W = $(shell tput -Txterm setaf 7)
Y = $(shell tput -Txterm setaf 3)

OBJS = 			$(SRCS:.c=.o)


NAME = 			libft.a

CFLAGS = 		-Wall -Wextra -Werror
CC		= 		@gcc -c
RM		= 		rm -f

.c.o =			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)
				@echo "$Glibft compiled$W"

clean:
				@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: 		clean
				@$(RM) $(NAME)
				@echo "$Rlibft.a deleted$W"

re: 			fclean all
