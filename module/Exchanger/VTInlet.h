// -*- C++ -*-
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  <LicenseText>
//
// Role:
//     impose velocity and temperature as b.c.
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

#if !defined(pyCitcomSExchanger_VTInlet_h)
#define pyCitcomSExchanger_VTInlet_h

#include "Exchanger/Array2D.h"
#include "Exchanger/DIM.h"
#include "Exchanger/Inlet.h"

struct All_variables;


class VTInlet : public Exchanger::Inlet {
    All_variables* E;
    Exchanger::Array2D<double,Exchanger::DIM> v;
    Exchanger::Array2D<double,Exchanger::DIM> v_old;
    Exchanger::Array2D<double,1> t;
    Exchanger::Array2D<double,1> t_old;

public:
    VTInlet(const Exchanger::BoundedMesh& boundedMesh,
	    const Exchanger::Sink& sink,
	    All_variables* E);

    virtual ~VTInlet();

    virtual void recv();
    virtual void impose();

private:
    void setVBCFlag();
    void setTBCFlag();

    void imposeV();
    void imposeT();

};


#endif

// version
// $Id: VTInlet.h,v 1.3 2004/05/11 07:55:30 tan2 Exp $

// End of file
