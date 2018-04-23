CC=gcc
CFLAGS= -Wall -Wextra -g -O2
LDFLAG= -lm
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
PROGS = $(patsubst %.c,%,$(SRCS))
AOUT = main

all : $(PROGS)

main : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o *.csv

proper:
	rm -f $(PROGS)

replace:
	sed -i 's/\./,/g' *.csv
