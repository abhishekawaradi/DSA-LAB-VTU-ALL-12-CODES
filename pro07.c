#include<stdio.h>
#include<stdlib.h>

struct node {
    char usn[25], name[50], branch[50];
    int sem;
    long long phone;
    struct node *link;
};
typedef struct node* NODE;

NODE start = NULL;
int count = 0;

NODE create() {
    NODE temp = (NODE)malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("\nMemory not available");
        exit(1);
    }

    printf("\nEnter USN: ");
    scanf(" %[^\n]", temp->usn);

    printf("Enter Name: ");
    scanf(" %[^\n]", temp->name);

    printf("Enter Branch: ");
    scanf(" %[^\n]", temp->branch);

    printf("Enter Semester: ");
    scanf("%d", &temp->sem);

    printf("Enter Phone Number: ");
    scanf("%lld", &temp->phone);

    temp->link = NULL;
    count++;
    return temp;
}

NODE insertfront() {
    NODE temp = create();

    if (start == NULL)
        return temp;

    temp->link = start;
    return temp;
}

NODE deletefront() {
    if (start == NULL) {
        printf("\nLinked list is empty");
        return NULL;
    }

    NODE temp = start;

    if (start->link == NULL) {
        printf("\nStudent node with USN %s deleted", start->usn);
        free(start);
        count--;
        return NULL;
    }

    start = start->link;
    printf("\nStudent node with USN %s deleted", temp->usn);
    free(temp);
    count--;
    return start;
}

NODE insertend() {
    NODE temp = create();

    if (start == NULL)
        return temp;

    NODE cur = start;
    while (cur->link != NULL)
        cur = cur->link;

    cur->link = temp;
    return start;
}

NODE deleteend() {
    if (start == NULL) {
        printf("\nLinked List is empty");
        return NULL;
    }

    if (start->link == NULL) {
        printf("\nStudent node with USN %s deleted", start->usn);
        free(start);
        count--;
        return NULL;
    }

    NODE prev = NULL, cur = start;

    while (cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }

    printf("\nStudent node with USN %s deleted", cur->usn);
    free(cur);
    prev->link = NULL;
    count--;
    return start;
}

void display() {
    if (start == NULL) {
        printf("\nNo contents to display\n");
        return;
    }

    NODE cur = start;
    int num = 1;

    printf("\n----- SLL Contents -----\n");
    while (cur != NULL) {
        printf("\n[%d] USN:%s | Name:%s | Branch:%s | Sem:%d | Phone:%lld",
               num, cur->usn, cur->name, cur->branch, cur->sem, cur->phone);
        cur = cur->link;
        num++;
    }

    printf("\n\nTotal student nodes = %d\n", count);
}

void stackdemo() {
    int ch;
    while (1) {
        printf("\n------- STACK DEMO (Front In/Out) -------\n");
        printf("1. Push (Insert at Front)\n");
        printf("2. Pop (Delete at Front)\n");
        printf("3. Display\n");
        printf("4. Exit Stack Demo\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: start = insertfront(); break;
            case 2: start = deletefront(); break;
            case 3: display(); break;
            case 4: return;
            default: printf("\nInvalid choice\n");
        }
    }
}

int main() {
    int ch, n, i;

    while (1) {
        printf("\n------------ MENU ------------\n");
        printf("1. Create SLL of Student Nodes\n");
        printf("2. Display Status\n");
        printf("3. Insert at End\n");
        printf("4. Delete at End\n");
        printf("5. Stack Demo (Insert/Delete Front)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter number of students: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                    start = insertfront();
                break;

            case 2:
                display();
                break;

            case 3:
                start = insertend();
                break;

            case 4:
                start = deleteend();
                break;

            case 5:
                stackdemo();
                break;

            case 6:
                exit(0);

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
}

