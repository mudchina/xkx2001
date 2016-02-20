//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
	set_name(HIB"蓝花"NOR, ({"lan hua","hua","flower"}));
	set_weight(5);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
	set("unit", "棵");
      set("long", "这蓝花花朵色作深蓝，形状奇特，每朵花便象是一只鞋子。\n");
      set("value", 100);
	set("medicine", 1);
	set("no_get",1);
	}
	setup();
}

