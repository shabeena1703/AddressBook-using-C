/*NAME: SHAIK SHABEENA
REGISTRATION NO:25048_004
SUBMISSION DATE: 03/04/2026

DESCRIPTION:
This program is used to create an addressbook which contains the contacts and their details.
It allows users to manage their contacts through a menu-driven interface.The main features include:
  1. Adding new contacts
  2. Searching for existing contacts
  3. Editing contact details
  4. Deleting contacts
  5. Listing all saved contacts
  6. Saving and exiting the program
  7.loading the saved contacts
The program stores contacts in a structure called `AddressBook`.
 * It keeps track of how many contacts we have and saves them so they can be loaded again the next time
  we run the program.
* We can choose options from the menu, and the program runs the matching function to perform that action.



                                        //addressbook.h//
 This header file defines the basic building blocks of the Address Book.
It contains:
  - Contact structure: stores one person's details (name, phone, email).
  - AddressBook structure: stores up to 100 contacts, keeps count of them.
It also declares the functions used in the program:
  add_contact(), search_contact(), edit_contact(),delete_contact(), list_contacts(), save_contacts(), load_contacts().

This file acts like a blueprint — it tells the program what data and operations exist, while the actual logic is written in .c files.



                                      //addressbook.c//
This file contains the working code for all the operations in the Address Book Management System. It 
provides the actual logic behind the menu options defined in main.c and the structures declared in contact.h
  
                              1.add_contact:
-> validations:
  Name: accepts any string input(no validations needed).
  Phone number:
    - Must be exactly 10 digits long.
    - All characters must be digits.
    - First digit must be between 6–9.
    - Must be unique (not already stored in the address book).
Email:
  - Must not start with @ or .
  - Must end with @gmail.com.
  - Only valid characters allowed (lowercase letters, digits, certain symbols).
Contact is added only if both phone and email pass validatiions.



                                    2.search_contact():
-> validations:
  User must choose a valid search option:
    1 → search by name
    2 → search by email
    3 → search by phone number
  If no contacts exist → prints “No contacts available.”
-> Compares user input with stored data:
    - Name → matches with contacts[i].name
    - Email → matches with contacts[i].email
    - Phone → matches with contacts[i].phone
  If found → displays details and stores index.
  If not found → prints “Contact Not Found.”



                                    3.edit_contact():
The function begins by calling search_contact() to find the contact you want to edit.
If no contact is found → editing stops.
If multiple contacts are found → you must choose a valid index (like 1, 2, 3, etc.) to select which one to edit.
-> Choose what to edit : 
  You are given three options:
    - Name
    - Phone number
    - Email
-> Validations for each choice:
  - Name: accepts any string, no strict validation.
  - Phone number: must pass Validation_phone() (10 digits, numeric, starts with 6–9) and is_unique_number()(not already used).
  - Email: must pass validation_email() (proper format, must end with @gmail.com).
 
If you enter anything other than given options → program shows “Invalid option” and cancels editing.
Update confirmation:
If the new details are valid → the contact is updated successfully and a message is shown.
If not valid → you are asked to re-enter until correct.


                             
                                    4.delete_contact():
The function begins by calling search_contact() to find the contact you want to delete.
If no contact is found → deletion stops.
If multiple contacts are found → you must choose a valid index (like 1, 2, 3, etc.) to select which one to delete.
-> Show contact details:
  - Once a contact is selected, the program displays the full details (Name, Phone, Email).
  - This ensures you can confirm that the correct contact is chosen before deletion.

-> Ask for confirmation:
  - The program asks: “Do you want to delete the contact details (Y/N)?”
  - You must enter either Y (Yes) or N (No).

-> Validations for confirmation:
  If you enter Y or y:
    - The contact is deleted by shifting the remaining contacts forward in the array.
    - contactCount is reduced by one.
Program prints “Deleted successfully.”
If you enter N or n:
  - Deletion is cancelled.
Program prints “Deletion cancelled.”


                                      5.list_contacts():
If no contacts exist → prints “No contacts found.”
Otherwise → prints all contacts in a formatted table.


                                     6.save_contacts(): 
This function saves all the contacts from the address book into a file called database.csv so they are 
not lost when the program ends.

Steps and Validations:
  - Opens the file database.csv in write mode.
  - If the file cannot be opened → shows an error using perror.
  - Loops through all contacts stored in the address book.
  - Writes each contact’s details (Name, Phone, Email) into the file in CSV format.
  - Closes the file after writing.


                                    7.load_contacts():
This function loads contacts back into the address book from the file database.csv when the program starts.
Steps and Validations:
  - Opens the file database.csv in read mode.
  - If the file cannot be opened → shows an error using perror.
  - Sets contactCount = 0 to start fresh.
  - Reads each line from the file in CSV format (name,phone,email).
  - Stores the details into the contacts array of the address book.
  - Increases contactCount for every contact loaded.
  - Closes the file after reading.
      
*/



#include "addressbook.h"

int main() 
{
    int choice;

    struct AddressBook addressBook;
    addressBook.contactCount = 0;
    addressBook.ir_size = 0;

    printf("%zu\n", sizeof(addressBook));
    load_contacts(&addressBook);
    do 
    {
  printf("\nAddress Book Menu:\n");
  printf("1. Add/Create contact\n");
  printf("2. Search contact\n");
  printf("3. Edit contact\n");
  printf("4. Delete contact\n");
  printf("5. List all contacts\n");
  printf("6. Exit\n");
  printf("Enter your choice: ");

  scanf("%d", &choice);
  switch (choice) 
  {
      case 1:
    add_contact(&addressBook);
    break;
      case 2:
    search_contact(&addressBook);
    break;
      case 3:
    edit_contact(&addressBook);
    break;
      case 4:
    delete_contact(&addressBook);
    break;
      case 5:
    list_contacts(&addressBook);
    break;
      case 6:
    printf("Saving and Exiting...\n");
    save_contacts(&addressBook);
    break;
      default:
    printf("Invalid choice. Please try again.\n");
  }
    } while (choice != 6);

    return 0;
}