// -*- C++ -*-
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  <LicenseText>
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

#include <portinfo>
#include "global_defs.h"
#include "journal/journal.h"
#include "CitcomSource.h"
#include "Convertor.h"
#include "VTOutlet.h"


VTOutlet::VTOutlet(const CitcomSource& source,
		   All_variables* e) :
    Outlet(source),
    E(e),
    v(source.size()),
    t(source.size())

{
    journal::debug_t debug("CitcomS-Exchanger");
    debug << journal::loc(__HERE__) << journal::end;
}


VTOutlet::~VTOutlet()
{}


void VTOutlet::send()
{
    journal::debug_t debug("CitcomS-Exchanger");
    debug << journal::loc(__HERE__) << journal::end;

    source.interpolateVelocity(v);
    v.print("CitcomS-VTOutlet-V");

    source.interpolateTemperature(t);
    t.print("CitcomS-VTOutlet-T");

    Exchanger::Convertor& convertor = Convertor::instance();
    convertor.velocity(v, source.getX());
    convertor.temperature(t);

    source.send(t, v);
}


// private functions



// version
// $Id: VTOutlet.cc,v 1.2 2004/05/11 07:55:30 tan2 Exp $

// End of file
