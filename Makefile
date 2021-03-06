CC=gcc
CFLAGS= -std=c99 -Wall -Wextra -g -O2
LDFLAG= -lm
LIBS += -lm
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
PROGS = $(AOUT)
AOUT = main

all : $(PROGS) clean

main : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o

proper: clean
	rm -f $(AOUT)
