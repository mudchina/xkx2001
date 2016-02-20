//Cracked by Roath
// Room: /d/beijing/west/baiqianyuan.c

inherit ROOM;

void create()
{
	set("short", "前院");
	set("long", @LONG
这是白家大宅的前院，地方虽然不大，但打扫得十分
整洁，院子中间种着几棵歪脖子杨树，大概已经长了百多
年了。院子两边是厢房。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"lingtang",
	"south" : __DIR__"baidamen",
	"east" : __DIR__"baidongxiang",
	"west" : __DIR__"baixixiang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
