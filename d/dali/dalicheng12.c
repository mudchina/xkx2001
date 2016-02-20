//Cracked by Roath
// Room: /d/dali/dalicheng12.c

inherit ROOM;

void create()
{
	set("short", "十字路口");
	set("long", @LONG
这是大理城内的主要商贸场所。形形色色的叫卖声在耳边此起彼伏，连绵不
绝。路上车水马龙，各色行人摩肩接踵，热闹非凡。大道两旁高立了两座楼牌，
西首是御林军的驻地，东面则是民居。
LONG);
	set("exits", ([
		"north" : __DIR__"dalicheng9",
		"south" : __DIR__"southgate",
		"west" : __DIR__"dalicheng13",
		"east" : __DIR__"dalicheng16",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}








