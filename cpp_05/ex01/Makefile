CC     = c++
FLAGS  = -Wall -Werror -Wextra -std=c++98

SRCS   = main.cpp Bureaucrat/Bureaucrat.cpp Form/Form.cpp
OBJS   = $(SRCS:.cpp=.o)
NAME   = a.out
HEADER = Bureaucrat/Bureaucrat.hpp Form/Form.hpp

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
