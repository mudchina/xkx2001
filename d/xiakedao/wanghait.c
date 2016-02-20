//Cracked by Roath
// xiakedao/wanghait
// ssy

inherit __DIR__"no_pk_room";

int fishing(object me);
int halt_fishing(object me);

void create()
{
        set("short", "望海亭");
        set("long", @LONG
一座典雅古朴的小亭子，亭左是一道深涧(stream)，涧水湍急，
激石有声。细碎的水珠形成一片雾气，整个亭子显得烟雨朦朦。亭旁
的大石(stone)後好象有什麽东西。北边隐约传来隆隆的响声。
LONG );

      set("exits", ([
		     "south" : __DIR__"xiaolu2",
		     "northup" : __DIR__"pubu",
		     "east" : __DIR__"tulu",
      ]));

	set("item_desc",([
	    "stream" : "涧水清澈，不时有鱼儿(fish)跃出水面。\n",
	    "fish" : "透过清澈的涧水，可以看到不少鱼儿在水里自由自在地游来游去。\n",
	    "stone" : "这是一块大山石，石头後面好象藏着什麽。想看看後面是什麽，就
要把大石移开(move)。\n",
	]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	set("objects", ([ 
	    __DIR__ + "npc/baodating" : 1,
      ]));

	set("pole_count", 3);
	set("fish_count", 1);
	setup();
}

void init()
{
        ::init();

	if (  present("fishing pole", this_player()) )
		add_action("do_fish", "fishing");

	add_action("do_move", "move");
}

int do_move(string arg)
{	object pole, me = this_player();

	if ( !arg )
		return notify_fail( "你要移什么？\n");
	if ( arg != "stone" )
		return notify_fail( "什么？\n");

	if (query("pole_count") < 1)
	{	message_vision("$N使劲把大石移开，却没有发现什麽东西。\n", me);
		return 1;
	}
	if (!(present("fishing pole", me)))
	{	message_vision("$N使劲把大石移开，发现一根鱼杆，可以用来钓鱼(fishing)。\n", me);
		pole = new(__DIR__+ "obj/pole.c");
		pole->move(me);
		add("pole_count", -1);
	}
	else
		message_vision("$N使劲把大石移开，却没有发现什麽东西。\n", me);

	add_action("do_fish", "fishing");
	return 1;
}
int do_fish()
{	object me = this_player();
	if (  !(present("fishing pole", me)) )
		return notify_fail( "没鱼杆钓什麽鱼？\n");
	if (me->is_busy())
		return notify_fail( "你正忙着呢。\n");

	message_vision("$N爬上山涧边的一块大石。掏出鱼杆，上了些鱼饵，开始钓起鱼来。\n", me);
	me->set_temp("fishing_time", 20);
	me->set_temp("learn_time", 0);
	me->set_temp("fish_caught", 0);
	me->start_busy((: fishing :), (: halt_fishing :));
	return 1;
}
int fishing(object me)
{	int check, level;
	int timeleft = (int) me->query_temp("fishing_time");
	int learned = (int) me->query_temp("learn_time");
	object fish;
	if (timeleft < 1)
	{	if (learned > 0)
		{	write("看着鱼儿在水里上下游动的样子，你突然领悟了招架方面的几个疑难。\n");
			me->improve_skill("parry", me->query("int") * (int) learned);
			message_vision("$N慢慢地站起来，脸上带着开心的笑容。\n", me);
		}
		else if ( (int)me->query_temp("fish_caught") > 0)
		{	message_vision("$N看着手中的鱼儿，满意地站了起来\n", me);
		}
		else
		{	message_vision("$N无聊地站了起来，喃喃地骂道：今天运气怎麽这麽烂。\n", me);
		}
		me->delete_temp("fishing_time");
		me->delete_temp("learn_time");
		me->delete_temp("fish_caught");
		return 0;
	}
	if ((int) me->query("kar") > random(500) )
	{	if ((int) me->query("kar") > random(1000) && (int)query("fish_count") == 1)
		{	set("fish_count", 0);
			fish = new(__DIR__ + "obj/fish1");
		}
		else
			fish = new(__DIR__ + "obj/fish");

		message_vision("$N手中的鱼杆突然动了起来。$N钓到了一条大鱼。\n", me);
		fish->move(me);
		me->set_temp("fishing_time", 0);
		me->set_temp("fish_caught", 1);
	}
	if ((int) me->query("int") > random(40) )
	{	level = (int) me->query_skill("parry", 1);
		check = level * level * level;
		if ((int) me->query("combat_exp") > check && (int)me->query_skill("parry", 1) <30)
		{	learned = learned + 1;
			me->set_temp("learn_time", learned);
		}
	}
	me->set_temp("fishing_time", (int)(timeleft - 1));
	return 1;
}
int halt_fishing(object me)
{	message_vision("$N无聊地站了起来，喃喃地骂道：今天运气这麽烂，不钓了。\n", me);
	return 1;
}
int valid_leave(object me, string dir)
{
	remove_action("do_fish", "fishing");
	return ::valid_leave(me, dir);
}
