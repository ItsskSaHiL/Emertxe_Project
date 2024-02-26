/*
Name : SK SAHIL
Date : 10/08/2022
Discription : A47 - WAP to convert Little Endian data to Big Endian
Sample I/O :

Test Case 1:
user@emertxe] ./endianness
Enter the size: 2
Enter any number in Hexadecimal: ABCD
After conversion CDAB

Test Case 2:
Enter the size: 4
Enter any number in Hexadecimal: 12345678
After conversion 78563412

*/



#include<stdio.h>
 int main()
  {
   
   int SIZE;
   // Enter the size 
   printf("Enter the size : ");
   scanf("%d",&SIZE);
   
     short int x;
     int y;
    // Using switch case for int and short input 
   
   switch(SIZE)
    {
        case 2 : 
               // short int x;
                printf("Enter any number in Hexadecimal :");
                scanf("%hX",&x);

               // Decleration char pointer 
                 void *sptr = &x;
               
              // For swap the Byte
                short int temp = *((char*)sptr + 1);
                *((char*)sptr + 1) = *((char*)sptr);
                *((char*)sptr) = temp;
                 printf("After conversion %hX\n",x);
                 break;
       case 4 : 
                // input an integer
               printf("Enter any number in Hexadecimal :");
                scanf("%x",&y);


               //Decleration of pointer 
                void *ptr = &y;
             
                // Swap the number 
             for(int i=0;i<2;i++)
              {
              int temp = *((char*)ptr + 3 - i);
              *((char*)ptr + 3 - i) = *((char*)ptr + i);
               *((char*)ptr + i) = temp;
              }
            printf("After conversion %x\n",y);
             break;
       default :
                printf("Error\n");
   
     }
   
   }
