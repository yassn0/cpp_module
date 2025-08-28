CC     = c++
FLAGS  = -Wall -Werror -Wextra -std=c++98

SRCS   = main.cpp Bureaucrat/Bureaucrat.cpp AForm/AForm.cpp ShrubberyCreationForm/ShrubberyCreationForm.cpp RobotomyRequestForm/RobotomyRequestForm.cpp PresidentialPardonForm/PresidentialPardonForm.cpp Intern/Intern.cpp
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
