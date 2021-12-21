#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct node
{
	char player[100];
	struct node *next;
};
int c=0;
struct node *head;
void lastinsert ();       
void remove_data();    
void display();  
int choice =0;  
int main()
{
        printf("\n****WELCOME TO MY GAME****\n");  
        printf("\n****LET'S PLAY****\n");  
         printf("\n****PASS THE PILLOW****\n");  
        printf("\n=====================================================================================\n");  
        printf("                                    * * * * * * * * * * *\n");
        printf("                                    * DEVELOPED BY      *    \n");
        printf("                                    * * * * * * * * * * *\n");
	    printf("                                    *  ANSHU UPADHYAY   *\n");
	    printf("                                    * * * * * * * * * * *\n");
	    printf("=======================================================================================\n");  

    while(choice != 7)   
    {  
        printf("\n1.ADD THE NAME OF THE PLAYERS \n2.SHOW THE PLAYER'S CIRCULATING PILLOW\n3.END THE GAME\n");  
        printf("\nENTER YOUR CHOICE?\n");         
        scanf("\n%d",&choice);  
        switch(choice)
        {
            case 1:  
            lastinsert();          
            break;  
            case 2:  
             display();   
            break;   
            case 3:  
            exit(0);          
            break;   
            default:  
            printf("PLEASE ENTER THE VALID CHOICE..");  
        }  
	}
	return 0;    
}
void lastinsert()  
{  
    struct node *ptr,*temp;   
    char item[100];
        ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
    }  
    else  
    {  
        printf("\nEnter player's name?");  
        scanf(" %[^\n]%*c",item);
       strcpy(ptr->player,item);  
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;    
        }  
        else  
        {  
            temp = head;  
            while(temp -> next != head)  
            {  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr -> next = head;  
        }  
          c++;
          printf(" total number of players=%d\n",c);  
        printf("%s is added\n",item);     
    }  
  
}  
void remove_data(char player[100]) {
	
   struct node *current = NULL;
struct node *prev = NULL;
   if(head->player ==player) {
      if(head->next != head) {
         current = head;
         while(current->next!=head){
            current = current->next;
         }
         current->next = head->next;
         head = head->next;
         return;
      } else {
         head = NULL;
      }
   
   } 
   current = head;
   while(current->next != head && current->player !=player) {
      prev = current;
      current = current->next;
   }        
   if(current->player==player) {
      prev->next = prev->next->next;
      free(current);
   } 
}

  void display()  
 {
	int d;
	char ch;
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        printf("\nNO PLAYERS IN THE LIST");  
    }     
    else  
    {  
        printf("\n HOLD ENTER KEY TO PASS THE PILLOW.............................PRESS -- 0+ENTER KEY TO STOP..............................\n");  
        while(1)  
        {  
				ch=getchar();  
			    if(ch=='0')
			    {
					
					printf("%s is holding the pillow\n", ptr ->player);
					printf("GIVE A DARE TO %s\n", ptr ->player); 
					sleep(5);
					printf("PRESS 1 IF HE/SHE COMPLETED THE DARE OR PRESS 0\n");
					scanf("%d",&d);  
				  if(d==0)
				  {
					  printf("%s is out\n", ptr ->player);
					  remove_data(ptr->player);
					  if(head->next!=head)
					  printf("AGAIN HOLD ENTER KEY TO CIRCULATE PILLOW\n");
					   if(head->next==head)
					   {
					  printf("%s is a winner\n",head->player);
					   remove_data(head->player);
					  break;
				      }
			   }
			   }	
            printf("%s", ptr ->player);  
            ptr = ptr -> next;  
        } 
	} 
        printf("%s\n", ptr ->player);  
    }
