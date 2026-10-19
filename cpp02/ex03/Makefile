NAME = bsp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -I. -std=c++98
SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ = $(SRC:%.cpp=%.o)
DEP = $(OBJ:%.o=%.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

-include $(DEP)

re: fclean all

.PHONY: all clean fclean re
