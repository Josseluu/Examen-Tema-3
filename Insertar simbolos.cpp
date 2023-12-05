#include <iostream>
#include <map>
#include <string>

class Environment {
public:
    Environment() {}

    // Método para insertar un símbolo en la tabla de símbolos sin conflictos
    void insert(const std::string& name, int value) {
        std::pair<std::map<std::string, int>::iterator, bool> result = symbols.insert(std::make_pair(name, value));

        if (!result.second) {
            std::cerr << "Error: El símbolo '" << name << "' ya está definido en el entorno." << std::endl;
        }
    }

    // Método para obtener el valor de un símbolo de la tabla de símbolos
    int getSymbolValue(const std::string& name) const {
        std::map<std::string, int>::const_iterator it = symbols.find(name);
        if (it != symbols.end()) {
            return it->second;
        } else {
            std::cerr << "Error: El símbolo '" << name << "' no está definido." << std::endl;
            return 0;
        }
    }

    // Método para buscar un símbolo y devolver su valor (maneja casos en los que el símbolo no existe)
    int lookup(const std::string& name) const {
        std::map<std::string, int>::const_iterator it = symbols.find(name);
        if (it != symbols.end()) {
            return it->second; // Devuelve el valor si el símbolo está definido
        } else {
            std::cerr << "Advertencia: El símbolo '" << name << "' no está definido en el entorno." << std::endl;
            return 0; // Devuelve 0 o maneja el caso de otra manera según tus necesidades
        }
    }

private:
    std::map<std::string, int> symbols;
};

int main() {
    Environment environment;


    environment.insert("x", 10);
    environment.insert("y", 20);


    int valueX = environment.lookup("x");
    int valueY = environment.lookup("y");
    int valueZ = environment.lookup("z");


    std::cout << "El valor de x es: " << valueX << std::endl;
    std::cout << "El valor de y es: " << valueY << std::endl;
    std::cout << "El valor de z es: " << valueZ << std::endl;

    return 0;
}
