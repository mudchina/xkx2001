//Cracked by Roath
// road: /zhongnan/shanlu30.c
// by sdong 08/98

inherit ROOM;
#include <ansi.h>
int do_climb(string arg);

void create()
{
                  set("short",HIC"悬崖"NOR);

                  set("long",@LONG
你眼前是一座悬崖，这悬崖高达数十丈，高耸接云，有些地方直如墙壁一般
陡峭，悬崖四面都是险岩怪石，无可攀援 (climb)。几只巨大的黑雕盘旋在空中。
此段小路两边都是杂草，看来走的人不多，四周的景色都越来越萧条，看来已经
快到沙漠了。往东南有一条小路，往西通往沙漠。
LONG);

                  set("exits",([ "west" : __DIR__"desert1",
                                                                "southeast" : __DIR__"shanlu29",
                                                  ])
                          );
          set("cost",4);
          set("outdoors", "zhongnan");
          setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me = this_player();
        int gain,cost;

        if(me->is_busy())
                return notify_fail("你还在忙着呢。\n");

        cost = ( 300-me->query_dex()*me->query_skill("dodge")/20 )/10;
        if ( cost<5 )cost = 5;

        if( me->query("jingli") < 30)
                return notify_fail("你累的实在爬不动了。\n");

        me->add("jingli",-cost);
        gain = me->query("con",1)*2;

        if ( me->query_skill("dodge") > 200 ) gain /= 2;



        if(arg == "up" )
        {
                message_vision( HIY"\n$N在悬崖上攀藤附葛，一步步地爬上去。\n"NOR, me);
                me->move("/d/zhongnan/xuanya1");
                message_vision( HIY"\n$N爬了上来。\n"NOR, me);
                me->start_busy( 1 );
                me->improve_skill( "dodge",gain+random( gain ) );
                if( me->query_skill( "jinyangong",1) > 0 )
                        me->improve_skill( "jinyangong",random( gain ) );
                return 1;
        }

        return notify_fail("那个方向没法爬。\n");
}
