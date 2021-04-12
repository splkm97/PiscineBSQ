# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/10 17:53:20 by kalee             #+#    #+#              #
#    Updated: 2021/04/11 22:31:39 by kalee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = 

SRCDIR = srcs
INCDIR = includes
TESTDIR = test

TARGET = bsq.out
TEST = test.out
TESTSRC = $(addprefix $(TESTDIR)/, main.c)
SOURCES = $(addprefix $(SRCDIR)/, fill_map.c ft_atoi.c ft_putstr.c parse_map.c read_map.c print_map.c get_map_width.c cal_minmax.c main.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCDIR)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $< $(OBJECTS)

$(TEST): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(TESTSRC) -I $(INCDIR)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET) $(TEST)

re: fclean all
