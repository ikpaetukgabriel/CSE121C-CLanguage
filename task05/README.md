1. Extend the bank program from last week's project to enable a menu system interface to your account system. This menu should give the user three choices: Add a new account, display all the information in all of the accounts, and quit the program. You should create new specialized functions as needed to provide this functionality. Use a linked list to store the information about each account. The menu system should be run in a loop until the user quits the program. If you did not already do so for week 4, you should add a new data member to your structure, which is a pointer to the next structure in your list. Each time you allocate memory for a new structure using malloc, you should set its next pointer to NULL. - /**IMPLEMENTED**/


2. Extend the previous project to add a new menu item: find account. If selected, ask the user for an account number, and search your list of records for that account number. If found, display the record contents. If not found, display an appropriate error message. - /**IMPLEMENTED**/


3. Extend the previous project to add a new menu item: update an account. If selected, ask the user for an account number, search for that account record, and if found, give the user the opportunity to re-enter the information stored in that record. Look for ways to reuse code you've already written to provide this functionality. - /**IMPLEMENTED**/


4. (Advanced, Optional) Extend the previous project to add a new menu item: delete an account. If selected, ask the user for an account number, search for that account record, and if found, delete that record while retaining all of the other records. - /** NOT IMPLEMENTED**/

5. (Advanced, Optional) Modify the previous project by storing the bank records in order by account number. Whenever a bank record is added, insert it into the linked list in the right place so that when the records are displayed, they are in order by the account number. When a record is modified, remove it from the linked list and re-insert it into the list so that the account order is maintained. /** NOT IMPLEMENTED**/
