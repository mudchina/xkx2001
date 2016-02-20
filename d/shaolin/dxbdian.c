//Cracked by Roath
// Room: /d/shaolin/dxbdian.c
// Date: YZC 96/01/19

inherit ROOM;


void create()
{
	set("short", "大雄宝殿");
	set("long", @LONG
这里是少林寺的大雄宝殿。正中供奉着如来三宝，左右各是
文殊、普贤菩萨。一群青衣小和尚们正在佛像前的地上诵经。
缕缕香烟与梵唱交错在一起，仰视佛祖拈花浅笑的面容，令人顿
时生起几分脱俗之感。身边经常有一队队僧人鱼贯而入，看他们
手持戒刀，似乎是巡寺的僧人。
LONG
	);

	set("no_fight", "1");

	set("exits", ([
		"southdown" : __DIR__"guangchang2",
	]));

	set("valid_startroom",1);
	set("book_count",1);

	set("objects",([
		CLASS_D("shaolin") + "/dao-zheng" : 1,
		__DIR__"npc/xiang-ke" : 1,
	]));

	set("cost", 1);
	setup();
}

void init()
{
	add_action("do_ketou", "ketou");
}

int do_ketou()
{
	object me, ob, *obs;

	me = this_player();
		
	if ( random(50 - me->query_temp("ketou_times")) == 0 )
	{
		message_vision("$N磕头磕得晕了过去。\n", me);
		me->set_temp("ketou_times", 0);
		me->unconcious();
		return 1;
	}

	me->add_temp("ketou_times", 1);	

	message_vision("$N虔诚地跪下来，在如来佛祖面前磕头。\n", me);

	if ( random(100) == 37 
	&& !present("silk", me)
	&& query("book_count") >= 1)
	{
		add("book_count", -1);
		obs = filter_array(children(__DIR__"obj/book-silk.c"), (: clonep :));
        if (sizeof(obs) < 2){
		ob=new("d/shaolin/obj/book-silk");
		ob->move("/d/shaolin/dxbdian");
		add("book_count", -1);
		CHANNEL_D->do_channel(me, "rumor", sprintf("%s弄到了易筋经修行篇。", me->query("name")));
		tell_object(me, "突然你面前，啪地一声掉下一束羊皮线穿起来的薄绢！\n");
		}
	}

	if(me->query_skill("force", 1) >= 30 
	&& me->query_skill("force", 1) <= 100 
	&& present("silk", me) )
	{
	if( me->query("class") == "bonze" || me->query("class") == "lama")
		{
		if( me->query("jing") >= 30 ) 
			me->receive_damage("jing", random(50), "磕头磕死了");
		else	me->unconcious();
		me->improve_skill("force", random(me->query_con()*2));
		if ( random(5) == 0 )
		tell_object(me, "冥冥之中，你似乎觉得佛祖在点拨你在内功方面的疑难。\n");
		}
	}

	return 1;

}

int valid_leave(object me, string dir)
{
	if(me->query_temp("ketou_times") >= 10 ) me->add_temp("ketou_times", 10);

	return ::valid_leave();
}
