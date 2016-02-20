//Cracked by Roath
// Room: /d/dali/chhill.c

inherit ROOM;

void create()
{
	set("short", "茶花山");
	set("long", @LONG
你站在一座小山西面脚下，大理盛产茶花，好品种的茶花遍地生长，东面的
这片小山林也长满了好茶。西边不远就是大理城的北门了。
LONG);
	set("exits", ([
		"southwest" : __DIR__"northgate.c",
		"eastup" : __DIR__"chhill1.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
