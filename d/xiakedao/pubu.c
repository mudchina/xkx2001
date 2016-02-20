//Cracked by Roath
// xiakedao/pubu.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "瀑布");
        set("long", @LONG
山路的尽头，迎面是一道瀑布(fall)从十余丈的高处直挂下来。
飞流而下的水柱击打着瀑布下的小潭，发出震耳欲聋的响声。小潭旁
有一棵大树(tree)。
LONG );

      set("exits", ([
		     "southdown" : __DIR__"wanghait",
      ]));

	set("item_desc",([
	    "fall" : "瀑布後面好像有个洞，你可以跳(jump)进去看看。\n",
	    "tree" : "这是一株百年老松，树上挂着些油布雨衣。太高你拿不着。\n",
	]));
	set("objects", ([ 
	    __DIR__ + "npc/master2" : 1,
      ]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	set("pole_count", 3);
	setup();
}

void init()
{
        ::init();

	add_action("do_jump", "jump");
	add_action("do_climb", "climb");
}

int do_jump(string arg)
{	object me = this_player();
	object coat;

	if ( (!arg )|| ((arg != "fall") && (arg != "tree")))
	{	write("往哪跳？(jump tree)\n");
		return 1;
	}
	if( (arg == "tree") )
	{	message_vision("$N使劲往上一跳，还是拿不到挂在树上的雨衣。试试爬(climb)树吧。\n", me);
		return 1;
	}
	if (!present("rain coat", me))
	{	write("水那麽大，你还是找件雨衣吧。\n");
		return 1;
	}
	coat = present("rain coat", me);
	if  (coat->query("equipped") == 0)
	{	write("水那麽大，你还是把雨衣穿上吧。\n");
		return 1;
	}
	else
	{	message_vision("$N走近瀑布，纵身跃了进去。\n", me);
		me->move(__DIR__"yongdao1");
		message("vision", me->name() + "纵身跳了进来。\n",environment(me), ({me}) );
	}

	return 1;
}
int do_climb(string arg)
{	object coat, me = this_player();

	if ( (!arg ) || (arg != "tree") )
		return 0;

	if (!(present("rain coat", me)) || !(present("rain coat", environment(me))))
	{	message_vision("$N爬上树，从树上拿下一件雨衣。\n", me);
		coat = new(__DIR__+ "obj/coat.c");
		coat->move(me);
	}
	else
		write ("这麽贪心，有了还拿。\n");

	return 1;
}
