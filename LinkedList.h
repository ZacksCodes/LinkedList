#include <stdio.h>

// Our Node Structure
typedef struct node
{
    int data;
    struct node *next;
}node;

/*Function to create/initialize a node.
 *Time = O(1) ; Space = O(1)
 *Return : &head of the list
 */
node *createN();

/*Function to add/append a node.
 *Time = O(1) ; Space = O(1)
 *Return : nothing
 */
void append(node *p);

/*Function to check if a node is empty
 *Time = O(1) ; Space = O(1)
 *Return : 1 if TRUE, 0 if FALSE
 */
int isEmpty(node *p);

/*Function to print the whole List.
 *Time = O(n) ; Space = O(1)
 *Return : Nothing but print the elements.
 */
void print(node *list);

/*Function to calculate the length of the list.
 *Time = O(n) ; Space = O(1)
 *Return : a integer lenght
 */
int lenght(node *p);

/*Function to insert a node in the head.
 *Time = O(1) ; Space = O(1)
 *Return : &Head
 */
node *insertStart(node *list, node *new);

/*Function to insert a node in at the tail.
 *Time = O(n) ; Space = O(1)
 *Return : &Tail
 */
node *insertEnd(node *list, node *new);

/*Function to search for an element in the list.
 *Time = O(n) ; Space = O(1)
 *Return : &element
 */
node *search(int elt, node *list);

/*Function to pop/delete an element in the list.
 *Time = O(n) ; Space = O(1)
 *Return : &of the next element in list
 */
node *pop(int elt, node *list);

/*Function to search for an element in the list.
 *Time = O(n) ; Space = O(1)
 *Return : &element
 */
node *searchPop(int elt, node *list);

/*Function to search for an element in the list.
 *Time = O(n) ; Space = O(1)
 *Return : &element
 */
node *searchInsert(int elt, node *list);

/*Function to insert a node in a linked list.
 *Time = O(n) ; Space = O(1)
 *Return : &element
 */
node *insert(node *list, node *new);