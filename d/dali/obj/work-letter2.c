//Cracked by Roath
// work-letter2.c 大理晋级用公文
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL "奏折" NOR, ({"zou zhe", "letter"}));
	set_weight(100);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("unit", "份");
		set("long",HIB"一本善阐侯向皇上呈报事情的奏折。\n"NOR);
		set("no_get", "这样东西不能离开你。\n");
		set("material", "paper");
	}
}
