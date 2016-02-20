//Cracked by Roath
// 金蛇洞
// qfy 16/10/1996

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "山洞石室");
	set("long", @LONG
这山洞石室里头黑漆漆的，甚么也看不到，不知有何古怪。    
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"out" :  __DIR__"jinshe1",
	]));

	set("zhui", 1);
	set("jian", 1);
	set("box1", 1);
	set("box2", 1);
	set("book", 1);
	set("con", 0);
	set("skeleton", 1);
	set("sword", 28+random(10));

	set("cost", 0);
	setup();
}

void init()
{
	object book, me=this_player();

	if ( query("con") == 2 ) {
		environment(me)->set("long",
		"石壁上有几百幅用利器刻成的简陋人形，每个人均不相同，举手踢足\n"
		"，似在练武。图形尽处，石壁上刻着“重宝密术，付与有缘，入我门来，\n"
		"遇祸莫怨”十六个字。\n");
	}
	else if ( query("con") == 1 ) {
		environment(me)->set("long", 
		"石壁上有几百幅用利器刻成的简陋人形，每个人均不相同，举手踢足\n"
		"，似在练武。图形尽处，石壁上刻着“重宝密术，付与有缘，入我门来，\n"
		"遇祸莫怨”十六个字。字旁有个剑柄凸出在石壁之上，直至剑柄(sword)。\n");
	}
	else {
		environment(me)->set("long",
		"这山洞石室里头黑漆漆的，甚么也看不到，不知有何古怪。\n");
	}

	if ( me->query("jinshe") && query("book") >= 1 && !present("jinshe miji", me) ) {
		book = new(__DIR__"obj/jinshe_book2");
		if (!book) return 0;
		book->move(me);
		CHANNEL_D->do_channel(me, "rumor", sprintf("%s弄到了金蛇密籍。", me->query("name")));
		tell_object(me, "你检起金蛇秘笈仔细收好。\n");
		add("skeleton", -1);
		add("box1", -1);
		add("box2", -1);
		add("book", -1);
	}

	if ( query("con") != 0 ) {
		set("item_desc",([
			"wall" : "石壁上刻着简陋人形，举手踢足，似在研练武功。\n",
		]));
	}

	add_action("do_use", "use");
	add_action("do_dig", "dig");
	add_action("do_lingwu", "lingwu");
	add_action("do_bury", "bury");
	add_action("do_pull", "pull");
}

int do_lingwu(string arg)
{
	object ob, me = this_player();
	int check, level;

	if( !arg || arg == "" ) return 0;

	if ( query("con") == 0 ) return 0;


	if ( arg == "zhangfa" ) {
		if( !ob=present("jinshe miji", me) || !ob->query("iden") ) 
			return notify_fail("什么？\n");
	////////////////////////////////////////////////////////////////////////
	//add by wzfeng

	if ((int)me->query("jingli") < 100)
		return notify_fail("你的精力不够研读金蛇秘籍。\n");
	/////////////////////////////////////////////////////////////////////////////


		level = (int)me->query_skill("youshen-zhang", 1);
		check = level*level*level;

		if ( level < 100 ) return notify_fail("你金蛇游身掌等级不够，无法深入领悟金蛇游身掌。\n");
		if ( check > (int)me->query("shen") * 10 ) 
			return notify_fail("你正神太少，不能屏弃邪念，驾驭学习金蛇秘籍上诡异招式的心法。\n");
		
		if ( check < (int)me->query("combat_exp")*10 ) {
			me->improve_skill("youshen-zhang", me->query("int"));
			tell_object(me, "你的金蛇游身掌进步了。\n");
			me->receive_damage("jing", 60, "心力绞瘁死了"); 
			return 1;
		}
		else {
			me->receive_damage("jing", 60, "心力绞瘁死了");
			return notify_fail("你仔细地揣摩良久，但仍然不能领悟金蛇游身掌。\n");
		}
	}

	if ( arg == "jianfa" ) {
		if( !ob=present("jinshe miji", me) || !ob->query("iden") ) 
			return notify_fail("什么？\n");

		level = (int)me->query_skill("jinshe-jianfa", 1);
		check = level*level*level;

		if ( level < 100 ) return notify_fail("你金蛇剑法等级不够，无法深入领悟金蛇游身掌。\n");
		if ( check > (int)me->query("shen") * 10 ) 
			return notify_fail("你正神太少，不能屏弃邪念，驾驭学习金蛇秘籍上诡异招式的心法。\n");

		if ( check < (int)me->query("combat_exp")*10 ) {
			me->improve_skill("jinshe-jianfa", me->query("int"));
			tell_object(me, "你的金蛇剑法进步了。\n");
			me->receive_damage("jing", 60, "心力绞瘁死了");
			return 1;
		}
		else {
			me->receive_damage("jing", 60, "心力绞瘁死了");
			return notify_fail("你仔细地揣摩良久，但仍然不能领悟金蛇剑法。\n");
		}
	}

	if ( arg == "zhuifa" ) {
		if( !ob=present("jinshe miji", me) || !ob->query("iden") ) 
			return notify_fail("什么？\n");

		level = (int)me->query_skill("jinshe-zhuifa", 1);
		check = level*level*level;

		if ( level < 100 ) return notify_fail("你金蛇锥法等级不够，无法深入领悟金蛇游身掌。\n");
		if ( check > (int)me->query("shen") * 10 ) 
			return notify_fail("你正神太少，不能屏弃邪念，驾驭学习金蛇秘籍上诡异招式的心法。\n");

		if ( check < (int)me->query("combat_exp")*10 ) {
			me->improve_skill("youshen-zhang", me->query("int"));
			tell_object(me, "你的金蛇锥法进步了。\n");
			me->receive_damage("jing", 60, "心力绞瘁死了");
			return 1;
		}
		else {
			me->receive_damage("jing", 60, "心力绞瘁死了");
			return notify_fail("你仔细地揣摩良久，但仍然不能领悟金蛇锥法。\n");
		}
	}
}

