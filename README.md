# Examen-Tema-3

https://github.com/Josseluu/Examen-Tema-3.git

PARTE 1: PREGUNTAS DE ELECCIÓN MÚLTIPLE

1. ¿Cuál es el propósito principal de la clase Variant en el lenguaje Tiny Lisp?

La respuesta correcta es el apartado B: Representar cualquier tipo de dato Lisp

2. ¿Qué representación se obtiene al utilizar el método to_string() en un objeto Variant?

La respuesta correcta es el apartado A: Una cadena de texto que representa una instancia de Variant

3. ¿Qué función cumple el método to_json_string() en la clase Variant?

La respuesta correcta es el apartado B: Convierte un objeto Variant a una cadena JSON

4. ¿Qué función cumple el método from_json_string() en la clase Variant?

La respuesta correcta es el apartado C: Parsea un objeto JSON a un objeto Variant


Parte 2: Pregunta de desarrollo de código 

Estructura básica: El código define una clase Environment en C++ que gestiona una tabla de símbolos usando un std::map. Proporciona métodos para agregar símbolos a la tabla addSymbol¡ y obtener sus valores getSymbolValue. El programa principal demuestra la creación de un entorno, la adición de símbolos, la obtención y visualización de valores, y manejo de errores al intentar obtener un símbolo no definido.

Insertar simbolos:El código en C++ define una clase Environment que gestiona un entorno con una tabla de símbolos utilizando un std::map. Se crean instancias de esta clase y se utilizan métodos para insertar símbolos en la tabla sin conflictos. Se demuestra la detección de intentos de inserción de símbolos ya existentes, y se obtienen y muestran valores asociados a símbolos específicos en la tabla. En resumen, el código ilustra cómo gestionar entornos simbólicos y manejar conflictos al insertar nuevos símbolos.

Búsqueda de símbolos:
