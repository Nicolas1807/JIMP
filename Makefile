all:
	gcc -Wall --pedantic *.c -o bin/gauss

test1: all
	bin/gauss dane/A dane/b
test2: all
	bin/gauss dane/Q dane/bq
