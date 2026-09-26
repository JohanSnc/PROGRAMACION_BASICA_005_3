#include <stdio.h>
#include <time.h>
int main() {
char modo;
int i;
while (1) {
printf("\nControl del LED simulado\n");
printf("0 -> Salir\n");
printf("1 -> 1 Hz\n");
printf("2 -> 2 Hz\n");
printf("3 -> 5 Hz\n");
printf("Seleccione una opcion: ");
scanf(" %c", &modo);
if (modo == '0') {
printf("Fin del programa.\n");
break;
}
else if (modo == '1') {
for (i = 0; i < 5; i++) {
printf("O\n");
clock_t inicio = clock();
while ((clock() - inicio) * 1000
/ CLOCKS_PER_SEC < 500) {
}
printf(".\n");
inicio = clock();
while ((clock() - inicio) * 1000
/ CLOCKS_PER_SEC < 500) {
}
}
}
else if (modo == '2') {
for (i = 0; i < 5; i++) {
printf("O\n");
clock_t inicio = clock();
while ((clock() - inicio) * 1000
/ CLOCKS_PER_SEC < 250) {
}
printf(".\n");
inicio = clock();
while ((clock() - inicio) * 1000
/ CLOCKS_PER_SEC < 250) {
}
}
}
else if (modo == '3') {
for (i = 0; i < 5; i++) {
printf("O\n");
clock_t inicio = clock();
while ((clock() - inicio) * 1000
/ CLOCKS_PER_SEC < 100) {
}
printf(".\n");
inicio = clock();
while ((clock() - inicio) * 1000
/ CLOCKS_PER_SEC < 100) {
}
}
}
else {
printf("Opcion no valida.\n");
}
}
return 0;
}