CC     = c++
FLAGS  = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp \
	Contact/Contact.cpp \
	PhoneBook/PhoneBook.cpp
	
OBJS   = $(SRCS:.cpp=.o)
NAME   = phonebook

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
