//Cracked by Roath
// coin.c

#include <ansi.h>
inherit MONEY;

void create()
{
	set_name("铜钱", ({"coin", "coins", "coin_money" }));
        set_color("$YEL$");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("long", "这是流通中单位最小的货币，约要一百文铜钱才值得一两白银。\n");
		set("unit", "些");
		set("base_value", 1);
		set("base_unit", "文");

		set("base_weight", 1);
	}
	set_amount(1);
	setup();
}

int value() { return query_amount() * (int)query("base_value"); }

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
        int amt;

        if( sscanf(param, "%d", amt)==1 )
                set_amount(amt);
}

