# 📘 Lenguaje C

## Libro utilizado
**Título:** *The C Programming Language*  
**Autores:** Brian W. Kernighan y Dennis M. Ritchie

## Fecha
**01 de agosto de 2025**

----

## Notas 

Hasta la página 23 he aprendido varios conceptos fundamentales que no conocía. Uno de los puntos más interesantes es que **C es un lenguaje bastante simple y conciso**, especialmente si lo comparamos con lenguajes modernos como **Python**, que poseen un ecosistema de librerías mucho más amplio.

C tiene una fuerte relación con **UNIX**, ya que fue creado específicamente para este sistema, y su diseño fue influenciado por un lenguaje previo llamado **BCPL**.

También es importante tener en cuenta que C no está atado a ningún sistema operativo o tipo de máquina en particular, lo que lo hace un lenguaje altamente portable.

A menudo se le conoce como un “lenguaje de programación de sistemas” (system programming language), ya que fue diseñado pensando en el desarrollo de sistemas operativos, compiladores, controladores y otros componentes de bajo nivel.

Otro punto interesante es que C trabaja con distintos tipos de datos, a diferencia de otros lenguajes que son *typeless*, es decir, que no requieren declarar explícitamente el tipo de dato (como es el caso de algunos lenguajes interpretados).

----

## Función `main()` y por qué es tan importante

La función `main()` es el punto de entrada principal de cualquier programa en C.  
Es decir, **el sistema operativo comienza la ejecución del programa desde `main()`**, por lo tanto, si no la definimos, el compilador no sabrá dónde empezar y generará un error.

### ¿Por qué `main()`?

Cuando ejecutamos un programa compilado en C, el sistema necesita saber **por dónde iniciar la ejecución**. `main()` cumple exactamente esa función. Desde ahí se llama a otras funciones, se inicializan variables, etc.

### 🧪 Ejemplo básico:

```c
#include <stdio.h>

int main() {
    printf("Hola mundo\n");
    return 0;
}
```

### ¿Por qué a veces ves `main()` sin tipo?

En versiones antiguas de C (antes del estándar ANSI C), era común ver el `main()` definido sin especificar el tipo de retorno:

```c
main() {
    // ...
}
```

Sin embargo, eso ya **no es recomendable**.  
Actualmente, la forma correcta (según el estándar moderno) es:

```c
int main() {
    // ...
    return 0;
}
```

El `int` indica que la función devuelve un valor entero, que normalmente sirve para informar al sistema si el programa terminó correctamente (`0`) o con errores (cualquier otro valor).

###  Conclusión

- Siempre debes tener una función `main()` en tu programa C.
- Define su tipo de retorno como `int` y usa `return 0;` para indicar éxito.
- Es el corazón de todo programa en C: sin `main()`, no hay ejecución.

## Entrada/Salida (I/O)

A diferencia de otros lenguajes, **C no posee entrada/salida integrada en su núcleo**. Estas funciones no están integradas directamente en el lenguaje.  
Para realizar operaciones como imprimir en pantalla o leer datos, se debe incluir la biblioteca estándar:

```c
#include <stdio.h>
```

#  Compilación en C

El proceso de compilación en C puede variar ligeramente según el sistema operativo, principalmente por el compilador disponible. Sin embargo, el estándar del lenguaje se mantiene igual.

## Compiladores por sistema operativo

| Sistema Operativo | Compilador más común | Nota                                                                 |
|-------------------|----------------------|----------------------------------------------------------------------|
| Linux             | `gcc`                | Viene preinstalado en muchas distros.                              |
| macOS             | `clang`              | Es el compilador por defecto; `gcc` puede instalarse con Homebrew. |
| Windows           | `gcc (MinGW)` / `cl` | `gcc` se puede usar vía MinGW o WSL; `cl` es el de Visual Studio.  |

----

## 📌 Comando básico de compilación:

```bash
gcc archivo.c
```
---

### `while` (estructura de control)

El `while` es una estructura de control que permite ejecutar un bloque de código repetidamente mientras se cumpla una condición determinada.

#### Estructura de un bucle `while`

```c
initialization;

while (condición) {
    // instrucciones a ejecutar
    incremento;
}
```

#### Ejemplo práctico obtenido del libro:

```c
#include <stdio.h>

int main() {
    float fahr, celsius;
    int lower = 0, upper = 300, step = 20;

    fahr = lower;

    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
```

A diferencia del bucle `for`, el `while` se divide en varias partes: inicialización, condición y cuerpo del bucle, que incluye la lógica y la actualización de variables.

1. Inicialización

```c
fahr = lower;
```

Se asigna un valor inicial a la variable antes de comenzar el bucle.

2. Condición

```c
while (fahr <= upper)
```

Se verifica si `fahr` es menor o igual a `upper`. Si la condición es verdadera, se ejecuta el cuerpo del bucle; si es falsa, el bucle termina.

