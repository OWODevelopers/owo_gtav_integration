#pragma once
#include "../OWOAPI/Controller/OWO.h"
#include "OWOVehicle.h"
#include "IntensityLerp.h"

class FeelDriving
{
private:
	sharedPtr<OWOGame::OWO> device = nullptr;
	sharedPtr<OWOVehicle> vehicle = nullptr;
	IntensityLerp engine = IntensityLerp(0,0,0,0);
	IntensityLerp forImpacts = IntensityLerp(10,60,40,90);
	int lastVelocity;

	int ImpactIntensity();
	bool DidImpact();
	uniquePtr<OWOGame::Sensation> DrivingSensation();
	bool CanFeelDriving();

	OWOGame::MusclesGroup SteeringMuscles();
	OWOGame::MusclesGroup TurningTowardsMuscles();
	OWOGame::MusclesGroup TurningAgainstMuscles();

	OWOGame::MusclesGroup Right();
	OWOGame::MusclesGroup Left();
public:
	FeelDriving(sharedPtr<OWOGame::OWO> device, sharedPtr<OWOVehicle> vehicle, IntensityLerp engine, IntensityLerp forImpacts)
		: device(device), vehicle(vehicle), engine(engine), forImpacts(forImpacts) {}
	void Execute();
};