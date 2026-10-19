NAME = bureaucrat
CXX = c++
CXXFLAGS =  -MMD -I. -std=c++98
SRC = Bureaucrat.cpp AForm.cpp main.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp Intern.cpp
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
