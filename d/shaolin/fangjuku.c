//Cracked by Roath
// Room: /d/shaolin/fangjuku.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "防具库");
	set("long", @LONG
这是一间很大的房间，靠墙整齐地放着一个个大柜子，不少
柜子门敞开着，露出里面的各种防具，品种之多，是你生平仅见。
一位灰衣僧人正埋头整理一堆破损的护具。连你进来也没有注意。
LONG
	);

	set("exits", ([
		"north" : __DIR__"yaopinku",
		"south" : __DIR__"wuqiku",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/dao-xiang" : 1,
	]));
	set("cost", 1);
	setup();
//	replace_program(ROOM);
}

void init()
{
        add_action("do_kill", "kill");
}

int do_kill(string arg)
{
        object ob, me=this_player();

        if ( arg == "daoxiang chanshi" || arg == "daoxiang" || arg == "chanshi" ) {
		if ( !ob=present(arg, environment(me)) ) return 0;

		message_vision("$N对著$n喝道：「死秃驴！今日不是你死就是我活！」\n", me, ob);
		me->kill_ob(ob);

		message_vision("$N一声冷笑，伸手在墙上一按，地上突然裂开一个大洞，$n意料之余跌了下去！\n", ob, me);
		me->move("/d/shaolin/jianyu.c");
		tell_object(me,"你跌入陷阱，直落到少林寺的监狱里！\n");

                return 1;
        }

        return 0;
}

