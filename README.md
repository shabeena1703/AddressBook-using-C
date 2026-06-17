DESCRIPTION:

The Address Book Management System is a C-based console application that allows users to store and manage contact information efficiently.
Each contact contains a Name, Phone Number, and Email ID.
The program supports all essential CRUD operations — Create, Read, Update, Delete — along with strong input validation to ensure data 
accuracy.

FEATURES:

Add new contact

Search Contacts

Edit existing contacts

Delete contact

List all contacts

TECHNOLOGIES USED:

Structures

Arrays

String Handling(strcmp),(strcpy),(strlen)

Character validation(is digit),(isaplha),(islower)

CHALLENGES FACED:

Validating phone numbers → Making sure the number is exactly 10 digits and starts with 6–9.

Avoiding duplicate phone numbers → Ensuring no two contacts have the same phone number.

Validating email format → Checking that the email ends with @gmail.com and is properly formatted.

Handling multiple search results → Allowing the user to choose when many contacts match the search.

Deleting contacts cleanly → Shifting the list after deletion so no empty gaps remain.

Keeping code modular → Splitting the program into clear functions for readability and maintenance.

I overcame all these challenges by breaking each problem into small steps, writing clear validation functions, testing each feature 
one by one, and improving the code until everything worked correctly.
