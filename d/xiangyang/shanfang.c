//Cracked by Roath
// Room: /d/xiangyang/shanfang.c
// xQin 2/00
inherit ROOM;

void create()
{
        set("short", "膳房");
        set("long", @LONG
这是膳房，几个丫鬟正来来回回地端送菜肴。西边一张木桌上满是大小盘碟，
各盛餐点，来客可以在此用餐(serve) ，吃些家常菜。
LONG
	);
        set("exits", ([
                "west" : __DIR__"neitang",
        ]));

        set("no_fight", 1);
        set("ricewater", 30);
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("soup", me) || present("rice", me))
        return notify_fail("丫环瞪着一双怪眼：吃不了要兜着走啊？\n");
        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_serve","serve");
}

int do_serve()
{
        object me;
        object food;
        object water;
        me=this_player();
        if(present("rice",this_player()) ) 
                return notify_fail("丫环道：吃完了再拿，别浪费食物。\n");
        if(present("rice",this_object()) ) 
                return notify_fail("丫环道：吃完了再拿，别浪费食物。\n");
        if (query("ricewater")>0)
        {
                message_vision("丫环给$N一碗高粱米饭和一碗野菜汤。\n",me);
                food=new(__DIR__"obj/rice");
                water=new(__DIR__"obj/soup");
                food->move(me);
                water->move(me);
                add("ricewater",-1);
        }
        else 
                message_vision("丫环对$N歉声道: 嗨，请您等一会儿再来吧，饭菜都吃光了。\n",me);
        return 1; 

        setup();
        replace_program(ROOM);
}
