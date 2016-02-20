//Cracked by Roath
// Room: /d/xixia/dayuan.c

inherit ROOM;

void create()
{
	set("short", "一品堂大院");
	set("long", @LONG
这是一品堂的大院，不时有身着白衣的人一闪而过，却没有一点声
息，静的出奇。院中的有两棵参天大树，地上拖出长长的影子。偶尔几
声鸟叫，打破死沈沈的寂静。微风吹过，树叶舞动，发出“沙沙”的声
音。青石的地面看上去干干净净。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"ypgate",
  "north" : __DIR__"dating",
  "east" : __DIR__"jytang",
  "west" : __DIR__"zhangfang" ,
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
