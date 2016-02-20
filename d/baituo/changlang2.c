//Cracked by Roath
// 白驼改版
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
一条白砖砌墙的长廊，四下寂静无声，气氛有些可怕。西边尽头是
一道黑沉沉的铁门，後面是庄主所居的灵蛇阁。
LONG
	);
	set("exits", ([ 
	    "east" : __DIR__"changlang1",
	    "west" : __DIR__"lingshege",
	]));
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
