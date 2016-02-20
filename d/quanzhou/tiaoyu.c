//Cracked by Roath
//Jay 5/10/97

inherit ROOM;

void check_trigger();
void on_ship();
void arrive();
void close_passage();
int  do_yell(string);

void create()
{
        set("short", "通吃岛");
	set("long", @LONG
这个小岛是一等通吃侯韦小宝命名的通吃岛，又叫钓鱼岛。本岛坐落在
台湾东北方，当年有五百水师曾在岛上驻扎，是中国的领土。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"gangkou4",
	]));

	set("objects", ([ 
		__DIR__"npc/tiao-fu" : 1,
		__DIR__"npc/shuishi" : 1,
        ]));

	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
}

void init()
{
        add_action("do_yell", "cheng");
}

int do_yell(string arg)
{

        object me = this_player();

	if (!arg || arg != "chuan") return 0;

    if(present("shuishi bing", environment(me)))
     {
	message("vision","水师士兵说道：再不走施将军要着急了，你就上船吧。\n", this_object());

	check_trigger();
	return 1;
     }
	else return 0;
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"ship")) )
            room = load_object(__DIR__"ship");
        if( room = find_object(__DIR__"ship") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"ship");
                room->set("exits/out", __FILE__);
                message("vision", "水师士兵把战船的风帆扯起，准备起航。\n", this_object());
                message_vision("水师士兵将一块踏脚板搭上沙滩，对$N说：“上来吧”\n", this_player());
                remove_call_out("on_ship");
                call_out("on_ship", 20);
            }
            else
                message("vision", "真遗憾！船刚开走。\n", this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
	
    else
        message("vision", "水师士兵说道：“快上来吧。”\n",
            this_object() );
}

void on_ship()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "水师士兵把船锚收起，顺风转动风帆。\n",
        this_object() );

    if( room = find_object(__DIR__"ship") )
    {
        room->delete("exits/out");
        message("vision", "战船驶向了茫茫的大海...\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 120);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"ship") )
    {
        room->set("exits/out", __DIR__"houzhu");
        message("vision", "水师士兵说道：“报告，泉州到了！”\n",room );
//        message("vision", "水师士兵说道：“报告，前方发现海岛！”\n",room );
    }

    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"ship") ) {
        room->delete("exits/out");
        message("vision","水师士兵把踏脚板收起来，战船驶向了茫茫的大海...\n", room);
        room->delete("yell_trigger");
    }
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"ship") )
        room->delete("yell_trigger");
}

