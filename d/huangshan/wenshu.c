//Cracked by Roath
// 文殊院
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "文殊院");
    set("long", @LONG
文殊院背靠玉屏峰，东南竖天都，西北插莲花，两山秀色似乎举手
可采。传说有个名叫普门的五台和尚，梦见一个云雾缥缈的仙境。因此
他四处漫游，寻山访水，一日他来到黄山，终於发现玉屏峰就是他梦中
的仙境，便在此兴土木建廊宇，起名“梦象台”，後人改称“文殊院”。
南边巨石下又有一洞，看来又要钻(zuan)了。巨石之上有一株千年古松。
这株体态雍容端庄的古松便是“迎客松”。从这里可眺望莲花峰(peak)。
右两边各有一大石，西边是
一条八百级下到莲花沟的山路。
LONG);

   set("item_desc", 
        ([
      	   "peak" : 
		"它肖似一朵初绽的夏莲。尤其在清晨，东方一抹朝晖首先染红莲花峰\n"
		"顶，片片莲瓣鲜红水灵，好象花瓣上的晶莹露珠也清晰可见。莲花旁\n"
		"边，一峰亭亭而立，顶端如莲苞而未放，那就是莲蕊峰。轻云飘荡，\n"
		"如水漾波，莲花莲蕊在池水中随风摇曳。\n"		
   	])
      );
    set("exits", ([ /* sizeof() == 3 */
	"left" : __DIR__"shishi",
	"right" : __DIR__"yuntai",
	"westdown" : __DIR__"niubi",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
void init()
{
   add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{
   if ( arg )
      return notify_fail( "什么？\n");
   me->move(__DIR__"jushi");
}
