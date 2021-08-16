
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct term {
    int coeff;
    int power;
    struct term *next;
} term;


void createTerm(int x, int y, term **ptr) {
    term *r;
    term *temp = *ptr;
    if (temp == NULL) {
        r = (term *) malloc(sizeof(term));
        r->coeff = x;
        r->power = y;
        r->next = NULL;
        *ptr = r;
    } else {
        r = (term *) malloc(sizeof(term));
        r->coeff = x;
        r->power = y;
        r->next = NULL;
        (*ptr)->next = r;
        *ptr = r;
    }

};

void printTerms(term *head) {
    while (head != NULL) {
        printf("%dx^%d ", head->coeff, head->power);
        if (head->next != NULL && head->next->coeff >= 0)
            printf(" + ");
        head = head->next;
    }
}

void swap(term *a, term *b) {
    int temp = a->power;
    int temp2 = a->coeff;
    a->power = b->power;
    a->coeff = b->coeff;
    b->power = temp;
    b->coeff = temp2;
}

void sort(term *start) {
    int swapped;
    term *itr1;
    term *itr2 = NULL;
    if (start == NULL)
        return;
    do {
        swapped = 0;
        itr1 = start;

        while (itr1->next->next != itr2) {
            if (itr1->power < itr1->next->power) {
                swap(itr1, itr1->next);
                swapped = 1;
            }
            itr1 = itr1->next;
        }
        itr2 = itr1;
    } while (swapped);
}

term *prodTwoPolynomial(term *itr1, term *itr2, term **result) {
    term *send;
    term *itr2_copy = itr2;
    for (itr1; itr1 != NULL; itr1 = itr1->next) {
        for (itr2; itr2 != NULL; itr2 = itr2->next) {
            if (*result == NULL) {
                (*result) = (term *) malloc(sizeof(term));
                send = (*result);
            }
            (*result)->power = (itr1->power) + (itr2->power);
            (*result)->coeff = (itr1->coeff) * (itr2->coeff);
            (*result)->next = (term *) malloc(sizeof(term));
            (*result) = (*result)->next;
            (*result)->next = NULL;
        }
        itr2 = itr2_copy;
    }

    return send;
}

term *addTwoPolynomial(term *itr1, term *itr2, term **result) {
    term *send;
    while (itr1 != NULL && itr2 != NULL) {
        if (*result == NULL) {
            (*result) = (term *) malloc(sizeof(term));
            send = (*result);
        }
        if (itr1->power == itr2->power) {
            (*result)->power = itr1->power;
            (*result)->coeff = itr1->coeff + itr2->coeff;
            itr1 = itr1->next;
            itr2 = itr2->next;
        } else if (itr1->power > itr2->power) {
            (*result)->power = itr1->power;
            (*result)->coeff = itr1->coeff;
            itr1 = itr1->next;
        } else {
            (*result)->power = itr2->power;
            (*result)->coeff = itr2->coeff;
            itr2 = itr2->next;

        }
        (*result)->next = (term *) malloc(sizeof(term));
        (*result) = (*result)->next;
        (*result)->next = NULL;


    }
    while (itr1 != NULL) {
        (*result)->coeff = itr1->coeff;
        (*result)->power = itr1->power;
        itr1 = itr1->next;
        (*result)->next = (term *) malloc(sizeof(term));
        (*result) = (*result)->next;
        (*result)->next = NULL;

    }
    while (itr2 != NULL) {
        (*result)->coeff = itr2->coeff;
        (*result)->power = itr2->power;
        itr2 = itr2->next;
        (*result)->next = (term *) malloc(sizeof(term));
        (*result) = (*result)->next;
        (*result)->next = NULL;

    }


    return send;
}

void merge(term *start) {
    term *ptr1, *ptr2, *dup;
    ptr1 = start;

    while (ptr1->next != NULL && ptr1->next->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next->next != NULL) {
            if (ptr1->power == ptr2->next->power) {
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            } else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
int main() {
    term *itr = NULL;
    printf("How many terms does the Polynomial One Contains?\n");
    int n;
    scanf("%d", &n);
    printf("Please Enter %d terms with coefficient separated by a space from the exponent. For example 3x^2 should be entered as 3,2\n",
           n);
    int a, b;
    scanf("%d%d", &a, &b);
    createTerm(a, b, &itr);
    term *head_poly_1 = itr;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        createTerm(a, b, &itr);
    }
    printf("\n");
    printf("The polynomial entered by you is\n");
    printTerms(head_poly_1);
    printf("\n");

    printf("How many terms does the Polynomial Two Contains?\n");
    scanf("%d", &n);
    printf("Please Enter %d terms with coefficient separated by a space from the exponent. For example 3x^2 should be entered as 3,2\n",
           n);
    itr = NULL;
    scanf("%d%d", &a, &b);
    createTerm(a, b, &itr);
    term *head_poly_2 = itr;

    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &a, &b);
        createTerm(a, b, &itr);
    }

    printf("\n");
    printf("The polynomial entered by you is\n");
    printTerms(head_poly_2);
    printf("\n");

    term *res = NULL;
    term *head_sum_poly;

    head_sum_poly = addTwoPolynomial(head_poly_1, head_poly_2, &res);
    merge(head_sum_poly);
    sort(head_sum_poly);

    //Printing Output of Addition Operation, Comment Out for Multiplication
    printf("\nThe sum of two polynomials is\n");
    while (head_sum_poly->next != NULL) {
        if (head_sum_poly->coeff != 0) {
            printf("%dx^%d ", head_sum_poly->coeff, head_sum_poly->power);
            if (head_sum_poly->next->next != NULL && head_sum_poly->next->coeff >= 0)
                printf(" + ");
        }
        head_sum_poly = head_sum_poly->next;
    }
    //End of Addition

}
