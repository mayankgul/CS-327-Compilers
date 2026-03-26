a.out: y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -o lec13ex3
	@echo "Run the program as ./lec13ex3 < input.txt"

y.tab.c: lec13ex3.y 
	yacc -d --report=itemsets,states,lookaheads -g lec13ex3.y

lex.yy.c: lec13ex3.l y.tab.h
	lex lec13ex3.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c lec13ex3 *.output *.gv

