#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[50];
    char phone[15];
    struct Contact* next;
} Contact;

Contact* head = NULL;

// Function to create a new contact node
Contact* createContact(char name[], char phone[]) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;
    return newContact;
}

// Add contact
void addContact(char name[], char phone[]) {
    Contact* newContact = createContact(name, phone);
    if (head == NULL) {
        head = newContact;
    } else {
        Contact* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newContact;
    }
    printf("Contact added successfully!\n");
}

// Display all contacts
void displayContacts() {
    if (head == NULL) {
        printf("No contacts found.\n");
        return;
    }
    Contact* temp = head;
    while (temp != NULL) {
        printf("Name: %s, Phone: %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

// Search contact by name
void searchContact(char name[]) {
    Contact* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Contact found: %s - %s\n", temp->name, temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("Contact not found.\n");
}

// Delete contact by name
void deleteContact(char name[]) {
    Contact *temp = head, *prev = NULL;
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Contact not found.\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Contact deleted.\n");
}

int main() {
    int choice;
    char name[50], phone[15];

    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter phone: ");
                fgets(phone, 15, stdin);
                phone[strcspn(phone, "\n")] = '\0';
                addContact(name, phone);
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                printf("Enter name to search: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0';
                searchContact(name);
                break;
            case 4:
                printf("Enter name to delete: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0';
                deleteContact(name);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
