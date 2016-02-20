//Cracked by Roath
// /d/shenlong/milin.c 密林
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "密林");
        set("long", @LONG
这是清源山区深处的一片密林。这儿林木茂盛，遮天蔽日，很容易
让人迷路。你似乎听到一阵“吱吱”叫声，想必是一群猴子在附近玩耍。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "northdown": "/d/quanzhou/wangzhou",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "quanzhou");
        set("cost", 2);
        setup();
}

void init()
{
        object me = this_player();

        if( interactive(me) && ! present("old monkey", this_object()) 
         && !random(2) && time() > (int)query("lastshow") + 600
         && (int)me->query("combat_exp") < 100000 ) {
                remove_call_out("monkeyshowup");
                call_out("monkeyshowup", 5 + random(5));
         }
}

void monkeyshowup()
{
        object ob;

        ob = new("/clone/beast/bmonkey");
        ob->move(this_object());
        set("lastshow", time());
        message_vision("只见一只老猴子大摇大摆地走了过来。\n", ob);

        remove_call_out("monkeydisappear");
        call_out("monkeydisappear", 20 + random(10), ob);
}

void monkeydisappear(object ob)
{
        if( !ob ) return;

        if( !living(ob) || ob->is_busy() || random(3) > 0 ) {
                remove_call_out("monkeydisappear");
                call_out("monkeydisappear", 5 + random(5), ob);
                return;
        }

        message("vision", "只见老猴子飞快地跳走了。\n", this_object());
        destruct(ob);
}
