//Cracked by Roath
// shizhu.c 石柱 
// by Fang 8/19/96
// modified by Ryu 6/15/97;
// xQin 8/00

inherit ROOM;

void create()
{
	set("short", "石柱");
	set("long", @LONG
这是南岩宫前的一根石柱，雕成龙形，自峭壁上横出，犹如飞龙在天。龙首
刻一香炉，在此上香称为“上龙头香”，是香客的最大心愿。石柱仅粗如屋梁，
旁无扶栏，前有白云缭绕，下有万丈深渊，稍一失足，即尸骨无存。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northup" : __DIR__"nanyanfeng",
	]));
	set("cost", 9);
	setup();
}
void init()
{
	add_action("do_mianbi","面壁");
        add_action("do_mianbi","mianbi");
}
int do_mianbi()
{
	object me, mengzhu, room;
	int shen, ep, gain;
	me = this_player();
	shen = me->query("shen");
	ep = me->query("combat_exp");

        if (me->is_busy()
        || me->query_temp("pending/exercising")
        || me->query_temp("exit_blocked"))
                return notify_fail("你现在正忙着呢。\n");

	if (me->query("jing") < 200 || me->query("jingli") < 200)
	return notify_fail("你觉得烦躁不安，难以聚精入定。\n");
	
        message_vision("$N面对着石柱跌坐静思，良久，似有所悟。\n", me);

	me->start_busy(8);
        me->set("jing",1);
	me->add("jingli", -200);

	if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");
        seteuid(getuid(me));
        if( !objectp(mengzhu = present("mengzhu", room)) ){
        mengzhu = new("/clone/npc/meng-zhu");
	mengzhu->move("/d/taishan/fengchan");
	}

        if (userp(me) && me->query("id") != mengzhu->query("winner") ){
        if (shen > 10000 && shen > ep){
	gain = (shen - ep) * 1000 / ep; 

	if (gain > 20) gain = 20;

	if (me->query("family/family_name") != "武当派") gain = gain/4;

	me->add("combat_exp", gain * 8 + random(gain*4));
	me->set("shen", me->query("combat_exp"));

	if (me->query("family/family_name") == "武当派")
	me->add("potential", gain * me->query_skill("taoism") / 25
	+ random(gain*me->query_skill("taoism")/60));

	if (me->query("potential") > me->query("max_potential"))
	me->set("potential", me->query("max_potential"));
	}
    }
        return 1;
}

