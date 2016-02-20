//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "经堂");
        set("long", @LONG
俗称大经堂，可容纳四千余人。经堂正中设有活佛和寺院总法台的法座，
法座两侧贡奉着宗喀巴、八大圣者、和各代嘉木大师像。殿内满挂五彩缤纷的
帜幡，宝盖，四周的木柱上裹着色彩绚丽的毡毯。
LONG
        );
        set("exits", ([
                "east" : __DIR__"yanwu",
                "north" : __DIR__"sengshe",
        ]));
	set("objects",([
        "d/qilian/obj/fojing1" : 1,
        ]));

	set("cost", 0);
        setup();
        replace_program(ROOM);
}

