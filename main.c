#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<time.h>
#include "accounts.h"
/*
struct user_account
{
    char user_name[20];
    char password[16];
}obj_a;

void account_run();
*/


struct node
{
	int data;
	float price;
	char name[20];
	char item_description[100];
	char item_type[30];
	int mdate;
	int mmonth;
	int myear;
	int qty;
	struct node *next;

};

struct pop
{
	int data;

	float price;
	char name[20];
	char item_description[100];
	char item_type[30];
	int mdate;
	int mmonth;
	int myear;
	int qty;
};

	int data;
	float price;
	char name[20];
	char item_description[100];
	char item_type[30];
	int mdate;
	int mmonth;
	int myear;
	int qty;


struct pop obj;
struct node *head=NULL,*p=NULL,*last=NULL,*q=NULL,*user_head=NULL,*user_last=NULL,*x=NULL;

int n,m,i,usermode=0,loc=0,not_entered=1,c;



void create();
void display();
void sort();
void search();
struct node* insert();
void reverse();
void write();
void read();
void delete1();
void modify();
int modechoose();
int admin();
void user();
void user_cart();
void buy();
void read_user();
void add_to_cart();
void user_write();
void stray();
void graph();
int pid(int);
int idser();
int nameser();
void buy_all();
void edit_cart();
void empty_cart();
void buy_selective();
void cart_delete();



int main()
{
    while(1)
    {
	c=modechoose();
    if(c==1){admin();}
    if(c==2){user();}
    if(c==0){break;}
    }
return 0;
}



void create()
{
	read();
	int c,not_entered=1,pid;
	char cname[20];
	float price;

	printf("Enter number of entries you want to enter");
	scanf("%d",&n);
	struct node *p;
	int i=0;
	p=last;
	if(last==NULL)
	{
	i=1;
	last=(struct node*)malloc(sizeof(struct node));
	last->next=NULL;

	printf("Enter product id");
	scanf("%d",&(last->data));
	printf("Enter name");
	scanf("%s",(last->name));
	printf("\nEnter price");
	scanf("\t%f",&(last->price));
	printf("Enter item description(use _ instead of space):");
	scanf("\n%s",last->item_description);
	printf("Enter item type");
	scanf("\n%s",last->item_type);
	printf("Enter Quantity available");
	scanf("%d",&last->qty);
	not_entered=1;
	while(not_entered)
    {
	printf("Enter manufacturer date");
	scanf("\n%d",&obj.mdate);
	printf("Enter manufacturer month");
	scanf("\n%d",&obj.mmonth);
	printf("Enter manufacturer year");
	scanf("\n%d",&obj.myear);

    c=chkda();
    if(c==1)
    {
        printf("\nWrong date or month or year.Please try again\n");
    }
    else{last->mdate=obj.mdate;
        last->mmonth=obj.mmonth;
        last->myear=obj.myear;
        not_entered=0;
        }

    }
    last->next=NULL;
	p=last;
	head=last;
	}//if


	for(;i<n;i++)
	{
    q=NULL;
	q=(struct node*)malloc(sizeof(struct node));
	q->next=NULL;

    while(1)
	{
	printf("Enter product id,last id=%d",last->data);
	scanf("\t%d",&obj.data);

	c=idser();
	if(c!=0)
	{printf("Data already exist.Enter data again");
	c=0;}
	else{
        printf("correct q->data");
	q->data=obj.data;
	not_entered=1;
       break;}
	}
	not_entered=1;
    while(not_entered)
	{

	printf("Enter name");
	scanf("%s",(obj.name));
	printf("%d",obj.data);

	c=nameser();
	if(c!=0)
	{printf("name already exist.Enter name again");
	c=0;}
	else{
	strcpy(q->name,obj.name);
	not_entered=1;
       break;}
	}



	printf("Enter price");
	scanf("%f",&(q->price));
	printf("Enter item description(use _ instead of space):");
	scanf("%s",q->item_description);
	printf("Enter item type");
	scanf("%s",q->item_type);
	printf("Enter Quantity available");
	scanf("%d",&q->qty);
	not_entered=1;
	while(not_entered)
    {
	printf("Enter manufacturer date");
	scanf("\n%d",&obj.mdate);
	printf("Enter manufacturer month");
	scanf("\n%d",&obj.mmonth);
	printf("Enter manufacturer year");
	scanf("\n%d",&obj.myear);

    c=chkda();
    if(c==1)
    {
        printf("\nWrong date or month or year.Please try again\n");
    }
    else{q->mdate=obj.mdate;
        q->mmonth=obj.mmonth;
        q->myear=obj.myear;
        not_entered=0;
        }

    }

    last->next=q;
    last=q;
	q->next=NULL;
	}//i for
	write();

	}//struct node* create

