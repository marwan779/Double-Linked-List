#include <stdio.h>
#include <stdlib.h>
#include "Double_Linked_List.h"

void Insert_Node_At_Beginning(struct node_t **HEAD) // this function will modify the head of the list so we pass the head as
{                                                   // a double pointer to prevent  the function form making a copy from the
    struct node_t *temp_node = NULL;                // pointer and modify the actual address (the head)
    temp_node = (struct node_t *)malloc(sizeof(struct node_t));
    if (temp_node == NULL)
    {
        printf("Error Creating The New Node :) \n");
    }
    else
    {
        printf("Enter Node Data : ");
        scanf("%i", &(temp_node->node_data));
        if (*HEAD == NULL) // list is empty
        {
            temp_node->node_lift_link = NULL;
            temp_node->node_right_link = NULL;
            (*HEAD) = temp_node;
        }
        else // the list is not empyt
        {
            temp_node->node_right_link = (*HEAD);
            temp_node->node_lift_link = NULL;
            (*HEAD)->node_lift_link = temp_node;
            (*HEAD) = temp_node;
        }
    }
}

void Insert_Node_At_End(struct node_t **HEAD)
{
    struct node_t *temp_node = NULL, *node_counter = *HEAD;
    uint32 lenght;
    temp_node = (struct node_t *)malloc(sizeof(struct node_t));
    lenght = Get_Lenght(*HEAD);
    if (temp_node == NULL)
    {
        printf("Error Creating The New Node :) \n");
    }
    else
    {
        printf("Enter Node Data : ");
        scanf("%i", &(temp_node->node_data));
        if (lenght == 0) // list is empty
        {
            temp_node->node_lift_link = NULL;
            temp_node->node_right_link = NULL;
            (*HEAD) = temp_node;
        }
        else // the list is not empyt
        {
            for (uint32 i = 1; i < lenght; i++)
            {
                node_counter = node_counter->node_right_link;
            }
            temp_node->node_lift_link = node_counter;
            temp_node->node_right_link = NULL;
            node_counter->node_right_link = temp_node;
        }
    }
}

void Insert_Node_After(struct node_t *HEAD)
{
    struct node_t *temp_node = NULL, *node_counter_one = HEAD, *node_counter_two = NULL;
    uint32 lenght, position;
    lenght = Get_Lenght(HEAD);
    printf("Enter Node Position : ");
    scanf("%i", &position);
    if (lenght == 0 || position > lenght)
    {
        printf("The List Is Empty Or You Have Entered Un Vaild Position :)\n");
    }
    else
    {
        if (position != lenght) // the first case (insert the new node in the middle)
        {
            temp_node = (struct node_t *)malloc(sizeof(struct node_t));
            if (temp_node == NULL)
            {
                printf("Error Creating The New Node :) \n");
            }
            else
            {
                printf("Enter Node Data : ");
                scanf("%i", &(temp_node->node_data));
                for (uint32 i = 1; i < position; i++)
                {
                    node_counter_one = node_counter_one->node_right_link;
                }
                node_counter_two = node_counter_one->node_right_link;
                temp_node->node_lift_link = node_counter_one;
                temp_node->node_right_link = node_counter_two;
                node_counter_one->node_right_link = temp_node;
                node_counter_two->node_lift_link = temp_node;
            }
        }
        else
        {
            Insert_Node_At_End(&HEAD);
        }
    }
}

void Insert_Node_Before(struct node_t **HEAD)
{
    struct node_t *temp_node = NULL, *node_counter_one = (*HEAD), *node_counter_two = NULL;
    uint32 lenght, position;
    lenght = Get_Lenght(*HEAD);
    temp_node = (struct node_t *)malloc(sizeof(struct node_t));
    if (temp_node == NULL)
    {
        printf("Error Creating The New Node :) \n");
    }
    printf("Enter Node Position : ");
    scanf("%i", &position);
    printf("Enter Node Data : ");
    scanf("%i", &(temp_node->node_data));
    if (lenght == 0 || position > lenght)
    {
        printf("The List Is Empty Or You Have Entered Un Vaild Position :)\n");
    }
    else
    {
        if (position != 1)
        {

            for (uint32 i = 1; i < (position - 1); i++)
            {
                node_counter_one = node_counter_one->node_right_link;
            }
            node_counter_two = node_counter_one->node_right_link;
            temp_node->node_lift_link = node_counter_one;
            temp_node->node_right_link = node_counter_two;
            node_counter_one->node_right_link = temp_node;
            node_counter_two->node_lift_link = temp_node;
        }
        else
        {
            temp_node->node_right_link = (*HEAD);
            temp_node->node_lift_link = NULL;
            (*HEAD)->node_lift_link = temp_node;
            (*HEAD) = temp_node;
        }
    }
}

