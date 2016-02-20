//Cracked by Roath
// /d/wanshou/qianting.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "山庄前厅");
        set("long", @LONG
进了山庄大门便是前厅，前厅正中央的墙壁上悬挂着巨幅水
墨“老树腾猿”，画下厅正中摆着一把太师椅，上坐万寿山庄五
庄主--八手仙猿史孟捷。厅两侧两道游廊，左通膳堂，右至练功
房，前厅在过去就是正厅。
LONG
        );
        set("exits", ([
				"north" : __DIR__"zhenting",
				"south" : __DIR__"frontgate",
				"east" : __DIR__"liangongfang",
				"west" : __DIR__"kitchen",
        ]));

	    set("cost", 0);
        setup();
        replace_program(ROOM);

}