int modechoose()
	{
	int mode,exit=0;
	char c,pass[4],pass1[4]={'1','2','3','4'};
	while(exit!=1)
    {
    printf("Enter your mode:-1.Admin 2.User 3.exit");
	scanf("%d",&mode);
	if(mode==1)
	{
	printf("Enter your password:");
	for(i=0;i<(sizeof(pass));i++)
    {
        c=getch();
        pass[i]=c;
        printf("*");
    }
    for(i=0;i<(sizeof(pass));i++)
    {
        if(pass[i]!=pass1[i])
        {
            printf("Wrong password");
        }
        else{if(i==sizeof(pass)-1)
            {return 1;}
        }
    }
	}
	if(mode==2){return 2;}
	if(mode==3){return 0;}
    }
	}//void modechoose


void display()

{
	read();
	int i;
	p=head;
	if(p==NULL)
	{
	printf("\nNo items loaded");
	}
	else
	{
	printf("\nItems are:");
	/*printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");*/

	//printf("\n\nPrice\t\t\tSr.no\t\t\tName\t\t\tDescription\t\t\tType\t\t\tDate");
	for(i=1;p!=NULL;i++)
	{
	printf("\n--------------------------------------------------------");
	printf("\n(%d)Pid=%d    ",i,p->data);
	printf("Price=%.2f    ",p->price);
	printf("Product_name=%s    ",p->name);
	printf("Description=%s    ",p->item_description);
	printf("Type=%s    ",p->item_type);
	printf("Quantity=%d    ",p->qty);
	printf("Date=%d/%d/%d    ",p->mdate,p->mmonth,p->myear);
	printf("\n--------------------------------------------------------\n");

	//write printf("%s\t",p->name);  and other variables
	p=p->next;

	}//for

	}


}//void display

struct node* insert()
{
    read();
	p=head;
	q=head;

    int i,loc,data;
    float price;
    char name[20];

    printf("Enter the new position:");
    scanf("%d",&loc);
    printf("Enter the new price:");
    scanf("%f",&price);

	not_entered=1;
	while(not_entered)
	{

	printf("Enter new product id");
	scanf("%d",&(obj.data));

	c=idser();
	if(c!=0)
	{printf("Id already exist.Enter Id again");
	c=0;}
	else{
	data=obj.data;
	not_entered=1;
       break;}
	}

	not_entered=1;
	while(not_entered)
	{

	printf("Enter new Name");
	scanf("%s",(obj.name));
	printf("%d",obj.data);

	c=nameser();
	if(c!=0)
	{printf("Name already exist.Enter name again");
	c=0;}
	else{
	strcpy(name,obj.name);
	not_entered=1;
       break;}
	}

	printf("Enter description");
	scanf("%s",item_description);
	printf("Enter item type");
	scanf("%s",item_type);
	printf("Enter Quantity available");
	scanf("%d",qty);
not_entered=1;
	while(not_entered)
    {
	printf("Enter manufacturer date");
	scanf("\n%d",&obj.mdate);
	printf("Enter manufacturer month");
	scanf("\n%d",&obj.mmonth);
	printf("Enter manufacturer year");
	scanf("\n%d",&obj.myear);

    c=chkda();
    if(c==1)
    {
        printf("\nWrong date or month or year.Please try again\n");
    }
    else{mdate=obj.mdate;
        mmonth=obj.mmonth;
        myear=obj.myear;
        not_entered=0;
        }

    }

    p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->price=price;
    p->qty=qty;
    p->mdate=mdate;
    p->mmonth=mmonth;
    p->myear=myear;
    strcpy(p->name,name);
	strcpy(p->item_description,item_description);
	strcpy(p->item_type,item_type);
    p->next=NULL;
    if(loc==1)
    {
        p->next=head;
	head=p;
        write();
        return(p);
    }
    q=head;
    for(i=1;i<loc-1;i++)
    {

        if(q!=NULL)
        {
            q=q->next;
        }
    }
    p->next=q->next;
    q->next=p;
    n=n+1;
    write();
    return(head);
}



