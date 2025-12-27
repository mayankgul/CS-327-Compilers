a.out: y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -o maps
	@echo "Run the program as ./maps < input.txt"

y.tab.c: mul_add_pred_swap.y 
	yacc -d mul_add_pred_swap.y

lex.yy.c: mul_add_pred_swap.l y.tab.h
	lex mul_add_pred_swap.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c maps

