//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("硝磺石", ({ "xiaohuang shi", "shi" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一块硝磺石，是制作火枪和火药的必须品。\n");
                set("unit", "块");
//				set("no_drop",1);

        }

}
