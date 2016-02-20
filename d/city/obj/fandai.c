//Cracked by Roath
// mabudai.c 麻布袋

inherit ITEM;

void create()
{
	set_name("食盒", ({ "shi he", "he", "box" }));
	set_weight(500);
	set_max_encumbrance(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一只用细竹编织成的食盒。\n");
		set("value", 50);
	}
}

int is_container() { return 1; }

int reject(object ob)
{
        if (ob && ob->query("food_supply") ) return 0;
        notify_fail("你只能把食物放进食盒。\n");
        return 1;
}
