//Cracked by Roath
// maco

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这是白驼山庄的厨房，里面有一个大灶和一口水缸，白驼山庄的
武师、家丁、婢女们可以在这儿喝水(drink) 。厨房里几个婢女正在
整治饭菜，祗要庄主、少主一有吩咐(order)，便有美酒佳肴上桌。
LONG
	);
	set("exits", ([ 
	    "northwest" : __DIR__"changlang4",
	    "northeast" : __DIR__"road2",

	]));
	set("resource/water", 1);
	set("no_fight", 1);
	set("objects", ([ 
	    "/d/xingxiu/obj/shegeng" : 1,
	    "/d/xingxiu/obj/kaoyang" : 1,
	    __DIR__"npc/binu" : 1,
	 ]) );
	set("cost", 0);
	setup();
}

void init()
{
	add_action("do_drink", "drink");
	add_action("do_order", "order");
}
int do_drink(string arg)
{
	int current_water;
	int max_water;
	object me;

	me = this_player();
	current_water = me->query("water");
	max_water = me->query("str")*10 + 100;
	
	if (me->query("family/master_id") == "ouyang feng" ) 
		return notify_fail("身为少庄主还趴在水缸上喝水，不觉得有失身分吗？\n");

	if (current_water<max_water) {
	    me->set("water", current_water + 30);
	    message("vision", me->name()+"趴在大水缸上咕嘟咕嘟灌了几口水。\n"
	    , environment(me), ({me}) );
	    write("你趴在大水缸上咕嘟咕嘟灌了几口水。\n");
	}
	else write("婢女奇怪地瞪着你，慢慢地咧开嘴，捧腹大笑起来：肚子都大了还喝！\n");

	return 1;
}


int do_order()
{
	object ob1, ob2, *inv, me = this_player();
	int food_ind, water_ind, f, w, i;
	mapping myfam;

	myfam = (mapping)me->query("family");
	if ( !myfam || myfam["family_name"] != "白驼山" )
		return notify_fail("你不是白驼山庄的人，不能拿取食物。\n");


	inv = all_inventory(me);
	for (i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("bt_food") && inv[i]->value() >= 0) f++;
		if (inv[i]->query("bt_liqueur") && inv[i]->value() >= 0) w++;
	}

	food_ind = me->query("food");
	water_ind = me->query("water");

	if ( (int)me->max_food_capacity()-food_ind < 10
	&& (int)me->max_water_capacity()-water_ind < 10 )
		return notify_fail("你已经吃饱喝足了，可别暴饮暴食。\n");

	if( (f && w) 
	|| (f && (int)me->max_water_capacity()-water_ind < 10 ) 
	|| (w && (int)me->max_food_capacity()-food_ind < 10) )
		return notify_fail("先把现有的酒菜吃完吧。\n");

	message_vision("$N用手指叩叩桌子，叫道：准备些酒菜来！\n", me);

	if (me->query("family/master_id") == "ouyang feng" ) {
	
	if(!f) {
	   switch(random(4)) {
	   case 0:
		ob1 = new("/clone/food/yangrou");
		break;
	   case 1:
		ob1 = new("/d/xingxiu/obj/zhuafan");
		break;
	   case 2:
		ob1 = new("/d/xingxiu/obj/xiangli");
		break;
	   case 3:
		ob1 = new("/d/xixia/obj/yangrou");
		break;
		}
	   	ob1->set("bt_food",1);
		ob1->move(me);
		message_vision("婢女在桌上放了一"+ob1->query("unit")+ob1->name()+"，轻声道：少主请用。\n", me);
		}
	if(!w) {
		ob2 = new("/d/baituo/obj/liqueur");
		ob2->set("bt_liqueur",1);
		ob2->move(me);
		message_vision("婢女替$N斟了一杯酒。\n", me);
		}
	}
	else if (me->query("family/master_id") == "ouyang ke" ) {
	message_vision("婢女摇了摇头，轻声说道："+RANK_D->query_respect(me)+"，这得要庄主或少主指示才行。\n", me);
	}
	else {
	message_vision("不过，婢女们仍然各忙各的，看来完全没人把$N的叫嚷当一回事。\n", me);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i, f, w;
	inv = all_inventory(me);
	for (i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("bt_food") ) f++;
	}

	if ( (f>0) ) 
		return notify_fail("吃饱喝足了还要外带酒菜，你想把白驼山庄坐吃山空吗？\n");

	return ::valid_leave(me, dir);
}
