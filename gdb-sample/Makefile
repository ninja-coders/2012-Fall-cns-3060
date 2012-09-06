all: hello-gdb-debug

run: release
	./hello-gdb

debug: hello-gdb-debug
	gdb hello-gdb

release: clean hello-gdb

hello-gdb-debug: hello-gdb.cpp
	g++ hello-gdb.cpp -g -o hello-gdb

hello-gdb: hello-gdb.cpp
	g++ hello-gdb.cpp -o hello-gdb

clean:
	rm -f hello-gdb

