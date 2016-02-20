//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "嘉峪关");
        set("long", @LONG
这是长城最西的关隘。岁月沧桑，仍掩不住它的风采。群山环抱之，更显它
的雄浑。由于西域安定，久无战事，边关守军已大为减少。一条大道向东延伸通
向中原。出关向西，过了丹山，便是著名的“丝绸之路”。
LONG
        );
        set("exits", ([
                "west" : __DIR__"danshan",
                "northeast" : __DIR__"yumen",
                "east" : __DIR__"tanglang",
		"southwest" : __DIR__"shalu",
        ]));

        set("objects", ([
		"/d/xingxiu/npc/wujiang" : 1,
		"/d/xingxiu/npc/bing" : 1,
	]));
	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
