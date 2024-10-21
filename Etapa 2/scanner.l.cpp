/* Milena Lopes Maciel [00274741] Richard Leal [00287725] */

%{

#include "tokens.h"
#include "symbols.h"
#include <string>
#include "parser.tab.hpp"

int running = 1;
int lineNumber = 1;

%}

%x COMMENT

%%


char             {return KW_CHAR;}
int              {return KW_INT;}
if               {return KW_IF;}
then             {return KW_THEN;}
else             {return KW_ELSE;}
while            {return KW_WHILE;}
read             {return KW_READ;}
print            {return KW_PRINT;}
return           {return KW_RETURN;}


[-,;:()\[\]{}=+*/%<>&|~]            {return YYText()[0];}


[a-zA-Z0-9]*                        {insertSymbol(YYText(), TK_IDENTIFIER); return TK_IDENTIFIER;}


#[0-9]+                             {insertSymbol(YYText(), LIT_INT); return LIT_INT;}


'.'                                 {insertSymbol(YYText(), LIT_CHAR); return LIT_CHAR;}


\"(\\.|[^"])*\"                     {insertSymbol(YYText(), LIT_STRING); return LIT_STRING;}


"//".* 
"\n"             {lineNumber++;}


"/**"             {BEGIN (COMMENT);}
<COMMENT>"**/"    {BEGIN (INITIAL);} 
<COMMENT>"\n"    {lineNumber++;}
<COMMENT>. 


[ \t] 

.                {return TOKEN_ERROR;}

%%

int yyFlexLexer::yywrap() {
    running = 0;
    return 1;
}

int getLineNumber(void){
    return lineNumber;
}

