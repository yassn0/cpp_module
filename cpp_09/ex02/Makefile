CC     = c++
FLAGS  = -Wall  -Wextra -g -std=c++98

SRCS   = main.cpp PmergeMe_class/PmergeMe.cpp PmergeMe_class/PmergeMeSortDeque.cpp PmergeMe_class/PmergeMeSortVector.cpp 
OBJS   = $(SRCS:.cpp=.o)
NAME   = PmergeMe

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
