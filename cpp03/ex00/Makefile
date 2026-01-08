NAME = claptrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -MMD -I. -std=c++98
SRC = main.cpp ClapTrap.cpp
OBJ = $(SRC:%.cpp=%.o)
DEP = $(OBJ:%.o=%.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

-include $(DEP)

re: fclean all

.PHONY: all clean fclean re
