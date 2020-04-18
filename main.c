#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

struct DataItem {
	int exercise;
	int amount;
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int amount) {
   return amount % SIZE;
}

struct DataItem *search(int amount) {
   //get the hash 
   int hashIndex = hashCode(amount);  
	
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->amount == amount)
         return hashArray[hashIndex]; 
			
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }        
	
   return NULL;        
}

void insert(int exercise, int amount) {
	struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
	item->exercise = exercise;
	item->amount = amount;

	// get hash
	int hashIndex = hashCode(amount);

	// move in array until an empty or delete cell
	while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->amount != -1) {
		// go to next cell
		++hashIndex;

		// wrap around the table
		hashIndex %=SIZE;
	}

	hashArray[hashIndex] = item;
}


struct DataItem* delete(struct DataItem* item) {
	int amount = item->amount;

	// get the hash
	int hashIndex = hashCode(amount);

	// move in array until an empty
	while (hashArray[hashIndex] != NULL) {
		if (hashArray[hashIndex]->amount == amount) {
			struct DataItem* temp = hashArray[hashIndex];

			// assign a dummy item at deleted position
			hashArray[hashIndex] = dummyItem;
			return temp;
		}

		// go to next cell
		++hashIndex;

		// wrap around the table
		hashIndex %= SIZE;
	}
	return NULL;
}

void display() {
	int i = 0;

	for (i = 0; i<SIZE; i++) {

		if (hashArray[i] !=NULL)
			printf(" (%d,%d)",hashArray[i]->amount,hashArray[i]->exercise);
		else
			printf(" ~~ ");
	}

	printf("\n");
}

int main(){

	printf("This program will allow users to keep track of their workout schedule.\n");
	printf("For this program, each exercise is assigned a number. To add your \n");
	printf("workout to the hashtable, enter the number that workout is assigned \n");
	printf("and then enter the number that you did.\n");
	printf("Pull ups=1 \n crunches=2 \n squats=3 \n bench press=4 \n leg lifts=5 \n");
	
	dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
	dummyItem->exercise = -1;
	dummyItem->amount = -1;


	char str;
	printf("Please type your first exercise.\n");
	scanf("%d",&str);

	int amount1;
	printf("How many have you done?\n");
	scanf("%d",&amount1);


	insert(str, amount1);

	int question;
	printf("Do you have more exercises to enter? Enter '1' if you do.\n");
	scanf("%d",&question);

	printf("%d\n",question);

	if(question==1) {	
		while(question==1) {


			printf("Please type the exercise.\n");
			scanf("%d",&str);
			printf("How many have you done?\n");
			scanf("%d",&amount1);

			insert(str, amount1);
		
			printf("Do you have more exercises to do? Enter '1' if you do.\n");
			scanf("%d",&question);
			
			if (question!=1) {
				break;
			}	

		}
	}
	display();






	return 0;










}
