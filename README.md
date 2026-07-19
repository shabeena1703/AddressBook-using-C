📘 Address Book Management System
------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
📝 Brief Summary
------------------------------------------------------------------------------------------------------------------------------------------
This project is a simple Address Book application written in C.

It allows users to add, search, edit, delete, and list contacts.

Each contact contains a Name, Phone Number, and Email ID.

The program validates all inputs and prevents duplicate phone numbers, ensuring clean and reliable data.

------------------------------------------------------------------------------------------------------------------------------------------
📌 Overview
------------------------------------------------------------------------------------------------------------------------------------------

An Address Book is a basic contact management system.

In this project:

-> Each contact is stored using a struct Contact

-> All contacts are managed inside struct AddressBook

-> The program supports full CRUD operations

-> Strong validation ensures correct data entry

-> The user interacts through a simple command‑line menu

This project helped me understand:

-> How structures and arrays work in C

-> How to validate user input

-> How to design modular functions

-> How CRUD operations work internally

-> How to manage records in memory

------------------------------------------------------------------------------------------------------------------------------------------
🛠️ Tools and Technologies Used
------------------------------------------------------------------------------------------------------------------------------------------
**Programming Language:** C

**Compiler:** GCC

**Operating system:** Linux / Windows

**Development Tools:** VS Code / Vim

**Version Control:** Git & GitHub

-----------------------------------------------------------------------------------------------------------------------------------------

🔧 Operations Performed 
-----------------------------------------------------------------------------------------------------------------------------------------
1️⃣ **Add Contact**

-> Enter name, phone number, and email

-> Validate phone number (10 digits, starts with 6–9)

-> Validate email (@gmail.com)

-> Prevent duplicate phone numbers

-> Save contact

2️⃣ **Search Contact**

Search by:

-> Name

-> Email ID

 ->Phone Number

Displays all matching contacts and stores their indices.

3️⃣ **Edit Contact**

-> First perform a search

-> If multiple results → user selects one

-> Edit name, phone number, or email

-> Re‑validate updated details

-> Save changes

4️⃣ Delete Contact
-----------------------------------------------------------------------------------------------------------------------------------------
-> First perform a search

-> User selects the contact

-> Confirm deletion

-> Remove contact and shift remaining contacts

**5️⃣ List All Contacts**

-> Display all saved contacts

-> Show name, phone number, and email in a clean table

-----------------------------------------------------------------------------------------------------------------------------------------
🧠 Methods
-----------------------------------------------------------------------------------------------------------------------------------------
**Phone Validation**

-> Must be 10 digits

-> Must start with 6–9

-> Must contain only digits

-> Must be unique

**Email Validation**

-> Must end with @gmail.com

-> Cannot start with @ or .

-> Must contain valid characters

**Search Logic**

->Loop through all contacts

-> Compare name/email/phone

-> Store matching indices

-> Display results

**Edit/Delete Logic**

-> Use stored indices from search

-> Allow user to choose correct contact

-> Validate new data (for edit)

-> Shift contacts (for delete)

-----------------------------------------------------------------------------------------------------------------------------------------
🚀 How to Run This Project
-----------------------------------------------------------------------------------------------------------------------------------------
1️⃣** Clone the Repository**

Code

  git clone https://github.com/yourusername/AddressBook-using-C.git
  
2️⃣** Navigate to the Project Folder**

Code

  cd AddressBook-using-C
3️⃣ **Compile the Program**

Code

  gcc *.c -o addressbook
  
4️⃣ **Run the Program**

Code
  ./addressbook

  ----------------------------------------------------------------------------------------------------------------------------------------
🧾 Output
-----------------------------------------------------------------------------------------------------------------------------------------
**📌 Menu**

Address Book Menu:
1. Add/Create contact
    
2. Search contact
 
3. Edit contact
 
4. Delete contact
  
5. List all contacts
   
6. Exit
7. 
Enter your choice:

**📌 Add Contact**

Enter Name: Shabeena

Enter Mobile number (10 digits): 9876543210

Enter email: skshabeena33@gmail.com

Contact added successfully!

**📌 Search Contact**

Enter your choice: 2

1. Search by name
   
2. Search by email ID
 
3. Search by phone number
 
Enter any number from the above: 1

Enter the name you want to search: user1

  Contact found
  ------------------------------------------------------------
  Name        Number        Email
  
  user1       7654321890    user1@gmail.com
  
  ------------------------------------------------------------
  
  Contact found
  ------------------------------------------------------------
  
  Name        Number        Email
  
  user1       6543217890    user1@gmail.com
  
  ------------------------------------------------------------
  
**📌 Edit Contact**

Enter your choice: 3

Enter the name you want to search: user1

Enter a choice from 1 to 2: 2

What do you want to edit?

1. Name
 
2. Mobile number
 
3. Email
 
Enter a number from above options: 1

Enter new name: user2

  Contact updated successfully!

**📌 List All Contacts**

  ------------------------------------------------------------
  No    Name        Number        Email
  ------------------------------------------------------------
  1    Shabeena    9876543210    skshabeena32@gmail.com
  
  2    karima      8765432190    karima@gmail.com
  
  3    user1       7654321890    user1@gmail.com
  
  4    user2       6543217890    user1@gmail.com
  
  ------------------------------------------------------------
  
**📌 Delete Contact**

Enter your choice: 4

Enter the email Id you want to search: user1@gmail.com

Enter a choice from 1 to 2: 2

Do you want to delete the contact details(Y/N): Y

Deleted successfully

-----------------------------------------------------------------------------------------------------------------------------------------
🚧 Challenges Faced 
-----------------------------------------------------------------------------------------------------------------------------------------
-> Validating phone numbers correctly

-> Avoiding duplicate phone numbers

-> Validating email format

-> Handling multiple search results

-> Deleting contacts without leaving gaps

-> Keeping code modular and readable

-----------------------------------------------------------------------------------------------------------------------------------------
🏁 Conclusion
-----------------------------------------------------------------------------------------------------------------------------------------
I overcame all challenges by breaking each problem into small steps, writing clear validation functions, testing each feature individually, and improving the logic until the entire Address Book worked smoothly and reliably.

-----------------------------------------------------------------------------------------------------------------------------------------
🔮 Future Work
-----------------------------------------------------------------------------------------------------------------------------------------
-> Add file storage (save contacts permanently)

-> Add sorting (A–Z, Z–A)

-> Add multiple email domain support

-> Add GUI version

-> Add categories (family, work, friends)

-----------------------------------------------------------------------------------------------------------------------------------------
👤 Author & Contact
-----------------------------------------------------------------------------------------------------------------------------------------
Shaik Shabeena  

Electronics and Communication Engineering

Email: skshabeena33@gmail.com

Linkedin: https://www.linkedin.com/in/shaik-shabeena-36a7b9332/
