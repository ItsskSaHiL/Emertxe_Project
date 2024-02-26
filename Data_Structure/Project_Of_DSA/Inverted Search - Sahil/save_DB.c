#include "inverted_search.h"


 void save_database( Wlist *head[])
{
    //prompt the user 
    char file_name[FNAME_SIZE];

    printf("Enter the filename\n");
    scanf("%s" , file_name);

    FILE *fptr = fopen(file_name , "w");
    
    for(int i = 0 ; i<27 ; i++)
    {
	if(head[i] != NULL)
	{
	    fprintf(fptr,"#[%d] :\n",(tolower(head[i]->word[0])%97) > 25 ? 26:tolower(head[i]->word[0])%97);
	    write_databasefile(head[i] , fptr);
	}
    }
    printf("Datbase is saved\n");
}

void write_databasefile(Wlist *head, FILE* databasefile)
{
    //.............TODO...................

    // # : index    [word]    :    [file_count]    :  [file_name]    :    [word_count] 
	while(head != NULL)
      {
          fprintf(databasefile," [%s] : [%d] :" , head->word , head->file_count);
 
          Ltable *Thead = head->Tlink ;
 
          //traverse
 
          while(Thead)
          {
             fprintf(databasefile," [%s] : [%d] #\n " , Thead->file_name , Thead->word_count);
              Thead = Thead->table_link;
 
          }
          head = head->link;
      }
}

