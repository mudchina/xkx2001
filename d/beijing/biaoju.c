//Cracked by Roath
// Room: biaoju 镖局大院
// Ssy

inherit ROOM;

void create()
{
        set("short", "镖局大院");
        set("long", @LONG
这里是武胜镖局的大院，青石地面上一尘不染，院内种了不少花草，一片幽
静的气象，与院外的嘈杂形成鲜明的对比。武胜镖局的总镖头，人称「金枪无敌」
的王武通就经常在院内处理镖局事务。
LONG
        );

        set("exits", ([
                "south" : __DIR__"wusheng",
        ]));

        set("objects", ([
                __DIR__"npc/wangwutong" : 1,
        ]));

        set("cost", 0);
        setup();
        replace_program(ROOM);
}

