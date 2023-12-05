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
int main() {
    try {
        Environment environment;

        environment.addSymbol("x", 10);
        environment.addSymbol("y", 20);

        int valueX = environment.getSymbolValue("x");
        int valueY = environment.getSymbolValue("y");

        std::cout << "El valor de x es: " << valueX << std::endl;
        std::cout << "El valor de y es: " << valueY << std::endl;


        environment.addSymbol("x", 30);
    } catch (const std::exception& e) {
        std::cerr << "Excepción atrapada: " << e.what() << std::endl;
    }

    try {
        Environment environment;


        int valueZ = environment.getSymbolValue("z");
    } catch (const std::exception& e) {
        std::cerr << "Excepción atrapada: " << e.what() << std::endl;
    }

    return 0;
}