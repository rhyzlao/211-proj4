#include "order.h"

void doAdd(waitlist **head, int debugMode)
{
	/* get number of burgers ordered from input */
	int NumBurgers = getPosInt();
	if (NumBurgers < 0)
	{
		printf("Error: Add command requires an integer value of at least 0\n");
		printf("Add command is of form: a <# burgers> <# salads> <name>\n");
		printf("  where:<# burgers> is the number of ordered burgers\n");
		printf("        <# salads> is the number of ordered salads\n");
		printf("        <name> is the name of the person putting the order\n");
		return;
	}

	/* get number of salads ordered from input */
	int NumSalads = getPosInt();
	if (NumSalads < 0)
	{
		printf("Error: Add command requires an integer value of at least 0\n");
		printf("Add command is of form: a <# burgers> <# salads> <name>\n");
		printf("  where:<# burgers> is the number of ordered burgers\n");
		printf("        <# salads> is the number of ordered salads\n");
		printf("        <name> is the name of the person putting the order\n");
		return;
	}

	/* get group name from input */
	char *name = getName();
	if (NULL == name)
	{
		printf("Error: Add command requires a name to be given\n");
		printf("Add command is of form: a <# burgers> <# salads> <name>\n");
		printf("  where:<# burgers> is the number of ordered burgers\n");
		printf("        <# salads> is the number of ordered salads\n");
		printf("        <name> is the name of the person putting the order\n");
		return;
	}
    
    // add code to perform this operation here

	if (doesNameExist(head, name) == 1) { //check to see if someone with the same name is in the queue
		free(name);
		printf("Error: existing name in the queue \n");
		if (debugMode == TRUE) {
			displayListInformation(*head);
		}
		return;
	}
    
    printf("Adding In-restaurant order for \"%s\": %d burgers and %d salads\n", name, NumBurgers, NumSalads);
	addToList(head, name, NumBurgers, NumSalads, in); 
	if (debugMode == TRUE) {
		displayListInformation(*head);
	}
    
    
}

void doCallAhead(waitlist **head, int debugMode)
{
	/* get number of burgers ordered from input */
	int NumBurgers = getPosInt();
	if (NumBurgers < 0)
	{
		printf("Error: Call-ahead command requires an integer value of at least 0\n");
		printf("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
		printf("  where:<# burgers> is the number of ordered burgers\n");
		printf("        <# salads> is the number of ordered salads\n");
		printf("        <name> is the name of the person putting the order\n");
		return;
	}

	/* get number of salads ordered from input */
	int NumSalads = getPosInt();
	if (NumSalads < 0)
	{
		printf("Error: Call-ahead command requires an integer value of at least 0\n");
		printf("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
		printf("  where:<# burgers> is the number of ordered burgers\n");
		printf("        <# salads> is the number of ordered salads\n");
		printf("        <name> is the name of the person putting the order\n");
		return;
	}


	/* get group name from input */
	char *name = getName();
	if (NULL == name)
	{
		printf("Error: Call-ahead command requires a name to be given\n");
		printf("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
		printf("  where:<# burgers> is the number of ordered burgers\n");
		printf("        <# salads> is the number of ordered salads\n");
		printf("        <name> is the name of the person putting the order\n");
		return;
	}
    
	// add code to perform this operation here
	
    if (doesNameExist(head, name) == 1) { //check to see if someone with the same name is in the queue
		free(name);
		printf("Error: Existing name in the queue \n");
		if (debugMode == TRUE) {
			displayListInformation(*head);
		}
		return;
	}
    
    printf("Adding Call-ahead order for \"%s\": %d burgers and %d salads\n", name, NumBurgers, NumSalads);
    
	addToList(head, name, NumBurgers, NumSalads, call); 
	if (debugMode == TRUE) {
		displayListInformation(*head);
	}
}

void doWaiting(waitlist **head, int debugMode)
{
	/* get order name from input */
	char *name = getName();
	if (NULL == name)
	{
		printf("Error: Waiting command requires a name to be given\n");
		printf("Waiting command is of form: w <name>\n");
		printf("  where: <name> is the name of the group that is now waiting\n");
		return;
	}


	// add code to perform this operation here
	if (doesNameExist(head, name) == 0) { //check to see if someone with the same name is in the queue
		printf("Not in queue \n");
		if (debugMode == TRUE) {
			displayListInformation(*head);
		}
		return;
	}
    
    printf("Call-ahead order \"%s\" is now waiting in the restaurant\n", name);
    
	//update the status of the person to waiting in restaurant
	updateStatus(head, name, in); //don't need to pass in & because not changing the head
	if (debugMode == TRUE) {
		displayListInformation(*head);
	}
}

void doRetrieve(waitlist **head, int debugMode)
{
	/* get info of prepared food ready on the counter from input */
	int PreparedBurgers = getPosInt();
	if (PreparedBurgers < 0)
	{
		printf("Error: Retrieve command requires an integer value of at least 0\n");
		printf("Retrieve command is of form: r <# burgers> <# salads>\n");
		printf("  where: <# burgers> is the number of burgers waiting on the counter for pick up\n");
		printf("         <# saladss> is the number of salads waiting on the counter for pick up\n");
		return;
	}

	int PreparedSalads = getPosInt();
	if (PreparedSalads < 0)
	{
		printf("Error: Retrieve command requires an integer value of at least 0\n");
		printf("Retrieve command is of form: r <# burgers> <# salads>\n");
		printf("  where: <# burgers> is the number of burgers waiting on the counter for pick up\n");
		printf("         <# saladss> is the number of salads waiting on the counter for pick up\n");
		return;
	}

	clearToEoln();
	printf("Retrieve (and remove) the first group that can pick up the order of %d burgers and %d salads\n", PreparedBurgers, PreparedSalads);

	// add code to perform this operation here
	
	retrieveAndRemove(head, PreparedBurgers, PreparedSalads, debugMode);
}

void doList(waitlist *head)
{
	/* get order name from input */
	char *name = getName();
	int namePresent;
	namePresent = 0; //flag to see if the name is in the queue

	if (NULL == name)
	{
		printf("Error: List command requires a name to be given\n");
		printf("List command is of form: l <name>\n");
		printf("  where: <name> is the name of the order to inquire about\n");
		return;
	}

	// add code to perform this operation here
	waitlist* head2 = head; //copy of head
	while (head != NULL) {
		if (strcmp(head->name, name) == 0) {
			namePresent = 1;
		}
		head = head->next;
	}

	if (namePresent == 0) {
		printf("Error: Name not in queue \n");
	}
	else {
		printf("Order for \"%s\" is behind the following orders\n", name);
		displayOrdersAhead(head2, name);
	}
}

void doDisplay(waitlist *head)
{
	clearToEoln();
	printf("Display information about all orders\n");

	// add code to perform this operation here
	displayListInformation(head);
}


void doEstimateTime(waitlist **head, int debugMode)
{
	/* get order name from input */

	char *name = getName();
	if (name == NULL)
	{
		printf("Error: List command requires a name to be given\n");
		printf("List command is of form: t <name>\n");
		printf("  where: <name> is the name of the order to inquire about\n");
		return;
	}


	// add code to perform this operation here  
	if (doesNameExist(head, name) == 0) {
		printf("Error: Name not in queue\n");
		return;
	}

	displayWaitingTime(*head, name, debugMode);
}



