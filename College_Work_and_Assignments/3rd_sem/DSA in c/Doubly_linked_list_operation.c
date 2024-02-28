#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;  };
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;     }
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;     }
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return head;    }
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;        }
        return newNode;     }
    struct Node* current = head;
    int currentPos = 1;
    while (currentPos < position - 1 && current != NULL) {
        current = current->next;
        currentPos++;    }
    if (current == NULL) {
        printf("Invalid position\n");
        return head;    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;    }
    current->next = newNode;
    return head;    }
struct Node* insertAfterNode(struct Node* head, int data, int key) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            newNode->next = current->next;
            if (current->next != NULL) {
                current->next->prev = newNode;            }
            current->next = newNode;
            newNode->prev = current;
            return head;        }
        current = current->next;    }
    printf("Node with key %d not found\n", key);
    return head;        }
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;    }
    current->next = newNode;
    newNode->prev = current;
    return head;        }
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;    }
    struct Node* newHead = head->next;
    free(head);
    if (newHead != NULL) {
        newHead->prev = NULL;    }
    return newHead;     }
struct Node* deleteFromPosition(struct Node* head, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return head;    }
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;    }
    if (position == 1) {
        struct Node* newHead = head->next;
        free(head);
        if (newHead != NULL) {
            newHead->prev = NULL;        }
        return newHead;    }
    struct Node* current = head;
    int currentPos = 1;
    while (currentPos < position && current != NULL) {
        current = current->next;
        currentPos++;    }
    if (current == NULL) {
        printf("Invalid position\n");
        return head;    }
    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;    }
    free(current);
    return head;        }
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;    }
    if (head->next == NULL) {
        free(head);
        return NULL;    }
    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;    }
    free(current->next);
    current->next = NULL;
    return head;}
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;    }
    printf("NULL\n");       }
int main() {
    struct Node* head = NULL;
    int choice, data, position, key;
    while (1) {
        printf("\nDoubly Linked List Operations\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at a specific position\n");
        printf("3. Insert after a specific node\n");
        printf("4. Insert at the end\n");
        printf("5. Delete from the beginning\n");
        printf("6. Delete from a specific position\n");
        printf("7. Delete from the end\n");
        printf("8. Display the nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the key value after which to insert: ");
                scanf("%d", &key);
                head = insertAfterNode(head, data, key);
                break;
            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 5:
                head = deleteFromBeginning(head);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;
            case 7:
                head = deleteFromEnd(head);
                break;
            case 8:
                display(head);
                break;
            case 9:
                // Exit the program
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }    }
    return 0;
}