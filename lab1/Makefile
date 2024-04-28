all: 	main

main:	main.c
    gcc -o main main.c

.PHONY:		clean
clean:
	find . -type f -name 'main' -exec rm -f {} \;
	rm -rf *.o