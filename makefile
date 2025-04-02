COMPILE = g++
FLAGS = -std=c++17

NAME = my_program
SOURCES = main.cpp matrix.cpp

$(NAME): $(SOURCES)
	$(COMPILE) $(FLAGS) -o $(NAME) $(SOURCES)

clean:
	rm -f $(NAME)
