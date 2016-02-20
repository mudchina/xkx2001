//Cracked by Roath
// Room: /city/guopintan.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
        set("short", "果品摊");
        set("long", @LONG
这里是扬州城内一个卖水果蔬菜的小摊子。经过这里的大多是普通百姓，
偶尔有几个当差的差爷们站在水果摊旁一边闲聊，一边大口大口地啃着摊主孝
敬的水果。北面连着热闹的东南大街。
LONG
        );
        set("outdoors", "city");

        set("exits", ([
                "north" : __DIR__"dongnanjie",
//              "west" : __DIR__"nandajie2",
        ]));

        set("objects", ([
                __DIR__"npc/xiao-fan" : 1,
                __DIR__"npc/xiangshi" : 1,
        ]));

        set("cost", 0);
        setup();
}
