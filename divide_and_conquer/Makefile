NAME		= subtraction

CXX	 		= g++
CXXFLAGS= -Wall -Wextra -Werror --std=c++11

SRC			= subtraction.cpp
OBJ			= $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) $(NAME)

.PHONY: all clean fclean re
