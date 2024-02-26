#include <iostream>
using namespace std;

int main()
{
	// Variable Decleration 
        int num;
	// Enter Input From User
        cout<<"Enter the Number : ";
        cin>>num;
       
	/* Check The Condition */
	 if(num == 0)             // If the Number is 0
	 {
	    cout<<num<<" is neither odd nor even"<<endl;
	 }
	else if(num > 0)          // If the Number is Postive 
	{
              if(num%2 == 0)
                {
                  cout<<num<<" is +ve Even Number"<<endl;
                }
                else
                {
                  cout<<num<<" is +ve Odd Number "<<endl;
                }
	}    
	else if(num < 0)           // If the Number is Negative
        {
              if(num%2 == 0)
                {
                  cout<<num<<" is -ve Even Number"<<endl;
                }
                else
                {
                  cout<<num<<" is -ve Odd Number "<<endl;
                }
        }
    return 0;
}
