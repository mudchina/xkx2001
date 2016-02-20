//Cracked by Roath
inherit ITEM;

string show_map();

void create()
{
    set_name("京城地图", ({"map"}));
    set_weight(300);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", (: show_map :));
	set("unit", "张");
	set("material", "paper");
	set("value", 300);
    }
}

string show_map()
{
    return read_file("/d/beijing/bj.map.txt");
}

