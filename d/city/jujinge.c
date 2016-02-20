//Cracked by Roath
// Room: /city/jujinge1.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
	set("short", "聚金阁");
	set("long", @LONG
你一来到这里只觉得到处都是亮光闪闪，宽敞的大厅里南边摆放着一些拿来
展示的珠宝首饰。北边的柜台(guitai)上则放着要卖的金银珠宝。但是这里看起
来特别冷清，那边的伙计看见你来也无动于衷。出去便是南大街了。
LONG
	);

	set("exits", ([
		"east" : __DIR__"nandajie2",
	]));

	set("item_desc", ([
                "guitai" : "白金戒指            十两黄金\n"
			   "天山雪珍珠          二两金子\n"
			   "凤头金手镯          一两金子\n"
                           "金带玉丝头冠        二两金子\n"
                           "玉石戒指          五十两白银\n"
			   "普通戒指          十五两白银\n"
                           "银宝钗              五两白银\n"
                           "翡翠项链        八十五两白银\n"
                           "凤尾鸳鸯钗      四十五两白银\n",  
	]));

	set("objects", ([
		__DIR__"npc/niu" : 1,
		__DIR__"npc/jjhuoji" : 1,
	]));

	set("cost", 0);
	set("day_shop", 1);
	setup();
	replace_program(ROOM);
}
