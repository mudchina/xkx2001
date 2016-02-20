//Cracked by Roath
// Room: /city/dongdajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
你走在东大街上，踩着坚实的青石板地面。东边是直通钱庄，嘈杂中隐隐约
约可以听到钱币的撞击声。北边是有着百年老店之称的药铺，那里的良药是平一
指药师亲自调配的，有着药到病除的神奇疗效，所以到这家药铺买药的人特别多。
南面一家打铁铺，门脸儿挂着一牌子(paizi)。西边的朗朗读书声和南边打铁铺叮
叮当当的声音相互呼应，感觉很有节奏。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"dongdajie3",
		"south" : __DIR__"datiepu",
		"west" : __DIR__"dongdajie1",
		"north" : __DIR__"yaopu",
	]));
	set("item_desc", ([
                "paizi" : "收购破铜烂铁。\n",
        ]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

