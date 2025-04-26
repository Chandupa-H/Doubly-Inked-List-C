#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *createNewNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void travers(struct node *head)
{
    struct node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->next;
        count++;
    }
    printf("\ncount :%d", count);
}

void insert_at_the_beginning(struct node **head)
{
    struct node *ptr = *head;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = 0;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insert_at_the_end(struct node **head)
{
    struct node *ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    ptr->next = newNode;
    newNode->data = 6;
    newNode->prev = ptr;
    newNode->next = NULL;
}

void insert_at(struct node *head, int position)
{
    struct node *ptr = head;
    int count = 1;
    while (count + 1 != position)
    {
        count++;
        ptr = ptr->next;
    }
    printf("ptr:%d", ptr->data);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = 30;
    newNode->prev = ptr;
    ptr->next->prev = newNode;
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void delete_at_the_beginning(struct node **head)
{
    (*head) = (*head)->next;
    (*head)->prev = NULL;
}

void delete_at_the_end(struct node *head)
{
    struct node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = NULL;
}

void delete_at(struct node *head, int position)
{
    struct node *ptr = head;
    int count = 1;
    while (count++ < position)
    {
        ptr = ptr->next;
        count++;
    }
    ptr->next = ptr->next->next;
    ptr->next->next->prev = ptr;
}

void print_backword(struct node *head)
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->prev;
    }
}

void cut_and_insert(struct node **head, int change, int newValue)
{
    struct node *ptr = *head;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = newValue;
    if (change == 1)
    {
        newNode->next = ptr->next;
        ptr->next->prev = newNode;
        (*head) = newNode;
    }
    else if (change > 1)
    {
        while (ptr->next->data != change)
        {
            ptr = ptr->next;
        }
        newNode->next = ptr->next->next;
        ptr->next->next->prev = newNode;
        ptr->next = newNode;
        newNode->prev = ptr;
    }
    else
    {
        printf("Invalid Position Added.");
    }
}

void reverse_the_list(struct node **head)
{
    struct node *ptr1 = *head;
    struct node *ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while (ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    (*head) = ptr1;
}

int main()
{
    struct node p1, p2, p3, p4, p5;
    p1.data = 1;
    p2.data = 2;
    p3.data = 3;
    p4.data = 4;
    p5.data = 5;

    p1.prev = NULL;
    p1.next = &p2;
    p2.prev = &p1;
    p2.next = &p3;
    p3.prev = &p2;
    p3.next = &p4;
    p4.prev = &p3;
    p4.next = &p5;
    p5.prev = &p4;
    p5.next = NULL;

    struct node *head = &p1;

    // createNewNode(3);
    // insert_at_the_beginning(&head);
    // insert_at_the_end(&head);
    // insert_at(head, 4);
    // delete_at_the_beginning(&head);
    // delete_at_the_end(head);
    // delete_at(head, 3);
    // print_backword(head);
    // cut_and_insert(&head, 1, 30);
    reverse_the_list(&head);
    travers(head);
}