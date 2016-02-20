//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "齐天峰");
        set("long", @LONG
北祈连山区第一高峰，直耸入云，无路可寻。只见山前一块大石(stone)，
据闻山中土人曾见时有黑衣神秘人出入此山，有胆大 好奇者入山探之，从未
生还。
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"zibai",
                "westdown" : __DIR__"tanglang",
        ]));

	set("item_desc", ([
                "stone" : "一块光洁的大石，中心部分很光滑，像是有人时常摩挲。\n",
        ]));
	set("outdoors" , "qilian-shan");
	set("insect_cont", 5);
	set("cost", 3);
	setup();
}

void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
	object me = this_player();

	set("exits/enter", __DIR__"rukou");

	write("你使劲挪开大石，现出一个山洞来。你突然发现大石侧面有些字迹，\n"
          "上面写着“非本教中人，死！”竟然全凭指力刻出，且入石三分，旁\n"
          "边还印着一个掌印，入石半尺有余，可见出掌人功力之深已达惊世骇\n"
          "俗的地步。\n", me);

       remove_call_out("close");
       call_out("close", 5, this_object());
 
	
   return 1;
}

void close(object room)
{
        message("vision","片刻之后，大石又滚回原地。\n", room);
        room->delete("exits/enter");
}


