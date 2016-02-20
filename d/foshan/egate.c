//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "佛山东门");
        set("long", @LONG
这里是佛山镇的东门。再往东走就要离开佛山，去往福建了。西
面一条东西向的大街是佛山镇的主要街道。
LONG
        );
        set("exits", ([
		"west" : __DIR__"street4",
		"east" : __DIR__"qzroad1",
	]));

	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
