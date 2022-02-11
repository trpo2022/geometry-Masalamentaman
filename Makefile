all: myprog
myprog: myprog.c
	gсс -Wall -Werror -o myprog myprog.c
clean:
	rm myprog
run:
	./myprog