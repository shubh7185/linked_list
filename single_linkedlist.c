#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *create(struct node*);
void display(struct node *);
void sum(struct node *);
void max(struct node *);
void min(struct node *);
void count(struct node *);
int  rcount(struct node *);
void search(struct node *);
void impsearch(struct node*);
void duplicate(struct node *);
int  issorted(struct node *);
void delete(struct node *);
struct node* Delete_firstnode(struct node *);
struct node * delete_keyelement(struct node *);
struct node* recu_delete_key_element(struct node * , int );
void insert(struct node *);
struct node* insert_at_fisrt_pos(struct node *);
struct node *reverse(struct node *);


int main()
{
    struct node *first=NULL;
    int ch;
    int key;

    do
    {
        printf("Enter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            first=create(first);
            break;
            case 2:
            sum(first);
            break;
            case 3:
            max(first);
            break;
            case 4:
            min(first);
            break;
            case 5:
            count(first);
            break;
            case 6:
            printf("%d:",rcount(first));
            break;
            case 7:
            search(first);
            break;
            case 8:
            impsearch(first);
            break;            
            case 9:
            duplicate(first);
            break;
            case 10:
            printf("%d : ",issorted(first));
            break;   
            case 11:
            display(first);
            break;          
            case 12:
            delete(first);
            break; 
            case 13:
            first=Delete_firstnode(first);
            break; 
            case 14:
            first=delete_keyelement(first);
            break; 
            case 15:
            insert(first);
            break; 
            case 16:
            first=insert_at_fisrt_pos(first);
            break; 
            case 17:
            printf("enter the key: ");
            scanf("%d",&key);
            first=recu_delete_key_element(first,key);
            break;   
            case 18:
            first=reverse(first);
            break;                          
            default:
            printf("invalid case: ");
            break;                                             
        }
    }while(ch<=18);
}


struct node * create(struct node * p)
{
    struct node *first=NULL;
    struct node* last=NULL;
    int x;
    int n;
    printf("enter the number of elments you want: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the data: ");
        scanf("%d",&x);
        p=(struct node*)malloc(sizeof(struct node));
        p->data=x;
        p->next=NULL;
        if(first==NULL && last==NULL)
        {
            last=first=p;
        }
        else
        {
            last->next=p;
            last=p;
        }
    }
    return first;
}

void sum(struct node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum = sum + p->data;
        p=p->next;
    }
    printf("%d :",sum);
    printf("\n");
}

void max(struct node *p)
{
    int max=-32768;
    while(p!=NULL)
    {
        if(p->data>max)
        {
            max=p->data;
        }
        else
        {
            p=p->next;
        }
    }
    printf("%d : ",max);
}

void min(struct node *p)
{
    int min=32768;
    while(p!=NULL)
    {
        if(p->data<min)
        {
            min=p->data;
        }
        else
        {
            p=p->next;
        }
    }
    printf("%d : ",min);
}

void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void count(struct node *p)
{
    int c=0;
    while(p!=NULL)
    {
        c=c+1;
        p=p->next;
    }
    printf("%d: ",c);
}

int rcount(struct node *p)
{
    
    if(p==0)
    return 0;
    else
    return rcount(p->next) +1 ;
}


void search(struct node *p)
{
    int key;
    printf("Enter the key element you want to search: ");
    scanf("%d",&key);
    int flag=0;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            flag=1;
            break;
        }
        else
        {
            p=p->next;
        }
    }
    if(flag==1)
    {
        printf("key is found: ");
    }
    else
    {
        printf("key is not found: ");
    }
}
void impsearch(struct node*p )
{
    struct node* first=NULL;
    first=p;
    int key;
    struct node*q=NULL;
    printf("enter the key to search: ");
    scanf("%d",&key);
    int flag=0;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            flag=1;
            break;
        }
        else
        {
            q=p;
            p=p->next;
        }
    }
    if(flag==1)
    {
        printf("key is found: ");
    }
    else
    {
        printf("key is not found: ");
    }
}

void duplicate(struct node *p)
{
    struct node *q=NULL;
    q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

int issorted(struct node*p)
{
    int x=-32768;
    int flag=0;
    while(p!=NULL)
    {
        if(p->data<x)
        {
            return 0;
        }
        else
        {
            x=p->data;
            p=p->next;
        }
    }
    return 1;
}

void delete(struct node *p)
{
    struct node *q;
    int pos;
    int x;
    printf("enter the pos: ");
    scanf("%d",&pos);
    for(int i=0;i<pos-1;i++)
    {
        q=p;
        p=p->next;
    }
    x=p->data;
    q->next=p->next;
    free(p);
}

struct node* Delete_firstnode(struct node *p)
{
    int x;
    struct node*q=NULL;
    q=p;
    x=p->data;
    p=p->next;
    free(q);

    return p;
}

struct node * delete_keyelement(struct node *head)
{
    int key;
    struct node *r;
    struct node *q;
    struct node *temp;
    printf("enter the key element: ");
    scanf("%d",&key);
    if(head==NULL)
    return NULL;
    q=(struct node*)malloc(sizeof(struct node));
    q->data=-1;
    q->next=head;
    r=q;
    while(r!=NULL && r->next!=NULL)
    {
        if(r->next->data==key)
        {
            temp=r->next;
            r->next=temp->next;
            free(temp);
        }
        else
        {
            r=r->next;
        }
    }
    return q->next;
}

// struct node* recu_delete_key_element(struct node *p , int key)
// {
//     if(p==NULL)
//     return NULL;
//     struct node* q;
//     p->next=recu_delete_key_element(p->next,key);
//     if(p->data==key)
//     {
//         q = p->next;
//         delete(p);
//         return q;
//     }
//     else
//     {
//         return p;
//     }
// }



void insert(struct node *p)
{
    int data , pos;
    struct node *temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d",&data);
    temp->data=data;
    printf("enter the pos: ");
    scanf("%d",&pos);
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;

}

struct node* insert_at_fisrt_pos(struct node* p)
{
    int data;
    printf("enter the data: ");
    scanf("%d",&data);
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=p;
    p=temp;
    return p;
}

struct node * reverse(struct node *p)
{
    struct node *first;
    struct node *q=NULL;
    struct node *r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
    return first;
}
