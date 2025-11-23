#include <stdio.h>
#include <math.h>

struct poly {
    int coef;
    int px, py, pz;
};

void readPoly(struct poly P[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\tEnter the %d term:\n", i + 1);
        printf("\t\tCoef =  ");
        scanf("%d", &P[i].coef);
        printf("\t\tEnter Pow(x) Pow(y) and Pow(z): ");
        scanf("%d %d %d", &P[i].px, &P[i].py, &P[i].pz);
    }
}

void printPoly(struct poly P[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%dx^%dy^%dz^%d", P[i].coef, P[i].px, P[i].py, P[i].pz);
        if (i != n - 1)
            printf(" + ");
    }
    printf("\n");
}

int evaluate(struct poly P[], int n, int x, int y, int z) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += P[i].coef * pow(x, P[i].px) * pow(y, P[i].py) * pow(z, P[i].pz);
    }
    return sum;
}

int main() {
    int choice;

    do {
        printf("\n--------Menu--------\n");
        printf("1.Represent and Evaluate a Polynomial P(x,y,z)\n");
        printf("2.Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int n, x, y, z;
            struct poly P[20];

            printf("\n----Polynomial evaluation P(x,y,z)----\n");
            printf("Enter the no of terms in the polynomial: ");
            scanf("%d", &n);

            readPoly(P, n);

            printf("\nRepresentation of Polynomial for evaluation:\n");
            printPoly(P, n);

            printf("\nEnter the value of x,y and z: ");
            scanf("%d %d %d", &x, &y, &z);

            int result = evaluate(P, n, x, y, z);
            printf("Result of polynomial evaluation is : %d\n", result);
        }

        else if (choice == 2) {
            int n1, n2;
            struct poly P1[20], P2[20], Sum[40];
            int k = 0;

            printf("\nEnter the POLY1(x,y,z):\n");
            printf("Enter the no of terms in the polynomial: ");
            scanf("%d", &n1);
            readPoly(P1, n1);

            printf("\nPolynomial 1 is:\n");
            printPoly(P1, n1);

            printf("\nEnter the POLY2(x,y,z):\n");
            printf("Enter the no of terms in the polynomial: ");
            scanf("%d", &n2);
            readPoly(P2, n2);

            printf("\nPolynomial 2 is:\n");
            printPoly(P2, n2);

            // Add polynomials
            int used[20] = {0};

            for (int i = 0; i < n1; i++) {
                int found = 0;
                for (int j = 0; j < n2; j++) {
                    if (P1[i].px == P2[j].px &&
                        P1[i].py == P2[j].py &&
                        P1[i].pz == P2[j].pz) {

                        Sum[k].coef = P1[i].coef + P2[j].coef;
                        Sum[k].px = P1[i].px;
                        Sum[k].py = P1[i].py;
                        Sum[k].pz = P1[i].pz;

                        used[j] = 1;
                        k++;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    Sum[k++] = P1[i];
                }
            }

            for (int j = 0; j < n2; j++) {
                if (!used[j]) {
                    Sum[k++] = P2[j];
                }
            }

            printf("\nPolynomial addition result:\n");
            printPoly(Sum, k);
        }

    } while (choice != 3);

    return 0;
}