void modify()
{

	int i=1,ch,choice=1,loc=0;

	read();

	printf("Enter the location you want to modify");
	scanf("%d",&loc);

	p=head;

	for(i=1;i<=loc;i++)
	{
	if(loc==i)
	{
	do{
	printf("\n0.exit");
	printf("1.pid=%d ",p->data);
	printf("2.price=%.2f ",p->price);
	printf("3.name=%s ",p->name);
	printf("4.description=%s ",p->item_description);
	printf("5.type=%s ",p->item_type);
	printf("6.Quantity available=%d ",p->qty);
	printf("7.Manufacturer date=%d/%d/%d",p->mdate,p->mmonth,p->myear);
	printf("\nEnter your choice to edit");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	not_entered=1;
	while(not_entered)
	{

	printf("Enter data");
	scanf("%d",&(obj.data));

	c=idser();
	if(c!=0)
	{printf("Data already exist.Enter data again");
	c=0;}
	else{
	p->data=obj.data;
	not_entered=1;
       break;}
	}
	break;
	case 2:
	printf("Enter new price=");
	scanf("%f",&p->price);
	break;
	case 3:
	not_entered=1;
	while(not_entered)
	{

	printf("Enter name");
	scanf("%s",(obj.name));
	printf("%d",obj.data);

	c=nameser();
	if(c!=0)
	{printf("name already exist.Enter name again");
	c=0;}
	else{
	strcpy(p->name,obj.name);
	not_entered=1;
       break;}
	}
	break;
	case 4:
	printf("Enter the new description(use _ instead of space)=");
	scanf("%s",p->item_description);
	break;
	case 5:
	printf("Enter the new type =");
	scanf("%s",p->item_type);
	break;
	case 6:
    printf("Enter Quantity available");
    scanf("%d",&p->qty);
    break;
	case 7:
    not_entered=1;
	while(not_entered)
    {
	printf("Enter new manufacturer date");
	scanf("\n%d",&obj.mdate);
	printf("Enter new manufacturer month");
	scanf("\n%d",&obj.mmonth);
	printf("Enter new manufacturer year");
	scanf("\n%d",&obj.myear);

    c=chkda();
    if(c==1)
    {
        printf("\nWrong date or month or year.Please try again\n");
    }
    else{p->mdate=obj.mdate;
        p->mmonth=obj.mmonth;
        p->myear=obj.myear;
        not_entered=0;
        }

    }

    break;
	}//switch
	}while(ch!=0);

	}//if
	if(p->next==NULL)
	{
	break;
	}//if
	p=p->next;

	}//for

	write();
}//void modify


void sort()
	{
	int k;
	read();
	int temp;
	struct node *i,*j;
	for(i=head;i!=NULL;i=i->next)
	{
	for(j=i->next;j!=NULL;j=j->next)
	{
	if((i->data)>(j->data))			//write integer variable only in place of data
	{
	obj.data=i->data;
	obj.price=i->price;
	obj.mdate=i->mdate;
	obj.mmonth=i->mmonth;
	obj.myear=i->myear;
	obj.qty=i->qty;

	i->data=j->data;
	i->price=j->price;
	i->mdate=j->mdate;
	i->mmonth=j->mmonth;
	i->myear=j->myear;
	i->qty=j->qty;

	j->data=obj.data;
	j->price=obj.price;
	j->mdate=obj.mdate;
	j->mmonth=obj.mmonth;
	j->myear=obj.myear;
	j->qty=obj.qty;
	for(k=0;k<sizeof(obj.name);k++)
	{
	obj.name[k]=i->name[k];
	i->name[k]=j->name[k];
	j->name[k]=obj.name[k];
	}

	strcpy(obj.name,i->name);
	strcpy(i->name,j->name);
	strcpy(j->name,obj.name);



	strcpy(obj.item_description,i->item_description);
	strcpy(i->item_description,j->item_description);
	strcpy(j->item_description,obj.item_description);


	strcpy(obj.item_type,i->item_type);
	strcpy(i->item_type,j->item_type);
	strcpy(j->item_type,obj.item_type);


	}//if
	}//j for
	}//i for

	write();
	}//void sort


void reverse()
	{
	read();

	struct node *prenode,*currnode;
	if(head!=NULL)
	{
	prenode=head;
	currnode=head->next;
	prenode->next=NULL;
	}
	while(head!=NULL)
	{
	head=currnode->next;
	currnode->next=prenode;
	prenode=currnode;
	currnode=head;
	}
	head=prenode;

	write();

	}//void reverse


void delete1()
{
	read();
	int loc,i;
	printf("Enter the location to delete");
	scanf("%d",&loc);
	printf("Number %d is being deleted.Please wait",loc);

	if(p!=NULL)
	{
	q=head;
	p=q->next;


	for(i=1;i<=loc;)
	{
	if(i==2)
	{
	q=head;
	p=q->next;
	}
	if(i==loc&&i==1)
	{
	    if(head->next==NULL)
        {
            printf("list head is last");
            last=NULL;
        }
	head=head->next;
	q=NULL;
	free(q);
	write();
	break;
	}
	else
	{
	if(i==loc)
	{
	q->next=p->next;
	//printf("q->data=%d",p->data);
	if(head==NULL||p==NULL||q==NULL)
    {
        printf("something null");
    }
	write();
	p=NULL;
	free(p);
	//printf("freed p");
	}//if
	}//else
	printf("incremented");
	p=p->next;
	q=q->next;
	i++;
	}//for
	p=head;
	q=head;
	}
	else
	{
	printf("\nSorry,The list is empty");
	}
	}//void delete

