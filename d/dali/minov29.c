//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov29.c

inherit ROOM;

void create()
{
	set("short", "杆栏中层");
	set("long", @LONG
这个杆栏的中层面积颇大，宽敞开阔。正中的香案古色古香，贡着的神像雕
制精细，显得与众不同，大盘的贡品正飘出香味，尤其当中的一个羊头特别抢眼。
看来这里是本村的祭祀所。
LONG);
	set("objects", ([
		__DIR__"npc/byjisi.c" : 1,
		]));
	set("exits", ([
		"down" : __DIR__"minov28",
		]));
	set("area", "阳宗镇");
	set("cost", 3);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
