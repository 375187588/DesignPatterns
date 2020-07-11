/**
 * Project Untitled
 */


#ifndef _IABSTRACTFACTOR_H
#define _IABSTRACTFACTOR_H

class IAbstractFactor {
public: 
	
virtual IBusinessCarBase* CreateBusinessCar();
	
virtual ICivilCarBase* CreateCivilCar();
	
virtual ISportCarBase* CreateSportCar();
};

#endif //_IABSTRACTFACTOR_H