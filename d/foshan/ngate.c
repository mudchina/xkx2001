//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "佛山北门");
        set("long", @LONG
这里是佛山镇的北门。出北门向北，翻过南岭可达中原。南
面一条东西向的大街是佛山镇的主要街道。
LONG
        );
        set("exits", ([
		"northup" : __DIR__"nanling",
		"south" : __DIR__"street2",
	]));

	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
