a.out: y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -o bottom-up
	@echo "Run the program as ./bottom-up < input.txt"

y.tab.c: bottom-up.y 
	yacc -d --report=itemsets,states -g bottom-up.y

lex.yy.c: bottom-up.l y.tab.h
	lex bottom-up.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c bottom-up *.output *.gv

