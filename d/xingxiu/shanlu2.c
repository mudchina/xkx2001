//Cracked by Roath
// shanlu1.c
// maco
inherit ROOM;

void create()
{
    int i;
	set("short", "山路");
	set("long", @LONG
此处地势群山围绕，中间一座白玉高峰参天而起。只见玉峰
隐隐泛彩，奇丽无伦。
LONG
	);

	set("exits", ([
		"east" : __DIR__"caoyuan5",
		"west" : __DIR__"chalu1",
	]));
	set("outdoors","xingxiu");
	set("cost", 3);
	setup();
	replace_program(ROOM);
}
