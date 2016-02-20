//Cracked by Roath
// Jay 8/9/96

inherit ITEM;

void create()
{
        set_name("铁床", ({"tie chuang","chuang","bed"}));
	set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","一张硬梆梆的铁床。\n");
                set("unit", "张");
                set("material", "steal");
        } 
	setup();
}

