//Cracked by Roath
// Room: /city/nandajie2.c
// YZC 1995/12/04 
// CLEANSWORD 1996/2/2

inherit ROOM;

void create()
{
        set("short", "南大街");
        set("long", @LONG
这条大街是新近浙江李提督用收来的地税钱派人新铺的，目的是给西面刚开
张的“聚金阁”架掂门面的。因为听说这里的老板给提督上贡甚勤，李克秀也就
给他面子，特意在门口把本来用青石板铺设的路面改成了大理石。两个差人正把
守着两旁。墙柱上挂了一个大布告，上面有一行大字：“损坏地面者罚银五十两
”。东边是另外一条大街，南北两头都是热闹的集市。
LONG
        );
        set("outdoors", "city");

        set("exits", ([
                "east" : __DIR__"dongnanjie",
                "south" : __DIR__"nandajie3",
                "west" : __DIR__"jujinge",
                "north" : __DIR__"nandajie1",
        ]));

        set("cost", 1);
        setup();
}
