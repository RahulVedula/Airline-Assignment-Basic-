#include "Customer.h"
#include "Flight.h"
#include "Luggage.h"
#include "Seat.h"
#include "User.h"
#include <iostream>
#include <limits>
#include <chrono>
#include <thread>

/*
Aspects covered in the course:
1. Recursion and Searching
  a. Recursive Binary Search is used to find the index of the customer within the flight using a bubble-sorted list
  b. Linear search is used to find the index of the customer within the hashmap 

2. Pointers
    a. Pointers are used throughout the code, including the hashmap, instance variables, and all the other components of the code. Deletes are used to also deallocate the memory on the Heap and mitigate memory loss

3. Sorting algorithms
    a. Quick sort is used to sort through all the customers in the system as it is more efficient dealing with bigger arrays of information
    b. Bubble sort is used to sort within the flight as it is a much smaller amount of people 

4. Functions
  a. Used everywhere, literally everywhere

5. Arrays
  a. Arrays are mainly used to sort groups of informations like all the customers on the system and all the flights added to the system along with seats/customers in the seats in the Flight class

6. Object Oriented Programming
  a. Classes are used to organize information on customers, flights, luggage, seats, and users
  b. Inhertiance is used within user and cutomer classes to avoid mix ups
  c. Encapsulation and polymorphism is used in all classes

*/
//Variables to track the number of customers and flights
int numberOfCustomers = 0;
int numberOfFlight = 0;

//Hashmaps for customers and flights, easy to find them using their unique key (index)
Customer *hashMapCustomers = new Customer[1000];
Flight *hashMapFlights = new Flight[10];

//Initalizing of all the methods used in switch cases and to find information
void addCustomerInfo();
void addFlight();
void reserveCustomerSeat();
void removeCustomerSeat();
void viewAllFlights();
void viewCustomerInfo();
int validateIntegerInput(int s, int e);
int findCustomerIndex(Customer arr[], int size, string firstName, string lastName);
int findFlightIndex(Flight arr[], int size, string destination); 

//Main Function—User guide is located in Instructions.txt
int main() {
  cout << "\e[1mWelcome to the Fly-by-Night Airlines Database" << endl;
  cout << "This is a database to ensure that Fly-by-Night keeps track of our "
          "flights and customers."
       << endl;
  bool condition = true;

//While loop to continously update the airline database, condition only turns false when 7 is entered
  while (condition) {

    cout << "Please select an option by entering the number allocated:\n1. Add "
            "Customer Information\n2. Add Flight\n3. Reserve Seat for "
            "Customer\n4. Remove Customer from Seat\n5. View all Flights\n6. "
            "View Customer Information\n7. Exit Program\n"
         << endl;
//Each switch case corresponds to the case chosen above detailing the type of action one would like to proceed with 
    int choice = validateIntegerInput(1, 7);
    switch (choice) {
    case 1:
      addCustomerInfo();
      break;
    case 2:
      addFlight();
      break;
    case 3:
      reserveCustomerSeat();
      break;
    case 4:
      removeCustomerSeat();
      break;
    case 5:
      viewAllFlights();
      break;
    case 6:
      viewCustomerInfo();
      break;
    case 7:
      condition = false;
      break;
    }
    if (condition){
      cout << "\nEnter any input to clear the console: ";
    // Clear any previous input from the input stream
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    system("clear");
    }
  }
  cout << "Program Has Been Terminated!" << endl;
}
//-------------------------------------------------------------------------------------------------------

//This function uses the addCustomer Information function taking in a variety of different parameters which are then stored in a customer object
void addCustomerInfo() {
  string fName, lName, address, phone, passPortID;
  int age;
  cout << "Please enter the customer's first name: " << endl;
  cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
  getline(cin, fName);
  cout << "Please enter the customer's last name: " << endl;
  getline(cin, lName);
  cout << "Please enter the customer's address: " << endl;
  getline(cin, address);
  cout << "Please enter the customer's phone number: " << endl;
  getline(cin, phone);
  cout << "Please enter the customer's age: " << endl;
  age = validateIntegerInput(1, 120);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Please enter the customer's passport ID: " << endl;
  getline(cin, passPortID);

//The information is stored inside the hashmap here
  hashMapCustomers[numberOfCustomers] =
      Customer(fName, lName, age, address, phone, passPortID);
  numberOfCustomers++;
    cout << "Customer Has Been Added" << endl;
}

//This method adds a flight to the Flight object
void addFlight() {
  int duration;
  string des, id, craft;
  cout << "Please enter the destination: " << endl;
  cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
  getline(cin, des);
  cout << "Please enter the ID:" << endl;
  getline(cin, id);
  cout << "Please enter the aircraft model: " << endl;
  getline(cin, craft);
  cout << "Please enter the the duration of the flight in hours: " << endl;
  duration = validateIntegerInput(0,10) ;

  //This segment of the code will add the flight to the hashmap specified above
  hashMapFlights[numberOfFlight] = Flight(10, des, id, duration, craft);
  numberOfFlight++;
  cout << "Flight Has Been Added" << endl;
}

