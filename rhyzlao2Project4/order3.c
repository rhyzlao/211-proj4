#include "order.h"

void addToList(waitlist **head, char *name, int NumBurgers, int NumSalads, status status) {
	waitlist *new = (waitlist *)malloc(sizeof(waitlist)); 
	new->burger = NumBurgers; 
	new->salad = NumSalads;
	new->name = name; 
	new->next = NULL; 
	new->status = status; 
	
	//check queue
	if (*head == NULL) {
		*head = new;
	}
	else { 
		waitlist *temp = NULL;
		temp = *head;
		while (temp->next != NULL) { //end
			temp = temp->next;
		}

		temp->next = new;
	}
}

int doesNameExist(waitlist **head, char *name) {
	waitlist *temp = NULL;
	temp = *head;
    
    if(temp == NULL){
        return 0;
    }
	while (temp != NULL) { 
		if (strcmp(temp->name, name) == 0) { 
			return 1; //name found
		}
		temp = temp->next;
	}

	return 0; 
}

int updateStatus(waitlist **head, char *name, status status) {
	waitlist *temp = NULL;
	temp = *head;

	while (temp != NULL) {
		if (strcmp(temp->name, name) == 0) { 
			if (temp->status == in) {
				printf("Already in the restaurant");
				return FALSE; 
			}

			temp->status = status; 
			return TRUE;
		}

		temp = temp->next; 
	}

	return FALSE; 
}

void retrieveAndRemove(waitlist **head, int num_burgers, int num_salads, int debugMode) {
	waitlist *temp = *head;
	waitlist *p = NULL;

	if (temp == NULL) { 
		printf("No one can pick up order\n");
		return;
	}
	else { // check first 
		if (temp->status == in) {
			if (temp->burger <= num_burgers) {
				if (temp->salad <= num_salads) {
					printf("Serving %s\n", temp->name);
					*head = (*head)->next;
					free(temp->name);
					free(temp); //free up the memory
					return;
				}
			}
		}
		else {
			if (debugMode == TRUE) {
				printf("%s is not in the resturant\n", temp->name);
			}
		}
        
        while (temp->next != NULL) {
			if (temp->next->status == in) {
				if (temp->next->burger <= num_burgers) {
					if (temp->next->salad <= num_salads) {
						printf("Serving %s\n", temp->next->name);
						p = temp->next;
						temp->next = temp->next->next; 
						free(p);
						return;
					}
					else {
						temp = temp->next; //next node
					}
				}
				else {
					temp = temp->next; 
				}
			}
			else {
				temp = temp->next; 
			}
		}
	}

	printf("Sorry no group can pick up \n");
	return;
}

void displayOrdersAhead(waitlist *head, char *name) {

	if (head == NULL) {
		printf("No one queue\n");
		return;
	}

	if (strcmp(head->name, name) == 0) { 
		printf("You are next\n");
		return;
	}

	while (head != NULL) {
		if (strcmp(head->name, name) != 0) {
			printf("Name: %s, Burgers: %d, Salads: %d, ", head->name, head->burger, head->salad);
			if (head->status == in) {
				printf("Status: In restaurant\n");
			}
			else {
				printf("Status: Not in restaurant\n");
			}
		}
		else {
			return;
		}
		head = head->next;
	}
	return;
}

void displayListInformation(waitlist *head) {
	if (head == NULL) {
		printf("No one is in the queue\n");
		return;
	}

	printf("Orders in qeueu: \n");
	while (head != NULL) {
		printf("Name: %s, Burgers: %d, Salads: %d, ", head->name, head->burger, head->salad);
		if (head->status == in) {
			printf("Status: In restaurant\n");
		}
		else {
			printf("Status: Not in restaurant\n");
		}
		head = head->next;
	}
	return;
}

void displayWaitingTime(waitlist *head, char* name, int debugMode) {
	int time = 0;
	

	if (debugMode == TRUE) {
		while (head != NULL) {
			time = time + ((head->burger * 10) + (head->salad * 5));
			if (strcmp(head->name, name) == 0) {
				printf("Requested: ");
			}
			printf("Estimated waiting time for %s is %d minutes\n", head->name, time);
			head = head->next;
		}
	}
	else {
		while (head != NULL) {
			if (strcmp(head->name, name) != 0) {
				time = time + ((head->burger * 10) + (head->salad * 5));
			}
			else {
				break;
			}
			head = head->next;
		}

		printf("Estimated waiting time for %s is %d minutes\n", name, time);
	}
}

int countOrdersAhead(waitlist *head, char*name) {
	int count = 0;
	while (head != NULL) {
		if (strcmp(head->name, name) != 0) {
			count++;
		}
		else {
			return count;
		}
		head = head->next;
	}
	return count;
}

void clean(waitlist **head) {
	waitlist *temp = *head;
	while (temp != NULL) {
		free(temp->name);
		*head = (*head)->next;
		free(temp);
		temp = *head;
	}
	*head = NULL;
}
