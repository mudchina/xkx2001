//Cracked by Roath
// Room: /d/xingxiu/yueerquan.c
// Jay 3.17/96

inherit ROOM;

void create()
{
        set("short", "月儿泉");
        set("long", @LONG
出乎你的意料之外，在沙漠中竟然有泉水。一泓清澈的泉水形成一个月牙
的形状，因而得名月儿泉。南面是一片峭壁(cliff)，东南边传来嗡嗡的声响。
LONG
        );
        set("resource/water", 1);

        set("exits", ([
		"east" : "/d/qilian/loulan",
        ]));

        set("item_desc", ([
                "cliff" : "一面十分陡悄的峭壁。\n"
        ]) );

	set("cost", 1);
        setup();
//        replace_program(ROOM);
/*}

void init()
{
        add_action("do_enter", "enter");
}
int do_enter(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="hole" ) {
                if ( me->query_encumbrance() * 100 / me->query_max_encumbrance() < 20) {
		                        message("vision",
me->name() + "一纵身跃进了洞里。\n",
                        environment(me), ({me}) );
                        me->move("/d/xingxiu/mogaoku");
                        message("vision",
me->name() + "从洞外跳了进来。\n",
                        environment(me), ({me}) );
                return 1;
                }
                else {
                        write("你身上背的东西太重，洞口又太高，你够不着。\n");
                        return 1;
                }
        }
*/
}

