#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct Node
	{
		struct Node *lptr;
		int info;
		struct Node *rptr;
	}Node;
	
	 Node *root=NULL;
	 
int search()	
{
    int num;
    printf("Enter the number which u want to search\n");
    scanf("%d",&num);
    Node *ptr=root;
    while(ptr!=NULL)
    {
        if (ptr->info == num)
        {
            printf("Number is present\n");
            return 0;
        }
        else if(ptr->info > num)
        {
            ptr=ptr->lptr;
        }
        else
        {
            ptr=ptr->rptr;
        }
    }
printf("Number is not found\n");    
}

void PreOrder()
{
    Node *cur;
    Node *a[100];
    int top=-1;
    if(root==NULL)
    {
        printf("Tree is empty\n");
    }
    else
    {
       a[++top]=root;
       while(top>=0)
       {
           cur=a[top--];
           printf("%d ",cur->info);
           if (cur->rptr!=NULL)
            a[++top]=cur->rptr;
           if(cur->lptr!=NULL)
           {
               a[++top]=cur->lptr;
           }
       }
    }
}
void PostOrder()
{
    Node *cur;
    Node *a[100],*b[100];
    int topA=-1,topB=-1;
    if(root==NULL)
    {
        printf("Tree is empty\n");
    }
    else
    {
        a[++topA]=root;
        while(topA>=0)
        {
            cur=a[topA--];
            b[++topB]=cur;
            if (cur->lptr!=NULL)
            {
                a[++topA]=cur->lptr;
            }    
            if(cur->rptr!=NULL)   
            {
                a[++topA]=cur->rptr;
            }    
        }
        while(topB>=0)
        {
            printf("%d ",(b[topB--])->info);
        }
    }
}

void InOrder()
{
    Node *cur;
    Node *a[100];
    int top=-1;
    if(root==NULL)
    {
        printf("Tree is empty\n");
    }
    else
    {
        cur=root;
        while(cur!=NULL || top>=0)
        {
            while(cur!=NULL)
                {
                    a[++top]=cur;
                    cur=cur->lptr;
                }
            if(top>=0)  
            {
                cur=a[top--] ;
                printf("%d ",cur->info);
                cur=cur->rptr;
            }
        }
    }
}

void LevelOrder()
{
    Node *ptr;
    Node *a[100];
    int f=0,r=-1;
    if (root==NULL)
    {
        printf("\nTree is empty\n");
    }
    else
    {
        ptr=root;
        a[++r]=ptr;
        while(f<=r)
        {
            ptr=a[f++];
            printf("%d ",ptr->info);
            if (ptr->lptr!=NULL)
                a[++r]=ptr->lptr;
            if (ptr->rptr!=NULL)
                a[++r]=ptr->rptr;
        }
        
    }
    
}

Node *insert()
{
   int data;
   Node *ptr,*pre; 
       Node *a= (Node *)malloc(sizeof(Node));
       printf("Insert value is\n");
       scanf("%d",&data);
       a->lptr=NULL;
       a->info=data;
       a->rptr=NULL;
   if (root==NULL)
   {
       root=a;
   }
   else
   {
       ptr=root;
       pre=NULL;
       while(ptr!=NULL)
       {
           pre=ptr;
           if (ptr->info > data )
           {
               ptr=ptr->lptr;
           }
           else
           {
               ptr=ptr->rptr;
           }
       }
       if(pre->info > data)
            pre->lptr=a;
       else   
            pre->rptr=a;
   }        
   return root;
}

void Delete()
{
    Node *ptr=NULL,*cur=NULL,*succ=NULL,*par=NULL,*pre=NULL;
    int item;
    if (root==NULL)
    {
        printf("\nTree is empty\n");
    }
    else
    {
        printf("\nEnter item which u want to delete\n");
        scanf("%d",&item);
        cur=root;
        while(cur!=NULL)
        {
            if(item==cur->info)
            {
                break;
            }
            par=cur;
            if(item > cur->info)
                cur=cur->rptr;
            else
                cur=cur->lptr;
        } 
        
        if (cur==NULL)
            printf("\nEntered element is not exist\n");
            
        if (cur->rptr==NULL) 
            ptr=cur->lptr;
        else if(cur->lptr==NULL)
            ptr=cur->rptr;
        else
        {
            succ=cur->rptr;
            while(succ->lptr!=NULL)
            {
                    pre=succ;
                    succ=succ->lptr;
            }
            succ->lptr=cur->lptr;
            ptr=cur->rptr;
            
        }
        if (par==NULL)
        {
            root=cur->rptr;
        }
        else if (par->info>cur->info)
            par->lptr=ptr;
        else 
            par->rptr=ptr;
            
    }
    
}


void main()
{
int n,var,vari;

back:
    printf("\nchoose operation\n");
    printf("1 Insert\n");
    printf("2 Delete\n");
    printf("3 Traversal\n");
    printf("4 Searching\n");
    printf("5 Exit\n");
    scanf("%d",&var);
    if (var==3)
    {
        printf("\nChoose traversal type\n");
        printf("1 PreOrder\n");
        printf("2 InOrder\n");
        printf("3 PostOrder\n");
        printf("4 LevelOrder\n");
        scanf("%d",&vari);
    }
switch(var)
{
	case 1:
		insert();
		goto back;
	case 2:
	    Delete();
		goto back;
		
	case 3:
	    switch(vari)
	    {
	        case 1:
	            PreOrder();
	            break;
	        case 2:
	             InOrder();
	            break;
	        case 3:
	             PostOrder();
	            break;
	        case 4:
	            LevelOrder();
	            break;
	    }
	    goto back;	
	case 4:
	    search();
	    goto back;
	case 5:
	    break;

}
}











