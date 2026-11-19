#include <stdio.h>
#include <string.h>

typedef struct book {
    int id;
    int price;
    char title[64];
} book_t;

int total_price(book_t book[],int n){
    int sum = 0;
    for (int i=0;i<n;i++){
        sum+=book[i].price;
    }
    printf("total price: %d\n",sum);
}

void book_writefile(book_t book[],int n){
    FILE* fp = fopen("Book.bin", "wb+");
    for (int i=0;i<n;i++){
        fwrite(&book[i], sizeof(book_t), 1, fp);
    }
    fclose(fp);
}

void book_readfile(book_t book[],int n){
    FILE* fp = fopen("Book.bin", "rb");
    int i = 0;
    while (fread(book+i, sizeof(book_t), 1, fp)){
        i++;
    }
    fclose(fp);
    return;
}

void list_book(book_t book) {
    printf("book id = %d\n", book.id);
    printf("book price = %d\n", book.price);
    printf("book title = %s\n\n", book.title);
}

int main(){
    book_t book[6];
    book[0].id = 1;
    book[0].price = 1000;
    strcpy(book[0].title, "All the Light We Cannot See");
    
    book[1].id = 2;
    book[1].price = 300;
    strcpy(book[1].title, "The 38 Letters from J.D. Rockefeller to his son");
    
    book[2].id = 3;
    book[2].price = 1000;
    strcpy(book[2].title, "The Ballad of Songbirds and Snakes");
    
    book[3].id = 4;
    book[3].price = 550;
    strcpy(book[3].title, "Killers of the Flower Moon");
    
    book[4].id = 5;
    book[4].price = 870;
    strcpy(book[4].title, "Elon Musk");
    
    book[5].id = 6;
    book[5].price = 1344;
    strcpy(book[5].title, "Milk and Honey 12-Month 2024");
    
    book_writefile(book, 6);
    book_t read_book[10];
    book_readfile(read_book, 6);
    
    for(int i=0;i<6;i++){
        list_book(book[i]);
    }
    total_price(book, 6);
    return 0;
}
