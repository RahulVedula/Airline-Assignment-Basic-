# Airline-Assignment-Basic-
Welcome to the Fly-by-Night Airlines Customer Service Database.

This database documents our current customer and flight information, and allows you to use administrative permissions in order to update it.

Below is a guided documentation of the abilities:

Creating a new customer object allows you to initialize and declare a new customer object, which is inherited from the user class. This will enter the customer information into our database, allowing it to be used at a later time. To complete, enter the first name, address, and all other information needed (strings/ints will be uniquely prompted and error-proofed).

Creating a new flight object allows you to initialize and declare a new flight object, which is inherited from the flight class. This will enter the flight information into our database, allowing it to be used at a later time. To complete, the destination, duration, and flight ID will be entered (strings/ints will be uniquely prompted and error-proofed).

Reserving a seat for a passenger means to associate a customer object with a seat object, thus reserving it and preventing another customer from reserving it. This will also associate the flight object with the customer object, allowing us to keep track of which customer is on which flight. To complete, please enter the first name, second name of an existing customer, and then the destination of an existing flight.

Deleting a seat reservation for a passenger means to disassociate a customer object with a seat object, thus freeing it and allowing another customer to reserve it. This will also disassociate the flight object with the customer object, allowing us to keep track of which customer is on which flight. To complete, please enter the first name, second name of an existing customer, and then the destination of an existing flight

View all flights will display all the flight objects on the screen, allowing the database operator to view all the flights in the database. This will aid in reserving seats for customers. The quick sorted list of flight destinations will be displayed.

View all customers will display all the customer objects on the screen, allowing the database operator to view all the customers in the database. This will aid in reserving seats for customers. The bubble sorted list of customers on a flight will be displayed.

The final option will exit the program. This is a crucial step, as it will save all the data in the database to a file, which will be loaded upon the next execution of the program. This will allow the database to be persistent, and will allow the database operator to keep track of all the customers and flights in the database.
