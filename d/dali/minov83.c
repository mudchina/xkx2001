//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov83.c

inherit ROOM;

void create()
{
	set("short", "榕树雨林");
	set("long", @LONG
这是一片湿润的雨林，脚下水汪汪的无路可行，十数丈高的巨大榕树盘根错
节，树干粗得几个人合抱也围不住。榕树的树枝下垂到泥水中反过来扎根，成为
特意的景致。雨林虽然少有走兽，却是飞禽聚居的乐土，身手零活的台夷猎人攀
越在大榕树浮露的根枝上，用短弩射猎飞鸟。
LONG);
	set("objects", ([
		__DIR__"npc/tylieren" : 1,
		]));
	set("exits", ([
		"west" : __DIR__"minov78",
		]));
	set("area", "鲁望镇");
	set("cost", 5);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
