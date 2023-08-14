/*Project for shop management. Code for a cloth shop management.
Programmed by Adil & team. Submitted to HSM sir as project.*/

#include<stdio.h>
#include<stdlib.h> //This header file is for standard library functions
#include<conio.h>
#include<string.h>
#define max 50  // Creating a value for array and string and for other use.

int H;

typedef struct product_info    // A structure named product is created to store product information.
{
    char name1[max];
    int id;
    char color[max];
    char size[max];
    char storage[max];
    float price;
    float rating;
} P;


typedef struct employee   // A structure named Employee is created to store and get employee's detailed information.
{
    char nam[max];
    char post[max];
    char id1[max];
    char phn[max];
    float salary;
} E;

typedef struct customer_info  // A structure named Customer_info is created to store customer's information and order.
{
    char name[max];
    char order[max];
    char phone[max];
    char address[max];

} C;

int main  ( ) //main function starts here
{


    while(1)  //an infinite loop to get value till user ends
    {
        cover(); //calling void finction named cov for cover
        showMenu();

    }
    getch();
    return 0;
}

void cover(void)  //void function for cover
{

    printf("\n\t\t\t\t\t*****************************************************************************\n");
    printf("\t\t\t **                                                                         **\n");
    printf("\t\t\t **                                                                         **\n");
    printf("\t\t\t **                                                                         **\n");
    printf("\t\t\t **                                                                         **\n");
    printf("\t\t\t ++                          NSU cloth store                                ++\n");
    printf("\t\t\t **                             programmed by:Adil,noman,Adam               **\n");
    printf("\t\t\t **                                                                         **\n");
    printf("\t\t\t **                                                                         **\n");
    printf("\t\t\t **                                                                         **\n");
    printf("\t\t\t **                                                                         **\n");
    printf("\t *****************************************************************************\n");

}



