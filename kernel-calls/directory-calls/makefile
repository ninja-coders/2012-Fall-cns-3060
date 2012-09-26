RUN_ARGS=

all: dir-calls

dir-calls: dir-calls.c
	gcc -g dir-calls.c -o dir-calls

run: clean dir-calls
	./dir-calls $(RUN_ARGS)

debug: clean dir-calls
	gdb --args dir-calls $(RUN_ARGS)

clean:
	rm -f dir-calls

