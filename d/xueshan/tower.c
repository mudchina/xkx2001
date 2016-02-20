//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;
int do_pray();
int do_pour(string);

void create()
{
        set("short", "舍利宝塔");
        set("long", @LONG
这里就是贡奉历代嘉木活佛舍利的地方，宝塔前有一个木案(muan)，
塔身上刻的有弥勒佛和八大菩萨，塔顶覆以鎏金铜瓦，形式别至小巧。
LONG
        );
        set("exits", ([
                "west" : __DIR__"frontyard",
        ]));
	set("item_desc", ([
                "muan" : "木案上放置了合种精巧别致的吉祥银鉴，净水银杯、酥油灯、铜
盆、铜盏等供器。\n",
        ]));
	set("objects", ([
                "/d/xueshan/npc/xiangke" : 1,
				"/d/xueshan/obj/lamp" : 1,
        ]));
	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
}
void init()
{
   add_action("do_pray","pray");
}

int do_pray()
{
    object ob, me = this_player();
    int check, wait_time = 0;
    remove_call_out("open_up");
    message_vision("$N心诚意真地跪下来默默祈祷。\n", me);
 
    if ( me->query_temp("marks/油")) { 
    me->set_temp("marks/祈", 1);
    me->delete_temp("marks/油");
	}
    if ( me->query_temp("marks/祈") && interactive(me) && !me->is_fighting()) {
           call_out("open_up", random(300)+300, me);
	}
    return 1;
}

int open_up(object me)
{
		object lamp;
	    /* make sure that only when lamp is lighted, the door opens */
		if ( objectp(lamp = present("lamp", this_object())) ) {
		   if (lamp->query("burning")) {
              message_vision("$N心诚意真地祈祷了良久，突然舍利塔底打开了一道小门。\n", me);
              me->set_temp("marks/等", 1);
              set("exits/enter", __DIR__"tadi");
              call_out("close_up", 8, me);
		   }
		}
        return 1; 
}

int close_up(object me)
{
        message_vision("小门又轻轻地合上了。\n", me);
        delete("exits/enter");
        me->delete_temp("marks/等");
        return 1;
}

int valid_leave(object me, string dir)
{
        if ( !me->query_temp("marks/等")
        && !me->query_temp("marks/祈")  && dir == "enter" )
           return notify_fail("你心意不诚，不能进入宝塔。\n");
        else if ( me->query_temp("marks/祈") && dir == "west" ) {
           remove_call_out("open_up");
        }

        return ::valid_leave(me, dir);
}
