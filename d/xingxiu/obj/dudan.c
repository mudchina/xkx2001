//Cracked by Roath
// wsky 4/7/00

#include <ansi.h>
#include <weapon.h>

inherit ITEM;

void create()
{
        set_name("¶¾µ¤", ({ "du dan", "dan"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¿é");
                set("long", HIR"Ò»¿éÐÈºìÈçÑªµÄµ¤Íè¡£\n"NOR);
                set("material", "stone");
        }
        setup();
}

