//製作裝備類別實作

#include "EquipIDTable.h"
#include "Equipbase.h"
#include "Equips.h"
#include "Equipfactory.h"

Equipbase* Equipfactory::createEquip(int num)
{
	Equipbase* newEquip;
	switch(num)
	{
	case TANSOUHOU_120MM:
		newEquip = new Tansouhou120();
		break;
	case TANSOUHOU_127MM:
		newEquip = new Tansouhou127();
		break;
	case TANSOUHOU_140MM:
		newEquip = new Tansouhou140();
		break;
	case RENSOUHOU_356MM:
		newEquip = new Rensouhou356();
		break;
	case RENSOUHOU_410MM:
		newEquip = new Rensouhou410();
		break;
	case KOUKAKUHHOU_REN_100MM:
		newEquip = new Koukakuhhouren100();
		break;
	case KOUKAKUHHOU_REN_127MM:
		newEquip = new Koukakuhhouren127();
		break;
	case GYORAI_SANREN_610MM:
		newEquip = new Gyoraisanren610();
		break;
	case GYORAI_YONREN_610MM:
		newEquip = new Gyoraiyonren610();
		break;
	case PONSHIKIKAN:
		newEquip = new Ponshikikan();
		break;
	default:
		newEquip = new NoEquip();
		break;
	}
	return newEquip;
}