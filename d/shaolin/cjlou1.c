//Cracked by Roath
// Room: /d/shaolin/cjlou1.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "藏经阁二楼");
	set("long", @LONG
千余年来少林寺执中原武林之牛耳，自达摩老祖以下，历代
人材辈出。其中有不少高僧遗著留存，汇集至今，终成名震天下
的少林七十二绝艺。少林精华，尽集于此。二楼四面开窗，确保
通风。中间排列着五排大书架。四周则陈列矮几，以供阅读。几
位老僧手执经卷，正在闭目凝思。
LONG
	);

	set("exits", ([
		"down" : __DIR__"cjlou",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/hui-zhen" : 1,
		"d/shaolin/obj/wuji1" : 1,
		"d/shaolin/obj/wuji2" : 1,
		"d/shaolin/obj/wuji3" : 1,
	]));
	set("cost", 2);
	setup();
}

void init()
{
	add_action("do_hit","hit");
}

int do_hit(string arg)
{
	object ob, me = this_player();

	if ( arg == "huizhen" || arg == "zunzhe" || arg == "huizhen zunzhe" ) {
		ob = present("huizhen zunzhe", environment(me));
		ob->kill_ob(me);
		me->fight_ob(ob);
		tell_object(me,"你突然天旋地转，冥冥中似乎有股力量在操纵你的命运!\n");
        	me->unconcious();
	
		return 1;
	}

	return 0;
}

int valid_leave(object me, string dir)
{
	object *inv, obj;
	int i, found = 0;

	inv = all_inventory(me);
	for (i=0; i<sizeof(inv); i++) {
                if ( inv[i]->is_container() && present("shaolin wuji", inv[i]) ) found = 1;
		if ( inv[i]->is_character() ) {
			if ( present("shaolin wuji", inv[i]) ) found = 1;
			if ( obj=present("bu dai", inv[i]) && present("shaolin wuji", obj) ) found = 1;
		}
	}

	if ( present("huizhen zunzhe", environment(me)) && (present("shaolin wuji", me) || found) )
	{
		if (dir == "down" )
		{
			return notify_fail("慧真说道: 武功秘籍只许在藏经阁内研习，不得携带外出 !\n");
		}
	}

	if ( present("huizhen zunzhe",me) )
		return notify_fail("哎哟！犯不着拐带大和尚吧？\n");

	return ::valid_leave(me, dir);
}
