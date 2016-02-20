//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;
int do_jump(string arg);

void create()
{
	set("short", "听鱼石");
	set("long", @LONG
这里已接近碧波池的中心，一块形如卧狮的大石立于水畔，侧面有两个大篆 --
“听鱼”。大概因为经常有人使用，石面已经十分光滑。池中白莲盛放，清香阵阵，
莲叶田田。你在石上坐了下来，一阵微风拂过，池中荷叶倏倏作响，几尾金色锦鲤戏
于荷间。北面池中央有一间重檐六角亭(ting)，可是似乎无路通向此亭。
LONG
	);

        set("item_desc", ([
        "ting" : 
		"亭上一匾，依稀可以看出上有“试剑亭”三字。\n你看看距离
不算太远，应该可以用轻功飞掠(fly)过去。\n",
        ]));
/*        
	set("objects", ([
                __DIR__"obj/taoshu" : 1,
        ]));
*/
	set("exits", ([
                "west" : __DIR__"bibochi",
                "south" : __DIR__"zhulin3",
        ]));


	set("cost", 2);
	set("outdoors", "taohua");

	setup();

}

void init()
{
        add_action("do_jump", "fly");
}

int do_jump(string arg)
{
        object me = this_player();

        if ( !arg || arg != "ting" )
             return notify_fail( "什么？\n");

        message_vision("$N纵身往试剑亭跳去。\n", me);
        if ( me->query_skill("dodge",1) <= 50 ) {
             message_vision("$N一个不留神，“噗嗵”一声掉进水里，吃了一嘴烂泥。\n", me);
             message_vision("$N落汤鸡似的从池子里爬起来，满足的抹了抹嘴。\n", me);
        }

        if ( me->query_skill("dodge",1) > 50 ) {
             me->move(__DIR__"shijian");
             message("vision", me->name() + 
"纵身由听鱼石跳了过来。\n",environment(me), ({me}) );
        }

        return 1;
}
