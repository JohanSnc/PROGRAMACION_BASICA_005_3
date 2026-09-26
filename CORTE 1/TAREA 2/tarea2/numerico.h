#ifndef NUMERICO_H
#define NUMERICO_H

double derivada_adelante(
    double (*f)(double),
    double x,
    double h
);

double derivada_central(
    double (*f)(double),
    double x,
    double h
);

double trapecio(
    double (*f)(double),
    double a,
    double b,
    int n
);

double biseccion(
    double (*f)(double),
    double a,
    double b,
    double tolerancia,
    int max_iteraciones
);

double error_absoluto(
    double real,
    double aproximado
);

double error_relativo(
    double real,
    double aproximado
);

#endif
