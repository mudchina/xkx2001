//Cracked by Roath
// qiaobi0.c 峭壁下
// qfy July 13, 1996

inherit ROOM;

void create()
{
        set("short", "峭壁下");
        set("long", @LONG
这是一座极大的峭壁，有如一座屏风，冲天而起。峭壁(cliff)中部离地
约二十馀丈处，生著一块三四丈见方的大石，便似一个平台(tai)，石上隐隐
刻得有字。
LONG
        );

	set("exits", ([
                "east" : __DIR__"xiaojing",
        ]));

	set("item_desc",([
	    "cliff" : 
	    "峭壁上每隔数尺便生著一丛青苔，数十丛笔直排列而上，原来是供人\n"
	    "借力上爬之处。年深日久，洞中积泥，因此生了青苔。\n",
	    "tai" : "平台石上刻着「剑冢」两个大字。\n"
        ]));

	set("cost", 4);
        setup();
}

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	object me = this_player();

	if ( !arg )
	   return notify_fail( "什么？\n" );

	if ( arg != "up" ) 
	   return notify_fail( "你只能往上爬！\n" );

	if ( (int)me->query_skill("dodge") <= 70 ) {
	   message_vision("$N纵身跃起，但轻功不济，够不着第一个小洞。\n", me);
	   return 1;
	}

	message_vision("$N纵身跃起，左足踏在第一个小洞之中，跟著窜起，右足对准第二\n", me);
	message_vision("丛青苔踢了进去。$N便如此连贯地爬上了十来丈。\n\n", me);
	message("vision",me->name()+"越爬越高，不久便看不见了。\n", environment(me), ({me}) );

	me->receive_damage("jingli", 7000/(int)me->query_skill("dodge"));
	write("你只觉得气喘心跳，气力不加，还是别再往上爬吧。\n\n");

	me->move(__DIR__"qiaobi1");

	return 1;
}
