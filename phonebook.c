#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define NAME_LEN 50
#define PHONE_LEN 15

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

Contact phoneBook[MAX];
int count = 0;

void sortContacts() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(phoneBook[i].name, phoneBook[j].name) > 0) {
                Contact temp = phoneBook[i];
                phoneBook[i] = phoneBook[j];
                phoneBook[j] = temp;
            }
        }
    }
}

void addContact() {
    if (count >= MAX) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", phoneBook[count].name);
    printf("Enter phone number: ");
    scanf(" %[^\n]", phoneBook[count].phone);
    count++;
    sortContacts();
    printf("Contact added .\n");
}

void displayContacts() {
    if (count == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("\n    Phone Book \n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char searchName[NAME_LEN];
    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < count; i++) {
        if (strcasecmp(phoneBook[i].name, searchName) == 0) {
            printf("Found: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact() {
    char deleteName[NAME_LEN];
    printf("Enter name to delete: ");
    scanf(" %[^\n]", deleteName);

    for (int i = 0; i < count; i++) {
        if (strcasecmp(phoneBook[i].name, deleteName) == 0) {
            for (int j = i; j < count - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            count--;
            printf("Contact deleted .\n");
            return;
        }
    }
    printf("No Contact found.\n");
}

int main() {
    int choice;
    do {
        printf("\n Phone Book  \n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}