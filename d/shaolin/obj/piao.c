//Cracked by Roath
//水瓢
//xiaojian May 25,2000

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("水瓢", ({"shui piao", "piao"}));
	set_weight(100);
	if(clonep())
		set_default_object(__FILE__);

	else {
		set("long", "这是一个舀水用的水瓢。\n");
		set("unit", "个");
		set("material", "wood");
		set("value", 0);
	}
}
init()
{
        object me = this_player();
         if (!wizardp(me)) {
                set("no_give",  "这个东西不能随便给人。\n");
                set("no_steal", "这个东西你偷不到。\n");
                }
}
	