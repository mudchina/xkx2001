//Cracked by Roath
// 山溪 /d/shenlong/shanxi
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山溪");
        set("long", @LONG
沿山溪而行，溪水淙淙，草木清新，颇感心旷神怡。往北是山路，向南
眺望，便是一望无际的大海。
LONG
        );
        set("outdoors", "shenlong");
	set("exits", ([
		"northwest" : __DIR__"shanlu1",
        ]));

	set("cost", 5);

        set("snaketype", ({"shuishe"}));

	setup();
}

#include "/d/shenlong/snakeroom.h"

