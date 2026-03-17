#include <stdio.h>
#include <stdlib.h>

double calcule_monnaie(double montant, double paiement) {
    return paiement - montant;
}

int main() {
    double montant;
    double paiement = 0;
    double random = rand() % 20001;
    srand(1);


    montant = (rand() % 2001) + ((double)rand() / RAND_MAX);
    printf("Montant à payer : %.2f Rs\n", montant);


    do {
        printf("Entrez le montant que vous donnez : ");
        scanf("%lf", &paiement);

        if (paiement < montant) {
            printf("Montant insuffisant, veuillez entrer une somme plus elevee.\n");
        }

    } while (paiement < montant);


    double monnaie = calcule_monnaie(montant, paiement);

    printf("Monnaie à rendre : %.2f Rs\n", monnaie);

    return 0;
}
