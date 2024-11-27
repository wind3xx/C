#include <stdio.h>
#include "MyMath.h"


void delete_file_contents(const char * calc_mem) {
    FILE * usun = fopen(calc_mem, "w");
    printf("\nZawartosc pliku .txt zostala pomyslnie wyczyszczona.\n");
    fclose(usun);
}


void jaka_funkcja() {
    printf("\n###Wybierz swoje dzialanie, wybierajac cyfre.###\n");
    printf("\n1. Dodawanie.\n");
    printf("2. Odejmowanie.\n");
    printf("3. Mnozenie.\n");
    printf("4. Dzielenie.\n");
    printf("9. Wyczyszczenie zawartosci pliku .txt\n");
    printf("0. Wyjscie.\n");
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

        if(sizeof(wybor) > 4) {
            continue;
        }

        empty_stdin();

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
                printf("\nDziekuje za zkorzystanie z kalkulatora :3");
                break;
            default:
                printf("\nTaka opcja nie istnieje.");
                fprintf(save_to_file, "Uzytkownik wybral opcje ktora nie istnieje.\n");
    }
    } while(wybor != 0);

    fclose(save_to_file);

    return 0;
}