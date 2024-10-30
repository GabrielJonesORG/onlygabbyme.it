#include <stdio.h>
#include <string.h>

#define MAX_STUDENTI 50
#define MAX_VOTI 10

typedef struct {
    char nome[50];
    int voti[MAX_VOTI];
    int num_voti;
} Studente;

void aggiungiVoto(Studente studenti[], int num_studenti) {
    char nome[50];
    int voto;
    printf("Inserisci il tuo nome: ");
    scanf("%s", nome);
    
    for (int i = 0; i < num_studenti; i++) {
        if (strcmp(studenti[i].nome, nome) == 0) {
            if (studenti[i].num_voti >= MAX_VOTI) {
                printf("Numero massimo di voti raggiunto per %s.\n", studenti[i].nome);
                return;
            }
            printf("Inserisci il voto: ");
            scanf("%d", &voto);
            studenti[i].voti[studenti[i].num_voti] = voto;
            studenti[i].num_voti++;
            printf("Voto aggiunto con successo!\n");
            return;
        }
    }
    printf("Studente non trovato. Assicurati di essere registrato.\n");
}

void visualizzaVoti(Studente studenti[], int num_studenti) {
    char nome[50];
    printf("Inserisci il tuo nome: ");
    scanf("%s", nome);
    
    for (int i = 0; i < num_studenti; i++) {
        if (strcmp(studenti[i].nome, nome) == 0) {
            printf("Voti di %s:\n", studenti[i].nome);
            for (int j = 0; j < studenti[i].num_voti; j++) {
                printf("%d ", studenti[i].voti[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("Studente non trovato.\n");
}

void calcolaMedia(Studente studenti[], int num_studenti) {
    char nome[50];
    printf("Inserisci il tuo nome: ");
    scanf("%s", nome);
    
    for (int i = 0; i < num_studenti; i++) {
        if (strcmp(studenti[i].nome, nome) == 0) {
            if (studenti[i].num_voti == 0) {
                printf("Nessun voto disponibile per %s.\n", studenti[i].nome);
                return;
            }
            int somma = 0;
            for (int j = 0; j < studenti[i].num_voti; j++) {
                somma += studenti[i].voti[j];
            }
            float media = (float)somma / studenti[i].num_voti;
            printf("La media dei voti di %s è: %.2f\n", studenti[i].nome, media);
            return;
        }
    }
    printf("Studente non trovato.\n");
}

void aggiungiStudente(Studente studenti[], int *num_studenti) {
    if (*num_studenti >= MAX_STUDENTI) {
        printf("Numero massimo di studenti raggiunto.\n");
        return;
    }
    printf("Inserisci il tuo nome per registrarti: ");
    scanf("%s", studenti[*num_studenti].nome);
    studenti[*num_studenti].num_voti = 0;
    (*num_studenti)++;
    printf("Studente registrato con successo!\n");
}

int main() {
    Studente studenti[MAX_STUDENTI];
    int num_studenti = 0;
    int scelta;
    
    do {
        printf("\n--- Gestionale Voti ---\n");
        printf("1. Registrati come studente\n");
        printf("2. Aggiungi voto\n");
        printf("3. Visualizza voti\n");
        printf("4. Calcola media\n");
        printf("5. Esci\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);
        
        switch (scelta) {
            case 1:
                aggiungiStudente(studenti, &num_studenti);
                break;
            case 2:
                aggiungiVoto(studenti, num_studenti);
                break;
            case 3:
                visualizzaVoti(studenti, num_studenti);
                break;
            case 4:
                calcolaMedia(studenti, num_studenti);
                break;
            case 5:
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Opzione non valida.\n");
                break;
        }
    } while (scelta != 5);
    
    return 0;
}
