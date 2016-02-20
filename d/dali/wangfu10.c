//Cracked by Roath
// Room: /d/dali/wangfu10.c

inherit ROOM;

void create()
{
	set("short", "大山石");
	set("long", @LONG
忽迎面突出插天的大玲珑山石来，四面群绕各式石块，竟把里面所有房屋悉
皆遮住。且一株花木也无，只见许多异草：或有牵藤的，或有引蔓的，或垂山巅，
或穿石隙，甚至垂绕柱，萦砌盘阶，或如翠带飘飘，或如金绳蟠屈，或实如丹砂，
或花如金桂。味芬气馥，非花香之可比。
LONG);
	set("exits", ([
		"southeast" : __DIR__"wangfuroad2",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
