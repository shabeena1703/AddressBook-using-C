#include "addressbook.h"
#include<string.h>
#include<ctype.h>
int Validation_phone(char phone[]) 
    {
        int len = strlen(phone);
        if (len != 10) 
        {
            return 0;
        }
        for (int i = 0; i < len; i++) 
        {
            if (!isdigit(phone[i])) 
            {
                return 0;
            }
        }
        if (phone[0] < '6' || phone[0] > '9') 
        {
            return 0;
        }
        return 1; // valid
    }
int validation_email(char email[])
{
    char *str="@gmail.com";
    char *pos=strstr(email,str);
    if(email[0]=='@' || email[0]=='.')
    {
        return 0;
    }
    if(pos==NULL)
        return 0;
    if(strcmp(pos,str)!=0)
    {
        return 0;
    }
    for(int i=0;email[i]!='\0';i++)
    {
        if(!islower(email[i]) && isalpha(email[i]) && !(email[i]>=33 && email[i]<=45)  && !(email[i]==47) && !(email[i]>=58 && email[i]<=63))
        {
            return 0;
        }
    }
    return 1;   
}   
int is_unique_number(struct AddressBook *addressBook,char phone[])
{
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].phone,phone)==0)
        {
            return 0;
        }
    }
    return 1;
}

void add_contact(struct AddressBook *addressBook)
{
    struct Contact newContact;
    int ret;
    printf("Enter Name: ");
    scanf(" %[^\n]", newContact.name);
    // Validate mobile number
    do 
    {
        printf("Enter Mobile number (10 digits): ");
         scanf("%s", newContact.phone);
        ret = Validation_phone(newContact.phone);
        if (ret == 0) 
        {
            printf("Error: Invalid phone number. Try again.\n");
        }
        if(!is_unique_number(addressBook,newContact.phone))
        {
            printf("Error:phone number already exists\n");
            ret=0;
        }
    } while (ret == 0);

    do
    {
        printf("enter email:");
        scanf("%s",newContact.email);
        ret=validation_email(newContact.email);
        if(ret==0)
        {
            printf("Error:invalid email.Try again.\n");
        }
    }while(ret==0);

    int idx = addressBook->contactCount;
    strcpy(addressBook->contacts[idx].name, newContact.name);
    strcpy(addressBook->contacts[idx].phone, newContact.phone);
    strcpy(addressBook->contacts[idx].email, newContact.email);
    addressBook->contactCount++;
}





void save_contacts(struct AddressBook *addressBook)
{
    FILE *fptr;
    fptr=fopen("database.csv","w");
    if(fptr==NULL)
    {
        perror("Error");
        return;
    }
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fptr);
}


    



void load_contacts(struct AddressBook *addressBook)
{
    FILE *fptr;
    fptr=fopen("database.csv","r");
    if(fptr==NULL)
    {
        perror("Error");
        return;
    }
    addressBook->contactCount=0;
    while((fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[addressBook->contactCount].name,addressBook->contacts[addressBook->contactCount].phone,addressBook->contacts[addressBook->contactCount].email))!=EOF)
    {
        addressBook->contactCount++;
    }
    fclose(fptr);
}

void search_contact(struct AddressBook *addressBook)
{
    if (addressBook->contactCount == 0) 
    {
        printf("No contacts available.\n");
        return;
    }
    printf("1.Search by name\n");
    printf("2.Search by email ID\n");
    printf("3.Search by phone number\n");
    int option,j=-1;
    char s_name[50];
    int found=0;
    printf("Enter any number from the above:");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
            addressBook->ir_size=0;
            printf("Enter the name you want to search:");
            scanf("%s", s_name);
            found=0;
            for(int i = 0; i < addressBook->contactCount; i++) 
            {
                if(strcmp(addressBook->contacts[i].name, s_name) == 0) 
                {
                    found = 1;
                    addressBook->index_record[addressBook->ir_size++]=i;
                    printf("Contact found\n");
                    printf("---------------------------------------------------------------------------------\n");
                    printf("%-30s %-30s %-30s\n\n","Name","Number","Email");
                    printf("%-30s %-30s %-30s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    printf("---------------------------------------------------------------------------------\n");
                }
            }
            if(found == 0)
            {
                printf("Contact Not found\n");
            }
        break;
        case 2:
            addressBook->ir_size=0;
            printf("Enter the email Id you want to search:");
            scanf("%s",s_name);
            found=0;
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(strcmp(addressBook->contacts[i].email,s_name)==0)
                {
                    found = 1;
                    addressBook->index_record[addressBook->ir_size++]=i;
                    printf("Contact found\n");
                    printf("---------------------------------------------------------------------------------\n");
                    printf("%-30s %-30s %-30s\n\n","Name","Number","Email");
                    printf("%-30s %-30s %-30s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    printf("---------------------------------------------------------------------------------\n");
                }
            }
            if(found==0)
            {
                printf("Contact Not found\n");
            }
        break;
        case 3:
            addressBook->ir_size=0;
            printf("Enter the phone number you want to search:");
            scanf("%s",s_name);
            found=0;
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(strcmp(addressBook->contacts[i].phone,s_name)==0)
                {
                    found = 1;
                    addressBook->index_record[addressBook->ir_size++]=i;
                    printf("Contact found\n");
                    printf("---------------------------------------------------------------------------------\n");
                    printf("%-30s %-30s %-30s\n\n","Name","Number","Email");
                    printf("%-30s %-30s %-30s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    printf("---------------------------------------------------------------------------------\n");
                }
            }
        break;
        default:
            printf("Invalid\n");
            addressBook->ir_size=0;
            return;
    }
}





