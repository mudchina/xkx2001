//Cracked by Roath
// shandong2.c 猴儿洞
// qfy 96/6/30

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "猴儿洞");
        set("long", @LONG
这是一个小山洞，洞里有个小泉眼，正泊泊地流着一股猴儿泉。奇怪
的是洞里酒香四溢，似乎源自那股泉水。猴儿泉的旁边有个诩诩如生，满
副武装的石猴(statue)，象是在守护酒泉。洞外是一片荒山野林。
LONG
        );

	set("exits", ([
                "out" : __DIR__"yelin1",
        ]));

        set("resource/water", 1);

	set("item_desc",([
	    "猴儿泉"	:
            "一股殷红的酒泉(wine)，散发着浓郁的芳香。这便是猴儿们采集百果\n"
            "特酿而成的猴儿酒。\n",
	    "石猴"	:
	    "一个巧夺天工的石猴雕象，不知如何会在此荒山里出现。\n",
	    "statue"	:
	    "一个巧夺天工的石猴雕象，不知如何会在此荒山里出现。\n"
        ]));

	set("cost", 2);
        setup();
}

void init()
{
        add_action("do_drink", "drink");
	add_action("do_fill", "fill");
	add_action("do_pat", "pat");
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me = this_player();

        if( !arg || arg!="wine" ) 
       	    return notify_fail("你要喝甚么？！\n");

        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if ( current_water<max_water && me->query_temp("marks/酒") < 20 ) {
            me->set("water", current_water+30);
    	    me->add("neili", 10);
	    me->receive_damage("jing", 20);	
	    me->add_temp("marks/酒", 1);
            message("vision", me->name()+"捧了一把猴儿酒喝了下去。\n"
            , environment(me), ({me}) );
            write("你捧了一把猴儿酒喝了下去。酒一入胸腹，如饮醇蜜，甘芳无比。\n");
	    write("你突然觉得一股真气直冲天庭，原来此酒竟对内力小有补益。\n");
	    write("同时又有另一股酒气冒了上来，你有些飘飘然的感觉。\n");
        }
        else if ( me->query_temp("marks/酒") >= 20 ) {
	    write("你已喝了好多猴儿酒，还是留点给其他人吧。\n");
	}
	else write("你之前已喝了好多，已经再也喝不下了。\n");

        return 1;
}

int do_fill(string arg)
{
	object me = this_player();

	message("vision",me->name()+"想取些猴儿酒带走。\n", environment(me), ({me}));
	if ( me->query_temp("marks/取") ) {
	   message_vision("只听得一阵怒吼，一大群猴子愤怒地冲了进来，围着$N大打出手。\n", me);
	   message("vision","结果"+me->name()+"被打得遍体鳞伤，昏昏沈沈地被扛出洞外。\n", environment(me), ({me}));
	   write("结果你被打得遍体鳞伤，昏昏沈沈地被扛出洞外扔在荒山野林里。\n");
	   me->add("eff_qi", -40);
	   me->add("qi", -40);
	   me->delete_temp("marks/取");
	   me->set_temp("marks/步", 6);
	   me->move(__DIR__"yelin2");
	   me->unconcious();
	}
	else {
           message_vision("一只猴子冲了过来，向$N摇手高叫，示意$N不要取走猴儿酒。\n", me);
           me->set_temp("marks/取", 1);
	}

	return 1;
}

int do_pat(string arg)
{
	object me = this_player();

	if( !arg || arg != "statue" ) 
	   return notify_fail( "你要拍什么？\n" );

	message_vision("$N在石猴头上轻拍了一下。突然石壁右侧轰隆隆响了一阵，露出道门来。\n", me);
	set("exits/enter", __DIR__"yunuci");
        remove_call_out("close");
        call_out("close", 5, this_object());

	return 1;
}

void close(object room)
{
    message("vision","小门轰隆隆地降了下来，又封住了入口。\n", room);
    room->delete("exits/enter");
}
	
