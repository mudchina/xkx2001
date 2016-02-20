//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;
int do_dig();
void create()
{
        set("short", "丹凤洞");
        set("long", @LONG
一个空荡荡的大山洞，四壁很光滑。你看见洞脚边上好想有什麽东
西在闪闪发光。
LONG
        );
        set("exits", ([
                "out" : __DIR__"danfeng",
        ]));
	set("gold_count", 30);

	set("cost", 2);
        setup();
}
void init()
{
        add_action("do_dig","dig");
}

int do_dig()
{
    object ob, me = this_player();

    if (present("tie qiao", me))  
    { message_vision("$N举起手中铁锹照着泥地上：铿！铿！ 一通乱挖。\n", me);
   
	if ( random(10) == 5 && query("gold_count") >= 1) {
      write("一块亮晶晶的东西一闪，哈哈。。。！你挖到一锭金元宝。\n");
	   me->add("jingli", -10);
           ob = new("clone/money/yuanbao");
           ob->move("/d/qilian/mine");
	   add("gold_count", -1);
	if (query("gold_count") < 1)
	log_file("MONEY", sprintf("%s(%s)于%s在丹凤洞挖了三百两黄金。\n",
		me->query("name"), getuid(me), ctime(time())));
         }    
   }
      else {
		write("没有合适的家伙，挖不开吧！");
        }
 	return 1;
}
