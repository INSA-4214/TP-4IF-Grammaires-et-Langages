/*
 * Programme.cpp
 *
 *  Created on: 28 mars 2015
 *      Author: Huber
 */

#include "Programme.h"
#include <map>
#include <string>

using namespace std;

Programme::~Programme() {
	// TODO Auto-generated destructor stub

}

void Programme::staticAnalysis(map<string, pair<bool, bool> > *table) {
	blocD->staticAnalysis(table);
	blocI->staticAnalysis(table);
}

//*TODO

void Programme::exec(map<string, pair<double, bool> > *table){
	blocD->exec(table);
	blocI->exec(table);
}
	void Programme::print(){
	blocD->print();
	blocI->print();
	}

//*/
