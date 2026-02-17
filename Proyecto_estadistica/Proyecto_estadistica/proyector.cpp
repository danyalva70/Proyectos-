#include <iostream>
#include <stdio.h>
#include <stdlib.h>

unsigned int vector[102];
unsigned int limite;

void varianza(unsigned int vector[102]);
void capturaarreglo(unsigned int vector[102]);
void moda(unsigned int vector[102]);
void mediana(unsigned int vector[102]);
float mediaaritmetica(unsigned int vector[102]);
int compare(const void *a, const void *b); // Funcion Para comparar 

int main() {
    do {
    	//para poder empezar le pedimos al usuario que ingrese lo que seria la cantidad de elementos a utilizar que no sobre pase a 100 y que no sea menor a 3
        printf("Escriba los elementos a capturar (minimo 3, maximo 100): ");
        scanf("%u", &limite);
    } while (limite < 3 || limite > 100);//en esta funcion se encarga de poner un limite al la variable limite 
//en esta funcion se encrga en mostrar los elementos de las variables u operaciones 
    capturaarreglo(vector);
    printf("La media aritmetica es: %.2f\n", mediaaritmetica(vector));
    mediana(vector);
    moda(vector);
    varianza(vector); 
    return 0;
}

void capturaarreglo(unsigned int a[102]) {
    printf("Limite: %u\n", limite);
    for (unsigned int i = 0; i < limite; i++) {
        printf("Capture el elemento # %u: ", i + 1);
        scanf("%u", &a[i]);// este funcionamiento se utiliza para poder capturar los numeros de elementos definidos o insertados 
    }
}
// media
float mediaaritmetica(unsigned int a[102]) {
    float total = 0;
    for (unsigned int i = 0; i < limite; i++) {
        total += a[i];
    }
    return total / limite;
}
//mediana 
void mediana(unsigned int a[102]) {
    // Sorting using qsort for simplicity
    qsort(a, limite, sizeof(unsigned int), compare);

    printf("Ordenamiento: ");
    for (unsigned int i = 0; i < limite; i++) {
        printf("%u ", a[i]);
    }
    printf("\n");

    float valor_mediana;
    if (limite % 2 == 1) {
        valor_mediana = a[limite / 2]; 
    } else {
        valor_mediana = (a[limite / 2 - 1] + a[limite / 2]) / 2.0; // For even number of elements
    }
    printf("La mediana es: %.1f\n", valor_mediana);
}

int compare(const void* a, const void* b) {
    return (*(unsigned int*)a - *(unsigned int*)b);
}
//moda 
void moda(unsigned int a[102]) {
    unsigned int b[102][2] = {0}; // To store value and count
    unsigned int count = 0;

    for (unsigned int i = 0; i < limite; i++) {
        unsigned int j;
        for (j = 0; j < count; j++) {
            if (b[j][0] == a[i]) {
                b[j][1]++;
                break;
            }
        }
        if (j == count) {
            b[count][0] = a[i];
            b[count][1] = 1;
            count++;
        }
    }

    printf("Tabla de la moda\n");
    for (unsigned int i = 0; i < count; i++) {
        printf("Valor: %u - Veces presente: %u\n", b[i][0], b[i][1]);
    }
}
//varianza

void varianza(unsigned int a[102]) {
    float media = mediaaritmetica(a);
    float suma_varianza = 0;

    for (unsigned int i = 0; i < limite; i++) {
        suma_varianza += (a[i] - media) * (a[i] - media);
    }
    
    float varianza = suma_varianza / limite;
    printf("La varianza es: %.2f\n", varianza);
}
