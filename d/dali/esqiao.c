//Cracked by Roath
// Room: /d/dali/esqiao.c

inherit ROOM;

void create()
{
	set("short", "洱水桥");
	set("long", @LONG
一座长百余步的青石桥。此桥横跨洱水，连接下关城和大理城，桥下清澈的
洱水滚滚东去。桥北正是下关城的城门，桥南一路南行十数里即可到大理城。
LONG);
	set("exits", ([
		"southeast" : __DIR__"gaten1",
		"north" : __DIR__"xiaguan",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
