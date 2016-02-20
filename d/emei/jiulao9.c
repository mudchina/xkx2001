//Cracked by Roath
// jiulao7.c 九老洞
// Shan: 96/06/22

inherit ROOM;

int do_use(string arg);
int do_zuan(string arg);
int do_leave(string arg);

void create()
{
	string *directions; 
	mapping exits;
	int entry = random(8);
	int exit = (entry + random(7) + 1) % 8;
				
        set("short", "九老洞");
        set("long", @LONG
这就是峨嵋第一大洞，洞内深窈无比，神秘难测。你一走进来，便发觉洞
中叉叉洞多如迷宫，怪异莫测，似乎黝黑无底。洞里隐隐传来鸡犬鼓乐之声，
令人惊异间，忽有蝙蝠群涌而至，扑熄火炬。还是快快离开吧。
LONG
        );
        set("objects", ([
                __DIR__"npc/bat": 4]));

	set("hidden_exits", ([
                "northeast": __FILE__,
                "southeast": __FILE__,
                "southwest": __FILE__,
                "northwest": __FILE__,
                "north": __FILE__,
                "west": __FILE__,
                "south": __FILE__,
                "east": __FILE__ 
	]));

	exits = query("hidden_exits");
	directions = keys(exits);
	exits[directions[entry]] = __DIR__"jiulao8";
	exits[directions[exit]] = __DIR__"jiulao_out";

	set("cost", 5);
        setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_zuan", "zuan");
        add_action("do_zuan", "leave");
}

int do_use(string arg)
{
        object me = this_player();
	object ob = present("fire", me);

        if ( !arg || arg=="" ) return 0;
        if ( !ob )  return 0;
        if( arg=="fire" ) {
             	write("你点燃火折，把洞内照亮了一些。\n");
        	set("exits", query("hidden_exits"));
               	message("vision", "洞内亮了一些，微弱的火光一闪一闪的。\n", environment(me));
		remove_call_out("fire_out");
		call_out("fire_out", 3, me, ob);
             	return 1;
       }
}


#include "/d/emei/jiulao.h"
