// -*- C++ -*-
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  <LicenseText>
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

#if !defined(pyCitcomSExchanger_VTOutlet_h)
#define pyCitcomSExchanger_VTOutlet_h

#include "Exchanger/Outlet.h"

struct All_variables;
class CitcomSource;


class VTOutlet : public Exchanger::Outlet {
    All_variables* E;
    Exchanger::Array2D<double,Exchanger::DIM> v;
    Exchanger::Array2D<double,1> t;

public:
    VTOutlet(const CitcomSource& source,
	     All_variables* E);
    virtual ~VTOutlet();

    virtual void send();

private:
    // disable copy c'tor and assignment operator
    VTOutlet(const VTOutlet&);
    VTOutlet& operator=(const VTOutlet&);

};


#endif

// version
// $Id: VTOutlet.h,v 1.2 2004/05/11 07:55:30 tan2 Exp $

// End of file
