//Cracked by Roath
// cangjingge.c 藏经阁
// by Xiang
// 05/30/96 Marz
// xQin 11/00

inherit ROOM;
#include <ansi.h>

string* books = ({
	"laozi1",
	"daodejing-i",
	"laozi2",
	"daodejing-i",
	"laozi8",
	"daodejing-i",
	"laozi13",
	"laozi1",
	"laozi16",
	"daodejing-i",
	"laozi18"
});

void create()
{
	set("short", "藏经阁");
	set("long", @LONG
你走上了阁楼，抬头看见正前方中央挂这一块木匾（bian）。靠墙是一
排书架，摆满了道教的典籍。中央有一个长方形的大桌子，上面也堆满了书
。一个道童正在旁整理书籍。
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"xilang2",
	]));
	
	set("item_desc", ([
		"bian" : YEL"
		※※※※※※※※※※
		※                ※
		※   藏  经  阁   ※
		※                ※
		※※※※※※※※※※\n\n"NOR,
	]));

	set("objects", ([
		CLASS_D("wudang") + "/daotong" : 1,
		__DIR__"obj/"+books[random(sizeof(books))] : 1,
		__DIR__"obj/"+books[random(sizeof(books))] : 1
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}
