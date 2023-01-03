#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// struct Node{
//     int data;
//     struct Node* next;
    
// };
struct Users{
    int id;
    char name[30];
    struct Users* next;
};
int hashfunction(int id,char name[]);
struct Users user_data[100];

int collision_detection(int data,char name[]){
    if(user_data[data%9].id==0){
        hashfunction(data,name);
    }
    else{
        struct Users *ptr=&user_data[data%9];
        while(ptr!=NULL){
            ptr=ptr->next;
        }
        struct Users *newNode =(struct Users*)malloc(sizeof(newNode));
        newNode->id=data;
        newNode->next=NULL;
        strcpy(newNode->name,name);
        ptr=newNode;
        
        printf("%d",ptr->id);
        printf("inserted here\n");
        
        

    }
   

}
int hashfunction(int id,char name[]){
    int hashed =id;
    hashed=hashed%9;
    user_data[hashed].id=id;
    strcpy(user_data[hashed].name,name);
    printf("inserted\n");

}
int search(int data){
    // printf("%d ",user_data[data%9].id);
    // printf("%s \n",user_data[data%9].name);
    struct Users *ptr=&user_data[data%9];
        while(ptr!=NULL){
            printf("%d",ptr->id);
            printf("%s\n",ptr->name);
            ptr=ptr->next;

        }
}



int main(){
    for(int i=0;i<100;i++){
        user_data[i].id=0;
    }
    collision_detection(5,"John");
    collision_detection(20,"Jozef");
    collision_detection(34,"James");
    collision_detection(29,"Johnny");

    // printf("hello");
    // for(int i=0;i<200;i++){
    //     printf("%d",user_data[i].id);
    // }
    // search(34);
    // search(5);
    // search(20);
    search(29);
}
