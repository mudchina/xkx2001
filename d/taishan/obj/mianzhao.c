//Cracked by Roath
// mianzhao.c 面罩
// modified by cleansword 1996/6/14

#include <armor.h>

inherit HEAD;

void create()
{
        set_name("面罩", ({ "mian zhao", "mask" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
		set("long", "这是个黑布头套，能把整个脑袋套起来，只露出两个眼睛。\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
		set("no_drop", "这样东西不能离开你。\n");
        }
        setup();
}

void init()
{
	add_action("do_wear", "wear");
	add_action("do_remove", "remove");
}

int do_wear(string arg)
{
	if (!arg || (arg != "mian zhao" && arg != "mask") ) return 0;

	this_player()->set_temp("apply/name",  ({"蒙面人"}));
	this_player()->set_temp("apply/short", ({"蒙面人(Mengmian ren)"}));
	this_player()->set_temp("apply/long",  ({"一个黑布蒙面，神秘兮兮的家伙。\n"}));

	return 0;
}

int do_remove(string arg)
{
	if (!arg || (arg != "mian zhao" && arg != "mask") ) return 0;

	this_player()->delete_temp("apply/name");
	this_player()->delete_temp("apply/short");
	this_player()->delete_temp("apply/long");

	return 0;
}
