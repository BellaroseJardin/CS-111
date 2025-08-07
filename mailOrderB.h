//22
#include <iostream> //outputInvoice1 uses cout                                                                                  
#include <iomanip>  //for setw and setprecision                                                                                 
using namespace std;


/*********************************************************************************
tw is the total weight of all the items the customer is buying.
cost is the total cost

This function calculates a shipping cost as follows and returns it.
25 pounds and under$5 (flat rate)
26 – 50 poundsabove rate for first 25 pounds and 10 cents/pound for pounds over 25
over 50 poundsabove rate for first 50 pounds and 7 cents/pound for pounds over 50
**********************************************************************************/
double calcShipping(int tw)  //You may not change the parameter
{
  double cost; //shipping cost
  if(tw <= 25) //when pounds is 25 AND under
    cost = 5.0;
  else if (tw >= 26 && tw <= 50) //when pounds is 26 to 50
    cost = 5 + (tw - 25 * 0.1);
  else //above 50
    cost = 7.5 + (tw - 50 * 0.07); //7.5 is 5 + 2.5 from 25 *0.1 above
  
  return cost;

}

/********************************************************************************* 
total is the total price the items the customer is buying
disc is the discount amount
tax is the sales tax amount
ship is the shipping cost
total due is the amount the customer owes
This function will output the bottom half of the invoice.
**********************************************************************************/

void  outputInvoice2(double total, double disc, double tax, double ship)//you may not change the parameters 
{
  double totalDue = (total - disc) + tax + ship; //orginal price - discount + tax & shipping
  cout << fixed << setprecision(2);

  //print bottom half
  cout << setw(25) << left << "TOTAL SALE AMOUNT:" << "$" << setw(10) << right << total << endl;
  cout << setw(25) << left << "DISCOUNT:" << "$" << setw(10) << right << disc << endl;
  cout << setw(25) << left << "SALES TAX:" << "$" << setw(10) << right << tax << endl;
  cout << setw(25) << left << "SHIPPING:" << "$" << setw(10) << right << ship << endl;
  cout << setw(25) << left << "TOTAL DUE:" << "$" << setw(10) << right << totalDue << endl;
  
}

