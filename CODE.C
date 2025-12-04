#include <stdio.h>

struct Book {
    int id;
    char title[50];
    float price;
};

int main() {
    int n, i, j;
    struct Book temp;

    printf("Enter number of books: ");
    scanf("%d", &n);

    struct Book books[n];

    for (i = 0; i < n; i++) {
        printf("\nENTER DETAILS OF BOOK %d:\n", i + 1);

        printf("Book ID: ");
        scanf("%d", &books[i].id);

        printf("Book Title: ");
        scanf(" %[^\n]", books[i].title);   
        printf("Book Price: \n");
        scanf("%f", &books[i].price);
    }

   
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (books[i].price < books[j].price) {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;  // Added this line to complete the swap
            }
        }
    }

    printf("\nBOOKS SORTED BY PRICE (High to Low):\n");
    printf("ID\tTitle\t\tPrice\n");
    printf("---------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%-15s\t%.2f\n", books[i].id, books[i].title, books[i].price);
    }

    return 0;
}

