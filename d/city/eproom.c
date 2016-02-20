//Cracked by Roath
// pigtest room

#include <pig.h>

inherit "/inherit/room/pigroom";

string look_table();
string look_scoreboard();
string look_rules();
void do_back(object ob);

void create()
{
	set("short", "拱猪房");
	set("long", @LONG
	这是一间专门为拱猪而特别设计的拱猪房。房间里面灯火通明，仿佛永
远准备着为拱猪狂们服务似的。房间的中心放着一张用百年老松树木材特制的拱
猪桌(table)，周围放着四把楠木靠背椅。桌子上摆着一本记分簿(scoreboard)，
北边的墙上贴着一张纸(paper)。
LONG
	);
	set("pigging", 1);

	set("item_desc", ([
		"table" : (: look_table :),
		"scoreboard" : (: look_scoreboard :),
		"paper" : "请务必读 help pig_cmds 和 help pig_rules。\n",
	]));

	set("exits", ([
		"west": "/d/city/duchang2",
	]));

/*
	set("objects", ([
		__DIR__"qiao" : 1,
	]));
*/

	set("no_fight", "1");

	setup();
}
void init()
{
        ::init();

        add_action("do_knock", "knock");
}

int do_knock(string arg)
{       
        object me = this_player();
	object jiang;

        if ( (!arg )|| (arg != "table"))
	  {       
	        write("敲什么呀？(knock table)\n");
                return 1;
	  }
        if( (arg == "table") )
	  {     
                if(!(jiang = find_living("qiaozhu jiang")))
                  {
		        jiang = new("/u/xbc/npc/qiao");
		        jiang->move(environment(me));
                  }

                jiang->move(environment(me));
                message_vision("$N伸出两个指头来，敲了敲桌子，只见一位劁猪将跑了过来。\n", me);
		remove_call_out("do_back");
	        call_out("do_back", 20 + random(10), jiang);
                return 1;
	  }
        return 1;
}

void do_back(object ob)
{
  message("vision", 
	  "劁猪将伸出鼻子嗅了嗅，似乎闻到了什么香味，急急忙忙地跑了出去。\n", 
	  environment(ob), ({ob}));
  ob->move("/d/city/duchang2");
}


string look_table()
{
	if (this_player()->query_temp("pigging_seat"))
		return table_str(this_player()->query_temp("pigging_seat"));
	return table_str("");
}

string look_scoreboard()
{
	return scoreboard_str();
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("pigging_seat"))
		return notify_fail("先离开拱猪桌才能行动。\n");
	return ::valid_leave(me, dir);
}
