//Cracked by Kafei
// road: /zhongnan/kitchen2.c

inherit ROOM;
int do_serve();

void create()
{
		  set("short","厨房");

		  set("long",@LONG
这里就是厨房了。只见石室中的桌上放了些香喷喷的小菜及茶水。一
旁一个满脸生满鸡皮疙瘩的老妇人正在忙着准备食物。弟子们都管这老妇
叫孙婆婆，只知道她在小时候已进了这古墓，不知道待了多少年了。墙角
边堆满了瓶瓶罐罐(bottle)，一股淡淡的香味从罐子里飘了出来。往南是
一条走道。
LONG);
	set("item_desc",(["bottle" : "
这罐子里装了一些黄白色的液体，闻起来有如花密般的香甜。你尝了
一些，只觉得那汁液冰凉清香，蛮好喝的。这就是古墓派着名的玉蜂浆了。
这玉蜂浆不仅可当做食物，更是一种疗伤胜药。
					\n",]));

	set("exits",([ "south" : __DIR__"zoudao3",]));
	set("cost",1);
	set("objects",([
		"/kungfu/class/gumu/sun" : 1,
		__DIR__"obj/mitao" : 1,
		 __DIR__"obj/xiangcha" : 1,
	]));
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
        if ( !myfam || myfam["family_name"] != "古墓派" )
                return notify_fail("你非本派弟子，不能拿取食物！\n");

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

        message_vision("$N向孙婆婆陪笑要些食物吃喝。\n", me);

        if ( (int)me->max_food_capacity()-food_ind >= 40 && !f
        && !present( "tao", environment(me) ) ) {
                ob1 = new(__DIR__"obj/mitao");
                ob1->move(me);
                message_vision("孙婆婆笑吟吟地拿出"+ob1->name()+"给$N。\n", me);
        }
        else if ( (int)me->max_food_capacity()-food_ind >= 40 )
                message_vision("孙婆婆对$N说道：你不是有东西吃吗？吃完再说吧。\n", me); 
        else message_vision("孙婆婆对$N说道：你别老想着吃，太饱可不好。\n", me);
        
        if ( (int)me->max_water_capacity()-water_ind >= 40 && !w 
        && !present("tea", environment(me)) ) {
                ob2 = new(__DIR__"obj/xiangcha");
                ob2->move(me);
                message_vision("孙婆婆笑吟吟地拿出"+ob2->name()+"给$N。\n", me);
        }
        else if ( (int)me->max_water_capacity()-water_ind >= 40 )
                message_vision("孙婆婆对$N说道：你不是有东西喝吗？喝完再说吧。\n", me);
        else message_vision("孙婆婆对$N说道：你才刚喝过，怎么又渴啦？\n", me);

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

        if ( f>0 || w>0 ) return notify_fail("孙婆婆拦着你说：别着急，还是把东西吃完再走吧。\n");

        return ::valid_leave(me, dir);
}
     