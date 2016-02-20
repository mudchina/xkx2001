//Cracked by Roath
//东厢房(仙福居) /d/shenlong/xianfuju

// ywz 09/25/96 /d/shenlong/xianfuju.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

void init()
{
        add_action("do_get", "get");
}

void create()
{
	set("short", "仙福居");
        set("long", @LONG
神龙教的仙福居，虽说是厢房，却也十分宽敞，陈设雅洁，桌上架上摆满
了金玉古玩，壁上悬着字画，床上被褥华美，居然有点皇宫中的派头。你真想
躺在床上美美地睡上它一觉。
LONG
        );
        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_steal", 1);

        set("exits", ([
                "north" : __DIR__"shibanlu",
        ]));
	set("cost", 1);

        setup();
//  	replace_program(ROOM);
}

int do_get(string arg)
{
        object obj;

        if( arg
        && objectp(obj = present(arg, environment(this_player())))
        && obj->is_character() ) {
                write("你不能搬动玩家的身体。\n");
                return 1;
        }
        else
                return 0;
}
/*
int valid_leave(object me, string dir)
{
        object room;

        if ( !::valid_leave(me, dir) )
                return 0;

        if(!(room = find_object(__FILE__)) )
                room = load_object(__FILE__);
        if(objectp(room))
        {
                room->add_temp("person_inside", -1);
                if ((int)room->add_temp("person_inside", -1) <= 0)
                        room->delete_temp("person_inside");
        }

        return 1;
}
*/
