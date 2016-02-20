//Cracked by Roath
// /d/huanghe/tccunko.c

inherit ROOM;

void create()
{
        set("short", "村口");
        set("long", @LONG
这里是黄河边红柳港外的一个小渔村的村口，原先还有不少渔民在此
打鱼为生。但这两年不知道为什麽一个个都不知去向，只剩下一个空空荡
荡的小村。整个渔村地处十分隐蔽，若不仔细寻找，很难被人发现。几个
满脸横肉的帮众正在来回巡逻。
LONG );

        set("exits", ([
		"south"  : __DIR__"tcxiaolu",
		"north"  : __DIR__"bank6",
        ]));

        set("objects",([
                __DIR__"npc/tc_wang" : 1,
                __DIR__"npc/tc_bangzhong" : 1,
        ]));

        set("cost", 1);
        set("outdoors", "huanghe");

        setup();
        replace_program(ROOM);
}
