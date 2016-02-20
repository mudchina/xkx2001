//Cracked by Roath
//iron.c

inherit ITEM;
void create()
{
        set_name("铁石", ({"iron stone", "tie shi", "stone", "iron"}));
        set_weight(random(300000));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("value", 0);
		set("material", "iron");
        }
	if (random(10) > 8){
                set("long", "一块泛着一层紫光的黑铁。\n");
                set("for_blade", 1);
                }
	setup();
}
