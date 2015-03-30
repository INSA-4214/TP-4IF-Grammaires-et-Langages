#include "Write.h"

void Write::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {
	e->staticAnalysis(table);
}


Write::~Write()
{
    //dtor
}
