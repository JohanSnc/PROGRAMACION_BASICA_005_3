#include <stdio.h>
#include <math.h>
#include "numerico.h"

double cuadrado(double x)
{
    return x * x;
}

double funcion_raiz(double x)
{
    return x * x - 2.0;
}

int main(void)
{
    double x = 3.0;
    double h = 0.001;

    /* Derivadas */
    double d_adelante = derivada_adelante(cuadrado, x, h);
    double d_central  = derivada_central(cuadrado, x, h);

    printf("Funcion: x^2\n");
    printf("Derivada (adelante) en %.2f = %.6f\n", x, d_adelante);
    printf("Derivada (central)  en %.2f = %.6f\n", x, d_central);
    printf("Error absoluto vs valor exacto (6.0) = %.6f\n",
           error_absoluto(6.0, d_central));
    printf("Error relativo vs valor exacto (6.0) = %.6f\n\n",
           error_relativo(6.0, d_central));

    /* Integral por trapecios: integral de x^2 entre 0 y 1 = 1/3 */
    double integral = trapecio(cuadrado, 0.0, 1.0, 100);
    printf("Integral aproximada de x^2 en [0,1] = %.8f\n", integral);
    printf("Error absoluto vs valor exacto (1/3) = %.8f\n\n",
           error_absoluto(1.0 / 3.0, integral));

    /* Raiz por biseccion: raiz de x^2 - 2 = sqrt(2) */
    double raiz = biseccion(funcion_raiz, 1.0, 2.0, 0.000001, 100);
    printf("Raiz aproximada de x^2 - 2 = %.8f\n", raiz);
    printf("Error absoluto vs valor exacto (sqrt(2)) = %.8f\n",
           error_absoluto(sqrt(2.0), raiz));

    return 0;
}
