//Cracked by Roath
inherit ITEM;


void create()
{
        set_name("铁锹", ({ "tie qiao", "qiao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一把普普通通的铁锹，看起来毫不起眼。\n"
);
                set("unit", "把");
		set("no_get", 1);
		set("no_drop", 1);


        }

}
