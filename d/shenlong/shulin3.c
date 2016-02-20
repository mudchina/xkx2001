//Cracked by Roath
// /d/shenlong/shulin3.c
// ALN Sep / 97

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "小树林");
        set("long", @LONG
这儿是一片小树林，树林中间有一小块空地。空地上除了坑哇
以外还堆了一些不同大小的石块，这些石块表面都比较光滑似乎是
人力所为。你一抬头发现空地四周的树干上都没了树皮。
LONG );

        set("exits", ([
        "southeast" : __DIR__"luanshi",
        ]));

        set("outdoors", "shenlong");
        set("cost", 2);

        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_kick", "kick");
        add_action("do_kick", "ti");
        add_action("do_pick", "take");
        add_action("do_pick", "pick");
}

int do_pick(string arg)
{
        object me = this_player();

        if( !arg || !(arg == "shikuai" || arg == "shitou") )
                return notify_fail("什么？\n");

        if( me->query_temp("sg/leg") > 1 )
                return notify_fail("你腿上绑不下那么多石块。\n");

        me->add("jingli", (int)200 / (1 + me->query_str()));
        if( random(me->query_temp("sg/shikuai")) < 3 ) {
                message_vision("$N捡起一块石头，掂了掂份量，摇了摇头，便扔在地上。\n", me);
                me->add_temp("sg/shikuai", 1);
                return 1;}

        me->delete_temp("sg/shikuai");
        if( !me->query_temp("sg/leg") ) {
                message_vision("$N捡起一块石头，掂了掂份量，便把它绑在右腿上。\n", me);
                me->add_temp("sg/leg", 1);
                me->add_temp("apply/dodge", -10);
                return 1;}

        if( me->query_temp("sg/leg") > 0 ) {
                message_vision("$N捡起一块石头，掂了掂份量，便把它绑在左腿上。\n", me);
                me->add_temp("apply/dodge", -10);
                me->add_temp("sg/leg", 1);}

        return 1;
}

int do_kick(string arg)
{
        object me = this_player();

        if( !arg || !(arg == "tree" || arg == "shu") )
                return notify_fail("什么？\n");

        message_vision("$N腾空而起双腿踢向周围树干。\n", me);

        me->receive_damage("jing", 15, "心力绞瘁死了");
        me->receive_damage("jingli", 25, "力尽而死");
        me->improve_skill("kick", random(me->query_int()));

        if( me->query_temp("sg/leg") == 2 ) {
                me->receive_damage("jing", 10, "心力绞瘁死了");
                me->receive_damage("jingli", 20, "力尽而死");
                me->improve_skill("dodge", random(me->query_int()));
                return 1;}

        if( me->query_temp("sg/leg") == 1 ) {
                me->receive_damage("jing", 8, "心力绞瘁死了");
                me->receive_damage("jingli", 16, "力尽而死");
                me->improve_skill("dodge", random(me->query_int() / 2));
                return 1;}
                
        me->improve_skill("dodge", random(me->query_int() / 5));
        return 1;
}

int valid_leave(object me, string dir)
{
        if( me->query_temp("sg/leg") ) {
                me->add_temp("apply/dodge", me->query_temp("sg/leg") * 10 );
                message_vision("$N松了绑，将腿上的石块扔在一边。\n", me);
                me->delete_temp("sg/leg");
                me->start_busy(1);}

        return ::valid_leave(me, dir);
}



