//Cracked by Roath
// room: /mingjiao/badake.c

inherit ROOM;

void create()
{
        set("short", "巴达克山");
        set("long", @LONG
这里地势险峻异常，已是极高山峰处的危崖峭壁。脚下无甚连贯道路，
必需或近或远地跳跃前进。山岩上积满冰雪，甚是滑溜，倘若一个失足，
必会摔得粉身碎骨。正与此地名称相符，那“巴达克”的原意就是“不
可逾越”。
LONG );

        set("exits", ([
                "southdown" : __DIR__"xingzi",
                "eastdown" : __DIR__"bailongdui",
                "northwest" : __DIR__"shanlu2",
        ]));
        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 3);

        setup();
        replace_program(ROOM);
}