int do_use(string arg)
{
    object ob, me = this_player();
       
    if( !arg || arg=="" ) return 0;

    if (!present("fire", me))  return 0;

    if ( arg=="fire" && query("con") != 0 )
	return notify_fail("你正用着火折子哪！\n");

    else if( arg=="fire" ) {
	if ( query("skeleton") >= 1 && !present("skeleton", environment(me)) && !me->query("jinshe") ) {
		message_vision("$N举起火把一照，登时吃了一惊！\n", me);
		message_vision("只见对面石壁上斜倚着一副骷髅骨，身上衣服已烂了七八成，\n", me);
		message_vision("那骷髅骨宛然尚可见到是个人形。\n", me);
		tell_object(me, "你看到这副情形，一颗心嘣嘣乱跳。\n");
	}
	else message_vision("$N举起火把一照。\n", me);

	set("con", query("last"));

	if ( query("con") <= 1 ) {
		environment(me)->set("long", 
		"石壁上有几百幅用利器刻成的简陋人形，每个人均不相同，举手踢足\n"
		"，似在练武。图形尽处，石壁上刻着“重宝密术，付与有缘，入我门来，\n"
		"遇祸莫怨”十六个字。字旁有个剑柄凸出在石壁之上，直至剑柄(sword)。\n"); 

		set("item_desc",([
			"wall" : "石壁上刻着简陋人形，举手踢足，似在研练武功。\n",
		]));

		set("con", 1);
	}
	else {
		environment(me)->set("long",
		"石壁上有几百幅用利器刻成的简陋人形，每个人均不相同，举手踢足\n"
		"，似在练武。图形尽处，石壁上刻着“重宝密术，付与有缘，入我门来，\n"
		"遇祸莫怨”十六个字。\n");
		set("con", 2);
	}

	if ( query("zhui") >= 1 ) {
		ob = new(__DIR__"obj/jinshe-zhui");
		ob->move(environment(me));
		add("zhui", -1);
	}

	if ( query("skeleton") >= 1 ) {
		ob = new(__DIR__"obj/skeleton");
		ob->move(environment(me));
		add("skeleton", -1);
	}       

	me->set_temp("visited", 1);

	return 1;
    }
    else return 0;      
}

