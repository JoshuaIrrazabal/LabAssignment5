#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head){
	int count = 0;
	node* tmp = head;
	if(tmp == NULL){
		return count;
	}	
	while(tmp != NULL){
		count++;
		tmp = tmp->next;
	}
	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head){
	
	int len = length(head);
	int i = 0;
	char* n = (char*)malloc(sizeof(char)*(len+1));
	node* tmp = head;
	while(tmp != NULL){
		n[i] = tmp->letter;
		tmp = tmp->next;
		i++;
	}
	n[i]='\0';
	return n;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c){

	struct node* tmpNew = (struct node*)malloc(sizeof(struct node)); //allocate new node

	 //node is being added at the end so next is NULL
	if(tmpNew == NULL){
		return;
	}
	tmpNew->letter = c; //enters data
	tmpNew->next = NULL;

	node* tmp = *pHead;

	while ((tmp != NULL)&&(tmp->next !=NULL)){
		tmp = tmp->next;
	}
	if(tmp != NULL){
		tmp->next = tmpNew;
	}else{
		*pHead = tmpNew;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead){
	struct node* tmp = *pHead;
	struct node* next;
	
	if(*pHead == NULL){
		return;
	}
	while(tmp != NULL){
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}