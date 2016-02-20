//Cracked by Roath
// jiulao1.c 九老洞口
// Shan: 96/06/22

inherit ROOM;

void do_yell(string);

void create()
{
        set("short", "九老洞口");
        set("long", @LONG
九老洞在仙峰寺外。传说远古时候，有九位仙叟住在这个洞里，不知他们
生于何年，终于何年。轩辕皇帝访道于此，见一老叟，问曰：『有侣乎？』答
曰：『九人』。这就是九老洞的来历。这个洞很深，很少有人进去，只有些人
站在洞口谈笑呼叫（yell）。这里向西经九十九道拐到千佛庵，一路向北到莲
花石。
LONG
        );

        set("exits", ([
		"northeast" : __DIR__"dao96",
		"northwest" : __DIR__"lianhua",
		"enter" : __DIR__"jiulao2.c"
        ]));

        set("objects", ([
                "/d/emei/npc/monkey" : 3,
        ]));

	set("outdoors", "emei");

	set("cost", 2);
        setup();
//	replace_program(ROOM);
}

void init()
{
    add_action("do_yell", "yell");
}

int do_yell(string arg)
{
	object me = this_player();

	message_vision("$N站在洞口向里大叫：“" + arg + "”\n", me);
        message_vision("洞内传来一阵回声：“" + arg +
            "～～～" + arg + "～～～" + arg + "～～～”\n", me);

	if ( me->query("family/master_id") == "zhou zhiruo"   
        	&& (arg == "有侣乎？" || arg == "有侣乎" )) {
		remove_call_out("through_cave");
		call_out("through_cave", 4, me);
	}

	return 1;
}

int through_cave(object me)
{
	tell_room(environment(me),(string)me->query("name")+"向洞里走去，转眼就不见了。\n", me);
	tell_object(me, "\n忽然有个人拉住你，进了洞。你跟着那人在黑暗中左转右转，不久就出了洞。\n\n");
	me->move(__DIR__"jiulao_out");
    	return 1;
}


