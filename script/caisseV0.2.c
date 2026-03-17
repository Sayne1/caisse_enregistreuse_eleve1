#include <stdio.h>
#include <stdlib.h>

double calcule_monnaie(double montant, double paiement) {
    return paiement - montant;
}

int main() {

    double montant = (rand() % 2001) + ((double)rand() / RAND_MAX);
    double paiement = 0;

    printf("Montant a payer : %.2f Rs\n", montant);

    do {
        printf("Entrez le montant que vous donnez : ");
        scanf("%lf", &paiement);

        if (paiement < montant) {
            printf("Montant insuffisant, veuillez entrer une somme plus elevee.\n");
        }
    } while (paiement < montant);

    double reste = calcule_monnaie(montant, paiement);
    printf("Monnaie a rendre : %.2f Rs\n", reste);

    double valeurs[] = {2000, 1000, 500, 200, 100, 50, 25, 20, 10, 5, 1, 0.50, 0.20, 0.05};
    int n = sizeof(valeurs) / sizeof(valeurs[0]);

    for (int i = 0; i < n; i++) {
        if (reste >= valeurs[i]) {
            int count = (int)(reste / valeurs[i]);
            reste -= count * valeurs[i];
            reste += 0.001;

            if (valeurs[i] >= 25) {
                printf("Billet de %.0f Rs : %d\n", valeurs[i], count);
            } else {
                printf("Piece de %.2f Rs : %d\n", valeurs[i], count);
            }
        }
    }

    return 0;
}
