//Cracked by Roath
// Room: /city/kedian.c
// YZC 1995/12/04
// sdong 3/2/2000
#include <localtime.h>
#include <ansi.h>
inherit ROOM;

// Marz added indecent or inapproapriate id check here :
string* Banned_id = ({
		  "ufk",
		  "none",
});
int do_close_men();
int do_open_men(string arg);


void create()
{
        mixed *local;
        object *ob;
        local = localtime(time());

  	set("short", HIC"客店"NOR);
        set("long", @LONG
这是一家价钱低廉的客栈，生意非常兴隆。外地游客多选择这里落脚，你可
以在这里打听到各地的风土人情。店小二里里外外忙得团团转，接待着南腔北调
的客人。客店的主人从不露面，他究竟是谁，有各种各样的猜测。墙上挂着一个
牌子(paizi)，北面是一间马厩。
LONG
        );

//      set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : "楼上雅房，每夜五两白银。\n",
//		"vortex" : 
//"这似乎是传说中提到过的传送点，传送点的那边可能是天堂，也许是地狱。\n",
        ]));

        set("objects", ([
                __DIR__"npc/xiaoer" : 1,
	]));


    if( local[LT_HOUR] == 2 || local[LT_HOUR] == 4 || 
		local[LT_HOUR] == 6 || local[LT_HOUR] == 8 || 
		local[LT_HOUR] >= 10 && local[LT_HOUR] <= 12 
		)
	{
  		set("exits", ([
			"east" : __DIR__"beidajie1",
			"up" : __DIR__"kedian2",
			"north" : __DIR__"majiu",
			"south" : __DIR__"yizhan",
			"west" : __DIR__"huadian",
			"enter" : "/d/bwdh/square",
			]));
	}
	else
	{
  		set("exits", ([
			"east" : __DIR__"beidajie1",
			"up" : __DIR__"kedian2",
			"north" : __DIR__"majiu",
			"south" : __DIR__"yizhan",
			"west" : __DIR__"huadian",
			]));
	}

	setup();

	"/clone/board/kedian_b"->foo();
//      "/clone/board/jiangpai_b"->foo();
}



int do_open_men(string arg)
{
	object ob, me = this_player();
	object room;

	if (query("exits/enter"))
		  return notify_fail("这扇门已经是打开的。\n");

	if (!arg || (arg != "men" && arg != "west"))
		  return notify_fail("你要打开什么？\n");

	if ( (string)SECURITY_D->get_status(me) != "(arch)" )
		  return notify_fail("什么？\n");

	log_file("status_log", sprintf( "%s opened sjsz door on %s.\n", me->query("id"), ctime(time()) ));

	set("exits/enter", "/d/bwdh/square");
	message_vision("$N用手指凌空一点，吱地一声，打开一道大门。\n", this_player());

	return 1;
}

int do_close_men()
{
	if (!query("exits/enter"))
		  return notify_fail("这扇门已经是关上的。\n");

  	delete("exits/enter");
	message("vision", "大门慢慢地关上了。\n", this_object());
     	return 1;
}

// the following is for a Diablo discussion room
// it's only temporary, maybe for a month or so,
// i'll remove it afterwards.  --ding
//void init()
//{
//	add_action("do_enter", "enter");
//}

//int do_enter(string arg)
//{
//	object me;
//	me = this_player();
//	if (arg =="vortex") {
//                        message("vision",
//		me->name() + "朝着南墙一直走了过去，走进墙里不见了。\n",
 //                       environment(me), ({me}) );
//                        me->move("/u/ding/diablo_r1");
 //                       message("vision",
//me->name() + "的身形突然凭空出现在你面前。\n",
//                        environment(me), ({me}) );
//                return 1;
//        } else 
//        return notify_fail("你要进入哪里？\n");
//}
// end of my temp. code --ding


int valid_leave(object me, string dir)
{
        string id;
        int i;

        if(me == present("xiao er"))
                return ::valid_leave(me, dir);

        if(objectp(present("xiao er", environment(me)))) {
                if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

                if ( me->query_temp("rent_paid") && dir != "up" )
                return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");
        }

		  id = (string)me->query("id");
        for (i = 0; i < sizeof(Banned_id); i++)
        {
        if (id == Banned_id[i])
        {
                me->set("startroom", "/d/death/block");
                me->move("/d/death/block");
                return notify_fail("嘿嘿，看你能跑到哪里去！！\n");
        }
		  }

		if( dir=="enter" ) {
      	me->delete("bwdh"); // clean record when enter bwdh field
		}


        return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_dial", "dial");
	add_action("do_open_men", "open");
	add_action("do_close_men", "close");
}

int do_dial(string arg)
{
        object me = this_player();
                if ( !arg || arg != "1-900-NOBODYHOME" )
             return notify_fail( "请问你要打给谁？\n");
        if ( me->query("family/family_name") == "星宿派") {
        	tell_object(me,
			"你只听得一声大喝："+RANK_D->query_rude(me)+"！你还敢打电话上门？先付赔偿费！！\n");
        	return 1;
	}
        if ( me->query("family/family_name") == "少林派") {
        	tell_object(me,
			"你耳边听到一阵破锅般的录音，对不起，没人在家，钱还没收到，请稍候！\n");
       		return 1;
	}
        tell_object(me,
		"对不起，没人在家，而且我们协会只处理少林派事务，请找有关巫师反映你的问题！\n");
	return 1;
}

