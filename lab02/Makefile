CC=gcc
CFLAGS=-Wall -std=c99

all: linked_list bit_ops vector

linked_list: linked_list.o test_linked_list.o
	$(CC) -g -o linked_list linked_list.o test_linked_list.o

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

test_linked_list.o: test_linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c test_linked_list.c
	
bit_ops: bit_ops.c test_bit_ops.c
	$(CC) -g -o bit_ops bit_ops.c test_bit_ops.c
	
vector: vector.c test_vector.c
	$(CC) -g -o vector vector.c test_vector.c

clean:
	rm linked_list linked_list.o test_linked_list.o vector bit_ops
