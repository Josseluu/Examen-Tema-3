#include <iostream>
#include <map>
#include <string>
#include <variant>
class Environment {
public:
    using SymbolData = boost::variant<int, double, std::string>;

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
    std::map<std::string, SymbolData> symbols;
};

int main() {
    try {
        // Crear un entorno para personalizar personajes
        Environment characterEnvironment;

        // Configuración inicial para un personaje
        characterEnvironment.addSymbol("Health", 100);
        characterEnvironment.addSymbol("Damage", 20);
        characterEnvironment.addSymbol("Name", "Hero");

        // Obtener propiedades del personaje
        int initialHealth = boost::get<int>(characterEnvironment.getSymbolValue("Health"));
        int initialDamage = boost::get<int>(characterEnvironment.getSymbolValue("Damage"));
        std::string characterName = boost::get<std::string>(characterEnvironment.getSymbolValue("Name"));

        // Mostrar propiedades iniciales
        std::cout << "Propiedades iniciales del personaje:" << std::endl;
        std::cout << "Nombre: " << characterName << std::endl;
        std::cout << "Salud: " << initialHealth << std::endl;
        std::cout << "Daño: " << initialDamage << std::endl;

        // Modificar propiedades en tiempo de ejecución
        characterEnvironment.addSymbol("Health", 120);
        characterEnvironment.addSymbol("Damage", 25);

        // Obtener y mostrar propiedades modificadas
        int modifiedHealth = boost::get<int>(characterEnvironment.getSymbolValue("Health"));
        int modifiedDamage = boost::get<int>(characterEnvironment.getSymbolValue("Damage"));

        std::cout << "\nPropiedades modificadas del personaje:" << std::endl;
        std::cout << "Salud: " << modifiedHealth << std::endl;
        std::cout << "Daño: " << modifiedDamage << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Excepción atrapada: " << e.what() << std::endl;
    }

    return 0;
}
