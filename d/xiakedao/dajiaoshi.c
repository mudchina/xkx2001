//Cracked by Roath
// dajiaoshi.c  大礁石
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
    	set("short", "大礁石");
    	set("long", @LONG
一块大礁石，周围都是水，西边是岛。
LONG
    	);

    	set("outdoors", "xiakedao");
        set("objects", ([ 
                         __DIR__"npc/haigui" : 2,
                         __DIR__"npc/haigui_s" : 2,
                         ]));

    	setup();
}

void init()
{
        ::init();
        add_action("do_tang", "tang");
}

int do_tang(string arg)
{
        object me = this_player();

        if ( !arg )
                return notify_fail("你要往哪个方向趟？\n");
        if ( arg != "west" )
                return notify_fail("那边趟不过去。\n");
        message_vision("$N卷起裤腿，往岛上趟了过去。\n",me);
        me->move(__DIR__"jiaoshi2");  
        message_vision("$N从大礁石上趟了过来。\n",me);
        return 1;
}



