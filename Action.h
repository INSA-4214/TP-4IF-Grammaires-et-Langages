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
	 typedef std::map<Etat::Id, std::map<Symbole::ident, Action *>> TableAction;

	virtual ~Action() {};



};

#endif /* ACTION_H_ */
