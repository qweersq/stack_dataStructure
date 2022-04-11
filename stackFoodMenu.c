#include <stdio.h>
#include <stdlib.h>

struct stack
{
    char nama[50];
    int harga;
    struct stack *next;
};
struct stack *top = NULL;
struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);
void peek(struct stack *);

int main(int argc, char *argv[])
{
    int val, option;
    do
    {
        printf("\n===========================================");
        printf("\n  S T A C K   I M P L E M E N T A T I O N");
        printf("\n             FOOD MENU THEME");
        printf("\n===========================================");
        printf("\n 1. (Push) Tambah Makanan");
        printf("\n 2. (Pop) Hapus makanan teratas");
        printf("\n 3. (Peek) Lihat makanan teratas");
        printf("\n 4. Lihat Menu Makanan");
        printf("\n 5. Keluar");
        printf("\n\n Masukkan pilihanmu : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n Berapa makanan yang ingin ditambahkan : ");
            scanf("%d", &val);
            top = push(top, val);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            peek(top);
        case 4:
            top = display(top);
            break;
        }
    } while (option != 5);
    return 0;
}

struct stack *push(struct stack *top, int val)
{
    struct stack *ptr;
    for (int i = 0; i < val; i++)
    {
        ptr = (struct stack *)malloc(sizeof(struct stack));
        printf("\nNama makanan : ");
        scanf("\n%[^\n]", ptr->nama);
        printf("Harga        : ");
        scanf("%d", &ptr->harga);
        if (top == NULL)
        {
            ptr->next = NULL;
            top = ptr;
        }
        else
        {
            ptr->next = top;
            top = ptr;
        }
    }
    return top;
}
struct stack *display(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if (top == NULL)
        printf("\n STACK IS EMPTY");
    else
    {
        printf("\n-----------------------------------------");
        printf("\n*** List makanan yang ada dalam stack ***");
        printf("\n-----------------------------------------");
        while (ptr != NULL)
        {
            if (ptr == top)
                printf("\ntop--> %-15s Rp.%d", ptr->nama, ptr->harga);
            else
                printf("\n       %-15s Rp.%d", ptr->nama, ptr->harga);
            // printf("%s data tdata", ptr==top?"top->>":"     ",)
            ptr = ptr->next;
        }
        printf("\n-----------------------------------------");
        printf("\n");
    }
    return top;
}
struct stack *pop(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if (top == NULL)
        printf("\nSilakan isi list makanan terlebih dahulu");
    else
    {
        top = top->next;
        printf("\n Makanan \"%s\" dengan harga \"%d\" berhasil dihapus.\n\n", ptr->nama, ptr->harga);
        free(ptr);
    }
    return top;
}
void peek(struct stack *top)
{
    if (top == NULL)
        printf("\nSilakan isi list makanan terlebih dahulu");
    else
        printf("\nList makanan teratas adalah \"%s\" dengan harga \"%d\"\n\n", top->nama, top->harga);
}