//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov60.c

inherit ROOM;

void create()
{
	set("short", "河边");
	set("long", @LONG
你来到河边，两侧山壁几乎是直上直下，西面是一条大河自北滚滚而来，在
此折向东奔腾而去，河水汹涌，巨浪滔天，发出一阵阵骇人的轰响。此处河谷稍
窄，前面有三根粗藤条绑在一棵大树上，另一端跨河而过，似可攀援而过。此去
向南乃是崇山峻岭。
LONG);
	set("objects", ([
		__DIR__"npc/wyshang" : 1,
		]));
	set("exits", ([
		"east" : __DIR__"minov61",
		"south" : __DIR__"minov59",
		]));
	set("area", "葛鲁城");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
