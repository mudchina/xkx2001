//Cracked by Roath
// Room: /city/lichunyuan.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"冬梅苑"NOR);
	set("long", @LONG
这是一间地方颇为宽大的厢房，屋内布置得古意盎然，一只古几，几上一
琴，旁有一只青铜古鼎，屡屡香烟从鼎中袅袅而上，地上铺以竹席，椅凳之属
均付阙如，令人顿发思古之幽情。四壁只点缀数枝腊梅，隐现幽香。
LONG
	);

/*
	set("objects", ([
	]));

	set("item_desc", ([
		"tu" :
	"\n"
	]));
*/
	set("exits", ([
		"south" : __DIR__"lichun2",
	]));

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}
 

