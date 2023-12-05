#include <iostream>
#include <map>
#include <string>
#include <variant>
#include <stdexcept>

class Environment {
public:
    Environment() {}


    void addSymbol(const std::string& name, const SymbolData& data) {
        auto result = symbols.insert({name, data});

        if (!result.second) {
            throw std::invalid_argument("Error: El símbolo '" + name + "' ya está definido en el entorno.");
        }
    }

    // Obtiene el valor asociado a un símbolo
    SymbolData getSymbolValue(const std::string& name) const {
        auto it = symbols.find(name);
        if (it != symbols.end()) {
            return it->second;
        } else {
            throw std::out_of_range("Error: El símbolo '" + name + "' no está definido.");
        }
    }

    // Elimina un símbolo del entorno
    void removeSymbol(const std::string& name) {
        auto it = symbols.find(name);
        if (it != symbols.end()) {
            symbols.erase(it);
        } else {
            throw std::out_of_range("Error: No se puede eliminar. El símbolo '" + name + "' no está definido.");
        }
    }

    // Verifica si un símbolo existe en el entorno
    bool symbolExists(const std::string& name) const {
        return symbols.find(name) != symbols.end();
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

        // Elimina el símbolo "x"
        environment.removeSymbol("x");

        // Intenta obtener el valor de un símbolo eliminado (debería lanzar una excepción)
        auto valueZ = environment.getSymbolValue("x");
    } catch (const std::exception& e) {
        std::cerr << "Excepción atrapada: " << e.what() << std::endl;
    }

    try {
        Environment environment;

        // Verifica si un símbolo existe
        bool existsX = environment.symbolExists("x");
        bool existsY = environment.symbolExists("y");

        std::cout << "¿Existe el símbolo 'x'? " << (existsX ? "Sí" : "No") << std::endl;
        std::cout << "¿Existe el símbolo 'y'? " << (existsY ? "Sí" : "No") << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Excepción atrapada: " << e.what() << std::endl;
    }

    return 0;
}
