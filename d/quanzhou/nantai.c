//Cracked by Roath
// Room: /u/qfy/quanzhou/nantai.c

inherit ROOM;

void create()
{
	set("short", "南台岩");
	set("long", @LONG
「苍崖千尺峭空虚」，这是清源山的最高处。一片高耸的巨石屹然矗立，
前面是悬崖峭壁，形势十分险峻。岩石上镌刻着「空中台阁」四大字。临台建
有「魁星阁」，因为山势高，这里常含云吐雾，漫为云海，从山下仰视，如在
空中。
LONG
	);

	set("outdoors", "quanzhou");

	set("exits", ([ /* sizeof() == 2 */
		"eastdown" : __DIR__"qingyuan",
		"westdown" : __DIR__"laojun",
	]));

	set("no_clean_up", 0);

	set("cost", 3);
	setup();
	replace_program(ROOM);
}
