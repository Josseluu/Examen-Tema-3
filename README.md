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

La respuesta correcta es el apartado A: Convierte una cadena JSON en un objeto Variant


Parte 2: Pregunta de desarrollo de código 

En estos ejercicios me he ayudado de GitHub Copilot

Estructura básica: El código define una clase Environment en C++ que gestiona una tabla de símbolos usando un std::map. Proporciona métodos para agregar símbolos a la tabla addSymbol¡ y obtener sus valores getSymbolValue. El programa principal demuestra la creación de un entorno, la adición de símbolos, la obtención y visualización de valores, y manejo de errores al intentar obtener un símbolo no definido.

Insertar simbolos:El código en C++ define una clase Environment que gestiona un entorno con una tabla de símbolos utilizando un std::map. Se crean instancias de esta clase y se utilizan métodos para insertar símbolos en la tabla sin conflictos. Se demuestra la detección de intentos de inserción de símbolos ya existentes, y se obtienen y muestran valores asociados a símbolos específicos en la tabla. En resumen, el código ilustra cómo gestionar entornos simbólicos y manejar conflictos al insertar nuevos símbolos.

Búsqueda de símbolos: El código en C++ define una clase Environment que gestiona un entorno simbólico mediante un std::map. La clase permite insertar y buscar símbolos, así como obtener sus valores. El programa principal crea un entorno, inserta símbolos, y realiza búsquedas, manejando posibles errores de símbolos no definidos.

Gestión de errores: El código en C++ define una clase llamada Environment que encapsula un entorno simbólico utilizando un contenedor std::map para gestionar los símbolos y sus valores asociados. El programa principal demuestra el uso de esta clase al crear una instancia del entorno, agregar símbolos con valores, y luego intentar acceder a estos símbolos. Se utiliza el mecanismo de manejo de excepciones para atrapar posibles errores, como la inserción de un símbolo ya existente o la búsqueda de un símbolo no definido.

Integración con variant: No he sido capaz de resolverlo

Expandiendo funcionalidades: El código proporciona una implementación simple de la clase Environment en C++, que simula un entorno o contexto de variables con nombres asociados a valores enteros. La clase incluye funciones para agregar, obtener, insertar, eliminar y verificar la existencia de símbolos en el entorno. Se proporciona un ejemplo en la función main() que ilustra el uso de estas funciones, como agregar símbolos, verificar su existencia, eliminar uno de ellos y luego verificar nuevamente.

Casos de uso: No he sido capaz de resolverlo

Reflexión y mejoras: Es cierto que esta segunda unidad ha sido bastante mas dificil, ya que nos vamos adentrando, a mi en particular me gustaría mas ejemplos practicos, como por ejemplo la instalacion y completacion de la libreria Boost.
Aunque esto tiene sus puntos fuertes como por ejemplo, la capacidad de buscar y resolver nuestros problemas por nosotros solos. Esto ahora nos fastidia pero de cara al futuro desarrollaremos la habilidad de comprender y realizar problemas complejos que otros no podrían.
Por otro lado la desventaja es que nos es muy abstracto y es dificil de entender algunos ejercicios pero como decia anteriormente esto hace que investiguemos y aprendamos mas.
Y por ultimo para concluir una cosa de cara al examen es poder llegar al examen y poder tener los ejercicios resueltos, y si es posible con algunos fallos que hayamos tenido para aprender de ellos.
