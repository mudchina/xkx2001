//Cracked by Roath
// Room: /d/shaolin/andao2.c
// Date: YZC 96/02/06
//modified by kane

#include <login.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "暗道");
	set("long", @LONG
这是一个阴暗潮湿的地道，四壁用粗糙的片岩垒垛而成，一颗
颗水珠沿着墙壁滚下来，溅在地上。也许是因为长时间无人通行的
缘故，整个地道弥漫着一股腐尸般的恶臭。旁边一面墙(wall)上的
青苔似乎有点剥落。
LONG
	);

	set("exits", ([
		"up" : __DIR__"gulou1",
	]));

	set("item_desc", ([
	"wall" : "这面墙看上去不太结实，不知道能不能推(tui)得动。\n",
	]) );

	set("cost", 1);
	setup();
}

void init()
{       
	object ob;

	if( interactive(ob = this_player()) 
	&& (int)ob->query_condition("bonze_jail") >= 0 )
	{
		message("vision",
			HIY "只听水声哗啦啦地一响，一个满脸漆黑，全身泥浆的家伙爬了过来！\n\n" NOR, 
			environment(ob), ob);

		tell_object(ob, "你觉得混身轻松，总算走出了这个五行迷魂阵，逃出生天了！\n");

		ob->set("startroom", START_ROOM);
		ob->clear_one_condition("bonze_jail");
	}

        add_action("do_push", "tui");
}

int do_push(string arg)
{
	object me = this_player();

        if( !arg || arg!="wall" ) {
                write("你要推什么？\n");
                return 1;
        }

        message_vision(
        "$N提一口气，运劲双臂，向石壁用力一推。\n",me);

	write("石壁微微一晃，只听＂轧轧＂几声，地上裂开一个大洞。\n");
        set("exits/down", __DIR__"mishi");
        remove_call_out("close");
        call_out("close", 5, this_object());

        return 1;
}

void close(object room)
{
	message("vision","只听得＂轧轧＂数声响，地面又恢复了原状。\n", room);
        room->delete("exits/down");
}
