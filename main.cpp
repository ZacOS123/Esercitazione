#include<iostream>
#include <cstring>

#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CUser.h"


const int LISTL = 50;

Quadrilateral* quadList[LISTL] = { nullptr };  //Initializing array of pointers (pointers to quadrilaterals)


int main() {
	Quadrilateral* tempQuadPtr = NULL; //used to temporarily store returned ptr from AddShape()
	int choice = MainMenu();
	
	while (choice != 5) {

		switch (choice) {
			case 1:
				Show(quadList);
				break;
			case 2:
				AddShape(quadList);
				break;
			case 3:
				deleteShape(quadList);
				break;
			case 4:
				deleteAll(quadList);
		}
		choice = MainMenu();
	}
	
}