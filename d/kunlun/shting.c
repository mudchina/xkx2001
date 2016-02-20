//Cracked by Roath
// Room: /d/mingjiao/shting.c
// Zhangchi 3/00

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "光明圣火厅");
	set("long", @LONG
这是明教总舵的大厅--圣火厅。地上铺着深红的绒毯，正中为一青铜
巨鼎。但见鼎中烈火熊熊，不时发出啪啪的爆响。一盏车轮大的水晶灯高
悬鼎上，也不见有灯光，却把成个大厅照得如同白昼，可谓奇异非凡。望
前看去，白玉石阶上，一把斑斓虎皮大椅，面南背北，乃是教主的宝座。
虎皮椅后高悬条幅，上书几行经文(jingwen)。
LONG
);
	set("item_desc",([
		"jingwen"	: HIR"\t焚我残躯，熊熊圣火。生亦何欢，死亦何苦？\n"
				+"\t为善除恶，惟光明故，喜乐悲愁，皆归尘土。\n"
				+"\t怜我世人，忧患实多！怜我世人，忧患实多！\n"NOR,
	]));

	set("objects",([
		__DIR__"npc/yangxiao" : 1,
	]));

	set("exits", ([ /* sizeof() == 3 */
	  "out" : __DIR__"shmen",
	  "west" : __DIR__"ceting64",
	  "east" : __DIR__"ceting67",
	]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
