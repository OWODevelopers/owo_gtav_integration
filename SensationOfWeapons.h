#pragma once
#include <vector>
#include "../OWOAPI/Domain/Sensation.h"
#include "../OWOAPI/Domain/SensationsParser.h"

class SensationOfWeapons
{
public:
	std::vector<unsigned long> weapons = { };
	std::string toBeFelt;

	SensationOfWeapons(std::vector<unsigned long> weapons, std::string sensation) : weapons(weapons), toBeFelt(sensation) {}

	bool ContainsWeapon(int which);
	uniquePtr<OWOGame::Sensation> ToBeFelt();

	// Impacts
	static SensationOfWeapons Melee()
	{
		return SensationOfWeapons({
			2725352035,
		4194021054,
		148160082,
		2578778090,
		1737195953,
		1317494643,
		2508868239,
		1141786504,
		2227010557,
		3854032506,
		3146768957,
		743550225,
		3030980043,
		4198358245,
		861723357,
		1205296881,
		1161062353,
		4106648222,
		955837630,
		2793925639,
		3799318422,
		94548753,
		4192643659,
		1703483498,
		2460120199,
		4191993645,
		3494679629,
		3794977420,
		3638508604,
		3713923289,
		2343591895,
		3756226112,
		2484171525,
		3441901897,
		419712736,
		940833800 }, "0");
	}
	static SensationOfWeapons Bullet()
	{
		return SensationOfWeapons({ 453432689,
	1593441988,
	584646201,
	2578377531,
	324215364,
	736523883,
	4024951519,
	3220176749,
	2210333304,
	2937143193,
	2634544996,
	2144741730,
	487013001,
	2017895192,
	3800352039,
	2640438543,
	100416529,
	205991906,
	1119849093,
	4256881901,
	1259576109,
	1186503822,
	3218215474,
	2132975508,
	3523564046,
	3231910285,
	2228681469,
	1785463520,
	1432025498,
	2285322324,
	2526821735,
	889061222,
	465894841,
	2548703416,
	3415619887,
	2939590305,
	1198256469,
	3056410471,
	1627465347,
	137902532,
	2828843422,
	984333226,
	3342088282,
	727643628,
	94989220,
	1470379660,
	2636060646,
	1198879012,
	1155224728,
	2144528907,
	2441047180,
	2756787765,
	3696079510,
	171789620,
	4019527611,
	1649403952,
	3675956304,
	729375873,
	3249783761,
	3041872152,
	50118905,
	3959029566,
	3173288789,
	317205821,
	3686625920,
	961495388,
	2024373456,
	4208062921,
	177293209,
	3219281620,
	3520460075,
	3684886537,
	1853742572,
	3347935668,
	350597077,
	485882440,
	1924557585 }, "1");
	}
	static SensationOfWeapons Explosive()
	{
		return SensationOfWeapons({ 856002082,
	2726580491,
	2982836145,
	375527679,
	324506233,
	1752584910,
	2481070269,
	741814745,
	1945616459,
	4171469727,
	3473446624,
	2669318622,
	3800181289,
	3204302209,
	539292904,
	1834887169,
	1686798800,
	4272043364,
	1672152130,
	2874559379,
	2138347493,
	1834241177,
	1638077257,
	1097917585,
	84788907,
	125959754,
	3125143736,
	3676729658 }, "2");
	}

	// Recoils
	static SensationOfWeapons Pistol() {
		return SensationOfWeapons({ 
			453432689,
			1593441988,
			584646201,
			2578377531,
			3218215474,
			3523564046,
			2285322324,
			465894841,
			2939590305,
			137902532,
			727643628,
			1470379660,
			3696079510,
			3675956304,
			3219281620,
			350597077
		}, "8");
	}

	static SensationOfWeapons SMG() {
		return SensationOfWeapons({	
			324215364,
			736523883,
			4024951519,
			3173288789,
			2024373456 
		}, "9");
	}

	static SensationOfWeapons Shotgun() {
		return SensationOfWeapons({ 
			487013001,
			2017895192,
			3800352039,
			2640438543,
			1432025498,
			984333226,
			94989220,
			4019527611,
			317205821
		}, "10");
	}

	static SensationOfWeapons Heavy() {
		return SensationOfWeapons({ 
			2726580491,
			1672152130,
			125959754,
			3676729658,
			2982836145,
			100416529,
			205991906,
			177293209,
			856002082,
			3347935668,
			1686798800,
			4272043364,
			2548703416,
			2828843422
		}, "11");
	}

	static SensationOfWeapons MiniGun() {
		return SensationOfWeapons({ 1119849093 }, "9");
	}
};