// patito_plus.c
// Lenguaje Patito+ 🦆 con soporte mejorado: paréntesis y suma de variables

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 256
#define MAX_VARS 100

struct Variable {
    char nombre[32];
    int valor;
};

struct Variable variables[MAX_VARS];
int total_vars = 0;

int variable_existe(const char *nombre) {
    for (int i = 0; i < total_vars; i++) {
        if (strcmp(variables[i].nombre, nombre) == 0) {
            return 1;
        }
    }
    return 0;
}

int get_variable(const char *nombre) {
    for (int i = 0; i < total_vars; i++) {
        if (strcmp(variables[i].nombre, nombre) == 0) {
            return variables[i].valor;
        }
    }
    return 0;
}

void set_variable(const char *nombre, int valor) {
    if (!isalpha(nombre[0])) {
        printf("[ERROR] Nombre de variable inválido: %s\n", nombre);
        return;
    }
    for (int i = 0; i < total_vars; i++) {
        if (strcmp(variables[i].nombre, nombre) == 0) {
            variables[i].valor = valor;
            return;
        }
    }
    strcpy(variables[total_vars].nombre, nombre);
    variables[total_vars].valor = valor;
    total_vars++;
}

void trim(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
}

int is_variable(const char *s) {
    return isalpha(s[0]);
}

int parse_expression(char *expr) {
    trim(expr);
  char *plus = strstr(expr, "+");
    if (plus) {
        *plus = '\0';
        char *left = expr;
        char *right = plus + 1;
        trim(left);
        trim(right);

        if (is_variable(left) && !variable_existe(left)) {
            printf("[ERROR] Variable no definida: %s\n", left);
            return 0;
        }
        if (is_variable(right) && !variable_existe(right)) {
            printf("[ERROR] Variable no definida: %s\n", right);
            return 0;
        }

        int a = is_variable(left) ? get_variable(left) : atoi(left);
        int b = is_variable(right) ? get_variable(right) : atoi(right);
        return a + b;
    } else {
        trim(expr);
        if (is_variable(expr) && !variable_existe(expr)) {
            printf("[ERROR] Variable no definida: %s\n", expr);
            return 0;
        }
        return is_variable(expr) ? get_variable(expr) : atoi(expr);
    }
}

void interpret(char *line) {
    trim(line);

    if (strncmp(line, "let ", 4) == 0) {
        char var[32];
        char expr[128];
        if (sscanf(line + 4, "%[^=]=%[^\n]", var, expr) == 2) {
            trim(var);
            if (!isalpha(var[0])) {
                printf("[ERROR] Nombre de variable inválido: %s\n", var);
                return;
            }
            trim(expr);
            int val = parse_expression(expr);
            set_variable(var, val);
            printf("[OK] %s = %d\n", var, val);
        } else {
            printf("[ERROR] Sintaxis incorrecta en declaración.\n");
        }
    } else if (strncmp(line, "print", 5) == 0) {
        char arg[64];
        char *start = strchr(line, ' ');
        if (!start) {
            printf("[ERROR] Falta argumento para print.\n");
            return;
        }
        start++;
        trim(start);
        if (start[0] == '(' && start[strlen(start) - 1] == ')') {
            start[strlen(start) - 1] = '\0';
            start++;
        }
        int val = parse_expression(start);
        printf("%d\n", val);
    } else {
        printf("[ERROR] Comando no reconocido.\n");
    }
}

int main() {
    char linea[MAX_LINE];

    printf("Bienvenido al intérprete Patito+ 🦆\n");
    printf("Soporta: let, print, variables y suma simple\n\n");

    while (fgets(linea, sizeof(linea), stdin)) {
        linea[strcspn(linea, "\n")] = '\0';
        interpret(linea);
    }

    printf("Fin del intérprete Patito+\n");
    return 0;
}