//Cracked by Roath
// 虎跑
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "虎跑泉");
    set("long", @LONG
只见泉水从沙岩中渗流而出，清澈见底。相传有位名叫性空的和
尚深爱此山风景灵秀，便住了下来。後因水源奇缺，准备迁走。一夜，
梦神告诉他说“南岳衡山童子泉，当遣二虎移来。”第二天，果然看
见两只老虎跑地作穴，涌出泉水，所以定名为“虎跑泉”。
LONG);
    set("resource/water",1);
    set("exits", ([ /* sizeof() == 2 */ 
                  "east" : __DIR__"road77", 
                 ])
       );
	set("cost", 2);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);

}
