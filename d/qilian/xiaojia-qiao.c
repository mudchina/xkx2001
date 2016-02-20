//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "萧家桥");
        set("long", @LONG
在兰州和古浪中间，纪永河水咆哮而过。河水湍激，河床最宽处九丈四尺，
窄处也有七丈余，渡船难过。相传在汉代时，本地一位萧姓大财主，穷六年之
功，遍集巧匠，费尽家私，方建成桥。欲到兰州，必先过本桥。
LONG
        );
        set("exits", ([
                "east" : __DIR__"gulang",
                "southwest" : __DIR__"lanzhou-beimen",
        ]));


	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
