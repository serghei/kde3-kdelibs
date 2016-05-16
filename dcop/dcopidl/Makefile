all: scanner.cc yacc.cc

scanner.cc: scanner.ll
	flex -B -8 -o scanner.cc scanner.ll

yacc.cc: yacc.yy
	bison -t -d -o yacc.cc yacc.yy && mv yacc.hh yacc.cc.h
