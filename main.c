#include <stdio.h>
#include "Double_Linked_List.c"

int main()
{
    struct node_t *LIST = NULL;
    uint32 user_choice , lenght;

    printf("-> Hello to Double Linked List \n");
    while (1)
    {
        printf("\n===============================\n");
        printf("-> 1) Insert_Node_At_Beginning \n");
        printf("-> 2) Insert_Node_At_End \n");
        printf("-> 3) Insert_Node_After \n");
        printf("-> 4) Insert_Node_Before \n");
        printf("-> 5) Delete_Node_At_Beginning \n");
        printf("-> 6) Delete_Node_At_End \n");
        printf("-> 7) Delete_Node_At_Specific_Position \n");
        printf("-> 8) Display_All_Nodes_Forward \n");
        printf("-> 9) Display_All_Nodes_Reverse \n");
        printf("-> 10) Get_Node_Lenght \n");
        printf("-> 11) Swap_Two_Nodes \n");
        printf("-> 12) Quit From The Program \n");
        printf("===============================\n");
        printf("\nEnter Your Choice : ");
        scanf("%i",&user_choice);
        switch (user_choice)
        {
            case 1 : 
                Insert_Node_At_Beginning(&LIST);
                break;
            case 2:
                Insert_Node_At_End(LIST);
                break;
            case 3 : 
                Insert_Node_After(LIST);
                break;
            case 4 :
                Insert_Node_Before(&LIST);
                break;
            case 5 :
                 Delete_Node_At_Beginning(&LIST);
                 break;
            case 6 :
                 Delete_Node_At_End(LIST);
                 break;
            case 7 :
                Delete_Node_At_Intermediate(LIST);
                break;
            case 8 :
                Display_All_Nodes_Forward(LIST);
                break;
            case 9 :
                Display_All_Nodes_Reverse(LIST);
                break;
            case 10 : 
                lenght = Get_Lenght(LIST);
                printf("List Length : << %i >> Nodes\n", lenght);
                break;
            case 11 :
                 Swap_Two_Nodes(&LIST);
                 break;
            case 12 : 
                printf("The Program Is Finish \n");
                exit(1);
                break;
            default : 
                printf("User Choice out of range !!\n");
                break;

        }
    }
    
}