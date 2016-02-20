//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov64.c

inherit ROOM;

void create()
{
	set("short", "喜州城");
	set("long", @LONG
喜州又名大鳖城，是大理南部大城，自唐代已极为繁荣，邑居人户尤众，商
贸甚繁荣，有大量他国客商来此交易，采购大理产的金银、丝织品、象牙、皮毛
等，其中又以来自印度的客商最多，前来贩丝绸往波斯甚至更远的西方。
LONG);
	set("objects", ([
		__DIR__"npc/indiman" : 1,
		]));
	set("exits", ([
		"southwest" : __DIR__"minov65",
		"north" : __DIR__"minov63",
		"south" : __DIR__"minov71",
		"east" : __DIR__"dlkd1",
		]));
	set("area", "喜州城");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
