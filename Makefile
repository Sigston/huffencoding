CC = g++
NAME = huffencode.out
CFLAGS = -g -Wall -Werror -std=c++17
DEPS = Huff.h HuffNode.h HuffTree.h Program.h
OBJS = main.o Huff.cpp HuffTree.cpp Program.cpp

%.o: %.cpp $(DEPS)
	$(CC) $< $(CFLAGS) -c -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f $(NAME)
