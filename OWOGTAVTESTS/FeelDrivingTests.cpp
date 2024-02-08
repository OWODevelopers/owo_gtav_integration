#include "CppUnitTest.h"
#include "HapticDevice.h"
#include "../OWOAPI/Domain/SensationsFactory.h"
#include "MockBody.h"
#include "../FeelDriving.h"
#include "../MockVehicle.h"
#include "../VehicleEngine.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OWOGTAVTESTS
{
	TEST_CLASS(FeelDrivingTests)
	{
	public:

		TEST_METHOD(FeelNothing_WheNotDriving)
		{
			sharedPtr<MockDevice> mock = CreateNewUnique(MockDevice, MockDevice());
			sharedPtr<MockVehicle> doc = CreateNewUnique(MockVehicle, MockVehicle());
			auto engine = VehicleEngine(0, 100, 0, 40);

			auto sut = FeelDriving(mock, doc, engine);

			sut.Execute();

			Assert::IsFalse(mock->DidFeelAnything());
		}

		TEST_METHOD(FeelSomething_WhenDriving)
		{
			sharedPtr<MockDevice> mock = CreateNewUnique(MockDevice, MockDevice());
			sharedPtr<MockVehicle> doc = CreateNewUnique(MockVehicle, MockVehicle());
			auto engine = VehicleEngine(0, 100, 0, 40);

			auto sut = FeelDriving(mock, doc, engine);

			doc->DriveAt(100);

			sut.Execute();

			Assert::IsTrue(mock->DidFeelAnything());
		}

		TEST_METHOD(Feel_MaxVelocity_Intensity)
		{
			sharedPtr<MockDevice> mock = CreateNewUnique(MockDevice, MockDevice());
			sharedPtr<MockVehicle> doc = CreateNewUnique(MockVehicle, MockVehicle());

			auto engine = VehicleEngine(0, 100, 0, 40);
			auto sut = FeelDriving(mock, doc, engine);

			doc->DriveAt(100);
			sut.Execute();

			Assert::AreEqual(40, mock->IntensityOfLastFelt());
		}

		TEST_METHOD(DontFeel_Below_MinVelocity)
		{
			Assert::AreEqual(0, VehicleEngine(3, 100, 20, 40).IntensityAt(2));
		}

		TEST_METHOD(Feel_MinIntensity)
		{
			Assert::AreEqual(1, VehicleEngine(6, 100, 1, 40).IntensityAt(6));
		}
	};
}