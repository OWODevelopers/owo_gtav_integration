#pragma once
#include "../OWOAPI/Controller/OWO.h"
#include "Vehicle.h"
#include "IntensityLerp.h"

class FeelDriving
{
private:
	sharedPtr<OWOGame::OWO> device = nullptr;
	sharedPtr<Vehicle> vehicle = nullptr;
	IntensityLerp engine = IntensityLerp(0,0,0,0);
	IntensityLerp forImpacts = IntensityLerp(10,60,40,90);
	int lastVelocity;

	int ImpactIntensity();
public:
	FeelDriving(sharedPtr<OWOGame::OWO> device, sharedPtr<Vehicle> vehicle, IntensityLerp engine, IntensityLerp forImpacts) 
		: device(device), vehicle(vehicle), engine(engine), forImpacts(forImpacts) {}
	void Execute();
};