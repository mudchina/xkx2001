//Cracked by Roath
// pool.c
// 洗象池中
// xQin 3/00

inherit ROOM;
#include <ansi.h>

int do_halt(object);
void out_of_pool(object, int);

void create()
{
	set("short", HIC"池中"NOR);
	set("long", "这是一个石砌的六角小池，传说普贤乘象至此，必先在此池沐浴其象，而\n"
"后才升至金顶，故为「洗象池」。\n\n"
"　　"HBBLU+HIC"池水清澈透亮\n"NOR
	);

	set("xixiang", 1);
	set("resource/water", 1);
        setup();
}

void init()
{
	int i;
	object room, me = this_player();
	object *inv = all_inventory(environment(me));

	if( !(room = find_object(__DIR__"xixiang")) )
		room = load_object(__DIR__"xixiang");

	if( interactive(me) )
	{ 
		tell_room(environment(me), "有人“扑通”一声跳了进来。\n", ({ me }));
		tell_object(me, "你“扑通”一声跳进了池水。\n");
		tell_room(room, "只听“扑通”一声，"+me->name()+"已经跳进了池水里。\n");
		me->start_call_out( (: call_other, __FILE__, "do_swim", me :), 1);

		for( i=0 ; i < sizeof(inv); i++)
			if( inv[i] != me && inv[i]->query_temp("xixiang_swimming") )
			{
				me->start_call_out( (: call_other, __FILE__, "disturb", inv[i], this_player() :), 0);
				break;
			}
	}

	add_action("do_ban", "save");
	add_action("do_ban", "quit");
	add_action("do_ban", "exercise");
	add_action("do_ban", "dazuo");
	add_action("do_ban", "respirate");
	add_action("do_ban", "tuna");
	add_action("do_ban", "practice");
	add_action("do_ban", "lian");
	add_action("do_ban", "kill");
	add_action("do_ban", "fight");
	add_action("do_ban", "hit");
	add_action("do_halt", "halt");
}

int do_ban()
{
	write("在水中做这事，你不怕被淹死啊？\n");
	return 1;
}

