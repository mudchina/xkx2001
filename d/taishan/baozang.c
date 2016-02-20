//Cracked by Roath
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "宝藏岭");
	set("long", @LONG
这里是泰山的一个名胜。岭上有一座状似狮子的巨石，称为狮
子崖。最出名的还是要数在东北面的东岳庙，也称上岳庙，是古代
封禅的地方，那里有一块唐玄宗的纪泰山铭。
LONG
	);

	set("exits", ([
		"westup" : __DIR__"weipin",
	]));

	set("objects",([
		__DIR__"npc/xiang-ke" : 1,
	]));

 	set("outdoors", "taishan");
	set("cost", 4);
	setup();
	replace_program(ROOM);
}

