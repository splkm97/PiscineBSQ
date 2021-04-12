# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/10 17:53:20 by kalee             #+#    #+#              #
#    Updated: 2021/04/13 00:56:40 by kalee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes
TESTDIR = test

TARGET = bsq.out
TEST = test.out

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)

TESTSRC = $(wildcard $(TESTDIR)/*.c)
TESTOBJ = $(TESTSRC:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCDIR)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(TEST): $(TESTOBJ)
	$(CC) $(CFLSGS) -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