void showMenu(void) //Function for menu
{
    int option;
    printf("\n\n%60s\n%60s\n%60s\n%61s\n%63s\n%62s\n%61s","Menu","****","1.Add","2.Show","3.Delete","4.About","5.Exit"); //Menu Options
    printf("\nEnter your choice:");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        addmenu(); //calling addmenu functions for add options
        break;
    case 2:
        show();  //calling show functions for show options
        break;
    case 3:
        dlt( );     //calling edit functions for edit options
        break;
    case 4:  // about this project
        printf("%60s\n%67s\n%57s","//This is a shop management software.//","//Created and Programmed by AbmHimel & Team.//","//Submitted to HSM sir as project.//"); //About
        printf("\n");
        break;
    case 5:
        exit(0);   //"exit();" is a built in function under <stdlib> header file.
        break;           // that terminates the programme and return a value to the OS.
    default:   //default case if user input invalid choice
        printf("\n%60s\n%58s","Invalid choice!!!!!","Please try again.");
        printf("\n");
        break;
    }

}
void addmenu()  //addmenu function to show menu to add goods,employee,customer information
{
    int add;
    printf("\n%60s\n%63s\n%63s\n%55s\n%55s","1.Add Goods","2.Add Employee","3.Add Customer","4.Menu","5.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&add);

    switch(add)
    {
    case 1:
        addgoods(); //used to add product
        break;
    case 2:
        addemployee("employee.txt");  //to add employee information
        break;
    case 3:
        addcustomer("customer.txt");  //to add customer information
        break;
    case 4:
        showMenu();  //to call menu function
        break;
    case 5:
        exit(0);
        break;
    default:   //default case if user input invalid choice
        printf("%60s\n%60s","you entered wrong choice!!!!!!","please try again");
        addmenu();
        printf("\n");
        break;
    }

}

int addgoods(void)  //option for adding goods
{
    int a;
    printf("\n\n\n");
    printf("%60s\n%62s\n%66s\n%65s\n%57s\n%54s\n%54s","1.Man's Wear","2.Women's Wear","3.Baby girl's Wear","4.Baby boy's Wear","5.go back","6.menu","7.exit");
    printf("\n");
    printf("Enter your choice:");
    scanf("%d",&a);
    H=a;
    return addgoods1(a);
}
void addgoods1(int a)
{

    switch (a)
    {
    case 1:
        addgood("Man's wear.txt"); //option 1 for adding men's wear
        break;
    case 2:
        addgood("women's wear.txt"); //option 2 for adding women's wear
        break;
    case 3:
        addgood("baby girl's wear.txt"); //option 3 for adding girls's wear
        break;
    case 4:
        addgood("baby boy's wear.txt"); //option 4 for adding boy's wear
        break;
    case 5:
        addmenu(); //calling function adding goods menu
        break;
        case 6:
            cover();
        showMenu(); //calling function adding goods menu
        break;
    case 7:
        exit(0); //exiting out function
        break;
    default:
        printf("\n\n\tInvalid Choice!!!!!!!!.\nPlease Try Again.");
        addgoods();
        printf("\n");
        break;
    }
}


void addgood(char filename[40]) //function to add goods
{
    P x;
    FILE *fp;
    fp=fopen(filename,"a");   //Creating a file to store goods information

    printf("\n\tEnter Product Name:");   /* getting goods information */
    getchar();
    gets(x.name1);
    printf("\n\tEnter Id:");
    scanf("%d",&x.id);
    printf("\n\tEnter Color:");
    getchar();
    gets(x.color);
    printf("\n\tEnter Size:");
    scanf("%s",&x.size);
    printf("\n\tEnter Storage:");
    scanf("%s",&x.storage);
    printf("\n\tEnter Price:");
    scanf("%f",&x.price);
    printf("\n\tEnter Rating:");
    scanf("%f",&x.rating);

    fputs(x.name1,fp);      // store goods information in a file named "goods.txt"
    fprintf(fp,"\n");

    fprintf(fp,"%d",x.id);
    fprintf(fp,"\n");     // creating a new line in file after one information

    fputs(x.color,fp);
    fprintf(fp,"\n");

    fputs(x.size,fp);
    fprintf(fp,"\n");

    fputs(x.storage,fp);
    fprintf(fp,"\n");

    fprintf(fp,"%f",x.price);
    fprintf(fp,"\n");

    fprintf(fp,"%f",x.rating);
    fprintf(fp,"\n");
    fclose(fp);
    printf("\n");
    printf("%60s","Information stored successfully!!!!!!");
    printf("\n\n");
    addgood_def();
}
void addgood_def(void) //default function for additional options
{
    int a;
    printf("%60s\n%60s\n%62s\n%57s\n","1.AddMore","2.go back","3.Main Menu","4.Exit");
    printf("ENter your choice:");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        addgoods1(H);
        break;
    case 2:
        addmenu();
        break;

    case 3:
        cover();
        showMenu();
        break;

    case 4:
        exit(0);// exit is a built in function that terminates the programme returning a value to the OS

    default:
        printf("\nInvalid Choice!!!!!!!!.\nPlease Try Again.");
        printf("\n");
        addgood_def();
        break;
    }
}


void addemployee(char filename[40])
{
    E y;   // declearing a variable for employee structure
    FILE *f;
    f=fopen(filename,"a"); // creating a file here

    printf("\n\tEnter Employee Name:"); //store information to structure
    getchar();
    gets(y.nam);
    printf("\n\tEnter Employee Post:");
    gets(y.post);
    printf("\n\tEnter Employee ID:");
    scanf("%s",&y.id1);
    printf("\n\tEnter Employee Phone number:");
    scanf("%s",&y.phn);
    printf("\n\tEnter Employee Salary:");
    scanf("%f",&y.salary);

    fputs(y.nam,f);  //storing information to the file
    fprintf(f,"\n");

    fputs(y.post,f);
    fprintf(f,"\n");

    fputs(y.id1,f);
    fprintf(f,"\n");

    fputs(y.phn,f);
    fprintf(f,"\n");

    fprintf(f,"%f",y.salary);
    fprintf(f,"\n");

    fclose(f);

    employee_def();
}
void employee_def(void)
{
    int b;
    printf("%60s\n%60s\n%62s\n%57s\n","1.AddMore","2.go back","3.Main Menu","4.Exit");
    printf("ENter your choice:");
    scanf("%d",&b);
    switch(b)
    {
    case 1:
        addemployee("Employee.txt");  //passing filename calling addemployee function
        break;
    case 2:
        addmenu();
        break;

    case 3:
        cover();
        showMenu();
        break;

    case 4:
        exit(0);// exit is a built in function that terminates the programme returning a value to the OS
        break;

    default:
        printf("\n\n\tInvalid Choice!!!!!!!!.\n\nPlease Try Again.");
        printf("\n");
        employee_def();
        break;

    }
}

