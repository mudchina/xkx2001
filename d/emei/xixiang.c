//Cracked by Roath
// /d/emei/xixiang.c 洗象池
// Shan: 96/06/22
// Re-Created by xQin on 3/00

#include <ansi.h>
#include <command.h>
inherit ROOM;

string look_pool();

void create()
{
	set("short", "洗象池");
	set("long", @LONG
洗象池原只是一亭，亭前有一个石砌的小池(pool)，池边不远就是危岩。
洗象池寓于一片冷杉林中，有若白云深处的仙山琼阁。若是云收雾敛、碧空万
里、月朗中天时，便觉万籁俱寂，清光无限，宛若身在天宫，彻体生凉。这正
是著名的「象池池夜」。由此向南上攀，便至雷洞坪，东下至莲花石。
LONG
	);
	set("exits", ([
		"southup" : __DIR__"lingyun",
		"eastdown" : __DIR__"po2",
	]));

	set("resource/water", 1);

	set("item_desc", ([
		"pool" : (: look_pool :),
		"危岩" : "危岩边刻有「岩谷灵光」四个大字。岩下终年为白云环绕，难见其底。\n",
		"rock" : "危岩边刻有「岩谷灵光」四个大字。岩下终年为白云环绕，难见其底。\n"
	]) ) ;

	set("no_clean_up", 0);
	set("outdoors", "emei");

	set("cost", 2);
	setup();
//	replace_program(ROOM);

}

void init()
{
	add_action("do_swim", "swim");
	add_action("do_swim", "dive");
}

int do_swim(string arg)
{
	int i, j;
	object me, room, *ob, *inv;
	me = this_player();

	if( me->is_busy() || me->is_fighting() || me->query_temp("pending") )
		return notify_fail("你现在正忙着呢。\n");

	if( !arg || (arg != "pool" && arg != "洗象池") )
		return notify_fail("什么？\n");

	inv = all_inventory(environment(me));
	for (i=0; i<sizeof(inv); i++) 
		if ( (string)inv[i]->query("race") == "人类" && inv[i] != me && !me->is_spouse_of(inv[i]) )
			return notify_fail("众目睽睽之下脱光衣裳下水，你不嫌害臊吗？！\n");

	inv = all_inventory(me);	
	for( i=0; i<sizeof(inv); i++ )
	{
		if( (string)inv[i]->query("equipped")=="worn" ) 
			switch( inv[i]->query("armor_type") )
			{
				case "cloth":
				case "armor":
				case "suncoats":
					if ( inv[i]->query_weight() > 8000)
						return notify_fail("穿着沉重的甲胃下水，不怕淹死你啊？！\n");
					else 
						me->receive_damage("jing", 10, me);
						return notify_fail(BLU"你跳进洗象池中，弄得浑身衣服湿漉漉的，赶紧爬回池外。冷风一吹，你不由\n得打了一个喷嚏。\n"NOR);
				case "boots":
					return notify_fail("穿着鞋下水？！\n");
				case "bandage":
					return notify_fail("你还裹着伤呢，不怕下水后伤口感染？！\n");
				default:
					break;
			}
	}

	if( me->query_encumbrance()*20 > me->query_max_encumbrance() )
        return notify_fail("你身上的东西太多了！\n");

	for( i = 0; i < sizeof(inv); i++ )
	{
		if( !inv[i]->query("no_drop") ) DROP_CMD->do_drop(me, inv[i]);
		else if(inv[i]->query("equipped")) inv[i]->unequip();
		else tell_object(me, "你将"+inv[i]->name()+"用衣物仔细包好。\n");               
	}
	message_vision(CYN"$N往洗象池中跳去。\n"NOR, me);

	if( !(room = find_object(__DIR__"pool")) )
		room = load_object(__DIR__"pool");
	if( !room ) return 0;
	me->move(__DIR__"pool");
	return 1;
}

string look_pool()
{
	int i, check=0;
	object *ob;
	object me, room;
	me = this_player();

	if( !(room = find_object(__DIR__"pool")) )
		room = load_object(__DIR__"pool");

	message_vision("$N悄悄转到池边，伸长脖子往池里望去。\n", me);
	"/cmds/std/look.c"->look_room(me, room);

	ob = all_inventory(room);
	for( i=0; i < sizeof(ob); i++ )
		if( ob[i]->is_character() ) check++;
	if( check )
	{
		check = 0;
		if( me->query("gender") == "女性" )
		{
			tell_object(me, "你好像看见有人在池里游水。\n");
			for( i=0; i < sizeof(ob); i++ )
				if( ob[i]->query("gender") != "女性" ) check++;

			if( check )
			{
				tell_object(me, "你脸上一红，原来在池中游水的人是．．．．\n");
				message("vision", CYN+me->name()+"突然脸上一红，回过头来。\n"NOR,
					environment(me), ({ me }) );
			}
			else tell_object(me, "你隐隐约约看到在池中戏水的好像是女子。\n");
		}
		else if( me->query("gender") == "男性" )
		{
			tell_object(me, "你发现池中有人在裸身游水，"NOR);
			for( i=0; i < sizeof(ob); i++ )
			{
				if( ob[i]->query("gender") == "女性" ) check++;
				if( !living(ob[i]) ) continue;
				if( random(5) == 1 )
				{
					ob[i]->enable_player();
					tell_object(ob[i], RED"你不经意一回头，突然发现有人躲在池边对你不怀好意地窥视着！\n"NOR);
					ob[i]->set_temp("been_looked", 1);
					if( ob[i]->query("gender") == "女性" )
					{
						tell_object(ob[i], HIR"你只血气上冲，顿时感到一阵旋晕！\n"NOR);
						ob[i]->set("jing", 0);
						ob[i]->start_busy(1);
						if( random(ob[i]->query_per()/6) )
						{
							ob[i]->unconcious();
							ob[i]->set_temp("apply/short", ({ ob[i]->query("title")+ " " +ob[i]->query("name")+
							"("+capitalize(ob[i]->query("id"))+")"+HIW" <全裸>"NOR }) );
						}
					}
					else
					{
						tell_object(ob[i], "你虽不以为意，但已经没有兴趣再继续游水了。\n");
						__DIR__"pool.c"->do_halt(ob[i]);
					}
				}
			}

			if( check )
			{
				tell_object(me, "而且还是女子！\n"
						HIC"你远远看着那近乎全裸的雪白身体，一阵热血上涌，魂灵儿早飞到九霄云外了。\n"NOR);
				message("vision", CYN +me->name()+"突然两眼发直，张大了口，口水滴嗒滴嗒直往外流。\n"NOR,
					environment(me), ({ me }) );
			}
			else
			{
				tell_object(me, "可惜其中却没有女子。\n");
				message("vision", me->name()+"深深地叹了口气，回过头来。\n",
					environment(me), ({ me }) );
			}
		}
		else tell_object(me, "你似乎看见有人在池中游水，可是你对此一点兴趣都没有。\n");
	}
	return "";
}