void disturb(object bather, object freeloader)
{
	int i, check=0;
	object *ob;
	if( environment(freeloader) != environment(bather)
	 || !(environment(bather))->query("xixiang") ) return;

	ob = all_inventory(environment(freeloader));
	for( i=0; i < sizeof(ob); i++ )
		if ( ob[i]->is_character() && ob[i] != freeloader ) check++;

	if( check > 1 )
	{
		tell_object(freeloader, "你突然发现池水中有人，而且还不止一个。\n");
		do_halt(freeloader);
		return;
	}

	if( bather->is_spouse_of(freeloader) )
	{
		tell_object(bather, HIB"你仔细一看，原来是你的"+ bather->query("spouse/title")
				+ "，虚惊一场。\n"NOR);
		message("vision",CYN + freeloader->name() + "对着你会心地一笑。\n"NOR, bather);
		message("vision",CYN"你对着" + bather->name() + "会心地一笑。\n"NOR, freeloader);
		return;
	}

	tell_object(freeloader, "你发现池中也有人在游水，");
	if( (string)freeloader->query("race") != "人类" )
	{
		tell_object(bather, HIB"你仔细一看，原来是" + freeloader->query("unit")
			+ freeloader->name() + "，虚惊一场。\n"NOR);
		return;
	}
	if( (string)bather->query("race") != "人类" )
	{
		tell_object(freeloader, HIB"仔细一看，原来是" + bather->query("unit")
			+ bather->name() + "，虚惊一场。\n"NOR);
		return;
	}
	if( freeloader->query("gender") == "男性" )
	{
		if( bather->query("gender") != "女性" )
		{
			tell_object(freeloader, "仔细一看，对方却不是女子。\n");
			message("vision",CYN + bather->name() + "皱了皱眉，似乎想对你说些什么。\n"NOR, freeloader);
			message("vision",CYN + freeloader->name() + "皱了皱眉，似乎想对你说些什么。\n"NOR, bather);
			return;
		}
		else
		{
			if( !living(bather) ) return;
			tell_object(bather, RED"你仔细一看，跳入池中的人竟是名男子，他正对着你不怀好意地窥视着！\n"NOR);
			tell_object(bather, HIR"你只血气上冲，顿时感到一阵旋晕！\n"NOR);             
			tell_object(freeloader, RED"\n仔细一看，象池中沐浴的是名女子，她几乎要被你吓得晕了过去。\n"NOR);
			bather->set("jing", 0);
			bather->set_temp("been_looked", 1);
			bather->start_busy(1);
			if( random(bather->query_per()/6) ) 
			{
				bather->unconcious();
				bather->set_temp("apply/short", ({ bather->query("title")+ " "
				+ bather->query("name")+ "("+capitalize(bather->query("id"))+")"+HIW" <全裸>"NOR }) );
			}
			return;
		}
	}
	if( freeloader->query("gender") == "女性" )
	{
		if( bather->query("gender") == "女性" )
		{
			tell_object(bather, "你仔细一看，原来对方也是个女子。\n");
			tell_object(freeloader, "仔细一看，原来对方也是个女子。\n");
			message("vision", CYN + freeloader->name() + "对着你轻轻一笑。\n"NOR, bather);
			return;
		}
		else
		{
			tell_object(freeloader, "仔细一看，原来对方竟是位．．．．\n");
			if( bather->query("gender") == "男性" )
				tell_object(bather, HIY"你仔细一看，跳进来的竟是女子！！\n"NOR);
			else 	tell_object(bather, "你仔细一看，跳进来的是名女子。\n"NOR);
			do_halt(freeloader);
			return;
		}
	}
	else
	{
		tell_object(bather, RED"你突然见到有外人跳进来，恨不得找个地缝钻进去。\n"NOR);
		do_halt(bather);
		bather->set("jing", 0);
		bather->start_busy(1);
		return;
	}	
}

int do_swim(object me)
{
	mixed local;
	int t, time;

	if( !living(me) )
	{
		out_of_pool(me, 0);
		return;
	}
	if( !(environment(me))->query("xixiang") ) return;

	if( me->query_con() < 25 )
	{
		tell_object(me, HIB"不料池水冰冷刺骨，你猛得一颤，连忙爬出池外！\n"NOR);
		tell_room(environment(me), me->name()+"冻得全身哆嗦，急急忙忙地又爬了上去！\n", ({ me }));
		me->move(__DIR__"xixiang");
		tell_room(environment(me), me->name()+"急急忙忙地从洗象池中跳了上来，全身发白，直打哆嗦！\n", ({ me }));
		me->start_busy(2);
		me->receive_damage("jingli", 100);
		me->receive_damage("qi", 100);
		me->receive_damage("jing", 100);
		return 1;
	}

	local = localtime(time()*60);
	t = local[2]*60 + local[1];

	time = (1000/me->query_skill("swimming") + random(1000/me->query_skill("swimming")))/2;
	if( time > 30 ) time = 30;
	if ( t > 1200 || t < 300 )
	{
		write(HIB"此时夜深人静，你尽情地在池中戏水，想借清凉的池水解除一天的疲劳。\n"NOR);	
		call_out("out_of_pool", time, me, 1);
	}
	else
	{
		write(HIB"池水清凉，你尽情地在池中戏水，但仍时时担心是否有人路过窥视。\n"NOR);
		call_out("out_of_pool", time, me, 0);
	}

	me->set_temp("xixiang_swimming", 1);
	me->set_temp("apply/short", ({ me->query("title")+ " " +me->query("name")+"("+capitalize(me->query("id"))+")"+HIC" <游水中>"NOR}));

        me->start_busy(6);      
        return 1;         
}

