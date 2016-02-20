//Cracked by Roath
// 白玉峰
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "殿堂");
	set("long", @LONG
大殿後是一座较小的殿堂，殿中情景却比大殿上尤为可怖，
数十具骸骨一堆堆相互纠结，骸骨大都直立如生时，有的手中握
有兵刃，有的却是空手。
LONG
	);

	set("exits", ([
		"south" : __DIR__"jadehall",
		"north" : __DIR__"jaderoad6",

	]));

	set("cost", 1);
	setup();
}
