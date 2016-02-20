//Cracked by Kafei
// Room: /u/suishin/workroom.c

inherit ROOM;
#include <ansi.h>


void init();
void close_dashi();
int do_push(string arg);
string look_dashi();

void create()
{
        set("short", HIW "水云间" NOR);
        set("long", @LONG
这里是无量山後的深谷，东南西北尽是悬崖峭壁。仰望高崖，白雾封谷
。左边山崖上一条大瀑布如玉龙悬空，滚滚而下，倾入一座清澈异常的大湖
中。瀑布注入处湖水翻滚，离得瀑布十余丈，湖水便一平如镜。淡淡的月
光照入湖中，湖心也有一个皎洁的圆月(moon)。
LONG
        );
        set("valid_startroom", 1);
        set("outdoors", "wizard");
        set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"direct.c",
    ]));

    set("item_desc",([
        "dashi"        :    (: look_dashi :),
        "moon" :       "你抬头向月亮瞧去，却已见不到月亮，原来皓月西沉，已落到了西首峭壁之後，
峭壁上有一洞孔，月光自洞孔彼端照射过来，洞孔(hole)中隐隐有光彩流动。\n",
        "hole" :       "月亮透过峭壁洞孔，将一把彩色缤纷的剑影映到小无量玉壁上。见壁上剑
影斜指北方，剑尖对准了一块大岩石(dashi)。\n",
    ]));

    setup();
}


void init()
{
    add_action("do_push", "push");
}

void close_dashi()
{
    object room;

    if(!( room = find_object(__DIR__"tomb")) )
        room = load_object(__DIR__"tomb");
    if(objectp(room))
    {
        delete("exits/down");
        message("vision", "大岩石轰轰地又回到了原位。\n", this_object());
        room->delete("exits/up");
        message("vision", "大岩石轰轰地又回到了原位。\n", room);
    }
    else message("vision", "ERROR: dashi not found(close).\n", room);
}


int do_push(string arg)
{
    object room;

    if (query("exits/down"))
        return notify_fail("大岩石已经被推开了。\n");

    if (!arg || (arg != "rock" && arg != "dashi"))
        return notify_fail("你要推什麽？\n");

    if(!(room = find_object(__DIR__"tomb")))
        room = load_object(__DIR__"tomb");
        
    if(objectp(room))
    {
    if((int)room->query_temp("person_inside")<=0)
    {
                room->delete_temp("person_inside");
        set("exits/down", __DIR__"tomb");
        message_vision("$N双手出力狠推，那块岩石竟然微微摇晃，缓缓转动，露出了一个三尺来高的洞穴。\n", this_player());
        room->set("exits/up", __FILE__);
//      message("vision", "有人从外面把大岩石推开了。\n", room);
        remove_call_out("close_dashi");
        call_out("close_dashi", 10);
    } else 
    {
        message_vision("$N想把大岩石推开，却发觉好像被卡住了。\n",
                this_player());
    }
    }

    return 1;
}


string look_dashi()
{
    object room;

    if (query("exits/down"))
        return ("一块巨大的岩石，上面缠满了蔓草葛藤。\n");

    if(!( room = find_object(__DIR__"tomb")) )
        room = load_object(__DIR__"tomb");

    if( objectp(room) )
    if( (int)room->query_temp("person_inside") > 0 )
    {
        return ("大小岩石之间藤草缠结。\n");
    } 
    
    return ("这是一块巨大的岩石，岩高齐胸，没二千斤也有一千斤。不过你可以试着推(push)推看。\n");
}


// End of file
