#include <stdio.h>
#include <string.h>
void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}
int main() {
    char STR[200], PAT[50], REP[50], RESULT[300];
    int i, j, k, found = 0;
    printf("Enter Main String (STR): ");
    fgets(STR, sizeof(STR), stdin);
    removeNewline(STR);
    printf("Enter Pattern String (PAT): ");
    fgets(PAT, sizeof(PAT), stdin);
    removeNewline(PAT);
    printf("Enter Replace String (REP): ");
    fgets(REP, sizeof(REP), stdin);
    removeNewline(REP);
    int lenSTR = strlen(STR);
    int lenPAT = strlen(PAT);
    int lenREP = strlen(REP);
    i = j = 0;
    while (i < lenSTR) {
        k = 0;
        while (k < lenPAT && STR[i + k] == PAT[k]) {
            k++;
        }
        if (k == lenPAT) {
            found = 1;
            strcpy(&RESULT[j], REP);
            j += lenREP;
            i += lenPAT;
        } else {
            RESULT[j++] = STR[i++];
        }
    }
    RESULT[j] = '\0';
    if (!found) {
        printf("\nPattern does NOT exist in the main string.\n");
    } else {
        printf("\nThe new string after replacement is:\n%s\n", RESULT);
    }
    return 0;
}

