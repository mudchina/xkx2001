//Cracked by Roath
// Room: chufang.c
//

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这里是归云庄的厨房，一个乡下妇人正在灶边忙来忙去，看来她就是
这里的厨娘了。如果肚子饿了，就赶快找厨娘要(serve)些吃的吧。
LONG
	);
	 set("exits", ([
		"south" : __DIR__"huayuan",
	]));


	set("item_desc", ([
	    "table" : "一张长方形的木桌，上面放着水果，茶水和食物。\n",
	    "chair" : "一只普通的木制靠椅。\n",
	]));


	set("objects",([
		__DIR__"obj/mitao" : 1,
		__DIR__"obj/xiangcha" : 2,
		__DIR__"obj/zongzi" : 1,
		__DIR__"obj/jitui" : 1,
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
	int food_ind, water_ind, f, w, i;
	mapping myfam;

	myfam = (mapping)me->query("family");
	if ( !myfam || myfam["family_name"] != "桃花岛" )
		return notify_fail("你非桃花岛弟子，不能拿取食物！\n");

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

	message_vision("$N向厨娘陪笑要些食物吃喝。\n", me);

	if ( (int)me->max_food_capacity()-food_ind >= 40 && !f
	&& !present( "zongzi", environment(me) )
	&& !present( "baozi", environment(me) )
	&& !present( "tao", environment(me) ) ) {
	   switch(random(3)) {
	   case 0:
		ob1 = new(__DIR__"obj/zongzi");
		break;
	   case 1:
		ob1 = new(__DIR__"obj/baozi");
		break;
	   case 2:
		ob1 = new(__DIR__"obj/mitao");
		break;
	   }
		ob1->move(me);
		message_vision("厨娘笑呵呵地拿出"+ob1->name()+"给$N。\n", me);
	}
	else if ( (int)me->max_food_capacity()-food_ind >= 40 )
		message_vision("厨娘对$N说道：你不是有东西吃吗？吃完再说吧。\n", me);
	else message_vision("厨娘对$N说道：你别老想着吃，太饱可不好。\n", me);

	if ( (int)me->max_water_capacity()-water_ind >= 40 && !w
	&& !present("tea", environment(me)) ) {
		ob2 = new(__DIR__"obj/xiangcha");
		ob2->move(me);
		message_vision("厨娘笑呵呵地拿出"+ob2->name()+"给$N。\n", me);
	}
	else if ( (int)me->max_water_capacity()-water_ind >= 40 )
		message_vision("厨娘对$N说道：你不是有东西喝吗？喝完再说吧。\n", me);
	else message_vision("厨娘对$N说道：你才刚喝过，怎么又渴啦？\n", me);

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

	if ( f>0 || w>0 ) return notify_fail("厨娘拦着你说：别着急，还是把东西吃完再走吧。\n");

	return ::valid_leave(me, dir);
}
