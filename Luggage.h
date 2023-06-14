#include <string>
#include <iostream>
#include "Customer.h"
#include "Flight.h"
#pragma once

class Luggage
{
  private:
    Flight flight;
    Customer owner;
    int weight;
    string instructions;

  public:
    Luggage();
    Luggage(Flight, Customer);
    Luggage(Flight, Customer, int, string);

    void setWeight(int);
    void setInstructions(string);
};