int do_pull(string arg)
{
	object ob, obj, me=this_player();

	if ( !arg || arg != "sword" ) return 0;

	if ( present("jinshe jian", me) || me->query_temp("marks/jinshe") )
		return notify_fail("你不是拿了剑吗？\n");

	if ( present("jinshe jian", environment(me)) )
		return notify_fail("地上不是有剑吗？\n");
	
	if (me->query("neili") < 500)
		return notify_fail("你内力不够！\n");

	ob=new("/clone/unique/jinshe-jian");
	if (ob && me->query_kar() > query("sword")) {
		message_vision("$N紧紧握住剑柄，潜运内力，猛然向外一拔。\n", me);

		if( me->query("max_neili") >= 300 && me->query("neili") >= 200 ) {
			message_vision("只听得嗤的一声，$N将剑拔了出来。突然间石室内只感寒气逼人！\n", me);
			add("jian", -1);
			ob->move(me);
	CHANNEL_D->do_channel(me, "rumor", sprintf("%s弄到了一柄金蛇剑。", me->query("name")));
			me->add("neili", -500);
			me->set_temp("marks/jinshe", 1);
			
			set("con", 2);
			environment(me)->set("long",
			"石壁上有几百幅用利器刻成的简陋人形，每个人均不相同，举手踢足\n"
			"，似在练武。图形尽处，石壁上刻着“重宝密术，付与有缘，入我门来，\n"
			"遇祸莫怨”十六个字。\n");
		}
		else {
			message_vision("$N使尽气力始终拔不出剑来，原来内力不足。\n", me);
			me->set("neili", 0);
			destruct(ob);
		}
	
		return 1;
	}
	else {
	obj=new("/clone/weapon/gangjian");
	obj->set("name", "断掉的" + obj->query("name"));
	obj->set("value", 0);
	obj->set("weapon_prop", 0);
	obj->move(me);
	me->set_temp("marks/jinshe", 1);
	me->add("neili", -500);
	me->start_busy(2);
	if(ob) destruct(ob);
	return notify_fail("嗖的一声，你把一柄钢剑折断了拔出来。\n");
	}
}

int do_dig()
{
	object ob, me = this_player();

	if ( !present("tie qiao", me) )
		return notify_fail("你拿什么来挖啊？\n");

	if ( query("con") == 0 )
		return notify_fail("这么暗你看得到么？\n");

	if ( !me->query_temp("weapon") || me->query_temp("weapon")->name() != "铁锹" )
		return notify_fail("铁锹不拿在手上怎么挖啊？\n");
	
	if ( !me->query_temp("dig") ) message_vision("$N举起手中铁锹在地上铿铿地挖了起来。\n", me);
	else message_vision("$N又向地下挖掘，这次泥土较坚，由时时出现山石，挖掘大为费力。\n", me);

	if ( !me->query_temp("dig") && query("box1") >= 1 && random(10) == 5 ) {
		message_vision("忽然叮的一声，铁锹碰到一件铁器。$N移近火把一看，原来是一只铁盒。\n", me);
		add("box1", -1);
		ob = new(__DIR__"obj/box1");
		ob->move(environment(me));
		me->set_temp("dig", 1);
		me->add("jingli", -20);
	}
	else if ( !me->query_temp("dig") ) {
		message_vision("过了不久，$N挖了一个大洞。\n", me);
		me->add("jingli", -20);
	}
	else if ( me->query_temp("dig") && me->query_temp("read1") && me->query_temp("read2")
	&& me->query_temp("read3") && query("box2") >= 1 && random(10) == 1 
	&& (present("skeleton", environment(me)) || present("skeleton", me)) ) {
		message_vision("$N累出了一身大汗，又挖了三尺，叮的一声，铁锹又碰到一物，果然又是一只铁盒。\n", me);
		add("box2", -1);
		ob = new(__DIR__"obj/box2");
		ob->move(environment(me));
		me->add("jingli", -20);
		me->set("jinshe", 1);
	}
	else {
		message_vision("$N累出了一身大汗，挖了一个又深又大的洞。\n", me);
		me->add("jingli", -50);
	}

	return 1;
}

int do_bury(string arg)
{
	object ob, me=this_player();

	if ( !arg || arg == "" ) return 0;

	if ( arg != "skeleton" && arg != "kulou" && arg != "gu" ) return 0;

	if ( !objectp(ob = present(arg, environment(me))) 
	&& !objectp(ob = present(arg, me)) ) return 0;

	if ( !me->query_temp("dig") )
		return notify_fail("你想将骸骨埋在那里呀？\n");

	message_vision("$N把骸骨依次搬入穴中，盖上泥土，拜了几拜。\n", me);
	me->set_temp("buried", 1);
	destruct(ob);

	return 1;
}

int valid_leave(object me, string dir)
{
	object ob1, ob2;

	environment(me)->set("last", environment(me)->query("con"));
	environment(me)->set("con", 0);
	me->delete_temp("dig");
	me->delete_temp("read1");
	me->delete_temp("read2");
	me->delete_temp("read3");

	if ( objectp(ob1=present("skeleton", environment(me))) ) {
		add("skeleton", 1);
		destruct(ob1);
	}

	if ( objectp(ob2=present("jinshe zhui", environment(me))) ) {
		add("zhui", 1);
		destruct(ob2);
	}

	return ::valid_leave(me, dir);
}
