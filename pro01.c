#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day {
    char *dayName;      // dynamically allocated string
    int date;
    char *activity;     // dynamically allocated string
};

struct Day *create() {
    // Create dynamic array of 7 days
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

        // Read day name
        printf("Enter Day Name: ");
        scanf("%s", temp);
        week[i].dayName = (char *)malloc(strlen(temp) + 1);
        strcpy(week[i].dayName, temp);

        // Read date
        printf("Enter Date (number): ");
        scanf("%d", &week[i].date);

        // Read activity description
        printf("Enter Activity Description: ");
        getchar(); // to clear newline
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = 0; // remove newline

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

    week = create();   // Create dynamic array of 7 days
    read(week);        // Read all values from the user
    display(week);     // Display the full weekly report

    // Free allocated memory after usage
    for (int i = 0; i < 7; i++) {
        free(week[i].dayName);
        free(week[i].activity);
    }
    free(week);

    return 0;
}

