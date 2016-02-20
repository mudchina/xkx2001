//Cracked by Roath
// Room: /d/emei/meihua2.c

inherit ROOM;

void create()
{
	set("short", "古德林");
	set("long", @LONG
这是一片密密的楠木林，株株秀挺俊拔，枝叶分披上捧，如两手拥佛，据
说有七万株之多，要是不熟悉地形很容易迷路。林中有一片空地，几只楠木桩
排成梅花模样。
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"meihua"+(random(7)+1),
		"northeast" : __DIR__"meihua"+(random(7)+1),
		"southeast" : __DIR__"meihua"+(random(7)+1),
		"southwest" : __DIR__"meihua3",
	]));

	set("outdoors", "emei");
	set("cost", 3);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me = this_player();
        if ( !arg || (arg != "梅花桩" && arg != "down")) return command("jump "+arg);
        if ( me->query_temp("meihua/on") )
                if ( arg == "down" ) {
                        me->delete_temp("meihua/on");
                        message_vision("$N一个空翻从桩上跳下，稳稳地站在地上。\n", me);
                        return 1;
                } else
                        return notify_fail("你已经站在梅花桩上了，再乱跳小心摔下去。\n");
        if ( arg == "down" ) return command("jump down");
        if ( me->query_skill("dodge", 1) < 30 ) {
                message_vision("$N一纵身，想要跳上梅花桩，结果跳的不够高，摔了个大跟头。\n", me);
                me->receive_wound("qi", 20, me);
                return 0;
        } else
                message_vision("$N一纵身，跳上梅花桩。\n", me);
        me->set_temp("meihua/on", 1);
        return 1;
}

int valid_leave(object me, string dir)
{
	if (dir == "southwest" ) me->add_temp("meihua/count", 1);
	else 			 me->add_temp("meihua/count", -1);

	return ::valid_leave(me, dir);
}


