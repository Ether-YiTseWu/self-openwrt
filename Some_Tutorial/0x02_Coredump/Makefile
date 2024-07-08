main : main.o
	gcc -g -o $@ $^

main.o : main.c
	gcc -g -c $<

clean : 
	rm -f *.o main
