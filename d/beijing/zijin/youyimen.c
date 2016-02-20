//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "右翼门");
	set("long",  @LONG
这是太和殿前广场的一个侧门，通向武英殿。这里的南面是贞度
门，西面有一条小道。
LONG
	);

	set("exits", ([
        "west" : __DIR__"gzxd1",
        "east" : __DIR__"guang1",
        "south" : __DIR__"zhendumen",
        "northwest" : __DIR__"hongyige",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
