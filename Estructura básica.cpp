#include <iostream>
#include <map>
#include <string>

class Environment {
public:
    // Constructor
    Environment() {}

    // Método para agregar un símbolo a la tabla de símbolos
    void addSymbol(const std::string& name, int value) {
        symbols[name] = value;
    }

