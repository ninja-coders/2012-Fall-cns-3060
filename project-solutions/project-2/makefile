all: cat1

cat1: cat1.c
	gcc -g cat1.c -o cat1

run: cat1
	./cat1 -n makefile README.md

debug: cat1
	gdb --args cat1 -n makefile README.md

clean:
	rm -f cat1
