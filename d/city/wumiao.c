//Cracked by Roath
// Room: /city/wumiao.c // YZC 1995/12/04
// modified by sdong to add Santa, 12/25/98
// Modified by Sure to add color, /17/2000
// Ssy plan to add a west link from this room to web room 09/22/2000
// Haowen disable door in order to reduce robot flooding 09/28/2000
// Mantian remove Ssy west room path since mirror and @us ppl can't access wiz tree 05/12/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", RED"武庙"NOR);
        set("long", 
"这里是岳王庙的正殿，内有岳飞像，像上方悬挂岳飞手书“还我河山”的横
匾。殿两侧壁上嵌着「精忠报国」四个大字。武人到此，都放下武器，毕恭毕敬
地上香礼拜。旁边似乎有一道侧门。\n"
        );

        set("no_fight", "1");
        set("no_steal", "1");
        set("no_sleep_room", "1");

        set("objects", ([
                __DIR__"obj/box" : 1,
        ]));

        if( strsrch(ctime(time()), "Dec 25") != -1 )
        {
                set("objects", ([
                        "/kungfu/class/misc/santa" : 1,
                ]));
        }

        set("exits", ([
                "east" : __DIR__"beidajie2",
                "northwest": "/d/wizard/guest_room",
//              "west": "/u/ssy/webroom",
//              "north" : "/u/oyxb/zhanbuwu",
        ]));

//      create_door("northwest", "竹门", "southeast", DOOR_CLOSED);
        set("cost", 0);
        setup();
        call_other("/clone/board/wumiao_b", "???");
}

void init()
{
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "dazuo");
        add_action("do_respirate",  "respirate");
        add_action("do_respirate",  "tuna");
        add_action("do_practice",  "practice");
        add_action("do_practice",  "lian");
        add_action("do_study",  "study");
        add_action("do_study",  "du");
     	  add_action("do_feed", "feed");
}

int do_exercise(string arg)
{
        object me = this_player();
        tell_object(me, "呆在武庙里，你只觉得心慌意乱，全身真气再也无法凝聚起来！\n");
        return 1;
}

int do_respirate(string arg)
{
        object me = this_player();
        tell_object(me, "呆在武庙里，你只觉得心慌意乱，全身精气再也无法凝聚起来！\n");
        return 1;
}

int do_practice(string arg)
{
        object me = this_player();
        tell_object(me, "你想站起来，却觉得浑身发软，全身提不起一丝劲儿来练功！\n");
        return 1;
}

int do_study(string arg)
{
        object me = this_player();
        tell_object(me, "你只觉得脑袋里发晕，书本上一个个字都飞来飞去，再也读不进去！\n");
        return 1;
}

int do_feed(string arg)
{
        object me = this_player();
        tell_object(me, "你发现所有的动物到了这里都不吃东西！\n");
        return 1;
}

int valid_leave(object me, string dir)
{
      object *inv;
        int i;
        inv = all_inventory(me);
           if ( dir == "east" || dir = "northwest") {
		// can not got to any where if they take players
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("你不能带着其他玩家离开这里。\n");
 			 }
        }
           me->set_temp("mark/武庙", 0);
        return ::valid_leave(me, dir);
}            