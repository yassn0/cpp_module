CC     = c++
FLAGS  = -Wall -Werror -Wextra -std=c++98 
SRCS   = main.cpp Dog/Dog.cpp Cat/Cat.cpp WrongAnimal/WrongAnimal.cpp WrongCat/WrongCat.cpp Brain/Brain.cpp
OBJS   = $(SRCS:.cpp=.o)
NAME   = a.out

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
