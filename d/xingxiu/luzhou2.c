//Cracked by Roath
// luzhou.c
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "绿洲");
	set("long", @LONG
这里青草较北边为多，是沙漠中的一处山麓绿洲，祗听得淙淙
水声，一条小溪水清见底，溪水中无数小块碎冰互相撞击，发出清
脆声音，叮叮咚咚，宛如仙乐。冰块闪耀之中，忽见夹杂有花瓣飘
流，溪水芳香，当是上游有花之故。
LONG
	);

	set("exits", ([
		"west" : __DIR__"xiaoxi",
		"north" : __DIR__"shaqiu",
	]));
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

