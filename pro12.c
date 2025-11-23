#include <stdio.h>
#include <stdlib.h>

int key[20], n, m;
int *ht, index_pos;
int count = 0;

void insert(int k)
{
    index_pos = k % m;

    while (ht[index_pos] != -1) {
        index_pos = (index_pos + 1) % m;
    }

    ht[index_pos] = k;
    count++;
}

void display()
{
    if (count == 0) {
        printf("\nHash Table is empty");
        return;
    }

    printf("\nHash Table contents are:\n");
    for (int i = 0; i < m; i++)
        printf("T[%d] --> %d\n", i, ht[i]);
}

int main()
{
    printf("\nEnter the number of employee records (N): ");
    scanf("%d", &n);

    printf("\nEnter the two-digit memory locations (m) for hash table: ");
    scanf("%d", &m);

    ht = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
        ht[i] = -1;

    printf("\nEnter the four-digit key values (K) for N employee records:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &key[i]);

    for (int i = 0; i < n; i++) {
        if (count == m) {
            printf("\n----- Hash table is full. Cannot insert record %d -----", i + 1);
            break;
        }
        insert(key[i]);
    }

    display();

    return 0;
}