void addcustomer(char filename[20])  //store customer information
{
    C x1;
    FILE *fp;
    fp=fopen(filename,"a");
    printf("\n\tEnter customers Name:"); //getting customer information
    getchar();
    gets(x1.name);
    printf("\n\tEnter customers order:");
    gets(x1.order);
    printf("\n\tEnter customers Phone Number:");
    gets(x1.phone);
    printf("\n\tEnter customers Address:");
    gets(x1.address);

    fputs(x1.name,fp); //storing information to the file
    fprintf(fp,"\n");

    fputs(x1.order,fp);
    fprintf(fp,"\n");

    fputs(x1.phone,fp);
    fprintf(fp,"\n");

    fputs(x1.address,fp);
    fprintf(fp,"\n");

    fclose(fp);

    printf("\n");
    printf("%60s\n","Information stored successfully!!!!!!");
    printf("\n");
    customer_def();


}
void customer_def(void)
{
    int a;
    printf("%60s\n%60s\n%62s\n%57s\n","1.AddMore","2.go back","3.Main Menu","4.Exit");
    printf("ENter your choice:");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        addcustomer("customer.txt");
        break;
    case 2:
        addmenu();
        break;

    case 3:
        cover();
        showMenu();
        break;

    case 4:
        exit(0);// exit is a built in function that terminates the programme returning a value to the OS
    default:
        printf("\n\n\tInvalid Choice!!!!!!!!.\n\nPlease Try Again.");
        printf("\n");
        customer_def();
        break;
    }
}

