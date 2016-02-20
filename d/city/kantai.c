//Cracked by Roath
// 看台

#include <ansi.h>
inherit ROOM;
int do_practice(string arg);
int do_study(string arg);

void create()
{
        set("short", HIG"看台"NOR);
        set("long",
"这里是临时搭起的比武看台。四面层层叠叠的搭起了一排排长凳，中间一
大块空地，立起了一座擂台。地下插了一面锦旗，白底红花，绣着“"+HIR"比武招亲"NOR+"”
四个金字，旗下两人正自拳来脚去的打得热闹，整个看台被挤得水泄不通，彩声
一阵高过一阵。\n"
        );

        set("valid_startroom", 1);

        set("no_fight", 1);
        set("no_practice", 1);

        set("exits", ([
                "up" : __DIR__"leitai",
                "north": "/d/city/yuelao",
        ]));

        set("objects", ([
                 "/d/city/obj/tulip" : 2,
                __DIR__"npc/mu":1,
        ]));

        setup();
        "/clone/board/broker_b"->foo();
        //      replace_program(ROOM);
}

void init()
{
                  add_action("do_practice",  "practice");
                  add_action("do_practice",  "lian");
                  add_action("do_study",  "study");
                  add_action("do_study",  "du");
}

int valid_leave(object me, string dir)
{
        if( dir=="up" ) {
                if( wizardp(me) || me->query_temp("organizer") ) return 1;
                else return notify_fail("你不能自己上去。\n");
        }

        if( dir=="north" ) {
                if( wizardp(me) || (!me->query_temp("admitted") && !me->query_temp("zhaoqing"))
                  ) return 1;
                else
                {
                        if( me->query_temp("zhaoqing") )
                        {
                                return notify_fail("你是女主人,现在不能离开。\n");
                        }
                        else return notify_fail("你是选手,现在不能离开。\n");
                }
        }

        if( dir=="enter" ) {
                if( wizardp(me) ) return 1;
                else return notify_fail("你不能进去。\n");
        }

        return ::valid_leave(me, dir);

}


int do_practice(string arg)
{
                  object me = this_player();
                  tell_object(me, "这里不准练功!\n");
                  return 1;
}

int do_study(string arg)
{
                  object me = this_player();
                  tell_object(me, "这里不准读书!\n");
        return 1;
}

