#include "FeelDriving.h"
#include "../OWOAPI/Domain/SensationsFactory.h"

int FeelDriving::ImpactIntensity()
{
	return OWOGame::Math::Clamp(lastVelocity - vehicle->Velocity(), 0, 90);
}

void FeelDriving::Execute()
{
	if (ImpactIntensity() > 20) 
	{
		device->Send(OWOGame::SensationsFactory::Create(100, .1f, ImpactIntensity())->WithMuscles(OWOGame::MusclesGroup::All()));
		lastVelocity = vehicle->Velocity();
		return;
	}

	if (vehicle->Velocity() <= 0) return;

	auto whereFeels = vehicle->DrivingForward() ? OWOGame::MusclesGroup::Back() : OWOGame::MusclesGroup::Front();
	device->Send(OWOGame::SensationsFactory::Create(100, .1f, engine.IntensityAt(vehicle->Velocity()))->WithMuscles(whereFeels));
	lastVelocity = vehicle->Velocity();
}