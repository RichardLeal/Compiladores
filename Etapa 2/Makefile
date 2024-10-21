CXX = g++
CXXFLAGS = -std=c++1 -Wall

target:	etapa1

etapa1:	lex.yy.o main.o symbols.o parser.tab.o
		$(CXX) lex.yy.o main.o parser.tab.o -o etapa1

%.o: %.cpp
		$(CXX) $(CXXFLAGS) $< -c

lex.yy.cpp:	scanner.l
		flex -o lex.yy.cpp scanner.l

parser.tab.cpp: parser.ypp
	bison parser.ypp -d

clean:
		rm etapa1 lex.yy.cpp parser.tab.cpp parser.tab.hpp *.o