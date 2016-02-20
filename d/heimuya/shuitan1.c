//Cracked by Roath
// Room: /d/heimuya/shuitan1.c
// Date: fear 1999/12/08
#include <ansi.h>

inherit FERRY;

void create()
{
        object room;

        set("short", HIC"水滩南岸"NOR);
        set("long", @LONG
前面是一处水滩，水流湍急。水滩(river)衔接着
石道的尽头，岸边停放着有几艘小船。
LONG
    );

        set("exits", ([
                "south" : __DIR__"stonechannel2",
        ]));

        set("item_desc", ([
                "river" : "也许喊(yell)一声，水滩的船家就能听见。\n",
        ]));

        set("resource/water", 1);
        set("outdoors", "heimuya");
        set("cost", 2);

        set("name", "江");
        set("boat", __DIR__"xiaochuan");
        set("opposite", __DIR__"shuitan2");
    
        setup();
}
