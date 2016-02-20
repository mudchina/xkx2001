//Cracked by Roath
//

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这里常年有几个哑仆在烹调食物，等候传唤。对待这些人不用太客气，
命令(order)他们就可以了。
LONG
	);
	 set("exits", ([
                "south" : __DIR__"changlang",
        ]));
        set("objects",([
		__DIR__"npc/yapu" : 1,
                __DIR__"obj/chicken" : 1,
                __DIR__"obj/xiangcha" : 1,
           	__DIR__"obj/baozi" : 1,
                __DIR__"obj/fish" : 1,
        ]));

        set("no_fight", 1);

	setup();

}

void init()
{
        add_action("do_order", "order");
}

int do_order()
{
        object ob1, ob2, *inv, me = this_player();
        int food_ind, water_ind, f, w, i;
        mapping myfam;

        myfam = (mapping)me->query("family");
        if ( !myfam || myfam["family_name"] != "桃花岛" )
                return notify_fail("你非桃花弟子，不能拿取食物！\n");

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

        message_vision("$N打手势命令一个哑仆拿些食物吃喝。\n", me);

        if ( (int)me->max_food_capacity()-food_ind >= 40 && !f
        && !present( "chicken", environment(me) )
        && !present( "baozi", environment(me) )
        && !present( "fish", environment(me) ) ) {
           switch(random(3)) {
           case 0:
                ob1 = new(__DIR__"obj/chicken");
                break;
           case 1:
                ob1 = new(__DIR__"obj/baozi");
                break;
           case 2:
                ob1 = new(__DIR__"obj/fish");
                break;
           }
                ob1->move(me);
                message_vision("哑仆面无表情地拿出"+ob1->name()+"给$N。\n", me);
        }
        else if ( (int)me->max_food_capacity()-food_ind >= 40 )
                message_vision("哑仆指了指$N拿着的食物，摇了摇头。\n", me);
        else message_vision("哑仆指了指$N的肚子，摇了摇手。\n", me);

        if ( (int)me->max_water_capacity()-water_ind >= 40 && !w
        && !present("tea", environment(me)) ) {
                ob2 = new(__DIR__"obj/xiangcha");
                ob2->move(me);
                message_vision("哑仆面无表情地拿出"+ob2->name()+"给$N。\n", me);
        }
        else if ( (int)me->max_water_capacity()-water_ind >= 40 )
                message_vision("哑仆指了指$N拿着的食物，摇了摇头。\n", me);
        else message_vision("哑仆指了指$N的肚子，摇了摇手。\n", me);

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

        if ( (f>0 || w>0) && present("ya pu", environment(me)) ) 
		return notify_fail("哑仆拦着你，指了指你拿着的食物，摇了摇头。\n");

        return ::valid_leave(me, dir);
}




