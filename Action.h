/*
 * Action.h
 *
 *  Created on: 11 mars 2015
 *      Author: vincent
 */

#ifndef ACTION_H_
#define ACTION_H_
#include <map>
#include "Etat.h"
#include "Symbole.h"
class Action {
public:
	// typedef std::map<Etat::EtatId, std::map<Symbole::Id, Action * > > TableAction;

	 Action(){}
	virtual ~Action() {};



};

#endif /* ACTION_H_ */