3. Cuerpo del bucle

```c
celsius = (5.0 / 9.0) * (fahr - 32.0);
printf("%3.0f %6.1f\n", fahr, celsius);
fahr = fahr + step;
```

- Se convierte la temperatura de Fahrenheit a Celsius.
- Se imprime el resultado con formato.
- Se incrementa `fahr` en 20 para la siguiente iteración.

#### 🔁 Ciclo paso a paso (`while`)

| Paso | `fahr` | Condición (`fahr <= 300`) | Celsius calculado | Acción siguiente       |
|------|--------|----------------------------|--------------------|------------------------|
| 1    | 0      | Verdadero                  | -17.8              | `fahr += 20` → 20      |
| 2    | 20     | Verdadero                  | -6.7               | `fahr += 20` → 40      |
| 3    | 40     | Verdadero                  | 4.4                | `fahr += 20` → 60      |
| …    | …      | …                          | …                  | …                      |
| 16   | 300    | Verdadero                  | 148.9              | `fahr += 20` → 320     |
| 17   | 320    | Falsa                      | -                  | Se termina el bucle    |

---

### Bucle FOR
El bucle for es una estructura de control que permite ejecutar un bloque de código de forma repetida mientras se cumpla una condición, con la ventaja de que la inicialización, la condición y el incremento están contenidos en una sola línea, lo que lo hace más compacto que while.


#### Estructura de un bucle For
```c
for (inicialización; condición; incremento) {
    // instrucciones a ejecutar
}
```



#### Ejemplo práctico obtenido del libro

```c
#include <stdio.h>

int main() {
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }

    return 0;
}
```

 1. Inicialización

```c
fahr= 0;
```
Se ejecuta una sola vez, antes de comenzar el bucle.

2. Condición
```c
fahr <= 300;
```
3. Incremento
```c
fahr = fahr + 20;
```

#### 🔁 Ciclo paso a paso (`for`)

| Paso | `fahr` | Condición (`fahr <= 300`) | Celsius calculado | Acción siguiente       |
|------|--------|----------------------------|--------------------|------------------------|
| 1    | 0      | Verdadero                  | -17.8              | `fahr += 20` → 20      |
| 2    | 20     | Verdadero                  | -6.7               | `fahr += 20` → 40      |
| 3    | 40     | Verdadero                  | 4.4                | `fahr += 20` → 60      |
| …    | …      | …                          | …                  | …                      |
| 16   | 300    | Verdadero                  | 148.9              | `fahr += 20` → 320     |
| 17   | 320    | Falsa                      | -                  | Se termina el bucle    |

---





## Constantes Simbólicas

**Fecha:** 24 de agosto de 2025

### ¿Qué son las constantes simbólicas?

Las **constantes simbólicas** son nombres descriptivos que se asignan a valores constantes mediante la directiva `#define`. Su uso es fundamental para escribir código más legible y mantenible.

### ¿Por qué son importantes?

1. **Legibilidad del código**: Hacen que el código sea más fácil de entender
2. **Mantenimiento**: Si necesitas cambiar un valor, solo lo modificas en un lugar
3. **Colaboración**: Otros programadores pueden entender mejor tu código
4. **Evitan errores**: Reduces la posibilidad de escribir mal un número

### Evitar números mágicos (Magic Numbers)

Los **números mágicos** son valores numéricos que aparecen en el código sin explicación alguna. Esto hace que el código sea difícil de entender y mantener.

#### ❌ Ejemplo con números mágicos:

```c
#include <stdio.h>

int main() {
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }

    return 0;
}
```

**Problemas:**
- ¿Por qué 300? ¿Por qué 20? ¿Por qué 32?
- Si quiero cambiar el rango, tengo que buscar todos los números
- No es claro qué representa cada valor

#### ✅ Ejemplo con constantes simbólicas:

```c
#include <stdio.h>

#define LOWER    0      /* límite inferior de la tabla */
#define UPPER    300    /* límite superior de la tabla */
#define STEP     20     /* incremento */
#define FREEZING 32     /* punto de congelación del agua en °F */

int main() {
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - FREEZING));
    }

    return 0;
}
```

**Ventajas:**
- El código se explica por sí mismo
- Fácil modificación de valores
- Menos propenso a errores
- Mejor documentación del código

### Sintaxis de `#define`

```c
#define NOMBRE_CONSTANTE valor
```

**Convenciones:**
- Usar **MAYÚSCULAS** para el nombre
- Usar **guiones bajos** para separar palabras
- No usar punto y coma al final
- Colocar las definiciones al inicio del archivo

### Ejemplos adicionales

```c
#define PI           3.14159
#define MAX_STUDENTS 50
#define BUFFER_SIZE  1024
#define TRUE         1
#define FALSE        0
```