void Delete_Node_At_Beginning(struct node_t **HEAD)
{
    uint32 lenght;
    lenght = Get_Lenght(*HEAD);
    if (lenght == 0)
    {
        printf("The List Is Empty Nothing To Delete :)\n");
    }
    else if (lenght == 1)
    {
        free(*HEAD);
        *HEAD = NULL;
    }
    else
    {
        (*HEAD) = (*HEAD)->node_right_link;
        free((*HEAD)->node_lift_link);
        (*HEAD)->node_lift_link = NULL;
    }
}

void Delete_Node_At_End(struct node_t *HEAD)
{
    struct node_t *node_counter = HEAD;
    uint32 lenght, counter = 1;
    lenght = Get_Lenght(HEAD);
    if (lenght == 0)
    {
        printf("The List Is Empty Nothing To Delete :)\n");
    }
    else
    {
        while (counter != (lenght - 1))
        {
            node_counter = node_counter->node_right_link;
            counter++;
        }
        free(node_counter->node_right_link);
        node_counter->node_right_link = NULL;
    }
}

void Delete_Node_At_Intermediate(struct node_t *HEAD)
{
    uint32 lenght, position;
    struct node_t *node_one_counter = HEAD, *node_two_counter = NULL;
    printf("Enter the Position Of The Node You Want To Delete :");
    scanf("%i", &position);
    lenght = Get_Lenght(HEAD);
    if (lenght == 0)
    {
        printf("The List Is Empty Nothing To Delete :)\n");
    }
    else
    {
        if (position == 1)
        {
            Delete_Node_At_Beginning(&HEAD);
        }
        else if (position == lenght)
        {
            Delete_Node_At_End(HEAD);
        }
        else
        {
            for (uint32 i = 1; (i < position - 1); i++)
            {
                node_one_counter = node_one_counter->node_right_link;
            }
            node_two_counter = (node_one_counter->node_right_link)->node_right_link;
            free(node_one_counter->node_right_link);
            node_one_counter->node_right_link = node_two_counter;
        }
    }
}

void Display_All_Nodes_Forward(struct node_t *HEAD)
{
    struct node_t *node_counter = HEAD;
    uint32 list_lenght;
    list_lenght = Get_Lenght(HEAD);
    if (list_lenght == 0) // the list is empyt
    {
        printf("The List Is Empyt Nothing To Display :)\n");
    }
    else // the list is not empyt
    {
        while (node_counter != NULL)
        {
            printf("-> %i ", node_counter->node_data);
            node_counter = node_counter->node_right_link;
        }
    }
}

void Display_All_Nodes_Reverse(struct node_t *HEAD)
{
    struct node_t *node_counter = HEAD;
    uint32 list_lenght;
    list_lenght = Get_Lenght(HEAD);
    if (list_lenght == 0) // the list is empyt
    {
        printf("The List Is Empyt Nothing To Display :)\n");
    }
    else // the list is not empyt
    {
        for(uint32 i =1;i<list_lenght ; i++)
        {
            node_counter = node_counter->node_right_link;
        }
        for(uint32 j =1;j<=list_lenght ; j++)
        {
            printf("-> %i ", node_counter->node_data);
            node_counter = node_counter->node_lift_link;
        }

    }
}

uint32 Get_Lenght(struct node_t *HEAD)
{
    struct node_t *node_counter = HEAD;
    uint32 list_lenght = 0;
    while (node_counter != NULL)
    {
        node_counter = node_counter->node_right_link;
        list_lenght++;
    }

    return list_lenght;
}

void Swap_Two_Nodes(struct node_t **HEAD)
{
    struct node_t *node_one = *HEAD , *node_two = *HEAD ;
    uint32 lenght , node_one_position ,node_two_position ,temp_data;
    printf("Enter Node One Position : ");
    scanf("%i",&node_one_position);
    printf("Enter Node Two Position : ");
    scanf("%i",&node_two_position);
    lenght = Get_Lenght(*HEAD);
    if(node_one_position > lenght || node_two_position > lenght)
    {
        printf("Out Of Ringe :)\n");
    }
    else if(node_one_position == node_two_position)
    {
        printf("Error Can't Swap Node With Itself :)\n");
    }
    else if(node_two_position < node_one_position)
    {
         printf("Error Node Two Position Must Be Bigger Than Node One Position");
    }
    else 
    {
        for(uint32 i = 1 ;i <node_one_position ; i++)
        {
            node_one = node_one->node_right_link;
        }

        for(uint32 j = 1 ;j <node_two_position ;j++)
        {
            node_two = node_two->node_right_link;
        }
        temp_data = node_one ->node_data;
        node_one->node_data = node_two->node_data;
        node_two->node_data = temp_data;
        
    }
}
