//Cracked by Roath
// Room: chufang.c
// qfy August 22, 1996.

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
厨房四周摆有几张桌子和椅子，几个老妈子和丫环正忙着烧饭煮菜。饭菜
的香气随风飘送，老远便能闻到，另人垂涎欲滴。你要想吃东西尽管向老妈子
要(serve)，想喝水便自个儿到外面的井去打(fill)。
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"zoulang2",
	]));
	
        set("item_desc", ([
	    "table" : "一张长方形的木桌，上面放着水果，茶水和食物。\n",
	    "chair" : "一只普通的木制靠椅。\n",
	]));
	                                

	set("objects",([
	]));
	
	set("no_fight", 1);
	
	set("cost", 0);
	setup();
}

void init()
{
	add_action("do_serve", "serve");
}

int do_serve()
{
	object ob1, ob2, *inv, me = this_player();
	int food_ind, f, i;

	if ( !me->query_temp("mark/马") )
		return notify_fail("你非武馆弟子，不能拿取食物！\n");

	inv = all_inventory(me);
	for (i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
	}

	food_ind = me->query("food");

	if ( (int)me->max_food_capacity()-food_ind < 10 )
		return notify_fail("你已吃饱喝足，还是等会儿再要吧！\n");	

	message_vision("$N向位老妈子要些食物吃喝。\n", me);

	if ( (int)me->max_food_capacity()-food_ind >= 40 && !f ) {
	   switch(random(2)) {
	   case 0: 
		ob1 = new(__DIR__"obj/zongzi");
		break;
	   case 1:
		ob1 = new(__DIR__"obj/dianxin");
		break;
           case 2:
		ob1 = new(__DIR__"obj/tangbao");
		break;
	   }	
		ob1->move(me);
		message_vision("老妈子地拿出"+ob1->name()+"给$N。\n", me);
	}
	else if ( (int)me->max_food_capacity()-food_ind >= 40 )
		message_vision("老妈子对$N说道：你不是有东西吃吗？吃完再说吧。\n", me); 
	else message_vision("老妈子对$N说道：你别老想着吃，太饱可不好。\n", me);
	
	return 1;
}

int valid_leave(object me, string dir)
{
	int i, f;
	object *inv;
	
        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
        }

	if ( f>0 ) return notify_fail("丫环拦着你说：别着急，还是把东西吃完再走吧。\n");

	return ::valid_leave(me, dir);
}
