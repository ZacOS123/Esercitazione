/*! \file CUser.h
	\brief Library of functions for user interface

	Details.
*/

#include <iostream>
#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"


/// @function Show
void Show(Quadrilateral* list[]);

/// @brief creates a new shape based on user choice
void AddShape(Quadrilateral* list[]);


/// @brief menu choice
void menu();

/// @brief Main startup menu
int MainMenu();


///  @brief User warning messages
void WarningMessage(int warning);