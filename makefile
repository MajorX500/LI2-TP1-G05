CFLAGS = -std=gnu11 -Wall -Wextra -pedantic-errors -O
CC = gcc

slimetrail: src/main.o src/data.o src/interface.o src/logic.o src/linked_lists.o src/algorithms.o
	$(CC) $(CFLAGS) -o slimetrail $^ 

bot: src/bot.o src/data.o src/interface.o src/logic.o src/linked_lists.o src/algorithms.o
	$(CC) $(CFLAGS) -o bot $^

run: slimetrail
	./slimetrail	

clean:
	@rm -f src/*.o
	@rm -f slimetrail
	@rm -f bot
