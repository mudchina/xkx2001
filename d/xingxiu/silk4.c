//Cracked by Roath
// /d/xingxiu/silk4.c
// Jay 3/17/96
// Ryu

inherit ROOM;

void create()
{
        set("short", "丝绸之路");
          set("long", @LONG
西面便是「平沙万里绝人烟」的大沙漠。一条条沙梁，蜿蜒起伏，
犹如黄龙偃卧；一座座高大的沙丘，比肩而立，环卫着瀚海迷宫。西
北则是一片连绵的山脉，丝绸之路从那里向前延续，通向焉耆、龟兹。
唐时的玄奘和边塞诗人岑参，都从这里越山西去。东面就是通向中原
的路。路边有一块石碑(shibei)。
LONG );
        set("outdoors", "xingxiuhai");

        set("exits", ([
                "east" : __DIR__"silk3",
		"west" : __DIR__"shamo1",
                "northwest" : __DIR__"shanjiao",
        ]));

        set("item_desc", ([
                "shibei" : "北至西域，东达中原。谁若西行，格杀勿论。白驼山主人启。\n",
        ]));
        set("objects", ([ 
            CLASS_D("baituo")+"/binu" : 1,
         ]) );


	set("cost", 2);
        setup();
}

void init()
{
        add_action("do_push", "push");
        add_action("do_push", "tui");
}
/*
int valid_leave(object me, string dir)
{
    if ((dir == "west")&& !userp(me)) return 0;
    return ::valid_leave(me, dir);
}
*/
int do_push(string arg)
{
	object me;
	mapping fam;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="shibei" )
	{
		if(me->query("rided"))
		return notify_fail("你骑着马，不能这麽干！\n");
		if( (fam = me->query("family")) && fam["family_name"] == "丐帮" ) 
		{
			message_vision("$N推开石碑，只见泥沙纷纷跌落，地面上露出一个小洞。\n", me);
			message("vision",
				me->name() + "运起丐帮缩骨功，一弯腰往洞里钻了进去。\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/underxx");
                	message("vision",
				me->name() + "从洞里走了进来。\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("这么小的洞，你钻得进去吗？\n");
	}
}	
