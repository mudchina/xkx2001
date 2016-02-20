//Cracked by Roath
// amulet.c 长命锁
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name("长命锁", ({ "amulet" }));
        set_color("$YEL$");
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一串颇为精致的长命锁，不过已相当破旧，"+
			    "上面依稀刻了“长命百岁”几个字，下面似乎有一个小小的“曲”字。\n");
		set("unit", "串");
		set("value", 1500);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
