//Cracked by Roath
// zhandao1.c 黑龙江栈道
// by Shan

inherit ROOM;

void create()
{
        set("short", "黑龙江栈道");
	set("long", @LONG
黑龙江栈道沿黑龙江而建。这里一山中开，两崖并立，形成一道宽仅数尺，
长达几百米的深峡——白云峡。黑龙江栈道就从狭窄的白云峡中转折穿过，架
设在绝壁上。走在栈道上，只觉道窄人危；俯视深涧，急流飞旋，山静而觉动；
仰观头顶，天光如隙，崖开而欲合。这就是天开画图的「一线天」。栈道南通
千佛庵，北至清音阁。
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"qingyin",
		"south" : __DIR__"zhandao2",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 5);
	setup();
//	replace_program(ROOM);

}

int valid_leave(object me, string dir)
{
	if ( me->query_weight() >= 70000 && dir == "south") {
		tell_object(me, "你太胖了，费了老半天劲也挤不过这一线天，反而擦破了皮。\n");
		me->receive_wound("qi", 5, me);
		return notify_fail("");
	}
	if ( me->query_encumbrance() >= 100000 && dir == "south") {
        	tell_object(me, "你身上东西带了太多，费了老半天劲也挤不过这一线天，看来得丢掉一些。\n");
        	return notify_fail("");
	}

	return ::valid_leave(me, dir);
}

