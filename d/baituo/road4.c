//Cracked by Roath
// 白驼改版
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
这是条偏僻的小径，蜿蜒地绕入白驼山，四周悄然无声。
LONG
	);
	set("exits", ([ 
	    "northwest" : __DIR__"road5",
	    "south" : __DIR__"road3",
	]));
	set("outdoors","baituo");
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
