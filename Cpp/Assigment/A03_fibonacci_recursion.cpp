#include <iostream>
using namespace std;
/*  Function Prototype */
void positive_fibonacci(int, int, int, int);

int main()
{
    int limit;                    // Variable Decleration 
    
    cout << "Enter the limit : ";  // User Input
    cin >> limit;
    
    positive_fibonacci(limit, 0, 1, 0);  // Function Call
    
    cout<<endl;                       
    return 0;
}
  /* Function Defination */
  void positive_fibonacci(int limit, int n1, int n2, int next_term)
     { 
          // Condition for 0
          if( limit == 0)
             {
               cout<<n1<<endl;
             }
            // Condition for greater then 0 value 
          else if( limit > 0 )
           {   
	  	 if(next_term < 1)       // Printing 0 and 1 
		  {
			cout<<n1<<","<<n2;	
		  }
               // Algoritham for next term
              next_term = n1 + n2;
              n1 = n2;
              n2  = next_term;
               if( next_term <= limit )
               {
                  cout<<","<< next_term;                        // Printing next element
                  positive_fibonacci(limit, n1, n2, next_term); // Recurtion function call
               }
           }
           else     // For the Negative Input 
	   {
           cout<<"Invalid input"<<endl;
           }
     }
