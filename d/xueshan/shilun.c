//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "时伦院");
        set("long", @LONG
这里是供逢法器之处，空荡荡的大殿一尊白玉大如来像独立正中，
像前有一法案，上面铺了厚厚的黄绸，依次排了法轮、法杵、法铃等
物。
LONG
        );
        set("exits", ([
                "east" : __DIR__"jingang",
		"south" : __DIR__"sengshe",
        ]));
	set("objects",([
        "clone/weapon/fachu" : 1,
	"clone/weapon/faling" : 1,
	"/clone/weapon/falun" : 1,
        "/kungfu/class/xueshan/ling-zhi" : 1,
        ]));
	set("cost", 1);
        setup();
}
