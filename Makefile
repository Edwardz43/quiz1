CC=gcc -Wall
obj=list.o

all: $(obj) test.c
	$(CC) $(obj) test.c -o test

$(obj): %.o: %.h %.c

clean:
	rm -f *.o test
