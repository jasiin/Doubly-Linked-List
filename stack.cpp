#include<iostream>
using namespace std;

struct node
{
    int value;
    node* next;
    node* prev;
};
node *head,*tail;

void init()
{
    head=NULL;
    tail=NULL;
}

void insertFirst(int element)
{
    struct node* newItem;
    newItem=new node;
    if(head==NULL)
    {
		head=newItem;
        newItem->prev=NULL;
        newItem->value=element;
        newItem->next=NULL;
        tail=newItem;
    }
    else
    {
        newItem->next=head;
        newItem->value=element;
        newItem->prev=NULL;
        head->prev=newItem;
        head=newItem;
    }
}

void insertLast(int element)
{
    struct node* newItem;
    newItem=new node;
    newItem->value=element;
    if(head==NULL)
    {
        head=newItem;
        newItem->prev=NULL;
        newItem->next=NULL;
        tail=newItem;
    }
    else
    {
        newItem->prev=tail;
        tail->next=newItem;
        newItem->next=NULL;
        tail=newItem;
    }
}

void insertAfter(int old, int element)
{
    struct node* newItem;
    newItem=new node;
    struct node* temp;
    temp=head;
    if(head==NULL)
    {
        cout<<"could not insert"<<endl;
        return;
    }
    if(head==tail)
    {
        if(head->value!=old)
        {
            cout<<"could not insert"<<endl;
            return;
        }
        newItem->value=element;
        head->next=newItem;
        newItem->next=NULL;
        head->prev=NULL;
        newItem->prev=head;
        tail=newItem;
        return;
    }
    if(tail->value==element)
    {
        newItem->next=NULL;
        newItem->prev=tail;
        tail->next=newItem;
        tail=newItem;
        return;
    }
    while(temp->value!=old)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            cout<<"Could not insert"<<endl;
            cout<<"element not found"<<endl;
            return;
        }
    }
    newItem->next=temp->next;
    newItem->prev=temp;
    newItem->value=element;
    temp->next->prev=newItem;
    temp->next=newItem;
}

void deleteFirst()
{
    if(head==NULL)
    {
        return;
    }
    if(head==tail)
    {
        struct node* cur;
        cur=head;
        head=NULL;
        tail=NULL;
        delete cur;
        return;
    }
    else
    {
        struct node* cur;
        cur=head;
        head=head->next;
        head->prev=NULL;
        delete cur;
    }
}
void deleteLast()
{
    if(head==NULL) return;
    if(head==tail)
    {
        struct node* cur;
        cur=head;
        head=NULL;
        tail=NULL;
        delete cur;
        return;
    }
    else
    {
        struct node* cur;
        cur=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete cur;
    }
}
void deleteMid(int element)
{
    struct node* temp;
    temp=head;
    if(head==tail)
    {
        if(head->value!=element)
        {
            cout<<"could not delete"<<endl;
            return;
        }
        head=NULL;
        tail=NULL;
        delete temp;
        return;
    }
    if(head->value==element)
    {
        head=head->next;
        head->prev=NULL;
        delete temp;
        return;
    }
    else if(tail->value==element)
    {
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete temp;
        return;
    }
    while(temp->value!=element)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            cout<<"element not found"<<endl;
            return;
        }
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    delete temp;
}
void pushList(int element){
	struct node* newItem;
    newItem=new node;
    if(head==NULL)
    {
        newItem->value=element;
        newItem->prev=NULL;
        newItem->next=NULL;
        head=newItem;
    }
    else
    {
        newItem->value=element;
        newItem->next=head;
        head->prev=newItem;
        newItem->prev=NULL;
        head=newItem;
    }
}

void popList()
{
	struct node* del;
	del=head;
    head=head->next;
    head->prev=NULL;
    delete del;
}

void printList()
{
struct node* temp;
    temp=head;
    if( head == NULL ){
    	cout << "Double Linked List belum dibuat!!!\n\n";
  	}else{
    while(temp!=NULL)
    {
        printf("%d>",temp->value);
        temp=temp->next;
    }
    puts("");
	}
    
}
int main()
{
    init();
    int choice;
    while(1)
    {
        cout<<("\n1.Insert First \n2.Insert Last \n3.Insert After \n4.Delete First \n5.Delete Last \n6.Delete Mid \n7.Push \n8.Pop");
        cout<<"\n\nMasukkan pilihan=";
        cin>>choice;
        if(choice==1)
        {
            int element;
            cout<<"\nMasukkan node=";
            cin>>element;
            insertFirst(element);
            printList();
        }
        else if(choice==2)
        {
            int element;
            cout<<"\nMasukkan node=";
            cin>>element;
            insertLast(element);
            printList();
        }
        else if(choice==3)
        {
            int old,newitem;
            cout<<"\nNode setelah item=";
            cin>>old;
            cout<<"Masukkan node baru=";
            cin>>newitem;
            insertAfter(old,newitem);
            printList();
        }
        
        else if(choice==4)
        {
            deleteFirst();
            printList();
        }
        else if(choice==5)
        {
            deleteLast();
            printList();
        }
        else if(choice==6)
        {
            int element;
            cout<<"\nMasukkan node yang akan dihapus=";
   			cin>>element;
            deleteMid(element);
            printList();
        }
        else if (choice == 7){
        	int element;
            cout<<"\nMasukkan node=";
            cin>>element;
            pushList(element);
            printList();
		}
        else if(choice == 8)
        {
        	popList();
        	printList();
		}
    }
return 0;
}
