#include <stdio.h>

void dodawanie(FILE *plik, float a, float b) {
    float wynik = a + b;
    printf("Suma: %f\n", wynik);
    fprintf(plik, "Suma %f i %f wynosi: %f\n", a, b, wynik);
}

void odejmowanie(FILE *plik, float a, float b) {
    float wynik = a - b;
    printf("Roznica: %f\n", wynik);
    fprintf(plik, "Roznica %f i %f wynosi: %f\n", a, b, wynik);
}

void mnozenie(FILE *plik, float a, float b) {
    float wynik = a * b;
    printf("Iloczyn: %f\n", wynik);
    fprintf(plik, "Iloczyn %f i %f wynosi: %f\n", a, b, wynik);
}

void dzielenie(FILE *plik, float a, float b) {
    if(b != 0) {
        float wynik = a / b;
        printf("Iloraz: %f\n", wynik);
        fprintf(plik, "Iloraz %f i %f wynosi: %f\n", a, b, wynik);
    }
    else {
        printf("Nie mozna dzielic przez 0!");
        fprintf(plik, "Co za debil, probowal podzielic %f przez %.0f haha!\n", a, b);
    }
}

void czyszczenie_pliku() {
    FILE *plik = fopen("prymitywny_kalkulator.txt", "w");
    printf("Plik zostal pomyslnie wyczyszczony.");
}

void jaka_funkcja() {
    printf("___Wybierz swoje dzialanie, wybierajac cyfre.___\n");
    printf("1. Dodawanie.\n");
    printf("2. Odejmowanie.\n");
    printf("3. Mnozenie.\n");
    printf("4. Dzielenie.\n");
    printf("9. Wyczyszczenie zawartosci pliku .txt");
}

int main() {

    float a;
    float b;

    FILE *plik = fopen("prymitywny_kalkulator.txt", "a");

    if(plik == NULL) {
        printf("Problem z otwarciem pliku");
        return 1;
    }

    printf("Podaj pierwsza liczbe: ");
    scanf("%f", &a);

    printf("Podaj druga liczbe: ");
    scanf("%f", &b);

    int wybor;
    jaka_funkcja();
    printf("\nWybierz jedna z powyzszych opcji: ");
    scanf("%d", &wybor);
    switch(wybor) {
        case 1:
            dodawanie(plik, a, b);
        break;
        case 2:
            odejmowanie(plik, a, b);
        break;
        case 3:
            mnozenie(plik, a, b);
        break;
        case 4:
            dzielenie(plik, a, b);
        break;
        case 9:
            czyszczenie_pliku(plik);
        break;
        default:
            printf("Taka opcja nie istnieje.");
            fprintf(plik, "Uzytkownik wybral opcje ktora nie istnieje.\n");
    }

    fclose(plik);

    return 0;
}