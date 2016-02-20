//Cracked by Roath
// 白驼改版
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
一条白砖砌墙的长廊，南边的拱门通往大厅，西北边是少主的卧
房，门前垂着绣花软帘，楹柱雕饰华丽，里面不时传出少女的娇笑声。
LONG
	);
	set("exits", ([ 
	    "northwest" : __DIR__"bedroom1",
	    "south" : __DIR__"dating",
	]));
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
