all: project-1

run: project-1
	./project-1 "CNS 3060" is going to be FUN

debug: clean project-1-debug
	gdb --args project-1 "CNS 3060" is going to be FUN

project-1: project-1.c
	gcc project-1.c -o project-1

project-1-debug: project-1.c
	gcc -g project-1.c -o project-1

clean:
	rm -f project-1

