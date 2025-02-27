#pragma once
#include "BakedSensation.h"
#include "String.h"
#include "SensationsParser.h"
#include "SensationsFactory.h"

namespace OWOGame
{
    class BakedSensationsParser {
    public:
        static bool CanParse(owoString value);
        static uniquePtr<OWOGame::BakedSensation> Parse(owoString value);
    };
}