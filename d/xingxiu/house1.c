//Cracked by Roath
// /d/xingxiu/house1.c
// Jay 3/26/96

inherit ROOM;

void create()
{
        set("short", "巴依家客厅");
        set("long", @LONG
这是巴依家的客厅。地上铺着波斯地毯，木架上摆着中原的瓷器，这种各地
特色的饰物在北疆并不多见，看得出这家的主人一定很有钱。
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"house",
]));
        set("objects", ([
                __DIR__"npc/afanti": 1 ]) );
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("cost", 0);
        setup();
        replace_program(ROOM);
}
