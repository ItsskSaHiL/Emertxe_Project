/*
Name : SK SAHIL
Date : 10/08/2022
Discription : A45 - Provide a menu to manipulate or display the value of variable of type t
Sample I/O :

Menu :
1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 1
Enter the type you have to insert:
1. int
2. char
3. float
4. double
Choice ---> 2
Enter the char : k
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 3
-------------------------
0 -> k
-------------------------
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 1
Enter the type you have to insert:
1. int
2. char
3. float
4. double
Choice ---> 1
Enter the int : 10
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 3
------------------------
0 -> k (char)
1 -> 10 (int)
------------------------
1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 2
0 -> k
1 -> 10
Enter the index value to be deleted : 0
index 0 successfully deleted.
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 4
*/
#include<stdio.h>
#include<stdlib.h>

 int main()

{
     // Initilization of memory 
    void *vp = malloc(8);
   
    // Initilization of flags variable 
     static int char_flag1 = 0;
     static int char_flag2 = 0;
     static int int_flag = 0;
     static int short_flag = 0;
     static int float_flag = 0;
     static int double_flag = 0;
     
    // Using varibale for menu option 
       int M1;  // For Display menu 1
       int M2;   // For display menu 2
       int M3;   // For Removing element 
       int index; // For deleting charecter
   
   do
    {
   // Printing the first menu 
    printf("\nMenu :\n1. Add element\n2. Remove element\n3. Display element\n4. Exit from the program\n");
     
    // Enter The first menu choise
      printf("\nChoice--->");
      scanf("%d",&M1); 
  
    // Switch case for mrnu 1
    switch(M1)
    {
      // For ADDING Element In Memory
       case 1 : 
              printf("Enter the type you have to insert:\n1. int\n2. char\n3. float\n4. double\n5. short\n");
             
              // Enter The choise 
              printf("\nChoice--->");
              scanf("%d",&M2);

            // Second switch case 
             switch(M2)
             {
                // For add Integer
                case 1 : 
                         if((int_flag == 0)&&(float_flag == 0)&&(double_flag == 0))
                         {
                            printf("Enter the Integer :");
                            scanf("%d",(int*)((char*)vp + 4));
                            int_flag++;
                           }
                           else
                                printf("\nError : No Enough space\n");
                          break;
               // for add Charecter
                case 2 :
                         if((char_flag1 == 0)&&(double_flag == 0))
                         {
                            printf("Enter the Charectre :");
                             getchar();
                            scanf("%c",(char*)(char*)vp);
                            char_flag1++;
                           }
                         else
                             printf("\nError : No Enough space\n");
                    // We want to add another charecter 
                        char ch;
                       printf("\nYou want to add another Charectre then Press Y : ");
                        getchar();
                         scanf("%c",&ch);
                       
                        // Logic for add another Charecter 
                         if( ch == 'Y')
                          {
                         if(char_flag2 == 0)
                          {
                           printf("Enter the Charectre :");
                             getchar();
                            scanf("%c",((char*)vp +1));
                            char_flag2++;
                           }
                          else
                             printf("\nError : No Enough space\n");
                          }
                          break;
                 // For Add Float
                   case 3 :
                           if((float_flag == 0)&&(int_flag == 0))
                            {
                               printf("Enter the Float :");
                              scanf("%f",(float*)((char*)vp + 4));
                             float_flag++;
                             }
                            else
                             printf("\nError : No Enough space\n");
                             break;
                  // For Add double
                   case 4 :
                           if((float_flag == 0)&&(int_flag == 0)&&(char_flag1 == 0)&&(char_flag2 == 0)&&(short_flag == 0))
                            {
                               printf("Enter the Double :");
                              scanf("%lf",(double*)(char*)vp);
                             double_flag++;
                             }
                            else
                             printf("\nError : No Enough space\n");
                             break;
                   // For Add Short
                   case 5 :
                           if((short_flag == 0) && (double_flag == 0))
                            {
                              printf("Enter the Short :");
                              scanf("%hi",(short*)((char*)vp + 2));
                             short_flag++;
                             }
                            else
                             printf("\nError : No Enough space \n");
                            break;
              }
            break; 
       // For Removing Element 
        case 2 :
                   printf("Enter the type you have to insert:\n1. int\n2. char\n3. float\n4. double\n5. short\n");

              // Enter The choise
              printf("\nChoice--->");
              scanf("%d",&M3);
                    // Using switch for Removing Element 
                   switch(M3)
                       {
                        // Removing Integer 
                         case 1 :
                                 if(int_flag == 1)
                                  {
                                      *(int*)((char*)vp + 4) = 0;
                                        int_flag--;
                                         printf("\nInteger Valu Remove\n");
                                      }
                                   else
                                      printf("\nSpace is Alrady Empty\n");
                                 break;
                         // Removing char
                         case 2 :
                                printf("Enter the index no 0 or 1 : ");
                                scanf("%d",&index);
                                switch(index)
                                  {
                               case 0 :
                                  // Remove 1st char
                                  if(char_flag1 == 1)
                                    { 
                                     *(char*)((char*)vp) = '0';
                                        char_flag1--;
                                         printf("\nChar - 0 Valu Remove\n");
                                       }
                                      else
                                      printf("\nSpace is alrady Empty\n");
                                       break;
                                case 1 :
                                     // Remove 2nd char
                                     if(char_flag2 == 1)
                                    {
                                     *(char*)((char*)vp + 1) = '0';
                                        char_flag2--;
                                          printf("\nChar - 1 Valu Remove\n");
                                       }
                                      else
                                      printf("\nSpace is alrady Empty\n");
                                      break;
                                    }
                            // Removing Float   
                            case 3 :
                                      if(float_flag == 1)
                                        {
                                           *(float*)((char*)vp + 4) = 0;
      
                                             float_flag--; 
                                             printf("\nFloat Valu Remove");
                                          }
                                         else
                                           printf("\nSpace is alrady Empty\n");
                                           break;
                             // Removing double  
                              case 4 : 
                                       if(double_flag == 1)
                                         {
                                            *(double*)((char*)vp) = 0;
                                             double_flag--;   
                                              printf("\nDouble Valu Remove\n");
                                           }
                                         else
                                           printf("\nSpace is alrady Empty\n");
                                           break;
                               // Removing Short 
                                case 5 :
                                         if(short_flag == 1)
                                         {
                                            *(short*)((char*)vp + 2) = 0;
                                             short_flag--;
                                              printf("\nShort Valu Remove\n");
                                           }
                                         else
                                           printf("\nSpace is alrady Empty\n");
                                           break;
                                 break;
                          }
  
                  
            break;
        // For Display element 
        case 3 :
                  printf("---------------\n");
                   // Printing First Charecter
                   if(char_flag1 == 1)
                    {
                      printf("0 -> %c(char)\n",*((char*)vp));
                     }
                   // Printing Second charectre 
                    if(char_flag2 == 1)
                    {
                      printf("1 -> %c(char)\n",*((char*)vp + 1));
                     }
                      // printing Short
                    if(short_flag == 1)
                     {
                       printf("2 -> %hi(short)\n",*(short*)((char*)vp + 2));
                      }   
                   // Printing Integre
                   if(int_flag == 1)
                   {
                   printf("4 -> %d(int)\n",*(int*)((char*)vp + 4));
                    }
                    // printing Float
                    if(float_flag == 1)
                     {
                       printf("4 -> %f(float)\n",*(float*)((char*)vp + 4));
                      }
                    // printing double
                    if(double_flag == 1)
                     {
                       printf("0 -> %lf(double)\n",*(double*)((char*)vp));
                      }
                   
                  printf("----------------\n");
                break;
        // For Terminate the program 
        case 4 : 
               exit(1);
               
     }
 
    } while(1); 
  
   free(vp);
    return 0;
}
