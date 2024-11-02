#include <stdio.h>

void dodawanie(FILE * plik) {

    float a;
    float b;

    printf("Podaj pierwsza liczbe: ");
    scanf("%f", &a);

    printf("Podaj druga liczbe: ");
    scanf("%f", &b);

    float wynik = a + b;
    printf("Suma: %f\n", wynik);
    fprintf(plik, "Suma %f i %f wynosi: %f\n", a, b, wynik);
}

void odejmowanie(FILE * plik) {

    float a;
    float b;

    printf("Podaj pierwsza liczbe: ");
    scanf("%f", &a);

    printf("Podaj druga liczbe: ");
    scanf("%f", &b);

    float wynik = a - b;
    printf("Roznica: %f\n", wynik);
    fprintf(plik, "Roznica %f i %f wynosi: %f\n", a, b, wynik);
}

void mnozenie(FILE * plik) {

    float a;
    float b;

    printf("Podaj pierwsza liczbe: ");
    scanf("%f", &a);

    printf("Podaj druga liczbe: ");
    scanf("%f", &b);

    float wynik = a * b;
    printf("Iloczyn: %f\n", wynik);
    fprintf(plik, "Iloczyn %f i %f wynosi: %f\n", a, b, wynik);
}

void dzielenie(FILE * plik) {

    float a;
    float b;

    printf("Podaj pierwsza liczbe: ");
    scanf("%f", &a);

    printf("Podaj druga liczbe: ");
    scanf("%f", &b);

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

void delete_file_contents(const char * calc_mem) {
    FILE * usun = fopen(calc_mem, "w");
    fclose(usun);
}

void jaka_funkcja() {
    printf("###Wybierz swoje dzialanie, wybierajac cyfre.###\n");
    printf("1. Dodawanie.\n");
    printf("2. Odejmowanie.\n");
    printf("3. Mnozenie.\n");
    printf("4. Dzielenie.\n");
    printf("9. Wyczyszczenie zawartosci pliku .txt\n");
    printf("0. Wyjscie.");
}


int main() {

    const char * calc_mem = "pamiec_kalkulatora.txt";

    FILE * save_to_file;
    save_to_file = fopen(calc_mem, "a");

    if(save_to_file == NULL) {
        perror("Blad z otwarciem pliku.");
        return 1;
    }

    int wybor;

    do {
    jaka_funkcja();
    printf("\nWybierz jedna z powyzszych opcji: ");
    scanf("%d", &wybor);
    switch(wybor) {
        case 1:
            dodawanie(save_to_file);
        break;
        case 2:
            odejmowanie(save_to_file);
        break;
        case 3:
            mnozenie(save_to_file);
        break;
        case 4:
            dzielenie(save_to_file);
        break;
        case 9:
            fclose(save_to_file);
            delete_file_contents(calc_mem);
            save_to_file = fopen(calc_mem, "a");
        break;
        case 0:
            printf("Dziekuje za zkorzystanie z kalkulatora :3");
            break;
        default:
            printf("Taka opcja nie istnieje.");
            fprintf(save_to_file, "Uzytkownik wybral opcje ktora nie istnieje.\n");
    }
    } while(wybor != 0);

    fclose(save_to_file);

    return 0;
}