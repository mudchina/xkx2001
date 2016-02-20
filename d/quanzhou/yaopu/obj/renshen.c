//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIW"人参"NOR, ({"renshen","shen"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "支");
                set("long","人参：大补品，吊命物。\n");
                set("value", 10000);
		set("yaocai", 1);
        	set("cure_s",100);
		set("cure_d",0);
		set("cure_n",0);
		
        }
        setup();
}
