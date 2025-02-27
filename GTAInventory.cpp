#include "GTAInventory.h"
#include "script.h"

int GTAInventory::CurrentAmmo()
{
    int ammo;
    WEAPON::GET_AMMO_IN_CLIP(PLAYER::PLAYER_PED_ID(), CurrentWeapon(), &ammo);

    return ammo;
}

int GTAInventory::CurrentWeapon()
{
    return WEAPON::GET_SELECTED_PED_WEAPON(PLAYER::PLAYER_PED_ID());
}

bool GTAInventory::HoldingWeapon()
{
    return true;
    return WEAPON::IS_PED_WEAPON_READY_TO_SHOOT(PLAYER::PLAYER_PED_ID()); // Esto es tremendamente lento
}