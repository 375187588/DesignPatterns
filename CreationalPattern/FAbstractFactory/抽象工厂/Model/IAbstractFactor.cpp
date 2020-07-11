/**
 * Project Untitled
 */


#include "IAbstractFactor.h"

/**
 * IAbstractFactor implementation
 */


/**
 * @return virtual IBusinessCarBase*
 */
virtual IBusinessCarBase* IAbstractFactor::CreateBusinessCar() {
    return null;
}

/**
 * @return virtual ICivilCarBase*
 */
virtual ICivilCarBase* IAbstractFactor::CreateCivilCar() {
    return null;
}

/**
 * @return virtual ISportCarBase*
 */
virtual ISportCarBase* IAbstractFactor::CreateSportCar() {
    return null;
}