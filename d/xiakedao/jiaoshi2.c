//Cracked by Roath
// Dong 1/9/98
// modifiedy by aln 5 / 98
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
    	set("short", "礁石");
    	set("long", @LONG
岛的这一边风光就差多了，到处都是嶙峋的礁石，阴森森的，尤
其到了夜间，漆黑中鱼类的尸体散射出荧火，四下里奕奕发光。你向
东方望去，只见不远处有一块大礁石，不知能不能趟水(tang)到东边
礁石上去。
LONG
    	);

    	set("exits", ([
		       "north" : __DIR__"jiaoshi1",
		       "south" : __DIR__"jiaoshi3",
		       ]));
    	set("outdoors", "xiakedao");


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
        if ( arg != "east" )
                return notify_fail("那边趟不过去。\n");
        message_vision("$N卷起裤腿，往大礁石上趟了过去。\n",me);
        me->move(__DIR__"dajiaoshi");  
        message_vision("$N从岛上趟了过来。\n",me);
        return 1;
}



