NAME = philo


CC = cc

# CFLAG = -Wall -Wextra -Werror -g3 -fsanitize=thread

CFLAG = -Wall -Wextra -Werror -g3

SRCS =	philo.c\
		check_conditions.c\
		init_struct.c\
		ft_atoi.c\
		init_threads.c\
		routine_philo.c

INCLUDE = philo.h

OBJS = $(SRCS:%.c=$(PATH_OBJS)%.o)

PATH_SRCS = src/

PATH_INCLUDE = include/

PATH_OBJS = obj/

all: $(NAME)

$(NAME) : $(PATH_OBJS) $(OBJS) $(PATH_INCLUDE)$(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -pthread


$(OBJS)	: $(PATH_OBJS)%.o: $(PATH_SRCS)%.c $(PATH_INCLUDE)$(INCLUDE)
				$(CC) $(CFLAG) -I$(PATH_INCLUDE) -c $< -o $@

$(PATH_OBJS) :
				mkdir -p $(PATH_OBJS)

$(PATH_OBJS_BONUS) :
				mkdir -p $(PATH_OBJS_BONUS)

clean:
	rm -rf ${OBJS} $(PATH_OBJS)
	rm -rf ${OBJS_BONUS} $(PATH_OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean all

FORCE: 

.PHONY: all re bonus clean fclean