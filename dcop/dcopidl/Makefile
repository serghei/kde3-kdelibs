all: scanner.cpp yacc.cpp

scanner.cpp: scanner.ll
	flex -B -8 -o scanner.cpp scanner.ll

yacc.cc: yacc.yy
	bison -t -d -o yacc.cpp yacc.yy && mv yacc.hh yacc.cpp.h
