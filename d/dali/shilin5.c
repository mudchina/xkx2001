//Cracked by Roath
// Room: /d/dali/shilin5.c

inherit ROOM;

void create()
{
	set("short", "长湖");
	set("long", @LONG
长湖，周长约十余里，湖面呈狭长形，故名。在密密的丛林中。它宛如一弯
新月，在蓝天中辉耀。湖周松柏成林，苍翠欲滴，芳草萋萋，色鲜叶嫩，间有山
花，点缀其间。湖水碧绿，似一幅在微风中抖动的锦缎，绿的晶莹，绿的活跃，
绿的醉人。
LONG);
	set("exits", ([
		"northeast" : __DIR__"shilin3",
		"southdown" : __DIR__"shilin1",
		"west" : __DIR__"shilin2",
		"enter" : __DIR__"shilin4",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