void search()
	{
	read();

    while(1)
    {
    int data,found=0;
	p=head;

    printf("Search by name(1) or by product id(2)? back(3):");
    scanf("%d",&c);

	if(c==1){
        printf("\n\nEnter the name you want to search=");
	scanf("%s",name);

	for(i=1;p!=NULL;i++)
	{
    strcpy(obj.name,p->name);
	if(!strcmp(strlwr(obj.name),strlwr(name)))
	{
	printf("\nName found at %dth location",i);
	printf("\n\n\nPid=%d  price=%f  name=%s description=%s type=%s date=%d/%d/%d Quantity_available=%d\n\n",p->data,p->price,p->name,p->item_description,p->item_type,p->mdate,p->mmonth,p->myear,p->qty);
	found=1;
	}
	p=p->next;
	}
	if(!found)
	{
	printf("\nNo entry found coorresponding to your data\n\n");
	}
	}
	if(c==2){
    printf("\n\nEnter the data you want to search=");
	scanf("%d",&data);

	for(i=1;p!=NULL;i++)
	{
	if(p->data==data)
	{
	printf("\nProuct id found at %dth location",i);
	printf("\n\n\nPid=%d Price=%f name=%s description=%s type=%s date=%d/%d/%d Quantity_available=%d\n\n",p->data,p->price,p->name,p->item_description,p->item_type,p->mdate,p->mmonth,p->myear,p->qty);
	found=1;
	}
	p=p->next;
	}
	if(!found)
	{
	printf("\nNo entry found corresponding to your Product id\n\n");
	}
	}
	if(c==3){break;}

    printf("Press enter to continue");
    getch();
    }
	}



void write()
	{

	FILE *ne=fopen("newfile.txt","w");
	int i;
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
	    printf("list is empty");
	}
	else
	{
	printf("\n list is being saved");
	for(i=0;temp!=NULL;i++)
	{
	fprintf(ne,"%d %f %s %s %s %d %d %d %d\n",temp->data,temp->price,temp->name,temp->item_description,temp->item_type,temp->mdate,temp->mmonth,temp->myear,temp->qty);

	temp=temp->next;
	}//for
	printf("\nDone.");

	}//else

	fclose(ne);
	}

void read()
	{
    head=NULL,p=NULL,last=NULL,q=NULL,user_head=NULL,user_last=NULL,x=NULL;
	int i,filempty=0;
	FILE *infile=fopen("newfile.txt","r");
	p=head;
	fseek(infile,0,SEEK_END);
	if(p==NULL)
	{
	p=(struct node*)malloc(sizeof(struct node));
	head=p;
	}

	int len=(int)ftell(infile);
	if(len<=0)
	{
	filempty=1;
	p=NULL;
	head=p;
	}

	if(filempty==0)
	{
	rewind(infile);
	/*while(fscanf(infile,"%d %f %s %s %s %d %d %d %d\n",&p->data,&p->price,p->name,p->item_description,p->item_type,&p->mdate,&p->mmonth,&p->myear,&p->qty))
	{
	if(feof(infile))
	{
	break;

	}
	p->next=(struct node*)malloc(sizeof(struct node));
	p=p->next;
	last=p;
	p->next=NULL;
	}//while*/
	for(;;)
    {

        fscanf(infile,"%d %f %s %s %s %d %d %d %d\n",&p->data,&p->price,p->name,p->item_description,p->item_type,&p->mdate,&p->mmonth,&p->myear,&p->qty);
        p->next=NULL;
        last=p;
      if(feof(infile))
	{
	break;
	}
        p->next=(struct node*)malloc(sizeof(struct node));
	p=p->next;

	p->next=NULL;

    }


	}//if
	}//void read

void user_write()
{
	FILE *ne=fopen(authorised_un,"w");
	int i;
	struct node *temp;
	temp=user_head;
	if(temp==NULL)
	{
	    printf("list is empty");
	}
	else
	{
	printf("\n list is being saved");
	for(i=0;temp!=user_last;i++)
	{
	fprintf(ne,"%d %f %s %s %s %d %d %d %d\n",temp->data,temp->price,temp->name,temp->item_description,temp->item_type,temp->mdate,temp->mmonth,temp->myear,temp->qty);
	temp=temp->next;
	}//for
	printf("\nDone.");

	}//else

	fclose(ne);
}


