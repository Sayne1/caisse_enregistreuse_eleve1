#include <stdio.h>
#include <stdlib.h>

double calcule_monnaie(double montant, double paiement) {
    return paiement - montant;
}

int main() {
    // Initial stocks for each bill/coin
    double valeurs[] = {2000, 1000, 500, 200, 100, 50, 25, 20, 10, 5, 1, 0.50, 0.20, 0.05};
    int stocks[] = {2, 2, 5, 5, 10, 10, 10, 10, 20, 20, 20, 50, 50, 50};
    int n = sizeof(valeurs) / sizeof(valeurs[0]);

    int continuer = 1;

    while (continuer) {
        // 8. Afficher l'état des stocks
        printf("\n---Stock Actuel---\n");
        for (int i = 0; i < n; i++) {
            printf("[%.2f Rs: %d] ", valeurs[i], stocks[i]);
            if ((i + 1) % 5 == 0) printf("\n");
        }
        printf("\n-----------\n");

        double montant = (rand() % 2001) + ((double)rand() / RAND_MAX);
        double paiement = 0;

        printf("\nMontant a payer : %.2f Rs\n", montant);

        do {
            printf("Entrez le montant que vous donnez (ou 0 pour fermer) : ");
            scanf("%lf", &paiement);
            if (paiement == 0) return 0;
            if (paiement < montant) {
                printf("Montant insuffisant.\n");
            }
        } while (paiement < montant);

        double reste = calcule_monnaie(montant, paiement);
        double temp_reste = reste + 0.001;
        int a_rendre[14] = {0};

        for (int i = 0; i < n; i++) {
            int besoin = (int)(temp_reste / valeurs[i]);
            if (besoin > 0) {
                int donnee = (besoin < stocks[i]) ? besoin : stocks[i];
                a_rendre[i] = donnee;
                temp_reste -= donnee * valeurs[i];
            }
        }

        if (temp_reste >= 0.05) {

            printf("ERREUR : Impossible de rendre la monnaie exacte (Manque %.2f Rs)\n", temp_reste);
            printf("Que voulez-vous faire ? (1: Remplir la caisse, 2: Fermer la caisse) : ");
            int choix;
            scanf("%d", &choix);
            if (choix == 1) {
                for (int i = 0; i < n; i++) stocks[i] += 10;
                printf("Caisse remplie !\n");
            } else {
                continuer = 0;
            }
        } else {

            printf("Monnaie a rendre : %.2f Rs\n", reste);
            for (int i = 0; i < n; i++) {
                if (a_rendre[i] > 0) {
                    stocks[i] -= a_rendre[i]; // Update stock
                    if (valeurs[i] >= 25) {
                        printf("Billet de %.0f Rs : %d\n", valeurs[i], a_rendre[i]);
                    } else {
                        printf("Piece de %.2f Rs : %d\n", valeurs[i], a_rendre[i]);
                    }
                }
            }
        }
    }

    printf("Programme arrete\n");
    return 0;
}
