#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define a symbol table entry structure
typedef struct Symbol {
    char name[50];
    char type[20];
    int size;
    struct Symbol* next;
} Symbol;
Symbol* head = NULL; // Head of the symbol table
// Insert a symbol
void insertSymbol(char* name, char* type, int size) {
    Symbol* newSymbol = (Symbol*)malloc(sizeof(Symbol));
    strcpy(newSymbol->name, name);
    strcpy(newSymbol->type, type);
    newSymbol->size = size;
    newSymbol->next = head;
    head = newSymbol;
    printf("Inserted: %s\n", name);
}
// Search for a symbol
Symbol* searchSymbol(char* name) {
    Symbol* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}
// Modify a symbol
void modifySymbol(char* name, char* newType, int newSize) {
    Symbol* sym = searchSymbol(name);
    if (sym) {
        strcpy(sym->type, newType);
        sym->size = newSize;
        printf("Modified: %s\n", name);
    } else {
        printf("Symbol not found.\n");
    }
}
// Delete a symbol
void deleteSymbol(char* name) {
    Symbol **temp = &head, *toDelete;
    while (*temp && strcmp((*temp)->name, name) != 0) temp = &(*temp)->next;
    if (*temp) {
        toDelete = *temp;
        *temp = (*temp)->next;
        free(toDelete);
        printf("Deleted: %s\n", name);
    } else {
        printf("Symbol not found.\n");
    }
}
// Display the symbol table
void displaySymbols() {
    Symbol* temp = head;
    printf("\nSymbol Table:\nName\tType\tSize\n");
    while (temp) {
        printf("%s\t%s\t%d\n", temp->name, temp->type, temp->size);
        temp = temp->next;
    }
}
int main() {
    int choice;
    char name[50], type[20];
    int size;
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Modify\n4. Delete\n5. Display\n6. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 6) break;
        switch (choice) {
            case 1:
                printf("Enter name, type, size: ");
                scanf("%s %s %d", name, type, &size);
                insertSymbol(name, type, size);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                Symbol* sym = searchSymbol(name);
                if (sym) printf("Found: %s\t%s\t%d\n", sym->name, sym->type, sym->size);
                else printf("Not found.\n");
                break;
            case 3:
                printf("Enter name, new type, new size: ");
                scanf("%s %s %d", name, type, &size);
                modifySymbol(name, type, size);
                break;
            case 4:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteSymbol(name);
                break;
            case 5:
                displaySymbols();
                break;
            default:
                printf("Invalid choice.\n");
        }    }
    return 0;
}