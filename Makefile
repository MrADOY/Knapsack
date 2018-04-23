CC=gcc
CFLAGS= -Wall -Wextra -g -O2
LDFLAG= -lm
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
PROGS = $(SRCS)
AOUT = main

all : $(PROGS)

main : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o

proper:
	rm -f $(AOUT)
