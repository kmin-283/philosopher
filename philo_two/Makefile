NAME = philo_two

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = ../includes

UTILS = ../utils
SRCS =	main.c input_args.c init.c finish_threads.c doing.c monitoring.c\
		$(UTILS)/ft_atoi.c $(UTILS)/strs.c $(UTILS)/ft_putnbr_fd.c $(UTILS)/ft_isdigit.c

OBJS = $(SRCS:%.c=%.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -I $(INC) -pthread -o $(NAME) $(OBJS)

%.o : %.c
			$(CC) $(CFLAGS) -I $(INC) -pthread -o $@ -c $<

all:		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:
			rm -rf $(OBJS)
			rm -rf $(NAME)

re: fclean all