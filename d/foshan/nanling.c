//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "南岭山口");
        set("long", @LONG
这里是南岭的一个山口。南面是岭南的大镇佛山，北面是湖南的
地界。岭南广东富庶繁盛，颇有豪侠之士。
LONG
        );
        set("exits", ([
		"northdown": __DIR__"road4",
		"southdown" : __DIR__"ngate",
	]));

	set("cost",3);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
