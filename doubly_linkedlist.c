#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* prev;
    int data;
    struct node* next;
};


struct node* create(struct node *);
void display(struct node *);

struct node* insert_before(struct node *);
void insert(struct node* );

struct node* delete_firstnode(struct node*);
void delete(struct node *);

void search(struct node *);
int evennodes(struct node *);

int main()
{
    struct node* first=NULL;
    int ch;
    do
    {
        printf("enter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            first=create(first);
            break;
            case 2:
            display(first);
            break;
            case 3:
            insert(first);
            break;
            case 4:
            first=insert_before(first);
            break;
            case 5:
            delete(first);
            break;
            case 6:
            first=delete_firstnode(first);
            break;
            case 7:
            search(first);
            break;
            case 8:
            evennodes(first);
            break;
            default:
            printf("invalid choice: ");
            break;
        }
    }while(ch<=8);
}


struct node* create(struct node * p)
{
    struct node* first=NULL;
    struct node* last=NULL;
    int n , x;
    printf("enter the number you want: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the value of x: ");
        scanf("%d",&x);
        p=(struct node*)malloc(sizeof(struct node));
        p->data=x;
        p->next=NULL;
        p->prev=NULL;
        if(last==NULL && first==NULL)
        {
            last=first=p;
        }
        else
        {
            last->next=p;
            p->prev=last;
            last=p;
        }
        return first;
    }
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


    struct node* insert_before(struct node* p)
    {
        int x;
        struct node* t;
        printf("enter the value of x :");
        scanf("%d",&x);
        t->data=x;
        t->next=p;
        t->prev=NULL;
        p->prev=t;
        p=t;
        return t;
    }

    void insert(struct node * p)
    {
        struct node*t;
        t=(struct node*)malloc(sizeof(struct node));
        int x , pos;
        printf("enter the pos: ");
        scanf("%d",&pos);
        printf("enter the value to be added: ");
        scanf("%d",&x);
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next)
        {
        p->next=t;
        p->next->prev=t;
        }
    }

    void delete(struct node* p)
    {
        int pos;
        int x;
        printf("enter the position: ");
        scanf("%d",&pos);
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)
        {
            p->next->prev=p->prev;
        }
        x=p->data;
        free(p);
    }
    struct node* delete_firstnode(struct node *p)
    {
        struct node*q=NULL;
        int x;
        x=p->data;
        q=p;
        x=p->data;
        p->prev=NULL;
        p=p->next;
        free(p);
        return p;
    }

    void search(struct node* p)
    {
        int key;
        int flag=0;
        printf("enter the key : ");
        scanf("%d",&key);
        while(p!=NULL)
        {
            if(p->data==key)
            {
                flag==1;
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

    int evennode(struct node*p)
    {
        int even=0;
        int odd=0;
        while(p)
        {
            if(p->data%2==0)
            {
                even=p->data;
                printf("Even data: %d",even);
            }
            else
            {
                odd=p->data;
                printf("Odd data: %d",odd);
            }
            p=p->next;
        }
    }