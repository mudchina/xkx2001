//Cracked by Roath
// Room: /d/dali/dalicheng8.c

inherit ROOM;

void create()
{
	set("short", "药铺");
	set("long", @LONG
这是一家神秘的药铺，座落在大和街和市中心的交界之处，普通的门面和招
牌，街坊们都说这家药铺的药灵验的很。从药柜上的几百个小抽屉里散发出来的
一股浓浓的药味，让你几欲窒息。据说这家店铺有一种很神密的药物。
LONG);
	set("objects", ([
		__DIR__"npc/hongyao" : 1,
		]));
	set("exits", ([
		"north" : __DIR__"dalicheng5",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
