//Cracked by Roath
// room: /d/xingxiu/shashan.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "鸣沙山");
        set("long", @LONG
这是一座黄沙堆积形成的山。微风吹动，沙山发出嗡嗡的响声。
故而当地人称之为鸣沙山。沙土中似乎有一种虫子在蠕动。
LONG
        );
        set("outdoors", "xingxiuhai");

        set("exits", ([
                "west" : __DIR__"yueerquan",
                "northeast" : __DIR__"silk3",

        ]));

        set("objects", ([
                __DIR__"npc/shachong" : 1 ]));

	set("cost", 3);
        setup();
        replace_program(ROOM);
}

