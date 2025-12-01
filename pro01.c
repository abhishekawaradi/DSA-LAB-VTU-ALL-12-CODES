#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Day {
    char *dayName;     
    int date;
    char *activity;     
};
struct Day *create() {
    struct Day *week = (struct Day *)malloc(7 * sizeof(struct Day));
    if (week == NULL) {
        printf("Memory Allocation Failed!\n");
        exit(0);
    }
    return week;
}
void read(struct Day *week) {
    char temp[100];
    printf("\nEnter the Weekly Calendar Details:\n");
    for (int i = 0; i < 7; i++) {
        printf("\n--- Day %d ---\n", i + 1);
        printf("Enter Day Name: ");
        scanf("%s", temp);
        week[i].dayName = (char *)malloc(strlen(temp) + 1);
        strcpy(week[i].dayName, temp);
        printf("Enter Date (number): ");
        scanf("%d", &week[i].date);
        printf("Enter Activity Description: ");
        getchar(); 
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = 0; 
        week[i].activity = (char *)malloc(strlen(temp) + 1);
        strcpy(week[i].activity, temp);
    }
}
void display(struct Day *week) {
    printf("\n\n===== WEEKLY ACTIVITY REPORT =====\n");
    for (int i = 0; i < 7; i++) {
        printf("\nDay %d: %s\n", i + 1, week[i].dayName);
        printf("Date: %d\n", week[i].date);
        printf("Activity: %s\n", week[i].activity);
    }
}
int main() {
    struct Day *week;
    week = create();  
    read(week);       
    display(week);     
    for (int i = 0; i < 7; i++) {
        free(week[i].dayName);
        free(week[i].activity);
    }
    free(week);

    return 0;
}

