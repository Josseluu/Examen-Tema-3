#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

class Environment {
public:
    Environment() {}

    void addSymbol(const std::string& name, int value) {
        std::pair<std::map<std::string, int>::iterator, bool> result = symbols.insert(std::make_pair(name, value));

        if (!result.second) {
            throw std::invalid_argument("Error: El símbolo '" + name + "' ya está definido en el entorno.");
        }
    }
    int getSymbolValue(const std::string& name) const {
        std::map<std::string, int>::const_iterator it = symbols.find(name);
        if (it != symbols.end()) {
            return it->second;
        } else {
            throw std::out_of_range("Error: El símbolo '" + name + "' no está definido.");
        }
    }

private:
    std::map<std::string, int> symbols;
};