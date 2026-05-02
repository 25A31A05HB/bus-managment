## Bus management system
## introduction
bus management is a c++ project to implement basic operations of the bus management system.

## problem statement
college management requries a praogram that would help in managing multipile buses without any in convinence.

## objective
to create a menu driven program for bus management.
To demonstrate the use of linked list,switch case and loops in C++.
To provide a simple real-life application of programming.
## algorithm
1.Start
2.Define Structure
•Create a structure Bus with fields:
regNo, bus no, name, location, route, next < 3.Initialize
Set head = NULL
4.Load Bus Details •Insert predefined bus data into a linked list using Insert bus() 5.Insert Bus •Create a new node •If head == NULL, assign new node to head •Else traverse to the last node and link the new node 6.Display Buses •If the list is empty, print "No buses available" •Else traverse and display bus details •Ask the user to select the bus number •Display stops using switch-case 7.Add Member •Input regNo, name, bus no •Traverse list •If the bus number matches:

Store student details in that node Print success message •Else print "Invalid bus number" 8.View Member Details •Input registration number •Traverse list •If found: Display name, bus number, route •Else print "No member found" 9.Main Menu • Repeat until the user exits: Display options: a.View Buses b.Add Member C.View Member Details d.Exit Read user choice Call corresponding function 10.Stop

## flowchart
