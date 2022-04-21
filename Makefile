CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

iffigure: main.o iffigure.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

iffigure.o: iffigure.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

-include main.d iffigure.d