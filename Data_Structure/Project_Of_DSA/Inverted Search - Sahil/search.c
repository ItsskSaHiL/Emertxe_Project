#include "inverted_search.h"

void search( Wlist *head, char *word)
{
    //check empty or not

    if(head == NULL)
    {
	printf("Search word is not available in the list as list is empty\n");
	return ;
    }

    //traverse the list
    while(head)
    {
	//compare the search_word with available words in Wlist
	if(!strcmp(head->word , word))
	{
	    printf("word %s is present in %d file/s " , word , head->file_count);
	    Ltable *Thead = head->Tlink;
	    while(Thead)
	    {
		printf("In file : %s   %d  time/s\n" , Thead->file_name , Thead->word_count);
		Thead = Thead ->table_link;
	    }
	    return ;
	}
	head = head->link;
    }
    printf("Search is not present in the list\n");
}

	

