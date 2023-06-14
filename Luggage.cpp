#include "Luggage.h"
#pragma once
using namespace std;

Luggage::Luggage()
{
  weight = (int)NULL; instructions = "";
}

Luggage::Luggage(Flight f, Customer c)
{
  flight = f; owner = c;
}

Luggage::Luggage(Flight f, Customer c, int w, string i)
{
  flight = f; owner = c; instructions = i;

  if(w <= 50) weight = w;
  else cout << "invalid weight!" << endl;
}

void Luggage::setWeight(int w)
{
  if(w <= 50) weight = w;
  else cout << "invalid weight!" << endl;
}

void Luggage::setInstructions(string i)
{
  instructions = i;
}