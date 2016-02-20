//Cracked by Roath
//伙房 /d/shenlong/huofang
// ALN Sep / 97

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "伙房");
        set("long", @LONG
这里是神龙教的伙房，房子的一边是个灶炉，旁边有一个老头在往灶内添
柴，锅内不知煮着什么东西，不过香味已经让你馋得按捺不注了。
LONG
        );

        set("exits", ([
                "south" : __DIR__"shibanlu",
        ]));
        set("objects",([
                "/d/shenlong/obj/hongcha" : 3,
                "/d/shenlong/obj/shegeng" : 2,
        ]));
        set("cost", 1);

        setup();
}
