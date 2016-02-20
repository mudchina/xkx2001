//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "熙和门");
	set("long",  @LONG
这扇门平时都紧紧关闭着，只有在早中晚三刻才打开，供卫士们
换班使用。
LONG
	);

	set("exits", ([
		"west" : __DIR__"wuyingmen",
        "east" : __DIR__"guang2",
	]));
	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
