//Cracked by Roath
// This is a room made by roommaker.

inherit ROOM;

void create()
{
    set("short", "顺贞门");
    set("long",@long
这是御花园北面的正门,在清朝,平时是关着的,皇帝,皇后,
妃嫔出入时,随时启闭。
    long
    );

	set("exits", ([
        "north" : __DIR__"shenwume",
        "south" : __DIR__"yuhuayua",
	]));
	setup();
	replace_program(ROOM);
}