void read_user()
{
    //head=NULL,p=NULL,last=NULL,q=NULL,user_head=NULL,user_last=NULL,x=NULL;
	int i,filempty=0;
	FILE *infile=fopen(authorised_un,"r");
	if(!(infile=fopen(authorised_un,"r")))
    {
    FILE *infile=fopen(authorised_un,"w");
    }

	user_head=NULL;
	p=user_head;

	if(p==NULL)
	{
	p=(struct node*)malloc(sizeof(struct node));
	p->next=NULL;
	user_head=p;
	}
	fseek(infile,0,SEEK_END);

	int len=(int)ftell(infile);
	if(len<=0)
	{
	filempty=1;
	printf("File empty");
	user_head=NULL;
	}
	if(filempty==0)
	{
	rewind(infile);
	while(fscanf(infile,"%d %f %s %s %s %d %d %d %d\n",&p->data,&p->price,p->name,p->item_description,p->item_type,&p->mdate,&p->mmonth,&p->myear,&p->qty))
	{
	if(feof(infile))
	{

    p->next=(struct node*)malloc(sizeof(struct node));
    user_last=p->next;
    user_last->next=NULL;
	break;
	}
	p->next=(struct node*)malloc(sizeof(struct node));
	p=p->next;
	user_last=p;
	p->next=NULL;
	}//while
	}//if

}



	int admin()
	{
		int ch,x;
	do
	{
	printf("\n Singly linked list operation");
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\t\t\t\t\t\t\t\t|1.Create|\t\n\t\t\t\t\t\t\t\t|2.Display|\t\n\t\t\t\t|3.Insert\t|\n\t\t\t\t\t\t\t\t\t\t|4.Sort\t|\n\t\t|5.reverse\t|\n\t\t\t\t\t\t\t\t\t\t\t\t|6.write\t\n||7.read\t|\n\t\t\t\t\t\t\t\t\t\t|8.delete|\t\n\t\t|9.search|\t\n\t\t\t\t\t\t\t\t|10.modify\t|\n\t\t\t\
        |11.graph\t|\n\t\t\t\t\t\t\t|12.exit\t|");
	printf("\n\t\t\t\t\tEnter your choice\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	create();
	break;
	case 2:
	display();
	break;
	case 3:
	insert();
	break;
	//n=n+1;
	case 4:
	sort(head);
	break;
	case 5:
	reverse();
	break;
	case 6:
	write();
	break;
	case 7:
	read();
	break;
	case 8:
        delete1();
        break;
	case 9:
	search();
	break;
	case 10:
	modify();
	break;
	case 11:
	graph();
	break;
	case 12:

    return 0;
    ch=13;
    break;
    case 13:
    break;
	}
	}while(ch!=13);

	return 0;
	}

	void user()
	{

    account_run();
	int c;
	int exitt=0;
	display();
	while(exitt==0)
	{
	printf("\n\nEnter your operation \t\t\t1.Buy directly\n \t\t\t\t\t2.add to cart\n \t\t\t\t\t3.show items\n \t\t\t\t\t4.show cart\n \t\t\t\t\t5.back ");
	scanf("%d",&c);

	switch(c)
	{
	case 1:
	buy();
	break;
	case 2:
	add_to_cart();
	break;
	case 3:
	display();
	break;
	case 4:
        user_cart();
        break;
        case 5:
        exitt=1;
        break;
	}//switch
	}//while
	}//void user

void add_to_cart()
{
    int found=0;
    display();
	read_user();
    printf("Enter the location to add to cart");
    scanf("%d",&loc);

    p=head;
    q=user_last;
    x=user_head;



	for(i=1;i<=loc;i++)
	{
	if(loc==i)
	{
	    if(p->qty<0)
	    {
            printf("Sorry, item out of stock");
            break;
            }
	    while(1){
                while(1){
                printf("\nEnter the quantity:");
                scanf("%d",&qty);
        if(qty<0){printf("Negative quantity won't work.");}
        else{break;}
                }
    if(p->qty>=qty){p->qty=p->qty-qty;
                    break;}
    else{printf("Not enough stock.Please enter less quantity");}
	}
    if(x!=NULL)
    {
        for(;x!=NULL;)
        {
            if(x->data==p->data&&!strcmp(x->name,p->name))
            {
                found=1;
                break;
            }
            x=x->next;
        }
    }
    if(q==NULL)
    {
    q=(struct node*)malloc(sizeof(struct node));
    q->next=NULL;
    user_head=q;
    }
    if(found){x->qty=x->qty+qty;}
    if(!found)
    {
	q->data=p->data;
	q->price=p->price;
	q->mdate=p->mdate;
	q->mmonth=p->mmonth;
	q->myear=p->myear;
	q->qty=qty;
	strcpy(q->name,p->name);
	strcpy(q->item_description,p->item_description);
	strcpy(q->item_type,p->item_type);


	q->next=(struct node*)malloc(sizeof(struct node));
	q=q->next;
	user_last=q;
	q->next=NULL;
    }
	}//if
	if(p==NULL)
	{
    printf("Theres nothing in that location.Just for you to know,the first number at the beginning of a record is its location.");
	break;
	}//if

	p=p->next;

	}//for

	user_write();
	write();

}

