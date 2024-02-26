#include <iostream>
using namespace std;

int third_largest(int *, int);

int main()
{
    int size, *Array,ret;
    
    //Read size from the user
    cout << "Enter the size of the array : ";
    cin >> size;
    
    Array = new int [size];
    
    //Read elements into the array
	cout<<"Enter The Element :";
	for(int i = 0; i < size;i++)
	{
		cin>>Array[i];
	}
    
    //funtion call
    ret = third_largest(Array, size);
    
    printf("Third largest element of the array is %d\n", ret);
}
   int third_largest(int *arr, int n)
   {
	// Use Shorting method to short the Array in Decending Order
	for(int i = 0;i < n;i++)
	{
		for(int j = (i+1);j < n; j++) 	
		{
			if(arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}	
		}
	}
	/* Return the Third Element from Shorted Array */
	return arr[2];

   }
