// Milena Lopes Maciel [00274741] Richard Leal [00287725]
#include "symbol.h"
#include <iostream>
#include <map>

using namespace std;

map<string, Symbol> symbolMap;


void insertSymbol(const std::string& text, int type) {
    // Tentar encontrar o símbolo no map
    auto it = symbolMap.find(text);

    // Se o símbolo não existir, inserir
    if (it == symbolMap.end()) {
        symbolMap[text] = Symbol(type, text);
    }
    
}

void printSymbolTable() {
    for (const auto& entry : symbolMap) {
        cout << "Symbol: " << entry.first << " and Type: " << entry.second.type << endl;    }
}

void printLineCount(int lineNumber) {

    if (lineNumber == 1)
        cout << "File has " << lineNumber << " line" << endl;
    if (lineNumber > 1)
        cout << "File has " << lineNumber << " lines" << endl;
}

void initMe(void) {
   
}