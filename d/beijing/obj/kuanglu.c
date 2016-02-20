//Cracked by Roath
// kuanglu.c 「匡庐图轴」

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_look", "look");
}

void create()
{
	set_name("「匡庐图轴」", ({"picture", "hua"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "幅");
		set("long", 
"这是后粱荆浩所画的庐山全景图，气势磅礴，为画中精品。\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	this_player()->add("neili", 200);
	message_vision("$N吃下一颗归元丹，只觉得四肢百骸真气充盈无比 !\n", this_player());
	destruct(this_object());
	return 1;
}