void buy()
{	int total;
	read();
	p=head;
	printf("Enter the location of item to buy");
	scanf("%d",&loc);
	printf("Enter the quantity:");
	scanf("%d",&qty);
	for(i=1;p!=user_last;i++)
	{
	if(i==loc)
	{
	total=p->price*qty;
	break;
	}
	p=p->next;
	}
	printf("\n\n%d\t",p->data);
	printf("%s\t",p->name);
	printf("%s\t",p->item_description);
	printf("%s\t",p->item_type);
	printf("%d/%d/%d\t",p->mdate,p->mmonth,p->myear);
	printf("%.2f\t",p->price);
	p->qty=p->qty-qty;
	printf("%d\t\n",qty);


	printf("Item(s) bought directly");
	printf(".Please pay rs %d to the delivery man",total);

	write();
}


void user_cart()
{

	int ch,choice;
	float sum=0;
	printf("user cart");
	read_user();
	int i;
	p=user_head;
	if(p==NULL)
	{
	printf("cart is empty");
	}
	else
	{
	    /*
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	*/printf("\nCart items are::");

	printf("\n*-----/------*------/--------Cart-------/---------*----/---*");
	for(i=1;p!=user_last;i++)
	{
    printf("\n--------------------------------------------------------");
	sum=sum+p->price*p->qty;
	printf("\n\n(%d)Pid=%d    ",i,p->data);
	printf("price=%.2f    ",p->price);

	printf("name=%s    ",p->name);
	printf("Item_description=%s    ",p->item_description);
	printf("Type=%s    ",p->item_type);
	printf("Date=%d/%d/%d    Qty=%d    ",p->mdate,p->mmonth,p->myear,p->qty);
	//write printf("%s\t",p->name);  and other variables
	p=p->next;

	}//for
    printf("\n\n");
	printf("\nYour total amount to be paid is :-%.2f\n",sum);

	if(sum>=599)
	{
	printf("\nCongratulations! you are eligible for free delivery");
	}
	else{printf("\nGet free delivery for just %.2f rs worth of shopping more",(599.00-sum));}


	printf("What do you want to do?:-1.Delete cart items 2.Empty cart 3.Buy all 4.Buy Selective 5.Shop more");
	scanf("%d",&choice);

	switch(choice)
	{
    case 1:
        cart_delete();
        break;
    case 2:
        empty_cart();
        break;
    case 3:
        buy_all();
        break;
    case 4:
        buy_selective();
        break;
    case 5:
        break;
    default:
        break;
	}



	}

}



void graph()
{
    read();
    int max;

    printf("\n1.Item-Price graph\t2.Record-Date graph.\nPlease enter a choice:");
    scanf("%d",&c);

    switch(c)
    {case 1:
    {
    int j;
	int value;
	float height=0,scale;
	int length;
	read();
	p=head;
	for(i=1;p!=NULL;i++)
	{
	if(height<p->price)
	{
	height=p->price;
	}
	p=p->next;
	}
	length=100/i;
	p=head;
    printf("Largest value of price in database is %f\nPlease enter your preferred scale (in Rs):",height);
    scanf("%f",&scale);
    height=height/scale;
	for((i=(int)height+10);i>=0;i--)
	{
	printf("\n|");
	p=head;
	for(;p!=NULL;)
	{
	value=((int)p->price);
	if(i<=value/scale)
	{
	printf("\t||");
	}
	else{printf("\t");}
	p=p->next;
	}
	}
	p=head;
	printf("\n\n");
	printf("0");
	for(j=1;p!=NULL;j++)
	{
	printf("\t%d",j);
	p=p->next;
	}
	printf("\n\n");
	printf("Please note that one bar means value for 0 to %.2f.\nSo for prices having 0 to %.2f RS the Graph may have only one bar.\n",scale,scale);
	p=head;
	for(i=1;p!=NULL;i++)
	{
	printf("%d.%s(%.2f)RS\n",i,p->name,p->price);
	p=p->next;
	}

    printf("Press Enter to continue");
    getch();
    }
    break;
    case 2:
    {
        printf("h");
     int month[13];
    int j;
    char smonth[10];

    /*int jan=0;
    int feb=0;
    int march=0;
    int april=0
    int may=0;
    int june=0;
    int july=0;
    int august=0;
    int september=0;
    int october=0;
    int november=0;
    int december=0;*/


    for(i=1;i<=12;i++)
    {
    month[i]=0;
    }


    for(x=head;x!=NULL;x=x->next)
    {
    for(i=1;i<=12;i++)
    {

    if(i==x->mmonth)
    {
        month[i]++;

    }
    }
    }

    for(i=1;i<=12;i++)
    {
        if(max<month[i])
        {
        max=month[i];
        }
    }


    printf("\n\n\n");
    for(j=1;j<=12;j++)
    {
    switch(j)
    {case 1:
    printf("\n\tJan\t|");
    break;
    case 2:
    printf("\n\tFeb\t|");
    break;
    case 3:
    printf("\n\tMar\t|");
    break;
    case 4:
    printf("\n\tApr\t|");
    break;
    case 5:
    printf("\n\tMay\t|");
    break;
    case 6:
    printf("\n\tJun\t|");
    break;
    case 7:
    printf("\n\tJul\t|");
    break;
    case 8:
    printf("\n\tAug\t|");
    break;
    case 9:
    printf("\n\tSept\t|");
    break;
    case 10:
    printf("\n\tOct\t|");
    break;
    case 11:
    printf("\n\tNov\t|");
    break;
    case 12:
    printf("\n\tDec\t|");
    break;
    }
    for(i=1;i<=month[j];i++)
    {
    printf("||||||||");
    }
    printf("_]");
    printf("(%d)\t\t\tentries in this month",month[j]);

    }
    printf("\n\n\n");

    }
    break;
}
}
/*
int pid(int pid)
{
	int i=0;
	printf("ghj");
	struct node* x=head;
	if(x==NULL)
	{
	    printf("sdf");
	return 0;
	}else{
	    printf("ssgddf");
	    for(i=0;x!=NULL;i++)
	{if(x->data==pid)
	{return 1;}
	x=x->next;}
	}
    printf("dsf");
    printf("sdfgf");
	return 0;
}
*/


