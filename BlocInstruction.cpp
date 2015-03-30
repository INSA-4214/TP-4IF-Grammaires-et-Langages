/*
 * BlocInstruction.cpp
 *
 *  Created on: 26 mars 2015
 *      Author: Huber
 */

#include "BlocInstruction.h"
#include <iostream>
//*TODO

 void BlocInstruction::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table){
	 for (std::set<Instruction*>::iterator it=instructions.begin(); it!=instructions.end(); ++it)
		 (*it)->staticAnalysis(table);

 }
 void BlocInstruction::print(){
 for (std::set<Instruction*>::iterator it=instructions.begin(); it!=instructions.end(); ++it)
	 (*it)->print();

 }
 //*/

 void BlocInstruction::exec(map<string, pair<double, bool> > *table){
 for (std::set<Instruction*>::iterator it=instructions.begin(); it!=instructions.end(); ++it)
	 (*it)->exec(table);
 }
