//Cracked by Roath
// Room: /d/xixia/yamen.c

inherit ROOM;

void create()
{
	set("short", "衙门");
	set("long", @LONG
这是灵州府衙所在地，黑色大门平时紧紧闭着，门前四个身着皂服的
衙役没精打采的拄着水火棍站着。边上有个大鼓。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dongdajie",
]));
	set("objects", ([
		"/d/xixia/npc/yayi" : 4,
	]));
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
