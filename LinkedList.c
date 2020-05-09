#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"

//Function head
node *createN();
void append(node *p);
int isEmpty(node *p);
void print(node *list);
int lenght(node *p);
node *insertStart(node *list, node *new);
node *insertEnd(node *list, node *new);
node *search(int elt, node *list);
node *pop(int elt, node *list);
node *searchPop(int elt, node *list);
node *searchInsert(int elt, node *list);
node *insert(node *list, node *new);
node *reverse (node * head);


int main (){

    int i, elt;
    node *list = (node *) NULL, *p;
    for (;;)
    {
        printf("\n ***********************************\n");
        printf ("1 : Insert at the Head of the list.\n");
        printf ("2 : Insert at the tail of the list.\n");
        printf ("3 : Print the whole List.\n");
        printf ("4 : Calculate the length of the list.\n");
        printf ("5 : Search of an element in the list.\n");
        printf ("6 : Insert\n");
        printf ("7 : Delete an element of the list.\n");
        printf ("8 : Reverse the linked List.\n");
        printf(" ***********************************\n");
        scanf("%d", &i);

        switch (i)
        {
            case 1: p = createN(); append(p);
                    list = insertStart(list, p); 
                    break;
            case 2: p = createN(); append(p);
                    list = insertEnd(list, p);
                    break;
            case 3: print(list);
            case 4: printf ("Length : %d\n", lenght(list));
                    break;
            case 5: printf ("Element : "); scanf("%d", &elt);
                    printf ("%d %p\n", elt, search(elt, list));
                    break;
            case 6: p = createN(); append(p);
                    list = insert(list, p);
                    break;
            case 7: printf ("Element to delete : ");
                    scanf("%d",&elt);
                    list = pop(elt, list);
                    break;
            case 8: printf("Reversed\n");
                    node *rev = reverse(list);
                    print(rev);
                    break;
            default: exit(0); 
        }
    }
}


node *createN()
{
    node *p;
    p = (node *) malloc (sizeof(node));
    p->next = NULL;
    return p;
}

void append(node *p)
{
    int value;
    printf ("Int : "); scanf("%d", &value);
    p->data = value;
}

int isEmpty(node *p)
{
    return p == NULL;
}

void print(node *list)
{
    node *p = list;
    while (p != NULL)
    {
        printf ("%d->", p->data);
        p = p->next;
    }
    printf("NULL");
    printf("\n");
}

int lenght(node *p)
{
    node *q = p;
    int count = 0;
    while (q != NULL)
    {
        count++;
        q = q->next;
    }
    return count;
}

node *insertStart(node *list, node *new)
{
    new->next = list;
    list = new;
    return list;
}

node *insertEnd(node *list, node *new)
{
    if (isEmpty(list))
    {
        list = new;
    }
    else
    {
        node *q = list;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = new;
    }
    return list;
}

node *search(int elt, node *list)
{
    node *p = list;
    while ((p != NULL) && (p->data != elt))
    {
        p = p->next;
    }
    if (p == NULL) return NULL;
    return p;
}

node *pop(int elt, node *list)
{
    node *pp, *p;
    if (list == NULL) return NULL;
    if (list->data == elt)
    {
        p = list;
        list = list->next;
        free(p);
        return list;
    }
    if((pp = searchPop(elt, list))->next == NULL)
    {
        printf("Not Found\n");
    }
    else
    {
        p = pp->next;
        pp->next = p->next;
        free(p);
        return list;
    }
}

node *searchPop(int elt, node *list)
{
    node *p = list, *pp = NULL;
    while ((p != NULL) && (p->data != elt))
    {
        pp = p;
        p = p->next;
    }
    return pp;
}

node *searchInsert(int elt, node *list)
{
    if ((list == NULL) || (list->data > elt)) return NULL;
    node *pp = list, *p = list->next;
    while ((p != NULL) && (p->data <= elt))
    {
        pp = p;
        p = p->next;
    }    
    return pp;
}

node *insert(node *list, node *new)
{
    node *p, *pp;
    if (new == NULL) return list;
    pp = searchInsert(new->data,list);
    p = list;
    if ((p == NULL) || (pp == NULL)) list = insertStart(list, new);
    else
    {
        new->next = pp->next;
        pp->next = new;
    }
    return list;
}

node *reverse (node * head)
{
    node *p, *pp = NULL;
    p = head;
    while (p != NULL){
        node *temp = p->next;
        p->next = pp;
        pp = p;
        p = temp;
    }
    return pp;
}