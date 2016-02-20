//Cracked by Roath
// 龙井
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "龙井");
    set("long", @LONG
只见井(jing)水澈可见底而且清冷异常。龙井原名龙泓涧，传说
此井与海相通，其中必定有龙，祈祷必雨，故名“龙井”。苏东坡曾
有诗“人言山佳水亦佳，下有万古蛟龙潭”。井旁建有茶室。往南便
回大路。
LONG);
    set("resource/water",1);
    set("exits", ([ /* sizeof() == 2 */ 
                  "east" : __DIR__"longjin1", 
                  "south" : __DIR__"road62", 
                 ])
       );
    set("item_desc", 
    	   ([
             "jing" : 
	     "井水清澈见底，井底部有一些豆状小颗粒叠起的小堆。\n"
   	   ])
	);
	set("cost", 2);
        set("outdoors", "hangzhou");
    setup();

}
void init()
{
   add_action("do_stir","stir");
   add_action("do_stir","搅");
}
int do_stir(string arg)
{   if( !arg || arg=="" ) return 0;
    if( arg == "jing" || arg == "井")
    {
	message_vision("$N弯下身，用手指搅动井水。只见水面上出现一条蠕动的水纹，\n", this_player());
	message_vision("由外向内渐渐缩小而终於消失了。$N很得意的说“那就是分水\n", this_player());
	message_vision("线，知道吗。”\n", this_player());
    }
    return 1;
}
