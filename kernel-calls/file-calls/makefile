all: kernal-calls

run: release
	./kernal-calls

debug: kernal-calls-debug
	gdb kernal-calls

release: clean kernal-calls

kernal-calls-debug: kernal-calls.cpp
	g++ kernal-calls.cpp -g -o kernal-calls

kernal-calls: kernal-calls.cpp
	g++ kernal-calls.cpp -o kernal-calls

clean:
	rm -f kernal-calls

