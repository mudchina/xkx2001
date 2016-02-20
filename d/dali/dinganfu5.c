//Cracked by Roath
// Room: /d/dali/dinganfu5.c

inherit ROOM;

int serve();

void create()
{
	set("short", "伙房");
	set("long", @LONG
这里是官宅的伙房，专为住在这里的官员们提供伙食(serve)。一群身着军
服的官员正围着桌子就餐，品尝大理特产的菜肴。官员们在这里可以不受限制地
吃喝要菜，但不许把食物带出厨房。
LONG);
	set("exits", ([
		"north" : __DIR__"dinganfu2",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
}
void init()
{
	add_action("do_serve", "serve");
}
int do_serve()
{
	object ob,me;
	me=this_player();

	message_vision("$N向厨子要些食物吃喝。\n", me);

	if (me->query("family/family_name") != "大理段家"
		&& !me->query("dali/employee")) return 1;

	if (!present("guoqiao mixian", environment(me))
		&& !present("guoqiao heiyu", environment(me))
		&& !present("ye er ba", environment(me))
		&& !present("guoqiao mixian", me)
		&& !present("guoqiao heiyu", me)
		&& !present("ye er ba", me))
	{
		switch(random(3))
		{
			case 0:
				ob=new(__DIR__"obj/mixian");
				break;
			case 1:
				ob=new(__DIR__"obj/guoqiao");
				break;
			case 2:
				ob=new(__DIR__"obj/yeerba");
				break;
		}    
		ob->move(environment(me));
		message_vision("厨子端出"+ob->name()+"给$N。“您慢慢吃，不够还有。”\n", me);
	}
	else message_vision("厨子对$N说道：你不是有东西吃吗，吃完再说吧。\n", me);
	
	if (!present("puer cha", environment(me))
		&& !present("qiguo ji", environment(me))
		&& !present("qiguo ji", me)
		&& !present("puer cha", me))
	{
		switch(random(2))
		{
			case 0:
				ob=new(__DIR__"obj/qiguoji");
				break;
			case 1:
				ob=new(__DIR__"obj/puercha");
				break;
		}
		ob->move(environment(me));
		message_vision("厨子端出"+ob->name()+"给$N。“您慢慢喝，不够还有。”\n", me);
	}
	else message_vision("厨子对$N说道：你不是有东西喝吗？喝完再说吧。\n", me);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (present("guoqiao mixian", me)
		|| present("guoqiao heiyu", me)
		|| present("qiguo ji", me)
		|| present("ye er ba", me)
		|| present("puer cha", me))
		return notify_fail("厨子拦着你说：“您还是吃完再走吧。”\n");
	return ::valid_leave(me, dir);
}
