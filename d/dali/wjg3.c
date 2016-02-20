//Cracked by Roath
// acep , mantian , mantian

inherit ROOM;

void create()
{
	set("short", "客厅");
	set("long", @LONG
万劫谷的正房，这是一间大客厅，宽敞明亮，青石铺的地，两边靠墙摆着的
刀枪架，十八般兵器样样俱全。正中一张八仙桌，上有清茶一盏。旁边是谷主坐
的太师椅。
LONG);
	set("objects", ([
		__DIR__"npc/zhongwanchou": 1,
		]));
	set("exits", ([
		"south" : __DIR__"wjg2.c",
		"east"  : __DIR__"wjg5.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
