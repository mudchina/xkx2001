//Cracked by Roath
// houyuan.c 财主后院
//Jay 2/3/97

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
这里是翰林府的后院。院子里种了不少的各种奇花异草，不知道是什么原因，
花草中尤以各色菊花为多。院西是丫鬟的房间，东侧有一扇门(men)。凌翰林正在
院中练功。
LONG
        );
        set("item_desc", ([
                "men" : "这扇门后便是凌小姐的闺房。\n",
        ]));

        set("exits", ([
                "east" : __DIR__"dongxiang",
                "south" : __DIR__"dayuan1",
                "west" : __DIR__"xixiang",
        ]));
        set("objects", ([
                __DIR__"npc/tuisi" : 1,
        ]));

        set("cost", 0);
        setup();
}

void init()
{
        add_action("do_unlock", "unlock");
        if (present("ling tuisi", environment(this_player())))
                delete("exits/east");
}
int do_unlock(string arg)
{
        object ob;
        if (query("exits/east"))
                return notify_fail("这扇门已经是打开的。\n");
        if (!arg || (arg != "men" && arg != "east"))
                return notify_fail("你要打开什么？\n");
        if (!(ob = present("guifang key", this_player())))
                return notify_fail("你不会撬锁。\n");
        set("exits/east", __DIR__"dongxiang");
        message_vision("$N用一把钥匙打开房门，可是钥匙却断了。\n", this_player());
        destruct(ob);
        return 1;
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("ling tuisi", environment(me))) && 
                (dir == "west" || dir =="east"))
                return notify_fail("凌翰林挡住了你：请勿入内宅。\n");
        return ::valid_leave(me, dir);
}
