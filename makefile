##################################################################
#
#	Makefile -- Parser
#
##################################################################

p:lex.yy.c y.tab.c
	g++ lex.yy.c y.tab.c -o a.out

y.tab.c:yacc.y symbol_table.cpp
	yacc -d yacc.y

lex.yy.c:lex_test_fin.l symbol_table.cpp y.tab.h
	lex lex_test_fin.l
clean:
	rm -f lex.yy.c y.tab.c