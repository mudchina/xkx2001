//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov84.c

inherit ROOM;

void create()
{
	set("short", "苍山中部");
	set("long", @LONG
你行走在苍山中部山颠，此间地形极为险恶，两边山高入云，中间一条崎岖
不平的山路。路西不远一条大河自北略偏西方向南流过，隆隆水声遥遥可闻，正
是南诏名川--泸水。此路是自西川和土番入大理的必经之途，时有客商过往。由
此向南穿越苍山可抵下关城，北面不远则是出苍山的山口。
LONG);
	set("exits", ([
		"northdown" : __DIR__"minov86",
		"southwest" : __DIR__"minov85",
		"southeast" : __DIR__"xiaguan",
		]));
	set("area", "剑川镇");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
