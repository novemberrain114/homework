#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;  // 原为 struct node *next; 大小写错误
} Node;

Node* creatnode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (newnode == NULL) {
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

Node* createhead() {
    Node* newnode = creatnode(0);
    return newnode;
}

void addfirst(Node **head, int data) {
    Node* newnode = creatnode(data);
    newnode->next = (*head)->next;
    (*head)->next = newnode;
}

void addtail(Node **head, int data) {
    Node* newnode = creatnode(data);
    Node* cur = *head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newnode;
}

void add(Node **head, int data, int pos) {
    if (pos == 0) {
        addfirst(head, data);
    }
    else {
        Node* newnode = creatnode(data);
        Node* cur = *head;
        int i = 0;
        while (i < pos) {
            cur = cur->next;
            if (cur == NULL) {
                return;
            }
            i++;
        }
        newnode->next = cur->next;
        cur->next = newnode;
    }
}


bool findnode(Node **head, int pos) {
    Node* cur = *head;
    int i = 0;
    while (i < pos) {
        cur = cur->next;
        if (cur == NULL) {
            return false;
        }
        i++;
    }
    printf("pos=%d,data=%d", pos, cur->data);
    return true;
}

bool delfirst(Node **head) {
    Node* cur = *head;
    if (cur->next == NULL) {
        return false;
    }
    cur = cur->next;
    (*head)->next = cur->next;
    cur->next = NULL;
    free(cur);
    return true;
}

bool deltail(Node **head) {
    Node* cur = *head;
    if (cur->next == NULL) {
        return false;
    }
    while ((cur->next)->next != NULL) {
        cur = cur->next;
    }
    Node* target = cur->next;
    cur->next = NULL;
    free(target);
    return true;
}

bool del(Node **head, int pos) {
    Node* cur = *head;
    if (cur->next == NULL) {
        return false;
    }
    int i = 0;
    while (i < pos - 1) {
        cur = cur->next;
        if (cur == NULL) {
            return false;
        }
        i++;
    }
    Node* target = cur->next;
    cur->next = target->next;
    target->next = NULL;
    free(target);
    return true;
}

bool changenode(Node **head, int pos, int data) {
    Node* cur = *head;
    if (cur->next == NULL) {
        return false;
    }
    int i = 0;
    while (i < pos) {
        cur = cur->next;
        if (cur == NULL) {
            return false;
        }
        i++;
    }
    cur->data = data;
    return true;
}

void turnaround(Node **head) {
    if ((*head)->next == NULL) {
        return;
    }
    Node* first = (*head)->next;
    (*head)->next = NULL;
    Node* cur = first;
    Node* turn = *head;
    while (first->next != NULL) {
        while ((cur->next)->next != NULL) {
            cur = cur->next;
        }
        Node* target = cur->next;
        cur->next = NULL;
        turn->next = target;
        turn = turn->next;
        cur = first;
    }
    turn->next = first;
}