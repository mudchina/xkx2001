//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "协和门");
	set("long",  @LONG
这扇门平时都紧紧关闭着，只有在早中晚三刻才打开，供卫士们
换班使用。
LONG
	);

	set("exits", ([
		"east" : __DIR__"wenhuamen",
        "west" : __DIR__"guang2",
	]));
	set("outdoors","beijing");

	setup();
	replace_program(ROOM);
}
