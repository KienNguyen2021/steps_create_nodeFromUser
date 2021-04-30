#include <stdio.h>
#include <stdlib.h>


// define element for structure
struct node {
	int data;      		 // data variable
	struct node *nextPtr;   	 // pointer to the next NODE
};
struct node *startNode;                            // declare a pointer for the starting NODE

static void createNodeList(int totalNodes);      		// Declare a function prototype for creating a NODE list
static void displayList();

int main()
{

	int numberOfNodes;    		    // Declare a variable to hold the maximum number of the nodes created by user
	printf("Input the number of nodes : ");        //   Ask the user Input for total of nodes to input
	scanf("%d", &numberOfNodes);
	createNodeList(numberOfNodes);              // Create a list of nodes
	displayList();    			// Display a list of nodes


	return 0;
}
static void createNodeList(int totalNodes)     		//  Create the definition of the declared function
{
	struct node *newNode;       // Declare a pointer for creating  new Nodes
	struct node *nodeBuffer;     //  Declare a variable for temporarily holding Nodes
	int nodeData;		// Declare a variable to contain user'input
	int nodeCounter;		// Declare a variable to count Nodes from user's input

	startNode = (struct node *) malloc(sizeof(struct node));    // Allocate  memory for starting Nodes

	if (startNode == NULL)                 // Check if memory was successfully allocated
	{
		printf(" Memory can not be allocated ");        // It failed,  exit the program
	}
	else 			              // if memory allocation was successful,    ask user to input first Node
	{
		printf(" Input data for Node :" );
			scanf("%d", &nodeData);             // d : data
			startNode->data = nodeData;     // Copy the user's input to the data element of the Node - Save the Input from user to the data element of Node
		    startNode->nextPtr = NULL;         // Initialize the Node's next Pointer element to NULL
		    nodeBuffer = startNode;            // Point the buffer to the first address of the NODE

										   // Use  LOOP to generate the successful NODEs
		for (nodeCounter = 2; nodeCounter <= totalNodes; nodeCounter++)
		{
			newNode = (struct node*)malloc(sizeof(struct node));           // Allocate memory for the new NODE

			if (newNode == NULL)                                                 // check if memory was successfully allocated to new NODE . If not, exit the program
			{
				printf(" Memory cannot be allocated");

				break;
			}
			else
			{
				printf(" Input data for node %d : ", nodeCounter);           // if memory was succesfully allocated, request user to input data for NODE
				scanf("%d", &nodeData);

				newNode->data = nodeData;             // Assign User's input to the node's data element
				newNode->nextPtr = NULL;                  // Initialize node's Next pointer to NULL
				nodeBuffer->nextPtr = newNode;        // link the ealier NODE to the new NODE
				nodeBuffer = nodeBuffer->nextPtr;    //   Point the buffer pointer to  the address of the current NODE

			}

		}
	}
}

// Define the function to display all nodes

static void displayList()

{

	struct node *nodeBuffer;    // Declare a temporary pointer to  NODE
	nodeBuffer = startNode;      // Point the temporary Node pointer to the first Node of the list of element

								 // check if the list is empty
	if (nodeBuffer == NULL)
	{
		printf(" List is empty");

	}
	else                    // if the list is not empty, LOOP through all the nodes until it reaches then end 
	{
		while (nodeBuffer != NULL)
		{
			printf("Data =%d\n", nodeBuffer->data);         // print data of the current element

															// go to the next node
			nodeBuffer = nodeBuffer->nextPtr;

		}
	}




}
























