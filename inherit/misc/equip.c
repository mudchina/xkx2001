//Cracked by Roath
// equip.c
// modified by xuy on 5/18/97 to add weapon attack speed prop.

inherit ITEM;
inherit F_EQUIP;

void setup()
{
	if( !query("armor_prop/dodge") && (weight() >= 3000) )
		set("armor_prop/dodge", - weight() / 3000 );
	if( !query("weapon_prop/dodge") && (weight() >= 3000) )
		set("weapon_prop/dodge", - weight() / 3000 );
	if( !query("weapon_prop/speed") && (weight() >= 3000) )
		set("weapon_prop/speed", - weight() / 3000 );
}
