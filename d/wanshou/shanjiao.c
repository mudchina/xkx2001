//Cracked by Roath
// /d/wanshou/shanjiao.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "山脚下");
        set("long", @LONG
青石小径到这里就中断了，眼前是一片阴森的树林，树林深处
隐隐传来猿啼虎啸之声，让人不寒而栗，几只小猴子在林边嬉戏着，
看见生人到来，嗖地一下窜进林中不见了。
LONG
        );
        set("exits", ([
				"south" : __DIR__"xiaojing",
                "northup" : __DIR__"forest0",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();
        replace_program(ROOM);

}
