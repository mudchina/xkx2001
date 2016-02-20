//Cracked by Roath
// Room: /d/xingxiu/xxroad6.c

inherit ROOM;

void create()
{
        set("short", "山间平地");
        set("long", @LONG
山间平地，地上是嫩绿的小草，周围布了几棵桦树，山边有一眼清泉。
南边有条小路，往西是齐腰的浓密的荒草，一直延向山谷深处。
LONG
        );

        set("resource/water", 1);
        set("objects", ([
                __DIR__"npc/obj/yangrou.c" : 3]));


        set("exits", ([
  "westdown" : __DIR__"xxroad9",
  "south" : __DIR__"xxroad5",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 1);
        setup();
        replace_program(ROOM);
}