int idser()
{
	x=head;
	for(i=0;x!=NULL;i++)
    {
        if(x->data==obj.data)
        {
        return 1;
        break;
        }
        x=x->next;
    }
    return 0;
}


int nameser()
{

	x=head;
	for(i=0;x!=NULL;i++)
    {
        if(!strcmp(x->name,obj.name))
        {
        return 1;
        break;
        }
        x=x->next;
    }
    return 0;
}


int chkda()
{
    time_t t=time(NULL);
    struct tm tm =*localtime(&t);
    printf("%d %d %d",tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday);

    myear=tm.tm_year+1900;
    mmonth=tm.tm_mon+1;
    mdate=tm.tm_mday;

    if(myear>obj.myear){if(mmonth>obj.mmonth&&obj.mmonth<13){if(mdate>obj.mdate&&obj.mdate<31){return 0;}
                                                if(mdate<obj.mdate&&obj.mdate<31){return 0;}
                                                if(mdate==obj.mdate&&obj.mdate<31){return 0;}}
                        if(mmonth<obj.mmonth&&obj.mmonth<13){if(mdate>obj.mdate&&obj.mdate<31){return 0;}
                                                if(mdate<obj.mdate&&obj.mdate<31){return 0;}
                                                if(mdate==obj.mdate&&obj.mdate<31){return 0;}}
                        if(mmonth==obj.mmonth&&obj.mmonth<13){if(mdate>obj.mdate&&obj.mdate<31){return 0;}
                                                if(mdate<obj.mdate&&obj.mdate<31){return 0;}
                                                if(mdate==obj.mdate&&obj.mdate<31){return 0;}}
                                                return 1;}
    if(myear<obj.myear){/*if(mmonth>obj.mmonth){if(mdate>obj.mdate){}
                                                if(mdate<obj.mdate){}
                                                if(mdate==obj.mdate){}}
                        if(mmonth<obj.mmonth){if(mdate>obj.mdate){}
                                                if(mdate<obj.mdate){}
                                                if(mdate==obj.mdate){}}
                        if(mmonth==obj.mmonth){if(mdate>obj.mdate){}
                                                if(mdate<obj.mdate){}
                                                if(mdate==obj.mdate){}}*/return 1;}
    if(myear==obj.myear){if(mmonth>obj.mmonth&&obj.mmonth<13){if(mdate>obj.mdate&&obj.mdate<31){return 0;}
                                                if(mdate<obj.mdate){return 1;}
                                                if(mdate==obj.mdate&&obj.mdate<31){return 0;}}
                        if(mmonth<obj.mmonth&&obj.mmonth<13){/*if(mdate>obj.mdate){}
                                                if(mdate<obj.mdate){}
                                                if(mdate==obj.mdate){}*/return 1;}
                        if(mmonth==obj.mmonth&&obj.mmonth<13){if(mdate>obj.mdate&&obj.mdate<31){return 0;}
                                                if(mdate<obj.mdate&&obj.mdate<31){return 0;}
                                                if(mdate==obj.mdate&&obj.mdate<31){return 0;}}
                                                return 1;}

                                                return 0;
}


