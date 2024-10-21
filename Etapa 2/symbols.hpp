// UFRGS - Compiladores - Marcelo Johan - 2024-2
// Tebela de Simbolos

#include <string>
using namespace std;

struct Symbol {
        int type;
        string text
        Symbol (int t, char *s): type(t), text(string(s)) {}
};

Symbol* insertSymbol(int type, char *text);
void printSymbols();

//END OF FILE