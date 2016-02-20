//Cracked by Roath
// Room: /d/dali/dalicheng5.c

inherit ROOM;

void create()
{
	set("short", "太和东街");
	set("long", @LONG
太和街连贯阳苜咩城南北门，延伸三里，是城内主要街道。街面是由碗口大
的彩色石块铺成，青兰紫绿，煞是好看。城内居民族裔繁杂，习俗各异，饮食穿
着无不异于中原。北面是薛氏成衣铺，南面是药铺。
LONG);
	set("exits", ([
		"north" : __DIR__"dalicheng6",
		"south" : __DIR__"dalicheng8",
		"west" : __DIR__"dalicheng2",
		"east" : __DIR__"dalicheng7",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
