#include<iostream>
#include<unordered_set>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void removeDup(struct Node *start)
{
    unordered_set<int> seen;
    struct Node * curr = start;
    struct Node * pre = NULL;
    while(curr != NULL){
        if(seen.find(curr->data) != seen.end())
        {
           pre->next = curr->next;
           delete(curr);
        }
        else
        {
            seen.insert(curr->data);
            pre = curr;
        }
        curr = pre->next;
    }

}

void printlist(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }

}
int main()
{
	/* The constructed linked list is:
	10->12->11->11->12->11->10*/
	struct Node *start = newNode(10);
	start->next = newNode(12);
	start->next->next = newNode(11);
	start->next->next->next = newNode(11);
	start->next->next->next->next = newNode(12);
	start->next->next->next->next->next =
									newNode(11);
	start->next->next->next->next->next->next =
									newNode(10);

	printf("Linked list before removing duplicates : \n");
	printlist(start);

	removeDup(start);

	printf("\nLinked list after removing duplicates : \n");
	printlist(start);

	return 0;
}
