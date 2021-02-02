CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors -c -std=c++14 $(DEBUG)
LFLAGS = -Wall -pedantic-errors $(DEBUG)

compile:	main.out

main.out:	main.o	ItemType.o	SortedLinkedList.o
	$(CC)	$(LFLAGS)	-o	main.out	main.o	ItemType.o	SortedLinkedList.o

main.o:	main.cpp	ItemType.o	SortedLinkedList.o
	$(CC)	$(CFLAGS)	main.cpp

ItemType.o:	ItemType.cpp	ItemType.h
	$(CC)	$(CFLAGS)	ItemType.cpp

SortedLinkedList.o:	SortedLinkedList.cpp	SortedLinkedList.h	ListNode.h
	$(CC)	$(CFLAGS)	SortedLinkedList.cpp

run: main.out
	./main.out	input.txt

clean:
	rm *.o
	rm *.out
