//Cracked by Roath
// woyun.c 卧云庵
// Shan: 96/06/25

inherit ROOM;

void create()
{
        set("short", "卧云庵");
	set("long", @LONG
卧云庵旁边有个井络泉，据说以前曾因饮水人多而干涸，众尼为之诵经，于
是泉水复出。出了卧云庵便是睹光台，旁边是华藏庵。
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"jinding",
		"southeast" : __DIR__"huazang",
		"out" : __DIR__"duguang2",
	]));

        set("resource/water", 1);

        set("objects", ([
                "/kungfu/class/emei/jingxuan.c" :1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 1);
	setup();
//	replace_program(ROOM);
}

void init()
{
        add_action("do_song", "song");
        add_action("do_song", "read");
}

int do_song(string arg)
{
        object me = this_player();
        int level, check;
        object ob;

        level = (int)me->query_skill("linji-zhuang",1);
        check = level*level*level;

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if( me->is_fighting() )
                return notify_fail("你无法在战斗中专心下来研读新知！\n");

	if (!arg || arg != "jing" || !objectp(ob = present("maha jing", me)) )
                return notify_fail("你要念什么？\n");

        if( !me->query_skill("literate", 1) )
                return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	if( me->query("jing") < 100)
		me->unconcious();
	
	me->receive_damage("jing",100, "诵经时精神不集中，昏死");

	message_vision("$N虔诚地在井边诵经。\n", me);

        if ( level >= 100  && check < (int)me->query("combat_exp")*10 
	&& SKILL_D("linji-zhuang")->valid_learn(me) )
                me->improve_skill("linji-zhuang", 1);

        return 1;

}
