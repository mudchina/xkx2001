//Cracked by Roath
// /d/changbai/renshen.c 人参

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("长白山人参", ({"renshen", "shen"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "株");
                set("long", "这是一株沾满山泥的长白山人参。\n");
                set("value", 10000000);
                set("medicine", 1);
        }
        setup();
}
