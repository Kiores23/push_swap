
NAME = push_swap

FILES =	main.c \
		ps_verif.c \
		ps_create_tab.c \
		ps_function.c \
		ps_utils.c \
		ps_sort.c \
		ps_undersort.c \

PATH_UTILS = ./utils/
FILES_UTILS = 	$(PATH_UTILS)ft_atoi.c \
				$(PATH_UTILS)ft_len.c \
				$(PATH_UTILS)ft_put.c \
				$(PATH_UTILS)ft_is.c \
				$(PATH_UTILS)ft_strcmp.c \
				$(PATH_UTILS)ft_bzero.c \
				$(PATH_UTILS)ft_rerror.c \

$(NAME) : $(FILES) $(FILES_UTILS)
		gcc $(FILES) $(FILES_UTILS) -o $(NAME)

f : $(FILES) $(FILES_UTILS)
		gcc -Wall -Wextra -Werror -g -fsanitize=address $(FILES) $(FILES_UTILS) -o $(NAME)