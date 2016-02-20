//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov56.c

inherit ROOM;

void create()
{
	set("short", "祭祀大屋");
	set("long", @LONG
这是乌撒部的祭祀大屋，颇为宽敞。屋子正中一张竹台，台上摆放着一排竹
制牌位，上书乌蛮族祖先之名。牌位后的墙上挂有大幅兽皮，上绘龙形花纹，似
是该族的图腾。一位老祭司常年守在祭台前，负责全族的祭司活动。
LONG);
	set("objects", ([
		__DIR__"npc/wyjisi" : 1,
		]));
	set("exits", ([
		"out" : __DIR__"minov55",
		]));
	set("area", "葛鲁城");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