void show(void)  //show function is used to show inputed data
{
    int i;

    printf("%60s\n%63s\n%63s\n%54s\n%54s","1.Show Goods","2.Show Employee","3.Show Customer","4.Menu","5.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&i);

    switch(i)
    {
    case 1:
        showgoods(); //to show goods
        break;
    case 2:
        showemployee( );
        break;
    case 3:
        showcustomer( );
        break;
    case 4:
        showMenu();
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("\n\n\tInvalid Choice!!!!!!!!.\nPlease Try Again.");
        printf("\n");
        show();
        break;
    }
}
void showgoods(void) //to show goods items
{
    int j;
    printf("%60s\n%62s\n%66s\n%65s\n%52s\n%49s\n%49s","1.Show Man's Wear","2.Show Women's Wear","3.Show Baby Girl's Wear","4.Show Baby Boy's Wear","5.go back","6.Menu","7.Exit");
    printf("\n");
    printf("Enter your choice:");
    scanf("%d",&j);
    switch (j)
    {
    case 1:
        showproduct("Man's wear.txt");
        break;
    case 2:
        showproduct("women's wear.txt");
        break;
    case 3:
        showproduct("baby girl's wear.txt");
        break;
    case 4:
        showproduct("baby boy's wear.txt");
        break;
    case 5:
        show();
        break;
    case 6:
        showMenu();
        break;

    case 7:
        exit(0);
        break;
    default:
        printf("\n\n\tInvalid Choice!!!!!!!!.\nPlease Try Again.");
        printf("\n");
        showgoods();
        break;
    }

}

void showproduct(char filename[30])  //function to show product information by searching or showing all
{
    int i;
    printf("%60s\n%54s\n%53s\n%50s\n%50s","1.Show By Search","2.Show All","3.go back","4.Menu","5.Exit");
    printf("\n");
    printf("Enter your choice:");
    scanf("%d",&i);
    switch (i)
    {
    case 1:
        searchshow(filename);
        break;
    case 2:
        allshow(filename);
        break;
    case 3:
        showgoods();
        break;
    case 4:
        cover();
        showMenu();
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("\n\n\tInvalid Choice!!!!!!!!.\nPlease Try Again.");
        printf("\n");
        showproduct(filename);

        break;
    }
}


void searchshow(char filename[max]) //to show by searching item
{
    FILE *fp;
    char search[max];
    P x[100];
    int i=0;
    int index;
    int found=0;
    printf("Enter Name to Search:");
    getchar();
    gets(search);


    fp=fopen(filename,"r");
    if(fp==NULL)
    {
        perror("Error opening file");
    }
    else
    {
        while( !feof(fp))
        {
            fflush(stdin);
            fgets(x[i].name1,30,fp);
            fscanf(fp,"%d\n",&x[i].id);
            fgets(x[i].color,30,fp);
            fgets(x[i].size,30,fp);
            fgets(x[i].storage,30,fp);
            fscanf(fp,"%f\n",&x[i].price);
            fscanf(fp,"%f\n",&x[i].rating);

            int y;
            y=strlen(x[i].name1);
            x[i].name1[y-1]='\0';

            if(strcmp(x[i].name1,search)==0)
            {
                index=i;
                found=1;
                break;
            }
            else
            {
                found=0;
            }
            i++;
        }


        if(found==1)
        {
            fflush(stdin);
            printf("\n");
            printf("\nProduct Name : ");
            puts(x[index].name1);
            printf("\nID\t     : %d",x[index].id);
            printf("\nColor\t     : ");
            puts(x[index].color);
            printf("Sizes\t     : ");
            puts(x[index].size);
            printf("\nStorage      : ");
            puts(x[index].storage);
            printf("\nPrice\t     : %.2f\n",x[index].price);
            printf("\nRating \t: %.2f",x[index].rating);
        }

        else if(found==0)
        {
            printf("NO match Found!!!!!!");
        }
        fclose(fp);
    }
}
void allshow(char filename[30]) //to show all goods
{
    P x;
    int i=0;
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL)
    {
        perror("Error opening file");
    }
    else
    {
        while( !feof(fp))
        {
            fflush(stdin);
            fgets(x.name1,30,fp);
            fscanf(fp,"%d\n",&x.id);
            fgets(x.color,30,fp);
            fgets(x.size,30,fp);
            fgets(x.storage,30,fp);
            fscanf(fp,"%f\n",&x.price);
            fscanf(fp,"%f\n",&x.rating);
            i++;
            printf("Product No:%d\n\n",i);

            fflush(stdin);
            printf("\n");
            printf("\nProduct Name : ");
            puts(x.name1);
            printf("\nID\t     : %d",x.id);
            printf("\nColor\t     : ");
            puts(x.color);
            printf("Sizes\t     : ");
            puts(x.size);
            printf("\nStorage      : ");
            puts(x.storage);
            printf("\nPrice\t     : %.2f\n",x.price);
            printf("\nRating \t: %.2f",x.rating);
            printf("\n\n");
        }
    }
}
void showemployee(void)  //menu to show employee
{
    int i;
    printf("%60s\n%54s\n%53s\n%50s\n%50s","1.Show By Search","2.Show All","3.go back","4.Menu","5.Exit");
    printf("\n");
    printf("Enter your choice:");
    scanf("%d",&i);
    switch (i)
    {
    case 1:
        searchshowemployee("employee.txt");
        break;
    case 2:
        allshowemployee("employee.txt");
        break;
    case 3:
        show();
        break;
    case 4:
        cover();
        showMenu();
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("\n\n\tInvalid Choice!!!!!!!!.\nPlease Try Again.");
        printf("\n");
        showemployee();

        break;
    }

}
void searchshowemployee(char filename[30]) //to show employee by searching
{

    FILE *fp;
    char search[max];
    E x[100];
    int i=0;
    int index;
    int found=0;
    printf("Enter Name to Search:");
    getchar();
    gets(search);


    fp=fopen(filename,"r");
    if(fp==NULL)
    {
        perror("Error opening file");
    }
    else
    {
        while( !feof(fp))
        {
            fflush(stdin);
            fgets(x[i].nam,30,fp);
            fgets(x[i].post,30,fp);
            fgets(x[i].id1,30,fp);
            fgets(x[i].phn,30,fp);
            fscanf(fp,"%f\n",&x[i].salary);

            int y;
            y=strlen(x[i].nam);
            x[i].nam[y-1]='\0';

            if(strcmp(x[i].nam,search)==0)
            {
                index=i;
                found=1;
                break;
            }
            else
            {
                found=0;
            }
            i++;
        }


        if(found==1)
        {
            fflush(stdin);
            printf("\n");
            printf("\nEmployee Name : ");
            puts(x[index].nam);
            printf("\nPost\t     : " );
            puts(x[index].post);
            printf("\nID\t     : ");
            puts(x[index].id1);
            printf("Phone\t     : ");
            puts(x[index].phn);
            printf("\nSalary\t     : %.2f\n",x[index].salary);
        }

        else if(found==0)
        {
            printf("NO match Found!!!!!!");
        }
        fclose(fp);
    }
}
void allshowemployee(void) //to show all employees
{
    FILE *fp;
    E x;
    int i=0;
    fp=fopen("employee.txt","r");
    if(fp==NULL)
    {
        perror("Error opening file");
    }
    else
    {
        while( !feof(fp))
        {
            i++;
            fgets(x.nam,30,fp);
            fgets(x.post,30,fp);
            fgets(x.id1,30,fp);
            fgets(x.phn,30,fp);
            fscanf(fp,"%f\n",&x.salary);

            printf("\n\nEmployee No:%d\n\n",i);
            printf("\nEmployee Name : ");
            puts(x.nam);
            printf("\nPost\t : ");
            puts(x.post);
            printf("\nID\t     : ");
            puts(x.id1);
            printf("\nPhone\t     : ");
            puts(x.phn);
            printf("\nSalary\t     : %.2f",x.salary);
        }
    }
}
void showcustomer(void)  //menu to show customer
{
    int i;
    printf("%60s\n%54s\n%53s\n%50s\n%50s","1.Show By Search","2.Show All","3.go back","4.Menu","5.Exit");
    printf("\n");
    printf("Enter your choice:");
    scanf("%d",&i);
    switch (i)
    {
    case 1:
        searchshowcustomer("customer.txt");
        break;
    case 2:
        allshowcustomer("customer.txt");
        break;
    case 3:
        show();
        break;
    case 4:
        cover();
        showMenu();
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("\n\n\tInvalid Choice!!!!!!!!.\nPlease Try Again.");
        printf("\n");
        showcustomer( );

        break;
    }

}
void searchshowcustomer(char filename[max])  //show customer by searching
{
    FILE *fp;
    char search[max];
    C x[100];
    int i=0;
    int index;
    int found=0;
    printf("Enter Name to Search:");
    getchar();
    gets(search);


    fp=fopen(filename,"r");
    if(fp==NULL)
    {
        perror("Error opening file");
    }
    else
    {
        while( !feof(fp))
        {
            fflush(stdin);
            fgets(x[i].name,30,fp);
            fgets(x[i].order,30,fp);
            fgets(x[i].phone,30,fp);
            fgets(x[i].address,30,fp);


            int y;
            y=strlen(x[i].name);
            x[i].name[y-1]='\0';

            if(strcmp(x[i].name,search)==0)
            {
                index=i;
                found=1;
                break;
            }
            else
            {
                found=0;
            }
            i++;
        }


        if(found==1)
        {
            fflush(stdin);
            printf("\n");
            printf("\nCustomer Name : ");
            puts(x[index].name);
            printf("\nOrder\t     : " );
            puts(x[index].order);
            printf("\nPhone\t     : ");
            puts(x[index].phone);
            printf("Address\t     : ");
            puts(x[index].address);

        }

        else if(found==0)
        {
            printf("NO match Found!!!!!!");
        }
        fclose(fp);
    }
}
void allshowcustomer(char filename[30])  //to show all customer
{
    C x;
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL)
    {
        perror("Error opening file");
    }
    else
    {
        while( !feof(fp))
        {
            fflush(stdin);
            fgets(x.name,30,fp);
            fgets(x.order,30,fp);
            fgets(x.phone,30,fp);
            fgets(x.address,30,fp);
            fflush(stdin);
            printf("\n");
            printf("\nCustomer Name : ");
            puts(x.name);
            printf("\nOrder\t     : " );
            puts(x.order);
            printf("\nPhone\t     : ");
            puts(x.phone);
            printf("Address\t     : ");
            puts(x.address);
        }
    }
}

