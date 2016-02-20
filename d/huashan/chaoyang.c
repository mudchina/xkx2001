//Cracked by Roath
// chaoyang.c

inherit ROOM;

void create()
{
	set("short", "朝阳峰");
	set("long", @LONG
这里就是华山的东峰—朝阳峰，於此俯瞰，黄河隐显东迤如带，南望
小孤峰背倚山河。东壁悬崖上，更有一个巨型掌印，相传为「河神巨灵」
劈山时所留下的。一旁有几棵大树。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		  "westdown" : __DIR__"zhenyue",
	]));

	set("no_clean_up", 1);
	set("outdoors", "huashan");

	set("tian_count", 1);

	set("cost", 5);
	setup();
}

void init()
{
	object me = this_player();

   	if ( interactive(me) && me->query("huashan/job_pending") ) {
		me->set_temp("hz_job/chaoyang", 1);
  	}

	add_action("do_shout", "shout");
	add_action("do_shout", "hu");
	add_action("do_shout", "jiao");
	add_action("do_gofeng", "feng");
}

int do_gofeng()
{
	object me = this_player();

	if ( me->query("family/master_name") != "风清扬" )
		return notify_fail("什么？\n");

	message_vision("$N快步奔下后山的丛林里。\n", me);
	me->move("/d/huashan/xiaojing1");

	return 1;
}


int do_shout(string arg)
{
	object ob, me = this_player();

	if( !arg || arg=="" ) return 0;

	message_vision("$N高声叫道："+arg+"。\n", me);

	if( ( arg == "风清扬前辈" || arg == "风前辈" || arg == "风老前辈" ) 
	&& query("tian_count") >= 1 && me->query_temp("marks/见") == 1
	&& !present("tian boguang", environment(me)) ) {
	    add("call_times", 1);

	    if( (int)query("call_times") == 3 ) {
		message_vision("只听得身旁的树上传来一阵唠骚：谁要找风老前辈啊？\n", me);
		message_vision("接着一个微醉的大汉从树上爬了下来，盯着你看了一会儿。\n", me);
		add("tian_count", -1);
		ob = new(__DIR__"npc/boguang.c");
		ob->move(environment(me));
		delete("call_times");
	    }

	}

	return 1;
}

void reset()
{
	::reset();
	delete("call_times");
}
