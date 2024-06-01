main : lib.o main.o
	gcc -o $@ $^

main.o : main.c
	gcc -c $<

lib.o : lib.c
	gcc -c $<

clean : 
	rm -f main.o lib.o main
