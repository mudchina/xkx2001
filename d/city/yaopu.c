//Cracked by Roath
// Room: /city/yaopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "药铺");
	set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个小抽
屉里散发出来的。神医平一指坐在茶几旁，独自喝着茶，看也不看你一眼。一名
小伙计站在柜台后招呼着顾客。柜台上贴着一张发黄的广告(guanggao)。
LONG
	);
	set("item_desc", ([
		"guanggao" : "本店出售以下药品：
金创药：\t五十两白银
蛇　药：\t二十两白银
养精丹：\t壹两白银
其他神药与老板面议。\n",
	]));

//	set("item_desc", ([
//		"guanggao" : "本店老板平一指外出采药未归，今日暂停营业。\n",
//	]));

	set("objects", ([
		__DIR__"npc/ping" : 1,
		__DIR__"npc/huoji" : 1,
	]));

	set("exits", ([
		"south" : __DIR__"dongdajie2",
	]));

	set("cost", 0);
	set("day_shop", 1);
	setup();
	replace_program(ROOM);
}

