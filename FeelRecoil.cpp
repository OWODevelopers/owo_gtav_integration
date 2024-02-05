#include "FeelRecoil.h"
#include "OWOAPI/Domain/SensationsFactory.h"
#include "OWOAPI/Domain/Muscle.h"

void FeelRecoil::Execute()
{
	owo->Send(OWOGame::SensationsFactory::Create()->WithMuscles({OWOGame::Muscle::Abdominal_L()}));
}
