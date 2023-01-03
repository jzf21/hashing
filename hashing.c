#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct Node{
//     int data;
//     struct Node* next;

// };
struct Users
{
    int id;
    char name[30];
    struct Users *next;
};
int hashfunction(int id, char name[]);
struct Users user_data[100];

// int collision_detection(int data, char name[])
// {
//     if (user_data[data % 9].id == 0)
//     {
//         hashfunction(data, name);
//     }
//     else
//     {
//         struct Users *ptr = &user_data[data % 9];
//         while (ptr != NULL)
//         {
//             ptr = ptr->next;
//         }
//         struct Users *newNode = (struct Users *)malloc(sizeof(newNode));
//         newNode->id = data;
//         newNode->next = NULL;
//         strcpy(newNode->name, name);
//         ptr = newNode;

//         printf("%d", ptr->id);
//         printf("inserted here\n");
//     }
// }
void display_hash_table()
{
    for (int i = 0; i < 9; i++)
    {
        printf("Index %d: ", i);
        struct Users *ptr = &user_data[i];
        while (ptr != NULL)
        {
            printf("(%d, %s) ", ptr->id, ptr->name);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int collision_detection(int data, char name[])
{
    int hashed = data % 9;
    if (user_data[hashed].id == 0)
    {
        hashfunction(data, name);
    }
    else
    {
        struct Users *ptr = &user_data[hashed];
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        struct Users *newNode = (struct Users *)malloc(sizeof(struct Users));
        newNode->id = data;
        newNode->next = NULL;
        strcpy(newNode->name, name);
        ptr->next = newNode;

        printf("%d", ptr->id);
        printf("inserted here\n");
    }
    return 1; // Indicate success
}

int hashfunction(int id, char name[])
{
    int hashed = id;
    hashed = hashed % 9;
    user_data[hashed].id = id;
    strcpy(user_data[hashed].name, name);
    printf("inserted\n");
}
int search(int data)
{
    // printf("%d ",user_data[data%9].id);
    // printf("%s \n",user_data[data%9].name);
    // struct Users *ptr = &user_data[data % 9];
    // while (ptr != NULL)
    // {
    //     printf("%d", ptr->id);
    //     printf("%s\n", ptr->name);
    //     ptr = ptr->next;
    // }
    int hashed = data % 9;
    if (user_data[hashed].id == data)
    {
        printf("Found\n");
        printf("Name: %s", user_data[hashed].name);
    }
    else
    {
        struct Users *ptr = &user_data[hashed];
        while (ptr != NULL)
        {
            if (ptr->id == data)
            {
                printf("Found\n");
                printf("Name: %s", ptr->name);
                break;
            }
            ptr = ptr->next;
        }
    }
}

int main()
{
    int id;
    char name1[30];
    int data;
    for (int i = 0; i < 100; i++)
    {
        user_data[i].id = 0;
    }
    while (1)
    {
        int choice;
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice)

        {
        case 1:

            printf("Enter the id: ");
            scanf("%d", &id);
            printf("Enter the name: ");
            scanf("%s", name1);
            collision_detection(id, name1);
            break;
        case 2:

            printf("Enter the id to search: ");
            scanf("%d", &data);
            search(data);
            break;
        case 3:
            display_hash_table();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
