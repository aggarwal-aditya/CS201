/*
 * Name:Aditya Aggarwal
 * Entry Number: 2020CSB1066
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int key;
    struct node *next;
} node;

void addElement(node *pNode, int i) {
    node *temp = (node *) malloc(sizeof(node));
    temp->key = i;
    pNode->next = temp;
}

bool detectCycle(node *head) {
    node *ptr = head;
    while (ptr != NULL && head != NULL) {
        if (ptr->next == NULL)
            return false;
        ptr = ptr->next->next;
        head = head->next;
        if (ptr == head) {
            return true;
            break;
        }
    }
    return false;
}

void detectFindStart(node *head) {
    if (!(detectCycle(head))) {
        printf("\nThere exists no cycle in the list\n");
        return;
    }
    node *slow = head;
    node *fast = head;
    while (slow != NULL && fast != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    slow = head;
    int count = 0;
    while (slow != fast) {
        count++;
        slow = slow->next;
        fast = fast->next;
    }
    int len = 1;
    slow = slow->next;
    while (slow != fast) {
        len++;
        slow = slow->next;
    }
    printf("\n\tThe list has a cycle of length: %d\n\tDistance of stating node of cycle from the head node is: %d\n",
           len, count);

}

node *makeListNoCycle(int x) {
    node *head = (node *) malloc(sizeof(node));;
    head->key = 1;
    node *ptr = head;
    for (int i = 1; i <= x; i++) {
        addElement(ptr, i + 1);
        ptr = ptr->next;
    }
    ptr->next = NULL;
    return head;
}

node *makeListCycle(int l, int x) {
    if (l < 1) {
        printf("\nInvalid Input:Cycle Should have atleast one element\n");
        return NULL;
    }
    node *head = (node *) malloc(sizeof(node));
    head->key = 1;
    node *ptr = head;
    for (int i = 1; i <= x; i++) {
        addElement(ptr, i + 1);
        ptr = ptr->next;
    }
    x = x + 2;
    node *ptr_copy = ptr;
    for (int i = 0; i < l - 1; i++) {
        addElement(ptr, (x));
        x++;
        ptr = ptr->next;
    }
    ptr->next = ptr_copy;
    return head;

}

int main() {
    printf("Press Y for linked list with a cycle and N for without cycles:");
    char inp;
    scanf("%c", &inp);
    node *head;
    if (inp == 'N') {
        printf("Enter the size (number of edges) of linked list without cycle:");
        int x;
        scanf("%d", &x);
        head = makeListNoCycle(x);
    } else {
        printf("Enter the length of cycle in the linked list:");
        int l;
        scanf("%d", &l);
        printf("Enter the distance (number of edges) of the start node of the cycle from the head of the linked list:");
        int x;
        scanf("%d", &x);
        head = makeListCycle(l, x);
        if (head == NULL)
            return 0;
    }
    int input;
    do {
        printf("\n*****MENU*****");
        printf("\n 1. Detect Cycle");
        printf("\n 2. Find Start and length of Cycle");
        printf("\n 3. EXIT");
        printf("\n Enter your choice");
        scanf("%d", &input);
        //We use a switch condition here to perform action according to use input
        switch (input) {
            case 1:
                if (detectCycle(head))
                    printf("\nThere exists a cycle in the list. Please enter '2' to find the length and start of the cycle\n");
                else
                    printf("\nThere exists no cycle in the linked list\n");
                break;
            case 2:
                detectFindStart(head);
                break;
            case 3:
                return 0;
            default:
                printf("\nNot a valid option\n");
        }
    } while (input != 3);


}
/*
    Working of Detect Cycle Function
    0)The function generates two copies of the head pointer to the linked list
    1)One of the pointer slow traverses as slow=slow->next and the fast pointer moves as fast=fast->next->next
    2)i.e. the fast pinter visits only alternate elements in the linked list after each iteration.
    3)If the linked list contains no cycle then the fast pointer will point ot NULL after some number of iterations and we will return false;
    4)If the linked list contains a cycle the fast pointer and slow pointer, once they enter the cycle will keep moving in the cycle and never get of it.
    5)So now we check if the fast pointer at any iteration becomes equal to slow pointer, this indicates a cycle is present.

    Why this Algorithm works?
    If a linked list does not contain any cycle then eventually the pointer will reach NULL and we return false in any such case when NULL is encountered.
    If a linked list contains a cycle then the fast pointer and slow pointer keep travelling the cycle, this can be compared to two athletes running on a circular track one with twice the speed of other, after some time (iterations in code) both will meet at some point due to the circular nature of path hence we detect a cycle whenever two pointers are equal.



    Working of Detect Find Start function
    0)We first like detect cycle take two pointers and move them as described above till they become equal
    1)Now we set one of the pointers equal to head of list and move both pointers one element at a time.
    2) Now when they again intersect this indicates the location of node from where linked list begins.
    3)We can find this nodes distance from head node by iteration and we can find size of cycle by keeping one pointer at starting node of cycle and move the other one element at a time till they become equal again


    Why this algorithm works?
    0)Let the point where both pointers meet for the first time be x.
    1)Let y be the node where the cycle starts
    2)Let z be the head of linked list.
    3)Then the number of nodes between x and y is equal to the number of nodes between y and z
    4)That is why when we set the first pointer to head in step (1) and travel the two pointers meet at the node where the cycle begins.

    Why (3) is true
    This is a very clear observation when we take examples and check.
    A proof can also be done for the same as below


    Let distance travelled by slow pointer be 'a' and then distance travelled by fast pointer be '2a'
    let d be the distance between head node and node where cycle begins
    let b be the anticlockwise distance between node where cycles begins and where the two pointers meet for the first time
    let b' be the clockwise distance between node where cycles begins and where the two pointers meet for the first time
   We need to show d=b'
   a=d+b
   2a=d+b+b'+b
   from above two eqns we have d=b'
   hence our claim is true;
 */
