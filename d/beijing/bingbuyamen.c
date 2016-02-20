//Cracked by Roath
// Room: /d/beijing/bingbuyamen.c

inherit ROOM;

void create()
{
	set("short", "兵部衙门");
	set("long", @LONG
这里是当今朝廷的兵部衙门。左右两边是肃立的官兵，正前方
是一个很大的厅堂。兵部尚书高高地坐在上手太师椅上查阅通文， 
一群文秘跑来跑去，有时还抱着一些名册。墙上有一个告示(gaoshi).
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	"out" : __DIR__"guloudajie_w",
	]));

	set("objects", ([
	"/clone/npc/mizheng":1,
	// __DIR__"npc/bb_shilang":1,
	]));
	
  	set("item_desc", ([
	"gaoshi" : "米尚书亲临处理投军，升迁，退役等事宜。\n",
	]));

	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
