# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/10 17:53:20 by kalee             #+#    #+#              #
#    Updated: 2021/04/12 22:30:45 by kalee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes

TARGET = bsq.out
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCDIR)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
