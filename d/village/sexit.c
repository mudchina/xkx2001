//Cracked by Roath
// Room: /d/village/sexit.c

inherit ROOM;

void create()
{
        set("short", "南村口");
        set("long", @LONG
这里是华山脚下，虽然远离县城，却没有什么山贼草寇在附近出没。西面是
一个小村庄，看来村子里人家不多，村民们过着日出而作，日落而息的宁静生活。
穿过这个小村子，就是上华山的山路了。
LONG
        );

        set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"sroad1",
        "south" : __DIR__"hsroad3",
]));
        
        set("objects", ([ __DIR__"npc/dog": 1,
                 ]) );
        set("no_clean_up", 0);
        set("outdoors", "village" );

        set("cost", 1);
        setup();
//      replace_program(ROOM);
}

void init()
{
        object me = this_player();

        if ( interactive(me) && me->query("huashan/job_pending") ) {
                me->set_temp("hz_job/sexit", 1);
        }
}

int valid_leave(object me, string dir)
{
    if ( dir == "south" && me->query_condition("hz_job") )
           return notify_fail("你身负巡山任务，不能轻离职守！\n");

    return ::valid_leave(me, dir);
}
