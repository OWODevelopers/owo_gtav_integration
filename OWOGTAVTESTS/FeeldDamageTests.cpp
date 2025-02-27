#include "CppUnitTest.h"
#include "HapticDevice.h"
#include "../OWOAPI/Domain/SensationsFactory.h"
#include "MockBody.h"
#include "../FeelDamage.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OWOGTAVTESTS
{
	TEST_CLASS(FeelDamageTests)
	{
	public:
		FeelDamage CreateSut(sharedPtr<OWOGame::OWO> device = nullptr, sharedPtr<PlayerBody> body = nullptr) 
		{
			sharedPtr<OWO> mock = device == nullptr ? CreateNewUnique(MockDevice, MockDevice()) : device;
			sharedPtr<PlayerBody> mockBody = body == nullptr ? CreateNewUnique(MockBody, MockBody(MusclesGroup({Muscle::Arm_L()}))) : body;
			return FeelDamage(mock, mockBody);
		}
		
		TEST_METHOD(FeelDamage_WhenHealthIs_BelowPreviousHealth)
		{
			sharedPtr<MockDevice> mock = CreateNewUnique(MockDevice, MockDevice());
			auto sut = CreateSut(mock);

			sut.Execute(100);
			sut.Execute(90);

			Assert::IsTrue(mock->DidFeelAnything());
		}

		TEST_METHOD(DontFeelHealing)
		{
			sharedPtr<MockDevice> mock = CreateNewUnique(MockDevice, MockDevice());
			auto sut = CreateSut(mock);

			sut.Execute(100);
			sut.Execute(200);

			Assert::IsFalse(mock->DidFeelAnything());
		}

		TEST_METHOD(UpdateLastHealth)
		{
			sharedPtr<MockDevice> mock = CreateNewUnique(MockDevice, MockDevice());
			auto sut = CreateSut(mock);

			sut.Execute(90);
			sut.Execute(100);
			sut.Execute(95);

			Assert::IsTrue(mock->DidFeelAnything());
		}

		TEST_METHOD(DontFeel_NoDamage)
		{
			sharedPtr<MockDevice> mock = CreateNewUnique(MockDevice, MockDevice());
			auto sut = CreateSut(mock);

			sut.Execute(45);
			sut.Execute(45);

			Assert::IsFalse(mock->DidFeelAnything());
		}

		TEST_METHOD(FeelOn_RightMuscle)
		{
			sharedPtr<MockDevice> mock = CreateNewUnique(MockDevice, MockDevice());
			sharedPtr<MockBody> body = CreateNewUnique(MockBody, MockBody(MusclesGroup({Muscle::Abdominal_R()})));
			auto sut = CreateSut(mock, body);

			sut.Execute(100);
			sut.Execute(99);

			Assert::IsTrue(mock->DidFeelIn(Muscle::Abdominal_R().WithIntensity(50)));
		}

		TEST_METHOD(FeelAt_HigherIntensity_ThanLowest)
		{
			sharedPtr<MockDevice> mock = CreateNewUnique(MockDevice, MockDevice());
			sharedPtr<MockBody> body = CreateNewUnique(MockBody, MockBody(MusclesGroup({ Muscle::Abdominal_R() })));
			auto sut = CreateSut(mock, body);

			sut.Execute(100);
			sut.Execute(50);

			Assert::IsFalse(mock->IntensityOf(Muscle::Abdominal_R()) == 20);
		}

		TEST_METHOD(FeelBasedOn_DamageType)
		{
			sharedPtr<MockDevice> mock = CreateNewUnique(MockDevice, MockDevice());
			sharedPtr<MockBody> body = CreateNewUnique(MockBody, MockBody(MusclesGroup({ Muscle::Abdominal_R() })));
			auto sut = CreateSut(mock, body);
			body->damageSensation = SensationsFactory::Create(20);

			sut.Execute(100);
			sut.Execute(50);

			Assert::IsTrue(mock->DidFeelWithoutMuscles(SensationsFactory::Create(20)));
		}

		TEST_METHOD(Assign_CorrectPriority)
		{
			sharedPtr<MockDevice> mock = CreateNewUnique(MockDevice, MockDevice());
			sharedPtr<MockBody> body = CreateNewUnique(MockBody, MockBody(MusclesGroup({ Muscle::Abdominal_R() })));
			auto sut = CreateSut(mock, body);

			sut.Execute(100);
			sut.Execute(50);

			Assert::IsTrue(mock->WhatFelt->GetPriority() == FeelDamage::Priority);
		}
	};
}