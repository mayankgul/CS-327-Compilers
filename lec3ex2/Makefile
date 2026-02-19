a.out: lex.yy.c
	gcc lex.yy.c -ll -o ex2
	@echo "Run the program as ./ex2 < input.txt"

lex.yy.c: ex2.l
	lex ex2.l

clean:
	@rm -f lex.yy.c ex2
