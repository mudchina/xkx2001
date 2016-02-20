//Cracked by Roath
// /d/huanghe/tctongdao.c

#define TIECHA "/d/huanghe/obj/tiecha"

inherit ROOM;

void create()
{
        set("short", "通道");
        set("long", @LONG
一条长长的通道，甬道墙上点着牛油巨烛，走出数丈，便即转弯。整个通
道一片寂静，显得十分阴森可怖。几个帮众正在来回巡逻。
LONG );

        set("exits", ([
		"up"    : __DIR__"tckitchen",
		"north" : __DIR__"tcdating",
        ]));

    	set("cost", 1);

        set("objects",([
               __DIR__"npc/tc_bangzhong" : 1,
        ]));


        setup();

        // replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object ob, obj;

        if( dir != "north" )
                return ::valid_leave(me, dir);

        if( !(ob = present("tiecha bangzhong", environment(me))) )
                return ::valid_leave(me, dir);

        if( !living(ob) )
                return ::valid_leave(me, dir);

        if( me->query_temp("bangs/fam") == "铁叉帮"
        ||  me->query("fam") == "铁叉帮" )
                return ::valid_leave(me, dir);

        if( (obj = present("tie cha", me)) ) {
                message("vision", "帮众说道：是王老六介绍来的吗，请进请进。\n", this_object());
                destruct(obj);
                return ::valid_leave(me, dir);
        }

        message_vision("$N拦在$n面前，说道：里面是本帮重地，想找死吗。\n", ob, me);
        return notify_fail("");
}

