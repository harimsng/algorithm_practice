NAME		= bignumcal

CXX	 		= g++
CXXFLAGS= -Wall -Wextra -Werror --std=c++17 -g -O2

SRC			= \
	main.cpp \
	subtraction.cpp \
	multiplication.cpp

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
