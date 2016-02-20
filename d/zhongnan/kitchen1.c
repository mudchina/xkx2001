//Cracked by Roath
// road: /zhongnan/kitchen1.c

#include <room.h>
inherit ROOM;
int do_serve();

void create()
{
        set("short","厨房");

        set("long",@LONG
这里位於山间僻静处。两三个伙工正忙着准备食物，没时间理你。只
见那灶上一个蒸笼，正冒着腾腾热气，不知蒸了什麽东西。旁边几个水缸，
盛满了清水。几个葫芦挂在墙上。北边一堆干柴後，一扇小门半掩着，不知
通向何处。往东是一条小径。往北可出小门。
LONG);

		  set("exits",([ "east" : __DIR__"yuanneixiaojing7",
				"north" : __DIR__"houyuan",
							 ])
			  );
		  set("objects",([
					 __DIR__"obj/mitao" : 1,
					 __DIR__"obj/xiangcha" : 1,
		  ]));

		  set("no_fight", 1);

		  set("cost", 0);

		  create_door("north", "木门", "south", DOOR_CLOSED);
		  setup();
}


void init()
{
        add_action("do_serve", "serve");
}



int do_serve()
{
        object ob1, ob2, *inv, me = this_player();
        int food_ind, water_ind, f, w, i;
		  mapping myfam;

        myfam = (mapping)me->query("family");
        if ( !myfam || myfam["family_name"] != "全真教" )
                return notify_fail("你非本教弟子，不能拿取食物！\n");

        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
                if (inv[i]->query("drink_supply") && inv[i]->value() >= 0) w++;
        }

        food_ind = me->query("food");
        water_ind = me->query("water");

        if ( (int)me->max_food_capacity()-food_ind < 10
        && (int)me->max_water_capacity()-water_ind < 10 )
                return notify_fail("你已吃饱喝足，还是等会儿再要吧！\n");       

        message_vision("$N向老师傅陪笑要些食物吃喝。\n", me);

        if ( (int)me->max_food_capacity()-food_ind >= 40 && !f
        && !present( "tao", environment(me) ) ) {
                ob1 = new(__DIR__"obj/mitao");
                ob1->move(me);
                message_vision("老师傅笑吟吟地拿出"+ob1->name()+"给$N。\n", me);
        }
        else if ( (int)me->max_food_capacity()-food_ind >= 40 )
                message_vision("老师傅对$N说道：你不是有东西吃吗？吃完再说吧。\n", me); 
        else message_vision("老师傅对$N说道：你别老想着吃，太饱可不好。\n", me);
        
        if ( (int)me->max_water_capacity()-water_ind >= 40 && !w 
        && !present("tea", environment(me)) ) {
                ob2 = new(__DIR__"obj/xiangcha");
                ob2->move(me);
                message_vision("老师傅笑吟吟地拿出"+ob2->name()+"给$N。\n", me);
        }
        else if ( (int)me->max_water_capacity()-water_ind >= 40 )
                message_vision("老师傅对$N说道：你不是有东西喝吗？喝完再说吧。\n", me);
        else message_vision("老师傅对$N说道：你才刚喝过，怎么又渴啦？\n", me);

        return 1;
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i, f, w;
        
        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
                if (inv[i]->query("drink_supply") && inv[i]->value() >= 0) w++;
        }

        if ( f>0 || w>0 ) return notify_fail("老师傅拦着你说：别着急，还是把东西吃完再走吧。\n");

        return ::valid_leave(me, dir);
}
     