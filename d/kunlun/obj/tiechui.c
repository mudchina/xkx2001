//Cracked by Roath
inherit ITEM;


void create()
{
        set_name("铁锤", ({ "tie chui", "chui" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一把大铁锤，是用来打铁的工具。\n"
);
                set("unit", "把");
		set("no_get", 1);
		set("no_drop", 1);


        }

}
