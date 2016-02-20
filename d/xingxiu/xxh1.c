//Cracked by Roath
// Room: /d/xingxiu/xxh1.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "星宿海");
        set("long", @LONG
这里是星宿海边。说是海，其实是片湖泊和沼泽，地形十分险恶。
芦苇、红柳和一些低矮的灌木散布其间，此外便是泥沼、干沙和白花
花的盐碱，海滩中的石头和败草枝叶上，都挂着厚厚的白霜。
LONG
        );
        set("exits", ([
             "north" : __DIR__"xxh2",
             "southup" : __DIR__"tianroad2",
]));
        set("objects", ([
                "/kungfu/class/xingxiu/tianlang" : 1,
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 2);
        setup();
        replace_program(ROOM);
}

