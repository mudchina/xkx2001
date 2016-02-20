//Cracked by Roath
// road: /zhongnan/gate.c

#include <ansi.h>
inherit ROOM;
void init();
void close_gate();
int do_open();
int valid_leave();
string look_gate();


void create()
{
        set("short", HIR"重阳宫大门"NOR);

        set("long",@LONG
你已走到了终南山半山腰，前面就是全真教的总部重阳宫了。
殿宇依山而筑，高低错落有致。周围古木森森，翠竹成林，景色清
幽。正前方黄墙碧瓦，飞檐翘檩，正中一道二丈来宽，三丈来高的
朱红杉木包铜大门(door)。上方一块大匾，龙飞凤舞地书着『重阳
宫』三个大字。南下是广场。
LONG);
        set("exits",([  //"northup" : __DIR__"dadian",
                        "southdown" : __DIR__"dajiaochang",
                      ])
           );

    set("outdoors", "shaolin");
    set("item_desc",([
        "door"        :    (: look_door :),
    ]));
    set("objects",([
		  CLASS_D("quanzhen") + "/pi" : 1,
	 ]));
	 set("cost", 1);
	 setup();
}

void init()
{
	 add_action("do_knock", "knock");
}

int close_door()
{
	 object room;

	 if(!( room = find_object(__DIR__"gate1")) )
		  room = load_object(__DIR__"gate1");
    if(objectp(room))
    {
        delete("exits/north");
        message("vision", "乒地一声，里面有人把大门关上了。\n",
            this_object());
        room->delete("exits/south");
        if (objectp(present("姬清虚", room)))
            message("vision", "姬清虚上前把大门关了起来。\n", room);
        else
            message("vision", "中年道士上前把大门关了起来。\n", room);
    }
    else message("vision", "ERROR: gate not found(close).\n", room);
}

int do_knock(string arg)
{
    object room;
    string event=NATURE_D->outdoor_room_event();

    if (query("exits/north"))
        return notify_fail("大门已经是开着了。\n");

    if (!arg || (arg != "door" && arg != "north"))
        return notify_fail("你要敲什么？\n");


    if(!( room = find_object(__DIR__"gate1")) )
        room = load_object(__DIR__"gate1");
	 if(objectp(room))
    {
        set("exits/north", __DIR__"gate1");
        message_vision("$N轻轻地敲了敲门，只听吱地一声，"
            "一位中年道士应声打开大门，\n"
            "他仔细地看了$N几眼。\n",
            this_player());
        room->set("exits/south", __FILE__);
        message("vision", "外面传来一阵敲门声，中年道士应声上前把大门开。\n", room);
        remove_call_out("close_door");
        call_out("close_door", 10);
    }

    return 1;
}

int valid_leave(object me, string dir)
{
    if ( dir != "north" )
	 {
        return ::valid_leave(me, dir);
    }

    if (!::valid_leave(me, dir))
        return 0;

    if ( (me->query("family/family_name") == "全真教"))
    {
            write("中年道士侧身让开，说道：道兄辛苦了，请进。\n");
				return 1;
	}
    else 
	{
              if( present("incense", me) )
              {
                   write("中年道士侧身让开，说道：原来是贵客驾到，请进请进！\n");
                   return 1;
              }
              else
              {
                   return notify_fail("中年道士说道：如果不是进香，请回吧。\n");
              }
	}
}

string look_door()
{
    return "这是一道三丈来高的朱红色杉木包铜大门，你可以试着敲一下门 (Knock door) 看看。\n";
}
