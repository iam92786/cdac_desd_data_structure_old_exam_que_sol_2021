/*Write a program to implement stack of books using singly linear linked list. 
Every book contains information like name, author, number of pages and price. 
Maximum 5 books can be pushed into the stack. 
Write a menu driven program to perform following operations:
*/
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
#define true 1
#define false 0

typedef int bool_t;

typedef struct book
{
    char name[16];
    char author[16];
    int pages;
    float price;
}book_t;

typedef struct node
{
    struct node *next;
    book_t book_data;
}node_t;

typedef struct
{
    node_t *head;
    int node_count;
}list_t;

enum menu {EXIT, PUSH, POP, TOP, DISPLAY_STACK};

int menu_list();
void list_init(list_t * lptr);
bool_t is_stack_empty(list_t *lptr);
bool_t is_stack_full(list_t *lptr);

void push_stack(list_t *lptr, book_t *b1);
node_t * creatnode(book_t *data);
void pop_stack(list_t *lptr);
void top_stack(list_t *lptr);

void display(book_t * bptr);
void display_all_stack_ele(list_t *lptr);

int main (void)
{
    int choice;
    list_t l1;
    book_t b1;
    list_init(&l1);
    while (1)
    {
        choice = menu_list();
        switch (choice)
        {
        case EXIT:
            exit(0);
            break;

        case PUSH:
            printf("\n>>>Enter Detail Here<<<\n");
            printf("BOOK NAME : ");
            scanf("%s",b1.name);
            printf("AUTHOR NAME : ");
            scanf("%s",b1.author);
            printf("NO. OF PAGE : ");
            scanf("%d",&b1.pages);
            printf("BOOK PRICE : ");
            scanf("%f",&b1.price);
            printf("\n");

            push_stack(&l1, &b1);
            printf(">>>first element is push on Stack !\n");
            break;

        case POP:
            pop_stack(&l1);
            printf(">>>first element is pop from stack !\n");
            break;

        case TOP:
            top_stack(&l1);
            break;

        case DISPLAY_STACK:
            printf(">>>Display Books In Stack<<<\n");
            printf("Book Name || Book Author || Page   ||   Price\n");
            display_all_stack_ele(&l1);
            printf("\n");
            break;
        
        default:
            printf("Invalid Choice!!!\n");
            break;
        }
    }
    
    return 0;
}

void display(book_t *bptr)
{
    //display element
    printf("%-15s %-12s %-17d %-10.2f\n",
        bptr->name,bptr->author,bptr->pages,bptr->price);
}
void display_all_stack_ele(list_t *lptr) //display all element store in the stack
{
        //cheked stack is no empty 
    if(lptr->head != NULL)
    {
        node_t *trav = lptr->head;

        do
        {
            // display elemen tof array
            display(&trav->book_data);
            trav = trav->next;
            // loop 
        } while (trav != NULL);
        
    }
    else
    {
        printf(">>>Stack is EMPTY !!!\n");
    }
    
}

node_t * creatnode(book_t *data)
{
    //new node variable
    node_t *newnode; 
    //dynamic memory allocation using malloc func
    newnode = (node_t*)malloc(sizeof(node_t));

    if (newnode == NULL)
    {
        //if malloc func fall
        //if memory allocation is not done by malloc 
        perror("amlloc() is failed !!! \n");
    }
    newnode->next = NULL;
    ////assign new book store data to new node
    newnode->book_data = *data;
    return newnode;
}

void push_stack(list_t *lptr, book_t* b1) ////add element at First Position on stack
{
    //cheked stack is no Full
    if (lptr->node_count == (SIZE - 1))
    {
        printf(">>>Stack is FULL !!!\n");
    }
    else
    {
        node_t *newnode = creatnode(b1);

        newnode->next = lptr->head;
        //assign new node to head of list
        lptr->head = newnode;
        lptr->node_count++; //count increment

    }

}

void pop_stack(list_t *lptr) //delete element at First Position
{
    //cheked stack is no empty 
    if(lptr->head != NULL)
    {
        // temproray node pointer variable
        node_t *temp = lptr->head;
        lptr->head = lptr->head->next;
        free(temp);
        lptr->node_count--;
    }
        else
    {
        printf(">>>Stack is EMPTY !!!\n");
    }
    
}

void top_stack(list_t *lptr)
{
    //cheked stack is no empty 
    if (lptr->head != NULL)
    {
        // temproray node pointer variable
        node_t *temp = lptr->head;
        printf(">>>TOP Data <<<\n");
        //call display function
        display(&temp->book_data);

    }
    else
    {
        printf(">>>Stack is EMPTY !!!\n");
    }
    
}

void list_init(list_t * lptr)
{
    lptr->head = NULL;
    lptr->node_count = 0;
}
bool_t is_stack_empty(list_t *lptr)
{
    if(lptr->head == NULL)
        return true;
    else
        return false;
}
bool_t is_stack_full(list_t *lptr)
{
    if(lptr->node_count == (SIZE-1))
        return true;
    else    
        return false;

}

int menu_list()
{
    int choice;
    printf("\n>>>>>>>>>> BOOK STORE <<<<<<<<<<<<\n");
    printf("__________________________________\n");
    printf("0. EXIT\n");
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. TOP\n");
    printf("4. DISPLAY ALL BOOK IN STACK\n");
    printf("Enter your choice of Operation : ");
    scanf("%d",&choice);
    return choice;
}