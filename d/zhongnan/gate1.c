//Cracked by Roath
// Room: /d/zhongnan/gate1.c
// Date: sdong 07/23/98

inherit ROOM;


void init();
void close_gate();
int do_open(string);
int do_close(string);
string look_gate();


void create()
{
		  set("short", "接引殿");
        set("long", @LONG
这里是重阳宫的前殿接引殿。殿内青砖铺地，两边各放一红木供桌，陈列香
烛，以供叩拜。南面是一道三丈来高的朱红杉木包铜大门(door)。
LONG
		  );

		  set("exits", ([
					 "north" : __DIR__"taijie1",
		  ]));

		  set("item_desc",([
					 "door"          :       (: look_door :),
		  ]));
		  set("objects",([
					 __DIR__"npc/xiang-ke" : 1,
					 CLASS_D("quanzhen") + "/yin" : 1,
		  ]));
		  set("cost", 1);
		  setup();
}


void init()
{
		  add_action("do_open", "open");
		  add_action("do_close", "close");
}

void close_door()
{
        object room;

        if(!( room = find_object(__DIR__"gate")) )
                room = load_object(__DIR__"gate");
        if(objectp(room))
        {
                delete("exits/south");
								message("vision", "中年道士上前把大门关了起来。\n", this_object());
                room->delete("exits/north");
                message("vision", "乒地一声，里面有人把大门关上了。\n", room);
        }
}

int do_close(string arg)
{
        if (!query("exits/south"))
                return notify_fail("大门已经是关着的了。\n");

        if (!arg || (arg != "door" && arg != "south"))
                return notify_fail("你要关什么？\n");

		  message_vision("$N朝中年道士点了点头。\n", this_player());

        remove_call_out("close_door");
		  call_out("close_door", 2);

        return 1;
}

int do_open(string arg)
{
        object room;

        if (query("exits/south"))
                return notify_fail("大门已经是开着了。\n");

		  if (!arg || (arg != "door" && arg != "south"))
                return notify_fail("你要开什么？\n");

        if(!( room = find_object(__DIR__"gate")) )
                room = load_object(__DIR__"gate");
        if(objectp(room))
        {
                set("exits/south", __DIR__"gate");
                message_vision("$N使劲把大门打了开来。\n", this_player());
                room->set("exits/north", __FILE__);
                message("vision", "吱地一声，里面有人把大门打开了。\n", room);
                remove_call_out("close_door");
                call_out("close_door", 10);
        }

        return 1;
}

string look_door()
{
        return "一道三丈来高的朱红杉木包铜大门。\n";
}


int valid_leave(object me, string dir)
{
//        if ( me->query("id") == "seng bing" &&  dir == "south" ) return 0;
        return ::valid_leave(me, dir);
}
