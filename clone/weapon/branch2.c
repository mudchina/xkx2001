//Cracked by Roath
// branch2.c
// Jay 7/4/96

#include <ansi.h>
#include <weapon.h>
inherit CLUB;

void create()
{
    set_name(YEL"����֦"NOR, ({"shuzhi", "zhi", "branch"}));
    set_weight(500+random(500)); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "����һ������֦��\n");
	set("unit","��");
	set("wield_msg","$N�γ�һ������֦�������С�\n");
	set("material", "wood");
    }
    init_club(random(2));

    setup();
}