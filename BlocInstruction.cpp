/*
 * BlocInstruction.cpp
 *
 *  Created on: 26 mars 2015
 *      Author: Huber
 */

#include "BlocInstruction.h"
#include <iostream>
//*TODO
 void BlocInstruction::print(){
 for (std::set<Instruction*>::iterator it=instructions.begin(); it!=instructions.end(); ++it)
	 (*it)->print();
 }
 //*/
