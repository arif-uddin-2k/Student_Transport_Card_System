#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the transport card
typedef struct TransportCard {
    char stu_name[30];
    char stu_id[15];
    char department[5];
    char access_semester[15];
    char access_road[20];
    float payment_due;
    struct TransportCard* next;
} TransportCard;

//define all the function here
TransportCard* createTransportCard(TransportCard *head);
TransportCard* searchTransportCard(TransportCard* head, char targetID[15]);
TransportCard* deleteTransportCard(TransportCard* head, char targetID[15]);
void updateTransportCard(TransportCard* card);
void displayTransportCard(TransportCard* card);
void displayAllTransportCards(TransportCard* head);
void selectAccessRoad(TransportCard* card);
void renewTransportCard(TransportCard* card);
void freeTransportCards(TransportCard* head);

int main() {
    //pre-compute two Transport Card to get instant data
    TransportCard* card = (TransportCard*)malloc(sizeof(TransportCard));
    strcpy(card->stu_name, "Arif Uddin");
    strcpy(card->stu_id, "221-15-5017");
    strcpy(card->department, "CSE");
    strcpy(card->access_semester, "Fall-2023");
    strcpy(card->access_road, "Dhanmondi");
    card->payment_due = 0.00;
    card->next = NULL;

    TransportCard* card1 = (TransportCard*)malloc(sizeof(TransportCard));
    strcpy(card1->stu_name, "Arfan Uddin");
    strcpy(card1->stu_id, "221-35-888");
    strcpy(card1->department, "SWE");
    strcpy(card1->access_semester, "Fall-2023");
    strcpy(card1->access_road, "ECB");
    card1->payment_due = 4500;
    card1->next = card;
    
    TransportCard* head = card1;
    int choice;
    char targetID[15];

    do {
        printf("\n<<---------- Student Transport Card System ---------->>\n\n");
        printf("\t1. Create a new Transport Card\n");
        printf("\t2. Update a new Transport Card\n");
        printf("\t3. Search a Transport Card\n");
        printf("\t4. Delete a Transport Card\n");
        printf("\t5. Display all Transport Card\n");
        printf("\t6. Renew a Transport Card\n");
        printf("\t7. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createTransportCard(head);
                break;
            case 2:
                fflush(stdin);
                printf("\nEnter Student ID to update Transport Card: ");
                fgets(targetID, sizeof(targetID), stdin);
                targetID[strcspn(targetID, "\n")] = '\0';
                TransportCard* cardToUpdate = searchTransportCard(head, targetID);
                if (cardToUpdate != NULL) {
                    updateTransportCard(cardToUpdate);
                } else {
                    printf("\nTransport Card not found!\n");
                }
                break;
            case 3:
                fflush(stdin);
                printf("\nEnter Student ID to search Transport Card: ");
                fgets(targetID, sizeof(targetID), stdin);
                targetID[strcspn(targetID, "\n")] = '\0';
                TransportCard* cardToSearch = searchTransportCard(head, targetID);
                if (cardToSearch != NULL) {
                    displayTransportCard(cardToSearch);
                } else {
                    printf("\nTransport Card not found!\n");
                }
                break;
            case 4:
                fflush(stdin);
                printf("\nEnter Student ID to delete Transport Card: ");
                fgets(targetID, sizeof(targetID), stdin);
                targetID[strcspn(targetID, "\n")] = '\0';
                head = deleteTransportCard(head, targetID);
                break;
            case 5:
                displayAllTransportCards(head);
                break;
            case 6:
                fflush(stdin);
                printf("\nEnter Student ID to renew Transport Card: ");
                fgets(targetID, sizeof(targetID), stdin);
                targetID[strcspn(targetID, "\n")] = '\0';
                TransportCard* cardToRenew = searchTransportCard(head, targetID);
                if (cardToRenew != NULL) {
                    renewTransportCard(cardToRenew);
                } else {
                    printf("\nTransport Card not found!\n");
                }
                break;
            case 7:
                freeTransportCards(head);
                printf("\nExiting program. Memory freed.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}

// Function to create a new transport card
TransportCard* createTransportCard(TransportCard *head) {
    TransportCard* newCard = (TransportCard*)malloc(sizeof(TransportCard));
    
    fflush(stdin);
    printf("\tEnter Student Name: ");
    fgets(newCard->stu_name, sizeof(newCard->stu_name), stdin);
    newCard->stu_name[strcspn(newCard->stu_name, "\n")] = '\0';
    
    fflush(stdin);
    printf("\tEnter Student ID: ");
    fgets(newCard->stu_id, sizeof(newCard->stu_id), stdin);
    newCard->stu_id[strcspn(newCard->stu_id, "\n")] = '\0';
    
    fflush(stdin);
    printf("\tEnter Department: ");
    fgets(newCard->department, sizeof(newCard->department), stdin);
    newCard->department[strcspn(newCard->department, "\n")] = '\0';
    
    fflush(stdin);
    printf("\tEnter Access Semester: ");
    fgets(newCard->access_semester, sizeof(newCard->access_semester), stdin);
    newCard->access_semester[strcspn(newCard->access_semester, "\n")] = '\0';

    selectAccessRoad(newCard);
    
    newCard->next = NULL;

    if (head == NULL) {
        head = newCard;
    } else {
        newCard->next = head;
        head = newCard;
    }
    
    printf("Transport Card created successfully!\n");
    return head;
}

//Function to select access road
void selectAccessRoad(TransportCard* card){
    int choice;
    do{
        fflush(stdin);
        printf("\nAvailable Transport Road: \n");
        printf("\t1. Dhanmondi\n");
        printf("\t2. Narayanganj\n");
        printf("\t3. Uttara\n");
        printf("\t4. Tongi\n");
        printf("\t5. ECB\n");
        printf("\t6. Mirpur\n");
        printf("\t7. Savar\n");
        printf("\t8. Baipal\n");
        printf("\t9. Mugdha\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
            {
            case 1:
                strcpy(card->access_road, "Dhanmondi");
                card->payment_due = 4000;
                break;
            case 2:
                strcpy(card->access_road, "Narayanganj");
                card->payment_due = 5000;
                break;
            case 3:
                strcpy(card->access_road, "Uttara");
                card->payment_due = 4000;
                break;
            case 4: 
                strcpy(card->access_road, "Tongi");
                card->payment_due = 4000;
                break;
            case 5:
                strcpy(card->access_road, "ECB");
                card->payment_due = 4500;
                break;
            case 6:
                strcpy(card->access_road, "Mirpur");
                card->payment_due = 4000;
                break;
            case 7:
                strcpy(card->access_road, "Savar");
                card->payment_due = 4000;
                break;
            case 8:
                strcpy(card->access_road, "Baipal");
                card->payment_due = 5000;
                break;
            case 9:
                strcpy(card->access_road, "Mugdha");
                card->payment_due = 5000;
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }while(choice < 1 || choice > 9);
}

// Function to display a transport card
void displayTransportCard(TransportCard* card) {
    printf("\n-------------------------------------------------------\n");
    printf("\n\tStudent Name : %s\n", card->stu_name);
    printf("\tStudent ID : %s\n", card->stu_id);
    printf("\tDepartment : %s\n", card->department);
    printf("\tAccess Semester : %s\n", card->access_semester);
    printf("\tAccess Road : %s\n", card->access_road);
    printf("\tPayment Due : %.2f\n", card->payment_due);
}

// Function to search for a transport card by student ID
TransportCard* searchTransportCard(TransportCard* head, char targetID[15]) {
    TransportCard* current = head;
    
    while (current != NULL) {
        if (strcmp(current->stu_id, targetID) == 0) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}

// Function to update a transport card
void updateTransportCard(TransportCard* card) {
    int choice;
    do{
        printf("\t1. Update Student Name\n");
        printf("\t2. Update Student Department\n");
        printf("\t3. Go Back\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                fflush(stdin);
                printf("\tEnter New Student Name: ");
                fgets(card->stu_name, sizeof(card->stu_name), stdin);
                card->stu_name[strcspn(card->stu_name, "\n")] = '\0';
                printf("\nStudent Name updated successfully.\n");
                break;
            case 2:
                fflush(stdin);
                printf("\tEnter New Student Department: ");
                fgets(card->stu_name, sizeof(card->stu_name), stdin);
                card->stu_name[strcspn(card->stu_name, "\n")] = '\0';
                printf("\nStudent Department updated successfully.\n");
                break;
            case 3:
                printf("\nReturnig to main menu.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }while(choice != 3);
}

// Function to delete a transport card
TransportCard* deleteTransportCard(TransportCard* head, char targetID[15]) {
    TransportCard* current = head;
    TransportCard* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->stu_id, targetID) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("\nTransport Card deleted successfully!\n");
            return head;
        }
        prev = current;
        current = current->next;
    }

    printf("\nTransport Card not found!\n");
    return head;
}

// Function to renew a transport card when payment due is zero
void renewTransportCard(TransportCard* card) {
    if (card->payment_due == 0.00) {
        // Implement logic for renewing the card
        selectAccessRoad(card);
        printf("\nTransport Card renewed successfully!\n");
    } else {
        printf("\nYou have %.2fTk  of payment due. Cannot renew the Transport Card.\n", card->payment_due);
    }
}

// Function to display all transport cards in the linked list
void displayAllTransportCards(TransportCard* head) {

    TransportCard* current = head;
    
    if (current == NULL) {
        printf("\nNo Transport Cards found.\n");
        return;
    }

    while (current != NULL) {
        displayTransportCard(current);
        current = current->next;
    }
}
// Function to free memory allocated for the linked list

//Function to free all memory when exit
void freeTransportCards(TransportCard* head) {
    TransportCard* current = head;
    TransportCard* next;

    while (current != NULL) {
        next = current;
        current = current->next;
        free(next);
    }
}

