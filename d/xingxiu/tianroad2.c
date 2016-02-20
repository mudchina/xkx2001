//Cracked by Roath
// room: /d/xingxiu/tianroad1.c
// Jay 3/18/96
// Ryu 5/10/97

inherit ROOM;

void create()
{
        set("short", "银山道");
        set("long", @LONG
北侧干枯的河床中，有芦苇、红柳和一些低矮的小灌木，还有一汪
不动的死水。此外便是干沙、泥沼。河滩中的石头和多年败草的枝叶上，
挂着一层白霜，好象寒冬腊月草木上结的淞花。天低野阔，了然无物。
LONG
        );
        set("exits", ([
            "northdown" : __DIR__"xxh1",
            "southdown" : __DIR__"gangou2",
            "west" : __DIR__"lithouse",
]));
        set("objects", ([
                "/kungfu/class/xingxiu/shihou" : 1,
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
        ]));
        set("resource/grass", 1);
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("cost", 3);
        setup();
//      replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "星宿派") && dir != "southdown" && me->query("id")!="shu"
                 && (present("shihou zi", environment(me)))) {
                say("狮吼子一言不发，闪身拦在"+me->name()+"面前。\n");
                return notify_fail("狮吼子一言不发，闪身拦在你面前。\n");
        }
        return ::valid_leave(me, dir);
}
