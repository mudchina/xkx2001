//Cracked by Roath
//棋苑
//From:http://www.lhmz.yn.cninfo.net/jackyboy/default.htm
//Modified by xQin 4/00
//xQin 8/00 

#include <ansi.h>
inherit  ROOM;

string look_zi();

void  create  ()
{
    set  ("short", "轩辕棋苑");
    set  ("long",@LONG
这里是新开张的轩辕棋苑，只见苑内布置简单却也十分优雅。不少文人雅士
都喜欢来此对弈谈天。苑内还分有其他三间棋室，不喜欢被打扰的客人可以进去
棋室内下棋。柜台后挂着一幅字(zi)。   
LONG);

    set("item_desc", ([
    "zi" : 
"【围棋十诀之一】：不得贪胜 \n"
"【围棋十诀之二】：入界宜缓 \n"
"【围棋十诀之三】：攻彼顾我 \n"
"【围棋十诀之四】：弃子争先 \n"
"【围棋十诀之五】：舍小就大 \n"
"【围棋十诀之六】：逢危须弃 \n"
"【围棋十诀之七】：慎勿轻速 \n"
"【围棋十诀之八】：动须相应 \n"
"【围棋十诀之九】：彼强自保 \n"
"【围棋十诀之十】：势孤取和 \n",

    ]));

    set("exits",  ([
    "west"  : "/d/city/wqiyuan1",
    "east"  : "/d/city/wqiyuan2",
    "south" : "/d/city/wqiyuan3",
    "north"  : "/d/city/xidajie1",
    ]));

    setup();
}

int valid_leave(object me, string dir)
{
        object room;
        mapping exit;

        exit = environment(me)->query("exits");

        if ( dir == "east" || dir == "north" || dir == "west" ) {
                if( !( room = find_object(exit[dir])) )
                       room = load_object(exit[dir]);
	        if( room->query_temp("action")  ==  1 )
                       return notify_fail("那间棋室已经有人开始下棋了，请勿打扰\n");
                }

        return ::valid_leave(me, dir);
}
