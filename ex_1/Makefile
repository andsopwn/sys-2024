# Makefile
CC=gcc
CFLAGS=
OBJS=ex_1_3.o ex_1_3_addnum.o ex_1_3_subnum.o
LIBS=
all : add.out

add.out : $(OBJS)
	$(CC) $(CFLAGS) -o add.out $(OBJS) $(LIBS)

ex1_3.o : ex_1_3.c
	$(CC) $(CFLAGS) -c ex_1_3.c
ch1_3_addnum.o : ex_1_3_addnum.c
	$(CC) $(CFLAGS) -c ex_1_3_addnum.c
ch1_3_subnum.o : ex_1_3_subnum.c
	$(CC) $(CFLAGS) -c ex_1_3_subnum.c

clean:
	rm -f $(OBJS) add.out *.o core