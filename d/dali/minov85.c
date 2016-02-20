//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov85.c

inherit ROOM;

void create()
{
	set("short", "苍山山路");
	set("long", @LONG
此处正当河边，两侧山壁几乎是直上直下，面前是一条大河自北滔滔而来，
在此折向东咆哮而去，河水奔腾汹涌，拍击河岸，发出一阵阵骇人的轰响。这里
恰缝河湾，河床较窄，河谷上并无桥梁，只有三根粗藤条横跨两岸，这端绑在一
棵大树上，似可攀援而过。
LONG);
	set("objects", ([
		__DIR__"npc/wylieren.c" : 1,
		]));
	set("exits", ([
		"northeast" : __DIR__"minov84",
		"west" : __DIR__"minov61",
		]));
	set("area", "剑川镇");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
