jsonParser : function.o main.o
	gcc -o jsonParser function.o main.o

function.o : function.c
	gcc -c -o function.o function.c

main.o : main.c
	gcc -c -o main.o main.c

clean : 
	rm *.o jsonParser