void edit_contact(struct AddressBook *addressBook)
{
    search_contact(addressBook);
    if(addressBook->ir_size==0)
    {
        printf("No search results to edit");
        return;
    }
    int index;
    if(addressBook->ir_size==1)
    {
        index=addressBook->index_record[0];
        printf("Only one contact found.Editing directly....\n");
    }
    else
    {
        int choice;
        printf("Enter a choice from 1 to %d:",addressBook->ir_size);
        scanf("%d",&choice);

        if(choice < 1 || choice > addressBook->ir_size)
        {
            printf("Invalid choice! try again \n");
            return;
        }
        index=addressBook->index_record[choice-1];
    }
    int option;
    int flag=0;
    printf("What do you want to edit?\n");
    printf("1. Name\n");
    printf("2. Mobile number\n");
    printf("3. Email\n");
    printf("Enter a number from above options:");
    scanf("%d", &option);
    struct Contact tempcontact = addressBook->contacts[index];
    switch(option)
    {
        case 1:
          printf("Enter new name: ");
          scanf("%s", tempcontact.name);
          break;
        case 2:
             do {
                printf("Enter new mobile number (10 digits): ");
                scanf("%s", tempcontact.phone);
                if(!Validation_phone(tempcontact.phone))
                {
                    printf("Invalid phone number,Try again\n");
                }
                else if(!is_unique_number(addressBook,tempcontact.phone))
                {
                    printf("phone number already exsist.Enter new number.\n");
                }
            } while (!Validation_phone(tempcontact.phone) || !is_unique_number(addressBook, tempcontact.phone));
            break;
        case 3:
            do{
                printf("Enter new Email ID:");
                scanf("%s",tempcontact.email);
            }while (!validation_email(tempcontact.email));
            break;
        default:
            flag=1;
            addressBook->ir_size=0;
            break;
    }
    addressBook->contacts[index] = tempcontact;
    if(flag==0)
    {
        printf("Contact updated successfully!\n");
    }
    else
    {
        printf("Invalid option\n");
        addressBook->ir_size=0;
    }
}





void delete_contact(struct AddressBook *addressBook)
{
    search_contact(addressBook);
    if(addressBook->ir_size==0)
    {
        printf("No contacts Found\n");
        return;
    }
    int index;
    if(addressBook->ir_size==1)
    {
        printf("One contact is found\n");
        index=addressBook->index_record[0];
    }
    else
    {
        int choice;
        printf("Enter a choice from 1 to %d:",addressBook->ir_size);
        scanf("%d",&choice);
        if(choice < 1 || choice > addressBook->ir_size)
        {
            printf("Invalid and try again");
            return;
        }
        index=addressBook->index_record[choice-1];
    }
    //confirm deletion
    char y;
    printf("The contact that you want to delete is:\n");
    printf("----------------------------------------------------------------------------\n");
    printf("%-30s %-30s %-30s\n\n","Name","Number","Email");
    printf(" %-30s %-30s %-30s\n",addressBook->contacts[index].name,addressBook->contacts[index].phone,addressBook->contacts[index].email);
    printf("----------------------------------------------------------------------------\n");
    printf("Do you want to delete the contact details(Y/N):");
    scanf(" %c",&y);
    if(y=='Y' || y=='y')
    {
        for(int i=index;i<addressBook->contactCount;i++)
        {
            addressBook->contacts[i]=addressBook->contacts[i+1];
        }
        addressBook->contactCount--;
        printf("Deleted successfully\n");
    }
    else
    {
        printf("Deletion cancelled");
        return;
    }
}





void list_contacts(struct AddressBook *addressBook)
{
    if(addressBook->contactCount==0)
    {
       printf("no contacts found\n");
       return; 
    }
    printf("---------------------------------------------------------------------------------\n");
    printf("%-4s %-30s %-30s %-30s\n","No","Name","Number","Email");
    printf("---------------------------------------------------------------------------------\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        
        printf("%-4d %-30s %-30s %-30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    printf("---------------------------------------------------------------------------------\n");
}