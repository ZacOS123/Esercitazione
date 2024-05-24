/// \file CUser.cpp 
///	\brief user interface functions file
///
///	Details.
///

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "CUser.h"
#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"


using std::cout;
using std::endl;
using std::scanf;

void Show(Quadrilateral* list[]) {

	int i;
	for (i = 0; list[i] != NULL; i++) {     // this means that all items should be moved when an object was deleted from the center of the array

		list[i]->Drawing();
	}
}

/// @brief creates a new shape based on user choice
/// @param choice (user choice)
/// @param height 
///	@param width 
/// 
Quadrilateral* AddShape() {
	int choice = 0;
	float height = 1;
	float width = 1;
	TextArea text;

	while (choice != 1 && choice != 2) { // verifies if the choice is valid
		menu();
		scanf_s("%i", &choice);
		if (choice != 1 && choice != 2)
		{
			cout << "Option not valid!" << endl;
			cout << "Select a valid option." << endl;
		}

	}

		switch (choice) {
		case 1:
				cout << "Enter rectangle height: " << endl;
				scanf_s("%f", &height);
				cout << "Enter rectangle width: " << endl;
				scanf_s("%f", &width);
				cout << "Add text (max 50): " << endl;
				scanf("%49s", text.string);
				cout << "Enter text size: " << endl;
				scanf_s("%i", &text.size);
			return new Rectangle(width, height, text);

		case 2:
			cout << "Enter rhombus' large diagonal: " << endl;
			scanf_s("%f", &height);
			cout << "Enter rhombus' small diagonal: " << endl;
			scanf_s("%f", &width);
			cout << "Add text (max 50): " << endl;
			scanf("%49s", text.string);
			cout << "Enter text size: " << endl;
			scanf_s("%i", &text.size);
			return new Rhombus(width, height, text);
		}
		return NULL;
	}

/// @brief menu choice
void menu() {
	cout << "To create a rectangle enter - 1 -" << endl;
	cout << "To create a rhombus enter - 2 - " << endl;
}