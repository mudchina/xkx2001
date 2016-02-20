//Cracked by Roath
// Room: /city/pomiao.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "土地庙");
	set("long", @LONG
这是一间破破烂烂的土地庙，庙里破败不堪，土地神像推在一旁，梁上地下
也布满了灰尘。一看就知道已经很久没有人来清理过了。正中放着个大香案，上
面零乱地扔着几根吃剩下来的鸡骨头。也许正是因为隐蔽的原因吧，据说丐帮江
南分舵就被设在此处。香案黑洞洞的，下边好像有个大洞，后面有一扇半开半掩
的小门。
LONG
	);

	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"ml4",
		"north" : __DIR__"zhulin1",
	]));
	set("objects", ([
		CLASS_D("gaibang") + "/lu" : 1,
		CLASS_D("gaibang") + "/peng" : 1,
	]));

	create_door("north", "小门", "south", DOOR_CLOSED);
	set("cost", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
	add_action("do_qingjiao", "qingjiao");
	add_action("do_qingjiao", "inquire");
	add_action("do_qingjiao", "wen");
}

int do_enter(string arg)
{
	object me;
	mapping fam;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "丐帮" ) 
		{
			message("vision",
				me->name() + "运起丐帮缩骨功，一弯腰往香案下的洞里钻了进去。\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/undergb");
                	message("vision",
				me->name() + "从洞里走了进来。\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("这么小的洞，你钻得进去吗？\n");
	}
}	

int do_qingjiao(string arg)
{
	object me=this_player();
	int check1, check2;

	if( !arg || arg=="" ) return 0;

	if( (arg == "lu" || arg == "lu youjiao" || arg == "youjiao" )
	&& !present("lu youjiao", environment(me)) )
		return notify_fail("鲁有脚不在这里，如何指点于你？\n");

        if( !me->query("family") || me->query("family/family_name") != "丐帮" )
                return notify_fail("鲁有脚摇摇头说道：向我请教，这怎么敢当？\n");	

	if( !me->query_temp("lu") )
		return notify_fail("鲁有脚斜着眼，对你理也不理，喃喃说道：最近帮里事务太多，没空出去买酒，\n"
			          +"肚里的酒虫闹得好不利害。\n");

	if( me->query_temp("lu") == 2 )
		return notify_fail("鲁有脚怒气冲冲地说道：滚开，老子不想见你！\n");

	if( !present("stick book", me) )
		return notify_fail("鲁有脚皱眉道：没书要我怎么教你？\n");

	write("你拿出棒法图解，恭恭敬敬的向鲁有脚请教基本棒法的精要。\n");

	check1 = (int)me->query_skill("stick", 1);
	check2 = check1 * check1 * check1;

	if ( check1 < 30 )
		return notify_fail("鲁有脚解释了老半天，你还是不明白，看来你的基本棒法修为仍然不够。\n");

	if ( check1 > 100 )
		return notify_fail("鲁有脚解释了一会儿，你觉得无聊得紧，看来你的基本棒法造诣艺已炉火纯青了。\n");

	if ( check2 > (int)me->query("combat_exp")*10 )
		return notify_fail("你实战经验不足，无法明了鲁有脚的讲解。\n");

	if ( (int)me->query("jing") < 30 )
		return notify_fail("你精神无法集中。\n");

	me->receive_damage("jing", 20);
	me->improve_skill("stick", me->query("int"));
	write("你想通了基本棒法方面的几个疑难。\n");

	return 1;
}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("lu") == 1 ) 
		me->delete_temp("lu");

	return ::valid_leave(me, dir);
}
