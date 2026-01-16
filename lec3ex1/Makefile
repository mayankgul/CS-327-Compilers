a.out: lex.yy.c
	gcc lex.yy.c -ll -o ex1
	@echo "Run the program as ./ex1 < input.txt"

lex.yy.c: ex1.l
	lex ex1.l

clean:
	@rm -f lex.yy.c ex1
