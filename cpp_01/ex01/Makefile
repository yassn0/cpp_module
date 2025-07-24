CC     = c++
FLAGS  = -Wall -Werror -Wextra -std=c++98

SRCS   = main.cpp zombieHorde.cpp Zombie/Zombie.cpp
OBJS   = $(SRCS:.cpp=.o)
NAME   = zombie

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