void reserveCustomerSeat() {
  //This function is used to reserve a customer seat within the Flight Class
  string fName,lName,destinationName;
  int seatNum;
  cout << "If you would like to exit this action, please enter \'exit\' in the \'first name\' field." << endl;
  cout << "Please enter the customer's first name: " << endl;
  cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
  getline(cin, fName);
  if(fName != "exit"){
  cout << "Please enter the customer's last name: " << endl;
  getline(cin, lName);
    int indexOfCustomer = findCustomerIndex(hashMapCustomers,numberOfCustomers,fName,lName); 
  //This while loop checks for invalid input if the customer is not found
  while (indexOfCustomer == -1){
      cout << "Customer Not Found, Please Try again " << endl;
      cout << "Please enter the customer's first name: " << endl;
    getline(cin, fName);
    cout << "Please enter the customer's last name: " << endl;
    getline(cin, lName);
    indexOfCustomer = findCustomerIndex(hashMapCustomers,numberOfCustomers,fName,lName);  
  }
  cout << "Please enter the flight destination you would like to book: " << endl;
  getline(cin, destinationName);
  int indexOfFlight = findFlightIndex(hashMapFlights,numberOfFlight,destinationName);
    //This while loop checks for invalid input if the Flight is not found
    while (indexOfFlight == -1){ 
      cout << "Flight Not Found, Please Try Again " << endl;
    cout << "Please enter the flight destination you would like to book: " <<     endl;
  getline(cin, destinationName);
    indexOfFlight = findFlightIndex(hashMapFlights,numberOfFlight,destinationName); 
  }

  hashMapFlights[indexOfFlight].availableSeats();
  cout << "\nPlease enter the seat number you would like to book " << endl;
  seatNum = validateIntegerInput(0, 10);
  //This is used to filter through invalid inputs 
  while(!hashMapFlights[indexOfFlight].checkSeatAvailability(seatNum)){
      cout << "\nThat seat is currently booked! Please enter the seat number you would like to book: " << endl;
  seatNum = validateIntegerInput(0, 10);
  
  }
  
  hashMapFlights[indexOfFlight].reserveSeat(seatNum,hashMapCustomers[indexOfCustomer]);
  cout<<hashMapFlights[indexOfFlight].getSeatInformation(seatNum);
  }
}
void removeCustomerSeat() {
  //This function is used to delete a customer seat within the Flight Class
  string fName,lName,destinationName;
  int seatNum;
  cout << "If you would like to exit this action, please enter \'exit\' in the \'first name\' field." << endl;
  cout << "Please enter the customer's first name: " << endl;
  cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
  getline(cin, fName);
  
  if(fName != "exit"){
  
  cout << "Please enter the customer's last name: " << endl;
  getline(cin, lName);
      int indexOfCustomer = findCustomerIndex(hashMapCustomers,numberOfCustomers,fName,lName);  
    //This is used to filter through invalid inputs 
  while (indexOfCustomer == -1){
      cout << "Customer Not Found, Please Try again " << endl;
      cout << "Please enter the customer's first name: " << endl;
    getline(cin, fName);
    cout << "Please enter the customer's last name: " << endl;
    getline(cin, lName);
    indexOfCustomer = findCustomerIndex(hashMapCustomers,numberOfCustomers,fName,lName);  
  }
  
  
  cout << "Please enter the flight destination you would like to cancel booking for: " << endl;
  getline(cin, destinationName);
  int indexOfFlight = findFlightIndex(hashMapFlights,numberOfFlight,destinationName);
    //This is used to filter through invalid inputs 
  while (indexOfFlight == -1){
      cout << "Flight Not Found, Please Try Again " << endl;
    cout << "Please enter the flight destination you would like to cancel booking for: " <<     endl;
  getline(cin, destinationName);
    indexOfFlight = findFlightIndex(hashMapFlights,numberOfFlight,destinationName); 
  }
  
  
  hashMapFlights[indexOfFlight].deleteSeat(hashMapCustomers[indexOfCustomer]);
  }
}

void viewAllFlights() {
  //This function is used to print out all the existing flights created
  for(int i = 0; i < numberOfFlight;i++){
    cout<<hashMapFlights[i].toString()<<endl;
  }
}
void viewCustomerInfo() {
  //This function is used to print out all the information of people on a certain flight 
  string destinationName;
  cout << "Please enter the flight destination you would like to book: " << endl;
  cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
  getline(cin, destinationName);
  int indexOfFlight = findFlightIndex(hashMapFlights,numberOfFlight,destinationName);
  hashMapFlights[indexOfFlight].passengerList();
}

//-------------------------------------------------------------------------------------------------------
//Method used to check for incorrect and correct input
int validateIntegerInput(int start, int end) {
  int value;

  cout << "Enter an integer between " << start << " and " << end << ": ";
  while (!(std::cin >> value) || value < start || value > end) {
    std::cout << "Invalid input. Please enter an integer between " << start
              << " and " << end << ": ";
    cin.clear();
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
  }

  return value;
}

//Method used to find the index of the customer within the hashmap
int findCustomerIndex(Customer arr[], int size, string firstName, string lastName) {
    for (int i = 0; i < size; i++) {
        if (arr[i].getFirstName() == firstName && arr[i].getLastName() == lastName) {
            return i; // Found the customer, return the index
        }
    }
    return -1; // Customer not found
}

int findFlightIndex(Flight arr[], int size, string destination) {
    for (int i = 0; i < size; i++) {
        if (arr[i].getDestination() == destination) {
            return i; // Found the flight, return the index
        }
    }
    return -1; // Flight not found
}
//This sorting algorithm is used to sort all the customers in the system in order of last name
void quickSort(Customer arr[], int left, int right) {
    if (left >= right)
        return; // Base case: array is already sorted

    Customer pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[right]);

    int pivotIndex = i + 1;

    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}








