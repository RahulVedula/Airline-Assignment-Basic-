#include <iostream>
#include "Customer.h"
#include "User.h"
#include <string>
#include <sstream>
#pragma once
using namespace std;

	bool Customer::isValidId(string id){
		if((id.at(0)=='t' || id.at(0)=='T') && id.length() == 10)
			return true;
		return false;
	}

//Constructors for Customer Class
	Customer::Customer(): User(){
    passportId = "Not entered";
    mealPlan = "Vegetarian";

  }
	Customer::Customer(string f,string l): User(f,l){
    passportId = "Not entered";
    mealPlan = "Vegetarian";

  }

	Customer::Customer(string f, string l, int num, string a, string p) : User(f, l,num,a,p){
    passportId = "Not entered";
    mealPlan = "Vegetarian";
  
  }

	Customer::Customer(string f, string l, int num, string a, string p, string passPort) : User(f, l,num,a,p){
  if(isValidId(passPort)==true)
      passportId = passPort;
		else
			passportId = "invlaid id";
    mealPlan = "Vegetarian";

  }

	Customer::Customer(string f, string l, int num, string a, string p, string passPort, string meal) : User(f, l,num,a,p){
    if(isValidId(passPort)==true)
      passportId = passPort;
		else
		passportId = "invlaid id";
    mealPlan = meal;

  }
//To String Methods 
	string Customer::toString(){
    string newAge = to_string(age);
		ostringstream s1;
		s1 << "Customer Information:\n"<< "\tName: "<<firstName<<" "<<lastName<<"\n\tAddress: "<<address<<"\n\tAge: "<<newAge<<"\n\tPhone Number: "<<phone<<"\n\tPassport ID: "<<passportId<<"\n\tMeal Plan: "<<mealPlan;
		string s2 = s1.str();
		return s2;
	} 
//Getters
  string Customer::getFirstName(){
    return firstName;
  }
  string Customer::getLastName(){
    return lastName;
  }
  //Setters are kept within the user class

//Overload operators for Customer Class, allows comparisons and for searching algorithms to function

  bool Customer::operator>(const Customer& other) const {
        if (lastName == other.lastName) {
            return firstName > other.firstName;
        }
        return lastName > other.lastName;
    }
  bool Customer::operator<(const Customer& other) const {
        if (lastName == other.lastName) {
            return firstName < other.firstName;
        }
        return lastName < other.lastName;
    }
  bool Customer::operator==(const Customer& other) const {
        return firstName == other.firstName && lastName == other.lastName;
    }

//Resets all information of a customer in case it needs to be replaced
void Customer::reset(){
	string passportId = "";
  string mealPlan = "";
  bool onFlight = false;
  firstName = "";
  lastName = "";
  address = "";
  phone = "";

}
