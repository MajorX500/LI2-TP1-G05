CFLAGS = -std=gnu11 -Wall -Wextra -pedantic-errors -O -lm
CC = gcc

slimetrail: projeto/main.o projeto/data.o projeto/interface.o projeto/logic.o projeto/linked_lists.o projeto/algorithms.o
	$(CC) $(CFLAGS) -o slimetrail $^ 

bot: bot/bot.o bot/data.o bot/interface.o bot/logic.o bot/linked_lists.o bot/algorithms.o
	$(CC) $(CFLAGS) -o bot.out $^

run: slimetrail
	./slimetrail	

clean:
	@rm -f projeto/*.o
	@rm -f bot/*.o
	@rm -f slimetrail
	@rm -f bot.out
