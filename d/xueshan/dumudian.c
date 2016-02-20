//Cracked by Roath
// /d/xueshan/dumudian.c
// Summer 9/25/96
#include <ansi.h>
#include "room.h"

inherit ROOM;

static string current_id = "";
static int current_job = 0;

int introduce_robber(object current_player);
int reset_to_normal();

void create()
{
        set("short", "度母殿");
        set("long", @LONG
这里是大轮寺的度母殿，正中五尊大座佛，均为高肉髻、外披
袒右袈裟、结跏趺坐、执手印须弭坐各异。殿内对称排列四根大柱，
上雕忍冬纹，下刻连珠纹。北壁上供有两尊金刚像：马头明王和阎
魔护法。
LONG
        );
        set("exits", ([
				"north" : __DIR__"changlang",
                "southdown" : __DIR__"yanwu",
        ]));
	set("objects", ([
		__DIR__"npc/zrlama": 1,
		__DIR__"obj/tonggang": 1,
	]));

	set("cost", 1);
    setup();
}

void reset()
{
	::reset();
	set("no_clean_up", 1);
}

void init() {
    object challenger, me = this_player();

//    printf("blah blah blah\n");
    if ( (me->query("family/family_name") == "雪山派" || 
          me->query("family/family_name") == "血刀门")
         && !(current_job) 
         && (me->query("combat_exp") > 2000000) ) {
//        printf("hehehe\n");
        call_out("introduce_robber", random(10)+10, me);
        current_job = 1; 
    }
//    printf("current_job = %d\n",current_job);
}

int introduce_robber(object current_player)
{   
    object robber;

//    printf("name = %s\n", current_player->query("id"));
    if ( objectp(present(current_player->query("id"), this_object())) )
    {
//        printf("test1\n");
        robber = new(__DIR__"npc/robber");
//        printf("test2\n");
        robber->setup_robber(current_player->query("combat_exp"));
        robber->move(this_object());    
//        printf("test3\n");
//        message("vision", "一个"+robber->name(1)+"急急忙忙走了过来。\n", this_object(), robber);
        message_vision(HIC"一个$N急急忙忙走了过来。\n"NOR, robber);
        message_vision(HIR"$N说道：听说这个铜缸里存着喇嘛用的酥油，老子今天特地来看看，识相的赶快给我滚开！\n" NOR, robber, current_player);
        robber->start_checking(current_player);
//        printf("test4\n");
    }
    else
    {
        reset_to_normal(); 
    }
}

int reset_to_normal()
{

   current_job = 0;
   return 1;

}
