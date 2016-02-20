//Cracked by Roath
// xtring.c 铁指环

#include <armor.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit FINGER;

void create()
{
        set_name("铁指环", ({ "tie zhihuan", "ring" }) );
	set_color(HIW+BLK);
        set("weight", 400);
        if( clonep() )
		set_default_object(__FILE__);
        else
	{
		set("long", "这是峨嵋掌门的信物，创派祖师郭襄女侠所遗之玄铁指环，指环内刻着“留贻襄女”四个字。\n");
		set("unit", "个");
		set("value", 100000);
		set("rigidity", 10000);
		set("material", "alloy");
		set("armor_prop/armor", 1);
		set("no_get", 1);
		set("no_drop", 1);
	}
	setup();
}       
