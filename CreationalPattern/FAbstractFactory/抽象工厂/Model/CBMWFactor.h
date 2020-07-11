/**
 * Project Untitled
 */


#ifndef _CBMWFACTOR_H
#define _CBMWFACTOR_H

#include "IAbstractFactor.h"


class CBMWFactor: public IAbstractFactor {
public: 
	
IBusinessCarBase* CreateBusinessCar();
	
ICivilCarBase* CreateCivilCar();
	
ISportCarBase* CreateSportCar();
};

#endif //_CBMWFACTOR_H