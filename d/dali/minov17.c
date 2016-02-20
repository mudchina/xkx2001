//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov17.c

inherit ROOM;

void create()
{
	set("short", "罗伽甸");
	set("long", @LONG
这里是滇池的东南，是么些蛮的罗伽部落聚居的地方。么些蛮族属摆夷。摆
夷喜居平原沿水，（沿水的平原坝子，即为“甸”）。这里土壤肥沃，灌溉便易。
罗伽是一个大部落，罗伽甸是个相当大的镇子，大理国在这里设有治府。
LONG);
	set("exits", ([
		"northwest" : __DIR__"minov16",
		"southwest" : __DIR__"minov18",
		"east" : __DIR__"minov20",
		]));
	set("area", "罗伽甸");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
