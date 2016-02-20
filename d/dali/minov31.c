//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov31.c

inherit ROOM;

void create()
{
	set("short", "密林");
	set("long", @LONG
此处山道狭窄，林木特别茂密，山民踏出来的小道被纵横交错的林木遮挡阻
碍着，行路者不停地用刀劈砍开路，才能顺利前进。四面青山峭立，丛林中时常
有鸟兽惊走，偶尔还能看见美丽的孔雀飞过。
LONG);
	set("objects", ([
		"/d/foshan/npc/zsnake.c" : 1,
		]));
	set("exits", ([
		"northeast" : __DIR__"minov26",
		"southup" : __DIR__"minov32",
		]));
	set("area", "阳宗镇");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
