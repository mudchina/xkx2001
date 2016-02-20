//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"红包"NOR, ({ "red pocket", "hong bao", "bao", "li shi"}) );
	set_weight(30);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
                set("long", "这是一只红色的利是封，上面喜气洋洋地写着「恭喜发财」几个金字。\n");
		set("value", 88);
		set("material", "paper");
	}
	setup();
}

int is_container() { return 1; }

int reject(object ob) 
{ 
        if (ob && (ob->query("money_id")=="ten-cash" ||
		ob->query("money_id")=="hundred-cash" )) return 0;

        notify_fail("利是封里只能装银票。\n");
        return 1;
}

