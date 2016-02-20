//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov63.c

inherit ROOM;

void create()
{
	set("short", "天威径");
	set("long", @LONG
此处据说是三国时蜀汉诸葛孔明第七次擒孟获之处，孟获曰：“公，天威也，
吾既降，南人不复反也。”，故此得名。这是一条贯通南北的大路，南去十里是
喜州城，北上约三十里可达大理城。
LONG);
	set("exits", ([
		"north" : __DIR__"minov62",
		"south" : __DIR__"minov64",
		]));
	set("area", "喜州城");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
