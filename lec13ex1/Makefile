a.out: y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -o lec13ex1
	@echo "Run the program as ./lec13ex1 < input.txt"

y.tab.c: lec13ex1.y 
	yacc -d --report=itemsets,states -g lec13ex1.y

lex.yy.c: lec13ex1.l y.tab.h
	lex lec13ex1.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c lec13ex1 *.output *.gv

