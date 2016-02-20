//Cracked by Roath
// Room: /u/qfy/quanzhou/qingyuan.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "清源洞");
	set("long", @LONG
从虎乳泉往上，就看到一个山门，门上刻着「第一洞天」四个字。门后有
一观空楼，楼宇尽处便是一洞曰「蜕岩」，即清源洞。相传南宋绍兴有一道人
裴姓者追赶一条伤害生灵的大蛇到了这里，那蛇妖钻入石洞中，裴道人索性就
在洞口上坐化了，因而又名「裴仙洞」。据闻此洞深不可测，可通至洛阳江。
LONG
	);

	set("outdoors", "quanzhou");

	set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"shanlu1",
		"southdown" : __DIR__"huru",
		"westup" : __DIR__"nantai",
	]));

	set("no_clean_up", 0);

	set("mang", 1);

	set("cost", 1);
	setup();
}

void init()
{
	object mang, me = this_player();

	if ( random(me->query("PKS")) > 50 && query("mang") >= 1
	&& random( me->query_kar() ) < 2 ) {
		message_vision(HIR"突然间「沙沙」之声大作，一条丑恶的巨蟒带着一阵腥风由洞口扑向$N！\n"NOR, me);
		mang = new(__DIR__"npc/jumang");
        	mang->move(environment(me));
		remove_call_out("mang_attack");
		call_out("mang_attack", 1, me, mang);
		add("mang", -1);
		me->set_temp("mang", 1);
	}
}

int mang_attack(object me, object mang)
{
        mang->kill_ob(me);
        me->kill_ob(mang);
	remove_call_out("observe");
	call_out("observe", 1, me, mang);

	return 1;
}

int valid_leave(object me, string dir)
{
	object mang;

	if ( me->query_temp("mang") && objectp(mang = present("ju mang", environment(me))) ) {
		if ( living(mang) )
			return notify_fail("巨蟒游上来向你发动攻击，你无法抽身逃走！\n");
		else  
			return notify_fail("巨蟒虽已昏了过去，但仍紧紧地缠在你身上，你无法脱身！\n");
	}

	if ( present("ju mang", me) )
		return notify_fail("巨蟒太大太重了，你虽扛得起来，但却带不动它！\n");

	me->delete_temp("mang");

	return ::valid_leave(me, dir);
}

int observe(object me, object mang)
{
	object corpse;

	if ( !me->is_ghost() && !present("ju mang", environment(me)) ) return 1;

	if ( me->is_ghost() ) {
		message_vision("$N张开血盆大口，慢慢地将尸体吐下肚去，接着便游回洞里去了。\n", mang);
		if ( objectp(corpse=present("corpse", environment(mang))) ) destruct(corpse);
		destruct(mang);
		return 1;
	}

	remove_call_out("observe");
	call_out("observe", 1, me, mang);
	return 1;
}
