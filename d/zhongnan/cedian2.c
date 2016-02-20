//Cracked by Roath
// /d/zhongnan/cedian2.c
// sdong 07/98

#include <ansi.h>
inherit ROOM;

int do_sit(string);
void delete_served(object);

void create()
{
        set("short", "重阳宫东侧殿");
        set("long", @LONG
这里是重阳宫东侧殿，是接待香客及来宾的地方。殿内摆着几张桌子，
桌旁围放数把椅子。墙上悬着几幅字画，墙边一排书架，架上摆满经书。有
几位进香客正在品茶养神，欣赏墙上的字画或翻阅架上的经书。一个十来岁
的小道士正在忙前忙后招待客人。
LONG
        );
        set("exits", ([
                "west" : __DIR__"sanqing",
        ]));


    set("item_desc", ([
            "table" : "一张典雅的桃木小桌，上面放着水果盘和饮茶器具。\n",
            "chair" : "一把红木椅子。\n",
        ]));

        set("objects",([
                __DIR__"npc/daotong" : 1,
		  ]));

		  set("no_fight", 0);
		  set("no_clean_up", 0);

		  set("cost", 0);
		  setup();

}

void init()
{
        add_action("do_sit", "sit");
}

int do_sit(string arg)
{

		  object me;
		  object daotong;

		  me = this_player();
		  if ( !arg || (arg != "chair") )
					 return notify_fail("你席地而坐，引来几个惊愕的目光。\n");

		  if( !objectp(daotong = present("daotong", environment(me))) )
                return notify_fail("你坐下来休息，没有人来打搅你。\n");

        if( me->query_temp("marks/served") )
        {
                message_vision("小道士笑着对$N说：我还忙着呐，您先再休息休息吧。\n", me);
                return notify_fail("");
        }

        message_vision("$N坐到桌前，小道士笑着过来招待。\n", me);
        daotong->serve_tea(me) ;
        
        me->set_temp("marks/served", 1);
        call_out("delete_served", 10, me);
        return 1;
}



void delete_served(object me)
{
        if ( objectp(me) ) me->delete_temp("marks/served");
}

int valid_leave(object me, string dir)
{
		  if (  (dir == "west")
			  && ( present("xiang cha", this_player())
					 || present("dian xin", this_player()) )
			  && objectp(present("daotong", environment(me))) ) {
		  message_vision("小道士见$N还没吃完，说道：这位客人用完茶点再走吧。", me);
		  return notify_fail("\n");
		  }

		  return ::valid_leave(me, dir);
}


