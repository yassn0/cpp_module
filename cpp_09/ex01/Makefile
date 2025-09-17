CC     = c++
FLAGS  =  -std=c++98

SRCS   = main.cpp RPN.cpp
OBJS   = $(SRCS:.cpp=.o)
NAME   = RPN

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o ./$(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f ./$(NAME)

re: fclean all

.PHONY: all clean fclean re
