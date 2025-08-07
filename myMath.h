
/*************************************************************************8
This function will calculate b^e ans return the answer
b is base
e is exponet
**************************************************************************/

int pow(int b,int e)
{
  int ans = 1;
  //b^e
  for(int i = 1; i <= e; i++)
    ans *= b;
  
  return ans;
}
/**************************************************
this fucntion will return the abs value
n  is decimal either + 0 or -
****************************************************/

double fabs(double n1)
{
  
  //absolute
  if ( n1 < 0 )
  n1 *=  -1;
  
  return n1;
}

int round (double num)
{
  
  num  = int (num + 0.5);
  return num;
}
/*************************************************************************                                                                                                                                            
Bellarose Jardin                                                                                                                                                                                                      
CS 111                                                                                                                                                                                                                
Professor slott                                                                                                                                                                                                       
Sqrt.cpp                                                                                                                                                                                                              
3-23-25                                                                                                                                                                                                               
a program that will find the square root of a positive integer number                                                                                                                                                 
 ************************************************************************/

double sqrt(int num)
{                                                                                                                                                                                   
  double start; //finds the square root using for the num entered                                                                                                                                                     
  int bottom = 0;
  int top = 1; //bottom and top for the sqrt                                                                                         

  //finds bottom and top perfect squares 'num' lies between                                                                                                                                                           
  for(int b = 1; b * b <= num; b++)
    {
      bottom = b;
      top = b + 1;
    }

  if(bottom * bottom == num) //if the square root of num is a perfect square
    start = bottom;
  else //if the square root of num is NOT a perfect square                                                                                                                                                            
    {
      if((top * top - num)  < (num - bottom * bottom )) //if the square of the top number is closer to 'num' than the square of the bottom                                                                            
        start = top;
      else //if the square of the bottom number is closer to 'num' than the square of the top
	start = bottom;
      for (int i = 0; i < 10; i++) //repeats step 3 & 3 10 times
	{
          start = (start + num / start) /2;
        }

    }
  return start;
    
}































