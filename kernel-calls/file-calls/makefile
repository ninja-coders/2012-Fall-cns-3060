all: file-calls

run: release
	./file-calls

debug: file-calls-debug
	gdb file-calls

release: clean file-calls

file-calls-debug: file-calls.cpp
	g++ file-calls.cpp -g -o file-calls

file-calls: file-calls.cpp
	g++ file-calls.cpp -o file-calls

clean:
	rm -f file-calls

