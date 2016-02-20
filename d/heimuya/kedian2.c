//Cracked by Roath
// Room: /d/heimuya/kedian2.c
// fear 1999/12/08 

inherit ROOM;

void create()
{
        set("short", "客店二楼");
        set("long", @LONG
你正走在客店二楼的走廊上，可以听到从客房里不
时地呼呼的打酣声，一阵高过一阵。不时有睡意朦胧的
旅客进进出出，到楼下的掌柜处付了钱再上来睡觉。
LONG
        );

        set("exits", ([
                "down" : __DIR__"kedian",
                "enter" : __DIR__"kedian3",
        ]));

        set("cost", 1);
        setup();
//      replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
       if(me == present("xiao er"))
                return ::valid_leave(me, dir);
                               
        if ( !me->query_temp("rent_paid") && dir == "enter" )
                return notify_fail("门锁着呐，进不去! \n");

        return ::valid_leave(me, dir);
}
