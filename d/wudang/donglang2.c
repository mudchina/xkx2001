//Cracked by Roath
// donglang2.c 东厢走廊
// By Marz 04/01/96 
// Modified by xQin 11/00

inherit ROOM;


void close_men();
string look_men();


void create()
{
    set("short", "东厢走廊");
    set("long", @LONG
你走在一条幽静的走廊上，隐约可以听到东边传来呼吸声，似乎有人正
在那里练功，北边有一扇门（men）， 好象是虚掩着。南边是间竹子扎就的
屋子，十分的素雅，里面飘出一阵阵的茶香，有人轻声细语地不知说那些什
么，引得女孩子“吃吃”笑出声来。
LONG
    );

    set("exits", ([
	"south" : __DIR__"chashi",
	"west" : __DIR__"donglang1",
    ]));
                                                    
    set("item_desc",([
        "men"        :    (: look_men :),
    ]));
    
	set("cost", 1);
    setup();
}


void init()
{
    add_action("do_knock", "knock");
    add_action("do_push", "push");
}

int close_men()
{
    object room;

    if(!( room = find_object(__DIR__"xiuxishi1")) )
        room = load_object(__DIR__"xiuxishi1");
    if(objectp(room))
    {
        delete("exits/north");
        message("vision", "门吱吱呀呀地自己合上了。\n", this_object());
        room->delete("exits/south");
        message("vision", "门吱吱呀呀地自己合上了。\n", room);
    }
    else message("vision", "ERROR: men not found(close).\n", room);
}

int do_knock(string arg)
{
    object room;

    if (query("exits/north"))
        return notify_fail("大门已经是开着了。\n");

    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("你要敲什么？\n");

    if(!( room = find_object(__DIR__"xiuxishi1")) )
        room = load_object(__DIR__"xiuxishi1");
        
    if(objectp(room))
    {
    if ((int)room->query_temp("sleeping_person") > 0)
    {
        message_vision(
        "$N刚轻轻地敲了一下门，就听见里面传出一阵雷鸣般的鼾声，\n"
	"显然里面的人睡得跟死猪似的，怎么敲都没用了\n",
        this_player());
    } else if ((int)room->query_temp("person_inside") > 0)
    {
    	switch( random(2) )
    	{
    	case 0:
        	message_vision(
        	"$N轻轻地敲了敲门，只听见里面有人很不耐烦地吼到：\n"
		"刚躺下就来敲门！我睡着了，听不见！！！\n",
        	this_player());
        	
        	break;
       	case 1: 
        	message_vision(
        	"$N轻轻地敲了敲门，只听见里面有些响动，\n"
		"好象有人在踱来踱去，拿不定主意是否开门。\n",
        	this_player());
        	
        	break;
	}       	
	        	
    } else
    {
	room->delete_temp("sleeping_person");
        message_vision("$N轻轻地敲了敲门：咚、咚、咚．．．咚、咚、咚．．．\n",
            this_player());
    }
    }

    if(objectp(room))
    	message("vision",
    	"外面传来一阵敲门声，你从门缝往外一瞧，是"+this_player()->query("name")+"一脸焦急地站在门外，\n"
    	"看样子也想进来休息。\n", room);
        
    return 1;
}

int do_push(string arg)
{
    object room;

    if (query("exits/north"))
        return notify_fail("门已经是开着了。\n");

    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("你要推什么？\n");

    if(!(room = find_object(__DIR__"xiuxishi1")))
        room = load_object(__DIR__"xiuxishi1");
        
    if(objectp(room))
    {
    if((int)room->query_temp("person_inside")<=0)
    {
	 	room->delete_temp("person_inside");
        set("exits/north", __DIR__"xiuxishi1");
        message_vision("$N轻轻地把门推开。\n", this_player());
        room->set("exits/south", __FILE__);
//      message("vision", "有人从外面把门推开了。\n", room);
        remove_call_out("close_men");
        call_out("close_men", 10);
    } else 
    {
        message_vision("$N想把门推开，却发觉门被人从里面闩上了。\n",
	 	this_player());
    }
    }

    return 1;
}


string look_men()
{
    object room;

    if (query("exits/north"))
	return ("门上挂了个牌子：南柯梦处\n");

    if(!( room = find_object(__DIR__"xiuxishi1")) )
        room = load_object(__DIR__"xiuxishi1");

    if( objectp(room) )
    if( (int)room->query_temp("person_inside") > 0 )
    {
	return ("门上挂了个牌子：请毋打扰\n");
    } 
    
    return ("门上挂了个牌子：男弟子休息室\n");
}

int valid_leave(object me, string dir)
{

    	object room;
    	if (me->query("gender") == "女性" && dir == "north")
    	return notify_fail("里面是男弟子休息室，你进去不妥吧！\n");
    	
	if(!( room = find_object(__DIR__"xiuxishi1")) )
        	room = load_object(__DIR__"xiuxishi1");

	if(objectp(room) && dir == "north")
	{
		room->add_temp("person_inside", 1);
		// will open the door if ppl inside stay too long 
		remove_call_out("force_open");
		call_out("force_open", 299, room);
	}		

	return ::valid_leave(me, dir);
}

int force_open(object room)
{
	if ( !objectp(room) ) return 0;
    if((int)room->query_temp("person_inside")<=0) return 0;
    
    room->delete_temp("person_inside");
    set("exits/north", __DIR__"xiuxishi1");
    room->set("exits/south", __FILE__);
    message("vision", "外面突然响起粗重的脚步声，由远而近，到门前停了下来．．．\n"
    	"张松溪啪地把门打开，伸个头进来，一脸狐疑：呆大半天了还不出去，搞什么鬼？\n", room);
    remove_call_out("close_men");
    call_out("close_men", 10);
}

// End of file
