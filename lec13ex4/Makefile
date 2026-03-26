a.out: y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -o lec13ex4
	@echo "Run the program as ./lec13ex4 < input.txt"

y.tab.c: lec13ex4.y 
	yacc -d --report=itemsets,states,lookaheads -g lec13ex4.y

lex.yy.c: lec13ex4.l y.tab.h
	lex lec13ex4.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c lec13ex4 *.output *.gv

