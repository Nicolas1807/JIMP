all:
	gcc -Wall --pedantic *.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
