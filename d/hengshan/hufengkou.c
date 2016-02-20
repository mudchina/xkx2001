//Cracked by Roath
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "虎风口");
        set("long", 
"走到虎风口山路山路陡然变陡变窄，路一侧为悬崖峭壁，
令一侧则是无底深渊，凛冽山风呼啸吹过，令人遍体生寒，
站立不稳。悬根于峰侧峭壁上一棵千年古松，迎风招展，便
是所谓“虎口悬松”。北上就是无色庵所在。\n"
        );
        set("exits", ([
                "southdown"  : __DIR__"chuyundong",
                "northup"  : __DIR__"wusean",
]));
        set("no_clean_up", 0);
        set("outdoors", "hengshan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

