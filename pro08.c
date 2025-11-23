#include<stdio.h>
#include<stdlib.h>

struct node
{
    char ssn[25], name[25], dept[10], designation[25];
    int sal;
    long int phone;
    struct node *llink;
    struct node *rlink;
};
typedef struct node * NODE;

NODE first = NULL;
int count = 0;

NODE create()
{
    NODE enode = (NODE)malloc(sizeof(struct node));
    if (enode == NULL)
    {
        printf("\nRunning out of memory");
        exit(0);
    }

    printf("\nEnter SSN: ");
    scanf("%s", enode->ssn);

    printf("Enter Name: ");
    scanf("%s", enode->name);

    printf("Enter Department: ");
    scanf("%s", enode->dept);

    printf("Enter Designation: ");
    scanf("%s", enode->designation);

    printf("Enter Salary: ");
    scanf("%d", &enode->sal);

    printf("Enter Phone Number: ");
    scanf("%ld", &enode->phone);

    enode->llink = NULL;
    enode->rlink = NULL;

    count++;
    return enode;
}

NODE insertfront()
{
    NODE temp = create();

    if (first == NULL)
        return temp;

    temp->rlink = first;
    first->llink = temp;

    return temp;
}

NODE insertend()
{
    NODE temp = create();

    if (first == NULL)
        return temp;

    NODE cur = first;
    while (cur->rlink != NULL)
        cur = cur->rlink;

    cur->rlink = temp;
    temp->llink = cur;

    return first;
}

NODE deletefront()
{
    if (first == NULL)
    {
        printf("\nDLL is empty");
        return NULL;
    }

    NODE temp = first;

    if (first->rlink == NULL)   // only one node
    {
        printf("\nDeleted Employee SSN: %s", first->ssn);
        free(first);
        count--;
        return NULL;
    }

    first = first->rlink;
    first->llink = NULL;

    printf("\nDeleted Employee SSN: %s", temp->ssn);
    free(temp);
    count--;

    return first;
}

NODE deleteend()
{
    if (first == NULL)
    {
        printf("\nDLL is empty");
        return NULL;
    }

    if (first->rlink == NULL)   // only 1 node
    {
        printf("\nDeleted Employee SSN: %s", first->ssn);
        free(first);
        count--;
        return NULL;
    }

    NODE cur = first;
    while (cur->rlink != NULL)
        cur = cur->rlink;

    printf("\nDeleted Employee SSN: %s", cur->ssn);

    cur->llink->rlink = NULL;
    free(cur);
    count--;

    return first;
}

void display()
{
    NODE cur = first;

    if (cur == NULL)
    {
        printf("\nNo contents to display in DLL\n");
        return;
    }

    int nodeno = 1;
    printf("\nEmployee DLL contents:\n");

    while (cur != NULL)
    {
        printf("\nNode:%d | SSN:%s | Name:%s | Dept:%s | Desig:%s | Salary:%d | Phone:%ld",
               nodeno, cur->ssn, cur->name, cur->dept,
               cur->designation, cur->sal, cur->phone);

        cur = cur->rlink;
        nodeno++;
    }

    printf("\nTotal Employees = %d\n", count);
}

void deqdemo()
{
    int ch;
    while (1)
    {
        printf("\n--- Double Ended Queue Demo ---\n");
        printf("1. Insert Front\n2. Delete Front\n3. Insert Rear\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: first = insertfront(); break;
            case 2: first = deletefront(); break;
            case 3: first = insertend(); break;
            case 4: first = deleteend(); break;
            case 5: display(); break;
            default: return;
        }
    }
}

int main()
{
    int ch, n, i;

    while (1)
    {
        printf("\n--------- MENU ---------\n");
        printf("1. Create DLL\n");
        printf("2. Display DLL\n");
        printf("3. Insert End\n");
        printf("4. Delete End\n");
        printf("5. Insert Front\n");
        printf("6. Delete Front\n");
        printf("7. Deque Demo\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("\nEnter no of employees: ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++)
                    first = insertend();
                break;

            case 2: display(); break;
            case 3: first = insertend(); break;
            case 4: first = deleteend(); break;
            case 5: first = insertfront(); break;
            case 6: first = deletefront(); break;
            case 7: deqdemo(); break;
            case 8: exit(0);

            default:
                printf("\nInvalid choice\n");
        }
    }
}

