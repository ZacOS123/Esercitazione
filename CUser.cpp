/// \file CUser.cpp 
///	\brief User interface functions file
///
///	Details.
///

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "CUser.h"
#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"
#define MAX 50


using std::cout;
using std::endl;
using std::scanf;


/// @prints all the objects 
void Show(Quadrilateral* list[]) {

	int i;
	int temp_i = -1; //Used to identify if the array is empty. Temporary index: if contaminated means that the array is not empty

	for (i = 0; i <= MAX; i++) {
		if (list[i] != NULL) {
			temp_i = i;
			cout << "\n" << i << "." << endl;
			list[i]->Drawing();
			continue;
		}
	}
	if (temp_i == -1) {
			cout << "\n\nNo shapes found. Storage empty.\n\n" << endl;
	}
}

/// @brief creates a new shape based on user choice
/// @param choice (user choice)
/// @param dim1 first side or diagonal
///	@param dim2  second side or diagonal
/// @param text type textarea of quadrilateral class
/// @param warning used to select the warning message
void AddShape(Quadrilateral* list[]) {
	int choice = 0;
	float dim2 = 0; //do not change this values. The checks will not work
	float dim1 = 0;
	TextArea text{"", 0};
	int warning = 0;
	Quadrilateral* tempQuadPtr = NULL;  //to store created shape temporarily
	int arrayIndex = 0; //used to search in array
	
	for (arrayIndex = 0; arrayIndex <= MAX; arrayIndex++) {  //checks for available storage
		if (list[arrayIndex] == NULL) {
			break;
		}
		else if (arrayIndex == MAX && list[arrayIndex] != NULL) {
			cout << "\nNo storage available. Maximum shapes number (MAX) reached.\n" << endl;
			return;
		}
	}
	while (choice != 1 && choice != 2) { 
		menu();
		scanf_s(" %i", &choice);
		if (choice != 1 && choice != 2) // verifies if the choice is valid
		{
			warning = 6;
			WarningMessage(6);
		}
	}

	switch (choice) {
		
			
		case 1:
			while (dim1 <= 0)
			{
				cout << "Enter rectangle height: " << endl;
				scanf_s("%f", &dim1);
				if (dim1 <= 0) {
					warning = 1;
					WarningMessage(warning);
				}
			}
			
			while(dim2 <= 0){
				cout << "Enter rectangle width: " << endl;
				scanf_s("%f", &dim2);
				if (dim2 <= 0) {
					warning = 2;
					WarningMessage(warning);
				}
			}

			cout << "Add text (max MAX, NO space): " << endl;
			scanf("%s", text.string);

			while (text.size == 0) {
					cout << "Enter text size: " << endl;
					scanf_s("%i", &text.size);
					if (text.size == 0) {
						warning = 5;
						WarningMessage(warning);
					}
			}
			list[arrayIndex] = new Rectangle(dim2, dim1, text);
			cout << "\n\nRectangle created successfully!\n\n" << endl;
			return;

		case 2:

			while (dim1 <= 0) {
				cout << "Enter rhombus' first diagonal:" << endl;
				scanf_s("%f", &dim1);
				if (dim1 <= 0) {
					warning = 3;
					WarningMessage(warning);
				}
			}

			while (dim2 <= 0) {
				cout << "Enter rhombus' second diagonal:" << endl;
				scanf_s("%f", &dim2);
				if (dim2 <= 0) {
					warning = 3;
					WarningMessage(warning);
				}
			}

			cout << "Add text (max MAX, NO space): " << endl;
			scanf("%s", text.string);

			while (text.size == 0) {
				cout << "Enter text size: " << endl;
				scanf_s("%i", &text.size);
				if (text.size == 0) {
					warning = 5;
					WarningMessage(warning);
				}
			}
			list[arrayIndex] = new Rhombus(dim2, dim1, text);
			cout << "\n\nRhombus created successfully!\n\n" << endl;
			return;
	}
		return;
	}



/// @brief menu choice
void menu() {
	cout << "To create a rectangle enter - 1 -" << endl;
	cout << "To create a rhombus enter - 2 - " << endl;
}


/// @brief deletes an object based on user choice
/// @param choice user choice
void deleteShape(Quadrilateral* list[]) {
	int choice;

	Show(list);
	cout << "\nWhich shape would you like to delete?\n" << endl;
	cout << "Enter corrisponding number: " << endl;
	scanf_s("%i", &choice);
	delete list[choice];
	list[choice] = NULL;
	cout << "\nObject deleted successfully\n" << endl;


}


/// @brief deletes all the objects.
void deleteAll(Quadrilateral* list[]) 
{
	int i = 0;
	if (list[i] == NULL) {   
		cout << "\n\nNo shapes found. Storage empty.\n\n" << endl;
	}
	else {
		for (i = 0; i <= MAX; i++) {
			if (list[i] == NULL) {
				i++;
			}
			else {
				delete list[i];
				list[i] = NULL;
			}
		}
	}
	cout << "\nAll shapes deleted successfully\n" << endl;

}


///  @brief User warning messages
/// @param waring select the warning case
void WarningMessage(int warning){

	cout << "-----  User warning ----- " << endl;
	switch (warning) {
		case 1:
			cout << "Height value should be greater than zero!!" << endl;
			break;
		case 2:
			cout << "Width value should be greater than zero!!" << endl;
			break;
		case 3:
			cout << "Diagonal value should be greater than zero!!" << endl;
			break;
		case 5:
			cout << "Font size value should be greater than zero!!" << endl;
			break;
		case 6:
			cout << "Option not valid!" << endl;
			cout << "Select a valid option." << endl;
			break;
	}
	cout << "       -----------" << endl;
	return;
}


/// @brief Main user menu 
/// @param choice user choice
int MainMenu() {
	int choice;
	cout << "\nWhat would you like to do?\n" << endl;
	cout << "1. Visualize all created shapes" << endl;
	cout << "2. Add new shape" << endl;
	cout << "3. Delete a shape" << endl;
	cout << "4. Delete all shapes" << endl;
	cout << "5. Quit program\n" << endl;
	cout << "Enter corresponding number: " << endl;
	scanf_s("%i", &choice);
	return choice;
}