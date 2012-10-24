all: main

main: main.c
	gcc main.c -o main

clean:
	rm -rf main

run: main
	main &
	sleep 3
	kill -s INT 
