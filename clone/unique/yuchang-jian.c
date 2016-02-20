//Cracked by Roath

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
        set_name(HIW"鱼肠剑"NOR,({ "yuchang jian", "yuchang", "sword", "jian" }) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 7000000);
                set("material", "steel");
		set("rigidity", 50);
                set("long", 
		"一柄尺半长短剑，剑身极薄，刃上宝光流动，变幻不定。\n");
                set("wield_msg", 
		HIW"$N握住鱼肠剑，提了起来，只见剑刃不住颤动，似乎只须轻轻一抖，便能折断。\n"NOR);
        }
	init_sword(80);
        setup();
	::create();
}

