//Cracked by Roath
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "冰洞");
	set("long", @LONG
进到冰洞里面，那洞顶上紧紧垂挂着冰锥(icicle)，长短不齐，
粗细不一；洞底下冰树丛生，千姿万态。穿行洞内，好似进了光怪
陆离的神话世界。洞顶有个窟窿似乎可以爬出去(out)。
LONG
	);
	set("exits", ([
                "east" : __DIR__"icecave1",
        ]));
	set("bing_can", 3);
	set("cost", 2);
	set("icicle", 100);

	setup();
}
void init()
{
        add_action("do_flick", "flick");
        add_action("do_flick", "tan");
	add_action("do_out", "out");
}
int do_flick(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" )
                return 0;

        if (me->query_busy())
                return notify_fail("你正忙着呢。\n");

	if (query("icicle") < 1)
		return notify_fail("这里的冰锥你都够不着了。\n");

	if ( (int)me->query("jing") < 30 || (int)me->query("jingli") < 30)
                return notify_fail("你的精神不能集中。\n");

        if( arg=="icicle")
        {
	me->receive_damage("jing", 15);	
	me->receive_damage("jingli", 15);
	add("icicle", -1);
        message_vision("$N轻轻地用手指弹断了一根冰锥。\n", me);
	if (random(me->query_skill("feixing-shu", 1)) > 30){
	me->improve_skill("feixing-shu", me->query("int"));
	message_vision("$N弹飞出去的冰锥撞断了另一根冰锥，乒乒乓乓乱响。\n", me);
	tell_object(me, "你似乎领悟了一层暗器的技能。\n");
	if (me->query_skill("feixing-shu", 1) > 100)
	me->receive_damage("jing", 15);
	if (me->query_skill("feixing-shu", 1) > 150)
        me->receive_damage("jing", 15);
	}
	if (query("icicle") < 1){
	remove_call_out("renew_up");
        call_out("renew_up", 300+random(200));
	}
	return 1;
	}
}
void renew_up()
{
	set("icicle", 100);
}
int do_out(string arg)
{
        object me;
	me = this_player();

	message_vision("$N攀上洞壁从窟窿里爬了出去，\n", me);
        me->move(__DIR__"shanluan");
	message("vision", me->name() + "水淋淋的不知从什么地方爬了上来。\n",
                    environment(me), ({me}) );
	return 1;
}
