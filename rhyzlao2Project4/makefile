order: order1.o order2.o order3.o
	gcc -o order order1.o order2.o order3.o
order1.o: order1.c order.h
	gcc -c order1.c
order2.o: order2.c order.h
	gcc -c order2.c
order3.o: order3.c order.h
	gcc -c order3.c
clean:
	rm order1.o order2.o order3.o order