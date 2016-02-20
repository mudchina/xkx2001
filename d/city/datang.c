//Cracked by Roath
// Room: /city/datang.c
// xQin 5/00

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIC"醉仙楼大堂"NOR);
	set("long", @LONG
这是便是新开的醉仙楼大堂，进来后让人不由自主的感觉眼前一亮。大堂内      
的布置带有三分贵气，显然是招待贵宾和喜庆之用。只见墙上挂着一幅对联(dui
lian)，笔致颇为潇洒但掩不住几分柔弱之气。往东是玫瑰厅，朝南的是牡丹厅，
向北是芙蓉厅。
LONG);
	set("exits", ([
		"east"   : __DIR__"meigui",
		"north"  : __DIR__"furong",
		"south"  : __DIR__"mudan",
		"west"   : __DIR__"zuixianlou2",
	]));
	set("item_desc", ([
	"duilian" : HIG"
       * * * * * * *
       * 春	东 *\n
       * 夏	南 *\n
       * 秋	西 *\n
       * 冬	北 *\n
       * 一	四 *\n
       * 岁	方 *\n
       * 川	宾 *\n
       * 流	至 *\n
       * 不	如 *\n
       * 息	归 *\n
       * * * * * * *
\n"NOR
	]) );
        set("no_fight","1");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

