/**
 * C program to insert a node in Doubly linked list
 */

#include <stdio.h>
#include <stdlib.h>


/*
 * Basic structure of Node
 */
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;


/*
 * Function used in this program
 *all function declaration is performed here
 */
void createList(int n);
void displayList();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtN(int data, int position);
void reverseList();
void deleteFromBeginning();
void deleteFromN(n);
void deleteFromEnd();
void  displayList();


int main()
{
    int n, data, choice=1;

    head = NULL;
    last = NULL;

    /*
     * Run forever until user chooses 0
     */
    while(choice != 0)
    {
        /*
         * Menu creation to use the program
         */
        printf("============================================\n");
        printf("DOUBLY LINKED LIST PROGRAM\n");
        printf("============================================\n");
        printf("1. Create List\n");
        printf("2. Insert node  at beginning\n");
        printf("3. Insert node at end\n");
        printf("4. Insert node at any position\n");
        printf("5. delete a node from the beginning\n");
        printf("6. delete a node from the end\n");
        printf("7. delete a node from any position\n");
//        printf("8. display the created list \n");
        printf("8. reverse the created list\n");
        printf("0. Exit\n");
        printf("9.to know the group members\n");
        printf("************************************\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);

        /*
         * Choose from different menu operation
         */
        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);

                createList(n);
                displayList(); 
                break;
            case 2:
                printf("Enter data of first node : ");
                scanf("%d", &data);

                insertAtBeginning(data);
               displayList();
                break;
            case 3:
                printf("Enter data of last node : ");
                scanf("%d", &data);

                insertAtEnd(data);
                 displayList();
                break;
            case 4:
                printf("Enter the position where you want to insert new node: ");
                scanf("%d", &n);
                printf("Enter data of %d node : ", n);
                scanf("%d", &data);

                insertAtN(data, n);
                 displayList();
                break;
                
                 case 5:
                deleteFromBeginning();
                displayList();
                break;
            case 6:
            	printf("list is deleting fro the end\n");
                deleteFromEnd();
              displayList();
                break;
            case 7:
                printf("Enter the node position which you want to delete: ");
                scanf("%d", &n);
                deleteFromN(n);
         displayList();
                break;
        
                
                case 8:
                	printf("the revese lists are:\n");
                reverseList();
displayList();
                break;
            case 0:
            	exit(0);
                break;
                case 9 :
                	printf("***************GROUP MEMBERS**************\n");
        printf("\t \t \t NAME  \t\t\t\t ID \n");
        printf("\t\t1.TESFALEM GIRMAY \t\t\\tMIT/UR/10140/10\n");
        printf("\t\t2.MISAEL HAILU \t\t\t MIT/UR/1098/10\n");
            break;
            default:
                printf("Error! Invalid choice. Please choose between 0-9");
        }

        printf("\n\n\n\n\n \n\n\n\n\n");
    }

    return 0;
}


/**
 * Creates a doubly linked list of n nodes.
 * @n Number of nodes to be created
 */
void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        /*
         * Create and link the head node
         */
        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;

        /*
         * Create and link rest of the n-1 nodes
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last; // Link new node with the previous node
            newNode->next = NULL;

            last->next = newNode; // Link previous node with the new node
            last = newNode;          // Make new node as last/previous node
        }

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}


/**
 * Display content of the list from beginning to end
 */
void displayList()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;

            /* Move the current pointer to next node */
            temp = temp->next;
        }
    }
}


/**
 * Inserts a new node at the beginning of the doubly linked list
 * @data Data of the first node i.e. data of the new node
 */
void insertAtBeginning(int data)
{
    struct node * newNode;

    if(head == NULL)
    {
        printf("Error, List is Empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = head; // Point to next node which is currently head
        newNode->prev = NULL; // Previous node of first node is NULL

        /* Link previous address field of head with newnode */
        head->prev = newNode;

        /* Make the new node as head node */
        head = newNode;

        printf("NODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST\n");
    }
}


/**
 * Inserts a new node at the end of the doubly linked list
 * @data Data of the last node i.e data of the new node
 */
void insertAtEnd(int data)
{
    struct node * newNode;

    if(last == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;

        last->next = newNode;
        last = newNode;

        printf("NODE INSERTED SUCCESSFULLY AT THE END OF LIST\n");
    }
}


/**
 * Inserts a node at any position in the doubly linked list
 * @data Data of the new node to be inserted
 * @position Position where to insert the new node
 */
void insertAtN(int data, int position)
{
    int i;
    struct node * newNode, *temp;

    if(head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = head;
        i=1;

        while(i<position-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }

        if(position == 1)
        {
            insertAtBeginning(data);
        }
        else if(temp == last)
        {
            insertAtEnd(data);
        }
        else if(temp!=NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = data;
            newNode->next = temp->next; // Connect new node with n+1th node
            newNode->prev = temp;          // Connect new node with n-1th node

            if(temp->next != NULL)
            {
                /* Connect n+1th node with new node */
                temp->next->prev = newNode;
            }
            /* Connect n-1th node with new node */
            temp->next = newNode;

            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
        }
        else
        {
            printf("whoopse!!!, Invalid position\n");
        }
    }
}


void deleteFromBeginning()
{
    struct node * toDelete;

    if(head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = head;

        head = head->next; // Move head pointer to 2 node
        
        if (head != NULL)
            head->prev = NULL; // Remove the link to previous node

        free(toDelete); // Delete the first node from memory
        printf("successfuly node deleted.\n");
    }
}


/**
 * 
 */
void deleteFromEnd()//Delete or remove the last node of the doubly linked list
{
    struct node * remove;

    if(last == NULL)
    {
        printf("whoops!. List is empty.\n");
    }
    else
    {
       remove = last;

        last = last->prev; // Move last pointer to 2nd last node
        
        if (last != NULL)
            last->next = NULL; // Remove link to of 2nd last node with last node

        free(remove);       // Delete the last node
        printf("deleted.\n");
    }
}


/**
 * Delete node from any position in the doubly linked list
 */
void deleteFromN(int position)
{
    struct node *current;
    int i;

    current = head;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }

    if(position == 1)
    {
        deleteFromBeginning();
    }
    else if(current == last)
    {
        deleteFromEnd();
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current); // Delete the n node

        printf("removed %d POSITION.\n", position);
    }
    else
    {
        printf("whoops!,Invalid position!\n");
    }
}


void reverseList()
{
    struct node *current, *temp;

    current = head;
    while(current != NULL)
    {
        /*
         * Swap the previous and next address fields of current node
         */
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        /// Move the current pointer to next node which is stored in temp */
        current = temp;
    }
    
   // Swap the head and last pointers
    
    temp = head;
    head = last;
    last = temp;

    printf("LIST REVERSED SUCCESSFULLY.\n");
}
