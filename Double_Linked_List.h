#ifndef Double_Linked_List
#define Double_Linked_List

#include "Platform_Types.h"

struct node_t
{
    uint32 node_data;
    struct node_t *node_lift_link;
    struct node_t *node_right_link;
};

void Insert_Node_At_Beginning(struct node_t **HEAD);
void Insert_Node_At_End(struct node_t *HEAD);
void Insert_Node_After(struct node_t *HEAD);
void Insert_Node_Before(struct node_t **HEAD);
void Delete_Node_At_Beginning(struct node_t **HEAD);
void Delete_Node_At_End(struct node_t *HEAD);
void Delete_Node_At_Intermediate(struct node_t *HEAD);
void Display_All_Nodes_Forward(struct node_t *HEAD);
void Display_All_Nodes_Reverse(struct node_t *HEAD);
void Swap_Two_Nodes(struct node_t **HEAD);
uint32 Get_Lenght(struct node_t *HEAD);

#endif