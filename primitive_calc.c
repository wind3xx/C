#include <stdio.h>

void empty_stdin() {
    int c = getchar();

    while(c != '\n' && c != EOF)
        c = getchar();
    
}


void dodawanie(FILE * plik) {

    unsigned int ile_liczb;
    printf("\nIle liczb chcesz zsumowac: ");
    scanf("%u", &ile_liczb);
    empty_stdin();

    float suma = 0;
    for(int i = 1; i <= ile_liczb; i++) {
        float curr_number;
        
        printf("Podaj (%d) liczbe: ", i);
        scanf("%f", &curr_number);
        empty_stdin();

        if(i == 1 && ile_liczb == 1) {
            fprintf(plik, "%f", curr_number);
        }
        else if(i == 1) {
            fprintf(plik, "SUMA %f i", curr_number);
        }
        else if(i == ile_liczb) {
            fprintf(plik, " %f", curr_number);
        }
        else {
            fprintf(plik, " %f i", curr_number);
        }

        suma += curr_number;
    }

    printf("\nSUMA WYNOSI: %f\n", suma);
    fprintf(plik, " WYNOSI: %f\n", suma);
}


void odejmowanie(FILE * plik) {

    unsigned int ile_liczb;
    printf("\nIle liczb chcesz odjac: ");
    scanf("%u", &ile_liczb);
    empty_stdin();

    float roznica = 0;
    for(int i = 1; i <= ile_liczb; i++) {
        float current_number;
        
        printf("Podaj (%d) liczbe: ", i);
        scanf("%f", &current_number);
        empty_stdin();

        if(i == 1 && ile_liczb == 1) {
            fprintf(plik, "%f", current_number);
        }
        else if(i == 1) {
            fprintf(plik, "ROZNICA %f i", current_number);
        }
        else if(i == ile_liczb) {
            fprintf(plik, " %f", current_number);
        }
        else {
            fprintf(plik, " %f i", current_number);
        }

        roznica -= current_number;
    }

    printf("\nSUMA WYNOSI: %f\n", roznica);
    fprintf(plik, " WYNOSI: %f\n", roznica);
}


void mnozenie(FILE * plik) {

    const unsigned int ile_liczb;
    printf("\nIle liczb chcesz pomnozyc: ");
    scanf("%u", &ile_liczb);
    empty_stdin();

    float iloczyn = 1;
    for(int i = 1; i <= ile_liczb; i++) {
        float current_number;
        
        printf("Podaj (%d) liczbe: ", i);
        scanf("%f", &current_number);
        empty_stdin();

        if(i == 1 && ile_liczb == 1) {
            fprintf(plik, "%f", current_number);
        }
        else if(i == 1) {
            fprintf(plik, "ILOCZYN %f i", current_number);
        }
        else if(i == ile_liczb) {
            fprintf(plik, " %f", current_number);
        }
        else {
            fprintf(plik, " %f i", current_number);
        }

        iloczyn *= current_number;
    }

    printf("\nILOCZYN WYNOSI: %f\n", iloczyn);
    fprintf(plik, " WYNOSI: %f\n", iloczyn);
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