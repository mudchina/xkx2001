//Cracked by Roath
// huyao.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name( "皮腰带", ({ "yao dai", "yaodai" }) );
	set_weight(300);
	set_max_encumbrance(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
                set("long", "这是一件皮质的宽腰带，夹层透空，可以放各种软兵刃。\n");
		set("value", 20);
		set("material", "waist");
		set("armor_prop/armor", 5);
	}
	setup();
}

int is_container() { return 1; }

int reject(object ob) 
{ 
	if (ob && ob->query("weapon_prop") ) return 0;
	if (sizeof(all_inventory(this_object()))==0) return 0;
	notify_fail("皮腰带再放不下任何东西了。\n");
	return 1;
}