void out_of_pool(object me, int recover)
{
	if( !me->query_temp("xixiang_swimming") ) return;
	if( !(environment(me))->query("xixiang") ) return;

	me->delete_temp("xixiang_swimming");
	me->delete_temp("been_looked");
	me->delete_temp("apply/short");

	if( !living(me) )
	{
		message_vision("一阵清风吹来，将昏迷的$N推到池边。\n", me);
		me->move(__DIR__"xixiang");
		message_vision("一阵徐徐清风吹来，将昏迷的$N推到了池边。\n", me);
		return;
	}
	if( recover )
	{
		tell_object(me, GRN"过了一小会儿，你爬出池外，只觉疲劳尽去，精神抖擞。\n"NOR);
		message("vision", "只见"+me->name()+"精神焕发地爬上池边，穿好衣服。\n",
			environment(me), ({ me }) );
		me->move(__DIR__"xixiang");
		message("vision", "只见"+me->name()+"精神焕发地从洗象池中爬了上来。\n",
			environment(me), ({ me }) );
		if( me->query("gender") == "女性" )
		{
			me->add("jing", (me->query("eff_jing") - me->query("jing"))/2);
			me->add("qi", (me->query("eff_qi") - me->query("qi"))/2);
			me->add("jingli", (me->query("max_jingli") - me->query("jingli"))/2);
			me->add("neili", (me->query("max_neili") - me->query("neili"))/2);
			me->improve_skill("beauty", 15*me->query_per());
			me->improve_skill("force", random(me->query_con()*5));
		}
		else
		{
			me->add("jing", ((int)me->query("eff_jing")-(int)me->query("jing"))/(3+random(5)));
			me->add("qi", ((int)me->query("eff_qi")-(int)me->query("qi"))/(3+random(5)));
			me->add("jingli", ((int)me->query("max_jingli")-(int)me->query("jingli"))/(3+random(5)));
			me->add("neili", ((int)me->query("max_neili")-(int)me->query("neili"))/(3+random(5)));
		}
	}
	else
	{
		tell_object(me, GRN"过了一小会儿，你觉得在池中游累了，爬回池外。\n"NOR);
		message("vision", "只见"+me->name()+"爬出洗象池，穿好衣服。\n",
			environment(me), ({ me }) );
		me->move(__DIR__"xixiang");
		message("vision", "只见"+me->name()+"从洗象池中爬了上来。\n",
			environment(me), ({ me }) );
		me->improve_skill("force", random(me->query_con()/5));
		if( me->query("gender") == "女性" )
			me->improve_skill("beauty", 5*me->query_per());
	}
	if( me->query_skill("swimming") < 125 ) me->improve_skill("swimming", random(me->query("dex"))*random(me->query_skill("swimming")/4)+1 );
	me->start_busy(1);      
}

int do_halt(object me)
{
	if( !me ) me = this_player();
//	if( me->is_busy() ) return notify_fail("你还在忙呢。\n");

	me->delete_temp("xixiang_swimming");
	me->delete_temp("apply/short");

	if( me->query_temp("been_looked") )
	{
		me->delete_temp("been_looked");
		tell_object(me, "你连忙穿好衣服，爬出洗象池。\n");
		message("vision", me->name()+"匆匆忙忙穿好衣物，爬上池边。\n",
			environment(me), ({ me }) );
		me->move(__DIR__"xixiang");
		message("vision", me->name()+"一脸气极败坏地从洗象池中爬了上来。\n",
			environment(me), ({ me }) );
		return 1;
	}

	tell_object(me, "你连忙爬上池边穿好衣服。\n");
	message("vision", me->name()+"急忙爬上池边穿好衣服。\n",
			environment(me), ({ me }) );
	me->move(__DIR__"xixiang");
	message("vision", me->name()+"急急忙忙地从洗象池中爬了上来。\n",
			environment(me), ({ me }) );
	return 1;         
}
