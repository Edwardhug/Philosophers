NAME = philo


CC = cc

CFLAG = -Wall -Wextra -Werror -g3

SRCS =	philo.c\
		check_conditions.c\
		init_struct.c\
		ft_atoi.c\
		init_threads.c\
		routine_philo.c

INCLUDE = philo.h

OBJS = $(SRCS:%.c=$(PATH_OBJS)%.o)

# LIBFT_A = Libft/libft.a

PATH_SRCS = src/

PATH_INCLUDE = include/

PATH_OBJS = obj/

# PATH_LIBFT = Libft/

# ----------------------------------variable bonus--------------------------

# NAME_BONUS = pipex_bonus

# SRCS_BONUS = pipex_bonus.c\
# 			 ft_utils_bonus.c\
# 			 ft_here_doc.c

# PATH_OBJS_BONUS = obj_bonus/

# OBJS_BONUS = $(SRCS_BONUS:%.c=$(PATH_OBJS_BONUS)%.o)

# PATH_SRCS_BONUS = src_bonus/

# INCLUDE_BONUS = pipex_bonus.h

# ------------------------------------make----------------------------------

all: $(NAME)

$(NAME) : $(PATH_OBJS) $(OBJS) $(PATH_INCLUDE)$(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -pthread


$(OBJS)	: $(PATH_OBJS)%.o: $(PATH_SRCS)%.c $(PATH_INCLUDE)$(INCLUDE)
				$(CC) $(CFLAG) -I$(PATH_INCLUDE) -c $< -o $@

# --------------------------------make bonus---------------------------------

# bonus: $(NAME_BONUS)

# $(NAME_BONUS) : $(PATH_OBJS_BONUS) $(OBJS_BONUS) $(PATH_INCLUDE)$(INCLUDE_BONUS)
# 	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_A) -o $(NAME_BONUS)

# $(OBJS_BONUS)	: $(PATH_OBJS_BONUS)%.o: $(PATH_SRCS_BONUS)%.c $(PATH_INCLUDE)$(INCLUDE_BONUS) $(LIBFT_A)
# 				$(CC) $(CFLAG) -I$(PATH_INCLUDE) -I$(PATH_LIBFT) -c $< -o $@

# ----------------------------------utils------------------------------------

$(PATH_OBJS) :
				mkdir -p $(PATH_OBJS)

$(PATH_OBJS_BONUS) :
				mkdir -p $(PATH_OBJS_BONUS)

# $(LIBFT_A)	:	FORCE
# 				make all -C $(PATH_LIBFT)

# ----------------------------------commands---------------------------------

clean:
	rm -rf ${OBJS} $(PATH_OBJS)
	rm -rf ${OBJS_BONUS} $(PATH_OBJS_BONUS)
#	@make clean -C $(PATH_LIBFT)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
#	@make fclean -C $(PATH_LIBFT)

re: fclean all

FORCE: 

.PHONY: all re bonus clean fclean