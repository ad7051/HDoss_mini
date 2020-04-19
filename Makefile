CC=gcc
#target
TP=market
DP=market_debug
#dependency
DEPENDENCY=main.c manager.o product.o

$(TP) : $(DEPENDENCY)
	$(CC) -o $@ $^

$(DP) : $(DEPENDENCY)
	$(CC) -DDEBUG -o $@ $^
clean : 
	rm *.o market market_debug *.txt
