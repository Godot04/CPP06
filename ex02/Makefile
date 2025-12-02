NAME	:= Identify_real_type
SRC		:= main.cpp \
			Identify.cpp
OBJ		:= $(SRC:.cpp=.o)

CC++	:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98

all: $(NAME)
#   Comment line below to meet the task requirements
	@$(MAKE) clean --no-print-directory

$(NAME): $(OBJ)
	$(CC++) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC++) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
