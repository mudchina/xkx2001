//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov75.c

inherit ROOM;

void create()
{
	set("short", "竹林深处");
	set("long", @LONG
这是一大片茂密的竹林，向南上山则是更茂密的阔叶林，鸟兽众多。有经验
的台夷猎人擅在竹林中下套、陷肼，捕捉兔、鹿等小兽，或结伙持利刃上深山捕
捉大些的猛兽。
LONG);
	set("objects", ([
		__DIR__"npc/tylieren" : 2,
		]));
	set("exits", ([
		"northeast" : __DIR__"minov74",
		]));
	set("area", "河西镇");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
