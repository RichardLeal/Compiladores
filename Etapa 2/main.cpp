// Milena Lopes Maciel [00274741] Richard Leal [00287725]
#include <iostream> 
#include <fstream>  
#include "symbols.h"  
#include "tokens.h"

// Cabeçalho de Flex usado para criar analisadores léxicos em C e C++.
// Gera analisadores léxicos.
#include <FlexLexer.h> 

using namespace std;

extern int lineNumber;
extern int running;

int main(int argc, char *argv[])
{
  if (argc < 2){
       fprintf(stderr, "Call: etapa1 source_file_name");
      return 1;
  }

  ifstream yyin(argv[1]);

  if (!yyin.is_open()){
      fprintf(stderr, "Cannot open file %s\n", argv[1]);
      return 1;
  }

  int tok;
  FlexLexer* lexer = new yyFlexLexer(&yyin, &cout);
  
  while (running)
  {
    tok = lexer->yylex(); 

    if (!running) break;
    switch (tok)
    {
      case KW_CHAR: 
      cout << "KW_CHAR" << endl;
      break;
      case KW_INT: 
      cout << "KW_INT" << endl; 
      break;
      case KW_IF: 
      cout << "KW_IF" << endl; 
      break;
      case KW_THEN: 
      cout << "KW_THEN" << endl; 
      break;
      case KW_ELSE: 
      cout << "KW_ELSE" << endl; 
      break;
      case KW_WHILE: 
      cout << "KW_WHILE" << endl; 
      break;
      case KW_READ: 
      cout << "KW_READ" << endl; 
      break;
      case KW_PRINT: 
      cout << "KW_PRINT" << endl; 
      break;
      case KW_RETURN: 
      cout << "KW_RETURN" << endl; 
      break;
      case TK_IDENTIFIER: 
      cout << "TK_IDENTIFIER" << endl; 
      break;
      case LIT_INT: 
      cout << "LIT_INT" << endl; 
      break;
      case LIT_CHAR: 
      cout << "LIT_CHAR" << endl; 
      break;
      case LIT_STRING: 
      cout << "LIT_STRING" << endl; 
      break;
      case TOKEN_ERROR: 
      cout << "TOKEN_ERROR" << endl; 
      break;
      default: 
      cout << "TOKEN_SPECIAL: " << static_cast<char>(lexer->YYText()[0]) << endl; 
      break;
    }
  }

  printSymbolTable();
  printLineCount(lineNumber);

  return 0;
}