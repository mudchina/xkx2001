//Cracked by Roath
// Room: /d/dali/dalicheng2.c

inherit ROOM;

void create()
{
	set("short", "太和街口");
	set("long", @LONG
由这条街再向北走就便可达皇宫大门了，是大理城内的主要街道。通街全用
天然的大块青石铺成。街上行人络绎不绝。大道两边遍植松柏，满目苍翠。
LONG);
	set("exits", ([
		"south" : __DIR__"dalicheng9",
		"north" : __DIR__"dalicheng1",
		"east" : __DIR__"dalicheng5",
		"west" : __DIR__"dalicheng3",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