void dlt(void)  //menu to delete
{
    int a;
    printf("%60s\n%62s\n%66s\n%65s\n%72s\n%63s\n%47s\n%47s","1.delete man's wear","2.delete women's wear","3.delete baby girl's wear","4.delete baby boy's wear","5.delete employee's information","6.delete customer info","7.menu","8.exit");
    printf("\nEnter your choice:");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        dlt_good("Man's wear.txt");
        break;
    case 2:
        dlt_good("women's wear.txt");
        break;
    case 3:
        dlt_good("baby girl's wear.txt");
        break;
    case 4:
        dlt_good("baby boy's wear.txt");
        break;
    case 5:
        dlt_employee("employee.txt");
        break;
    case 6:
        dlt_customer("customer.txt");
        break;
    case 7:
        cover();
        showMenu();
        break;
    case 8:
        exit(0);
        break;
    default:
        printf("\n\n\tInvalid Choice!!!!!!!!.\nPlease Try Again.");
        printf("\n");
        dlt();
        break;
    }
}
void dlt_good(char filename[30])  //option for user to delete by search of everything
{
    int b;
    printf("%60s\n%60s\n%60s\n%60s\n%60s","1.Delete by search","2.Delete All","3.go back","4.Menu","5.exit");
    printf("\nEnter your choice:");
    scanf("%d",&b);
    FILE *fp;

    fp=fopen(filename,"r");

    if(fp==NULL)
    {
        perror("Error opening file");
        dlt();
    }

    if (b==1)
    {
        FILE *fp1;
        fp1=fopen("temp.txt","a");
        char search[max];
        P x[100];

        int i=0;
        int index;
        int found=0;
        printf("Enter Name to Search:");
        getchar();
        gets(search);
        while( !feof(fp))
        {
            fflush(stdin);
            fgets(x[i].name1,30,fp);
            fscanf(fp,"%d\n",&x[i].id);
            fgets(x[i].color,30,fp);
            fgets(x[i].size,30,fp);
            fgets(x[i].storage,30,fp);
            fscanf(fp,"%f\n",&x[i].price);
            fscanf(fp,"%f\n",&x[i].rating);

            int y;
            y=strlen(x[i].name1);
            x[i].name1[y-1]='\0';

            if(strcmp(x[i].name1,search)!=0)
            {
                fflush(stdin);
                fputs(x[i].name1,fp1);
                fprintf(fp1,"%d",x[i].id);
                fputs(x[i].color,fp1);
                fputs(x[i].size,fp1);
                fputs(x[i].storage,fp1);
                fprintf(fp1,"%f",x[i].price);
                fprintf(fp1,"%f",x[i].rating);
            }
            else
            {
                found=1;
            }

        }

        fclose(fp1);

        if(found==1)
        {
            fclose(fp);
            fclose(fp1);
            remove(filename);
            rename("temp.txt",filename);
            printf("\nDelete complete!!!!!!!\n");
        }
        else if(found==0)
        {
            printf("\nNo nformation to delete!!!!!!!\n");

        }
    }

    else if(b==2)
    {
        fclose(fp);
        remove(filename);
        printf("\nDelete complete!!!!!!!\n");
    }
    else if(b==3)
    {
        dlt();
    }
    else if(b==4)
    {
        cover();
        showMenu();
    }
    else if(b==5)
    {
        exit(0);
    }

}

