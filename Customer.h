#include <iostream>
#include "User.h"

#pragma once
using namespace std;

class Customer: public User{
private:
	string passportId;
  string mealPlan;
  bool onFlight; 
  bool isValidId(string);

public:
	Customer();
  Customer(string,string);
	Customer(string,string,int,string,string);
  Customer (string,string,int,string,string,string);
  Customer (string,string,int,string,string,string,string);
  string toString();
  string getFirstName();
  string getLastName();
  bool operator>(const Customer& other) const;
  bool operator<(const Customer& other) const;
  bool operator==(const Customer& other) const;
  void reset();
};