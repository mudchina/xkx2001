//Cracked by Roath
// ten.c

#include <ansi.h>
inherit MONEY;

void create()
{
	set_name("十两银票", ({"cash", "ten-cash", "ten-cash_money"}));
        set_color("$HIG$");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "ten-cash");
		set("long", "一张面额值十两银子的银票。\n");
		set("unit", "叠");
		set("base_value", 1000);
		set("base_unit", "张");
		set("base_weight", 3);
	}
	set_amount(1);
}

