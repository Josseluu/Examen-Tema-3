#include <iostream>
#include <map>
#include <string>

class Environment {
public:
    Environment() {}


    void insert(const std::string& name, int value) {
        std::pair<std::map<std::string, int>::iterator, bool> result = symbols.insert(std::make_pair(name, value));

        if (!result.second) {
            std::cerr << "Error: El símbolo '" << name << "' ya está definido en el entorno." << std::endl;
        }
    }
    int getSymbolValue(const std::string& name) const {
        auto it = symbols.find(name);
        if (it != symbols.end()) {
            // Utiliza std::get para extraer el valor del std::variant
            return std::get<int>(it->second);
        } else {
            std::cerr << "Error: El símbolo '" << name << "' no está definido." << std::endl;
            return 0;
        }
    }

