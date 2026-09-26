#include <math.h>
#include "numerico.h"

double derivada_adelante(
    double (*f)(double),
    double x,
    double h
)
{
    return (f(x + h) - f(x)) / h;
}

double derivada_central(
    double (*f)(double),
    double x,
    double h
)
{
    return (f(x + h) - f(x - h)) / (2.0 * h);
}

double trapecio(
    double (*f)(double),
    double a,
    double b,
    int n
)
{
    double h = (b - a) / n;
    double suma = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        suma += f(x);
    }

    return h * suma;
}

double biseccion(
    double (*f)(double),
    double a,
    double b,
    double tolerancia,
    int max_iteraciones
)
{
    double c = 0.0;

    for (int i = 0; i < max_iteraciones; i++)
    {
        c = (a + b) / 2.0;

        if (fabs(f(c)) < tolerancia)
        {
            return c;
        }

        if (f(a) * f(c) < 0.0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    return c;
}

double error_absoluto(
    double real,
    double aproximado
)
{
    return fabs(real - aproximado);
}

double error_relativo(
    double real,
    double aproximado
)
{
    return fabs(real - aproximado) / fabs(real);
}
