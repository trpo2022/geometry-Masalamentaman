main: main.c
	gcc -Wall -Werror -g -o main main.c
clean:
	rm main
run:
	./main