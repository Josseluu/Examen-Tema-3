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
        std::map<std::string, int>::const_iterator it = symbols.find(name);
        if (it != symbols.end()) {
            return it->second;
        } else {
            std::cerr << "Error: El símbolo '" << name << "' no está definido." << std::endl;
            return 0;
        }
    }

private:
    std::map<std::string, int> symbols;
};

int main() {
    Environment environment;


    environment.insert("x", 10);
    environment.insert("y", 20);


    environment.insert("x", 30);


    int valueX = environment.getSymbolValue("x");
    int valueY = environment.getSymbolValue("y");

    std::cout << "El valor de x es: " << valueX << std::endl;
    std::cout << "El valor de y es: " << valueY << std::endl;

    return 0;
}