void cart_delete()
{
	read_user();
	read();
	int loc,i;
	printf("Enter the location to delete");
	scanf("%d",&loc);

	p=user_head;

	for(i=1;i<=loc;i++)
    {
        data=p->data;
        strcpy(name,p->name);
        qty=p->qty;
        p=p->next;
    }
    q=head;

    for(;q!=user_last;)
    {
        if(data==q->data&&!strcmp(name,q->name))
        {
            printf("found");
            q->qty=q->qty+qty;
            break;
        }
        q=q->next;
    }

	printf("Number %d is being deleted.Please wait",loc);
    p=user_head;
	if(p!=NULL)
	{
	q=user_head;
	p=q->next;


	for(i=1;i<=loc;)
	{
	if(i==2)
	{
	q=user_head;
	p=q->next;
	}
	if(i==loc&&i==1)
	{
    if(user_head->next!=NULL)
	{user_head=user_head->next;}
	else{user_head=NULL;
	user_last=NULL;}
	//printf("qdata=%d",q->data);
	free(q);
	write();
	//printf("freed q");
	break;
	}
	else
	{
	if(i==loc)
	{
	q->next=p->next;
	//printf("q->data=%d",p->data);
	write();
	free(p);
	//printf("freed p");
	}//if
	}//else
	//printf("incremented");
	p=p->next;
	q=q->next;
	i++;
	}//for
	p=user_head;
	q=user_head;
	}
	else
	{
	printf("\nSorry,The list is empty");
	}
	user_write();
	write();
	}//void cart_delete

	void buy_all()
	{
    int ch;
    float sum=0;

    q=user_head;
	for(i=0;q!=user_last;i++)
    {
        //printf("iterated");
        sum=sum+q->price*q->qty;
        q=q->next;
        //printf(" it");
    }

    printf("\nDo you want to proceed to buy all the selected items (%.2f rs)?1.Yes 2.No",sum);
	scanf("%d",&ch);

	if(ch==1)
	{
	printf("\nOrder placed.Please pay rs %.2f to the delivery man",sum);
	x=user_head;

	/*
	for(;q!=user_last;)
    {
        free(x);
        x=q->next;
        free(q);
        q=x->next;
    }*/
    user_head=NULL;
    user_last=NULL;
	}
	user_write();
	}

void empty_cart()
{
    int i,j;
    read();
    read_user();
    p=head;
    x=user_head;
    printf("Do you really want to empty the cart?1.Yes 2.No");
    scanf("%d",&c);

    if(c==1){
            for(i=1;x!=user_last;i++,x=x->next)
            {
                for(j=1;p!=NULL;j++,p=p->next)
                {
                    if(x->data==p->data&&!strcmp(x->name,p->name))
                    {
                        p->qty=p->qty+x->qty;
                    }
                }
            }



    user_head=NULL;
    user_last=NULL;
    FILE *ne=fopen("authorised_un","w");
    fclose(ne);
    }
    write();
    user_write();

}



void buy_selective()
{
        int found=0,tax,ch;
        float sum;
    read_user();
    printf("Enter the location to buy");
	scanf("%d",&loc);

    x=user_head;
    p=user_head;
    for(i=1;i<=loc;i++)
    {
        printf("%d",p->data);
    if(i==loc)
    {
        found=1;
        printf("%d",p->data);
        sum=p->price;
        break;
    }

    if(x==NULL)
    {
        break;
    }
    p=p->next;

    }
    if(sum<599){tax=50;}
    else{tax=0;}

    if(!found)
    {
    printf("No item in selected location");
    }
    if(found)
    {
    printf("\nDo you want to proceed to buy the selected item (%.2f rs+%d(tax))?1.Yes 2.No",sum,tax);
	scanf("%d",&ch);

	if(ch==1)
	{
    sum=sum+tax;
	printf("\nOrder placed.Please pay rs %.2f to the delivery man",sum);
	}


    read_user();


	printf("Number %d is being deleted.Please wait",loc);

	if(p!=NULL)
	{
	q=user_head;
	p=q->next;


	for(i=1;i<=loc;)
	{
	if(i==2)
	{
	q=user_head;
	p=q->next;
	}
	if(i==loc&&i==1)
	{
	    if(user_head->next==user_last){user_head=NULL;user_last=NULL;}
	    else{
    user_head=user_head->next;
	free(q);}

	user_write();
	break;
	}
	else
	{
	if(i==loc)
	{
	q->next=p->next;
	//printf("q->data=%d",p->data);
	user_write();
	free(p);
	//printf("freed p");
	}//if
	}//else
	printf("incremented");
	p=p->next;
	q=q->next;
	i++;
	}//for
	p=user_head;
	q=user_head;
	}
	else
	{
	printf("\nSorry,The list is empty");
	}

}

    user_write();
}

/*
void account_run()
{
    char password1[16],user_name1[50];
    int found=1;
    FILE *user_name_read=fopen("user_name_data","r");


    printf("Please enter your username");
    scanf("%s",user_name1);

    while(fscanf("%s %s\n",obj_a.user_name,obj_a.password))
    {
        if(strcmp(user_name1,obj_a.user_name))
        {
            printf("username found");
            found=1;
            break;
        }
    }

    if(!found)
    {
        printf("Username not found.Please try again");
    }
    if(found)
    {
        printf("Please Enter your password");
        scanf("%s",password1);

        if(strcmp(obj_a.password,password1))
        {
            printf("Welcome to your account.We missed you.....");
        }
        else{printf("Sorry wrong password");}


    }


}
*/