void dlt_employee(char filename[30])  //to delete employee
{
    E x[1000];
    int b,i=0,found=0;

    printf("%60s\n%60s\n%60s\n%60s\n%60s","1.Delete by search","2.Delete All","3.go back","4.Menu","5.exit");
    printf("\nEnter your choice:");
    scanf("%d",&b);

    FILE *fp;
    fp=fopen("employee.txt","r");

    if(fp==NULL)
    {
        perror("Error opening file");
        dlt();
    }
    if(b==1)
    {
        char search[max];
        FILE *f;
        f=fopen("temp.txt","a");

        printf("Enter Name to Search:");
        getchar();
        gets(search);
        while( !feof(fp))
        {
            fflush(stdin);
            fgets(x[i].nam,30,fp);
            fgets(x[i].post,30,fp);
            fgets(x[i].id1,30,fp);
            fgets(x[i].phn,30,fp);
            fscanf(fp,"%f\n",&x[i].salary);

            int y;
            y=strlen(x[i].nam);
            x[i].nam[y-1]='\0';

            if(strcmp(x[i].nam,search)!=0)
            {
                fflush(stdin);
                fputs(x[i].nam,f);
                fputs(x[i].post,f);
                fputs(x[i].id1,f);
                fputs(x[i].phn,f);
                fprintf(f,"%f\n",x[i].salary);
            }
            else
            {
                found=1;
            }
            i++;
        }

        fclose(f);
        if(found==1)
        {
            remove(filename);
            rename("temp.txt",filename);
            printf("%60s","Information Deleted Successfully!!!!!!");
        }
        else if(found==0)
        {
            printf("\n No Match Found!!!!!!!!!!\n");
        }

    }

    else if(b==2)
    {
        fclose(fp);
        remove(filename);
        // rename("temp.txt",filename);
        printf("%60s","Information Deleted Successfully!!!!!!");
    }
    else if (b==3)
    {
        dlt();
    }
    else if (b==4)
    {
        cover();
        showMenu();
    }
    else if(b==5)
    {
        exit(0);
    }
    else
    {
        printf("\n\n\tInvalid Choice!!!!!!!!.\nPlease Try Again.");
        printf("\n");
        dlt_employee(filename);
    }

}
void dlt_customer(char filename[30])
{
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL)
    {
        perror("Error opening file");
        dlt();
    }
    char search[max];
    C x[100];
    int i=0,b,index,found=0;
    printf("%60s\n%60s\n%60s\n%60s\n%60s","1.Delete by search","2.Delete All","3.go back","4.Menu","5.exit");
    printf("\nEnter your choice:");
    scanf("%d",&b);
    if(b==1)
    {
        FILE *f;
        f=fopen("temp.txt","a");
        while( !feof(fp))
        {
            printf("Enter Name to Search:");
            getchar();
            gets(search);
            fflush(stdin);
            fgets(x[i].name,30,fp);
            fgets(x[i].order,30,fp);
            fgets(x[i].phone,30,fp);
            fgets(x[i].address,30,fp);


            int y;
            y=strlen(x[i].name);
            x[i].name[y-1]='\0';

            if(strcmp(x[i].name,search)!=0)
            {
                fflush(stdin);
                 fputs(x[i].name,f);
            fputs(x[i].order,f);
            fputs(x[i].phone,f);
            fputs(x[i].address,f);

            }
            else
            {
                found=1;
            }
        }

        if(found==1)
        {  fclose(fp);
        fclose(f);
           remove(fp);
           rename("temp.txt",filename);
           printf("%60s","Delete Complete");

        }
         else
      printf("\nNO Match Found!!!!!!!\n");
    }
  else if(b==2)
    {
        fclose(fp);
        remove(filename);
        // rename("temp.txt",filename);
        printf("%60s","Information Deleted Successfully!!!!!!");
    }
    else if (b==3)
    {
        dlt();
    }
    else if (b==4)
    {
        cover();
        showMenu();
    }
    else if(b==5)
    {
        exit(0);
    }
    else
    {
        printf("\n\n\tInvalid Choice!!!!!!!!.\nPlease Try Again.");
        printf("\n");
      dlt_customer(filename);
    }

    cover();
    showMenu();
}




