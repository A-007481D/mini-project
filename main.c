#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void welcome() {
    printf("\n\tBonjour!\n");
    printf("*");
    printf("\n0: exit\n1: ajouter un livre\n2: afficher les livres\n3: update livre\n4: delete livre\n5: afficher le nombre du livre et du stock\n");
}

void  ajouter(char titre[][100], char auteur[][100], float prix[], int quantite[], int count)
{
    printf ("titre : ");
    scanf ("%s", titre[count]);
    printf ("auteur : ");
    scanf ("%s", auteur[count]);
    printf ("prix : ");
    scanf ("%f", &prix[count]);
    printf ("quantite : ");
    scanf ("%d", &quantite[count]);
}

void afficher(char titre[][100], char auteur[][100], float prix[], int quantite[], int count)
{
    printf("\nListe des livres :\n");
    for (int i = 0; i < count; i++)
    {
        printf("\n| Titre : %s | Auteur : %s | Prix :  %.2f | Quantite : %d |", titre[i], auteur[i], prix[i], quantite[i]);
    }
    printf("\n");
}

void update(char titre[][100], int quantite[], int count, char word[], int toAdd) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(titre[i], word) == 0) {
            quantite[i] += toAdd;
        } else {
            printf("There is no such Book");
        }
    }
}

void delete(char titre[][100] , char auteur[][100] , float prix[], int quantite[] , int c, char word[]) {
    int i, j;
    for (i = 0; i < c; i++) {
        if (strcmp(titre[i], word) == 0) {
            for (j = i; j < c - 1; j++) {
                strcpy(titre[j], titre[j + 1]);
                strcpy(auteur[j], auteur[j + 1]);
                prix[j] = prix[j + 1];
                quantite[j] = quantite[j + 1];
            }
            break;
        }
    }
}

void calcule(int quantite[], int count) {
    int i, total = 0;
    for (i = 0; i < count; i++) {
        total += quantite[i];
    }
    printf("Total Books in storage: %d\n", count);
    printf("Total quantité: %d\n", total);
}

int main() {
    int choix;
    int c = 0;

    char titre[10][100];
    char auteur[10][100];
    float prix[10];
    int quantite[10];

    while(1) {
        welcome();
        printf("Entee votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                ajouter(titre, auteur, prix, quantite, c);
                c++;
                break;
            case 2:
                printf("Count: %d\n", c);
                afficher(titre, auteur, prix, quantite, c);
                break;
            case 3:
                char word[100];
                int new;
                printf("Enter the titre: ");
                scanf("%s", word);
                printf("Enter how to much to Add: ");
                scanf("%d", &new);
                update(titre, quantite, c, word, new);
                break;
            case 4:
                char mot[100];
                printf("Enter the titre to delete: ");
                scanf("%s", mot);
                delete(titre ,auteur, prix, quantite, c, mot);
                c--;
                break;
            case 5:
                calcule(quantite, c);
                break;
            case 0:
                printf("exit...\n");
                exit(0);
            default:
                printf("Default!");
        }
    }
    return (0);
}