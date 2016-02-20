//Cracked by Roath
// huyao.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name( BLU "÷¼÷Ã¹Ú" NOR, ({ "kulou guan", "guan" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¶¥");
                set("long", "ÕâÊÇÒ»¶¥÷¼÷Ã×öµÄ±¦¹Ú¡£\n");
		set("value", 500);
		set("no_sell",1);
		set("material", "head");
		set("armor_prop/armor", 10);
	}
	setup();
}
