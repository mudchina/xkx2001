//Cracked by Roath
// Room: /city/chaguan.c
// xQin 6/00

inherit ROOM;

void create()
{
	set("short", "春来茶馆");
	set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌一字排
开，坐满了客人，或高声谈笑，或交头接耳。据说这里生意好不兴旺的原因不单
是因为这里的茶，还为喜欢对奕象棋的可以提供了一个可以切磋的好去处。若觉
不太清楚品茶之道，就看看(help tea)吧。
LONG 
	);
	
//	set("no_clean_up", 0);
//	set("no_fight", 1);
	set("day_shop", 1);
	set("exits", ([
		"south" : __DIR__"xidajie1",
		"north" : __DIR__"qiyuan2",
		"west" : __DIR__"qiyuan3",
		"east" : __DIR__"qiyuan4",
 
	]));
	set("objects", ([
		"/d/city/npc/wang_lifa" : 1
	]));
	setup();

}

