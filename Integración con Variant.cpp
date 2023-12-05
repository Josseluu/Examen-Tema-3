#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <variant>

class Environment {
public:
    Environment() {}

    void addSymbol(const std::string& name, const SymbolData& data) {
        auto result = symbols.insert({name, data});

        if (!result.second) {
            throw std::invalid_argument("Error: El símbolo '" + name + "' ya está definido en el entorno.");
        }
    }

    SymbolData getSymbolValue(const std::string& name) const {
        auto it = symbols.find(name);
        if (it != symbols.end()) {
            return it->second;
        } else {
            throw std::out_of_range("Error: El símbolo '" + name + "' no está definido.");
        }
    }

private:
    using SymbolData = std::variant<int, double, std::string>;
    std::map<std::string, SymbolData> symbols;
};

int main() {
    try {
        Environment environment;

        environment.addSymbol("x", 10);
        environment.addSymbol("y", 20.5);

        auto valueX = environment.getSymbolValue("x");
        auto valueY = environment.getSymbolValue("y");

        std::cout << "El valor de x es: " << std::get<int>(valueX) << std::endl;
        std::cout << "El valor de y es: " << std::get<double>(valueY) << std::endl;

        // Intenta insertar un símbolo que ya está definido (debería lanzar una excepción)
        environment.addSymbol("x", 30);
    } catch (const std::exception& e) {
        std::cerr << "Excepción atrapada: " << e.what() << std::endl;
    }

    try {
        Environment environment;

        // Intenta obtener el valor de un símbolo no definido (debería lanzar una excepción)
        auto valueZ = environment.getSymbolValue("z");
    } catch (const std::exception& e) {
        std::cerr << "Excepción atrapada: " << e.what() << std::endl;
    }

    return 0;
}
