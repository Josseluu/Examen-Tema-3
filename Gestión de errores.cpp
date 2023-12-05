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
