#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { FALSE = 0, TRUE, NO = 0, YES } boolean;
typedef enum { in = 0, call = 1 } status; //status of order

typedef struct node {
	char *name;
	int burger;
	int salad;
	status status;
	struct node *next;
} waitlist;

//prototypes
void addToList(waitlist **head, char *name, int NumBurgers, int NumSalads, status status);
void displayOrdersAhead(waitlist *head, char* name);
void displayListInformation(waitlist *head);
void displayWaitingTime(waitlist *head, char* name, int debugMode);
void retrieveAndRemove(waitlist **head, int num_burgers, int num_salads, int debugMode);
int updateStatus(waitlist **head, char *name, status status);
int doesNameExist(waitlist **head, char *name);