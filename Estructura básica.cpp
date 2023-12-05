#include <iostream>
#include <map>
#include <string>

class Environment {
public:
    Environment() {}

    void addSymbol(const std::string& name, int value) {
        symbols[name] = value;
    }

    int getSymbolValue(const std::string& name) const {
        auto it = symbols.find(name);
        if (it != symbols.end()) {
            return it->second;
        } else {
            std::cerr << "Error: El símbolo '" << name << "' no está definido." << std::endl;
            return 0;
        }
    }

private:
    std::map<std::string, int> symbols; // Tabla de símbolos
};
int main() {
    Environment environment;


    environment.addSymbol("x", 10);
    environment.addSymbol("y", 20);


    int valueX = environment.getSymbolValue("x");
    int valueY = environment.getSymbolValue("y");


    std::cout << "El valor de x es: " << valueX << std::endl;
    std::cout << "El valor de y es: " << valueY << std::endl;


    int valueZ = environment.getSymbolValue("z");

    return 0;
}