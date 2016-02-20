//Cracked by Roath
// dahulu.c 

inherit F_UNIQUE;
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("大葫芦", ({"da hulu", "hulu", "hu", "bottle"}));
	set_color("$HIR$");
	set_weight(800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个朱红漆的大葫芦，自唐末传到今日，已有好几百年，\n世世代代由丐帮的帮主执掌，就好像皇帝的玉玺、做官的金印一般。\n");
		set("unit", "个");
		set("value", 350);
		set("max_liquid", 90);
	}

	// because a container can contain different liquid
	// we set it to contain water at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "米酒",
		"remaining": 90,
		"drunk_apply": 3,
	]));
	setup();
	::create();

}
