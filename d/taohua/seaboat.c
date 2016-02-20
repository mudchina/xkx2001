//Cracked by Roath
// /d/shenlong/seaboat.xkx.c
// by ALN 10 / 97
// i will add more and more things
//modified by Kane

#include <ansi.h>
inherit ROOM;

string long_desc();
void do_ready();
void do_drop();
void reset();

void create()
{
        set("short", "海船");
        set("long", (: long_desc :));
        set("invalid_startroom", 1);

        set("cost", 5);
        set("outdoors", "taohua");

        setup();
}

string long_desc()
{
        string desc;

        desc ="这是一艘很普通的渔船，几名水手摆弄着帆篷，篙桨，绳索，和船尾木舵。\n";
        desc += "以下指令有助于你的航行：(1)start, (2)stop, (3)go, (4)lookout, (5)locate。\n\n";

        if( !query("exits/out") )
                switch((int)query_temp("navigate/weather")) {
                        case 1: desc += BLU"天空中彤云密布，只有几只海鸥还在奋力展翅，海船左右摇晃不已，你感到有\n点立足不稳。\n"NOR; break;
                        case 2: desc += BLU"海面汹涌澎湃，几丈高的巨浪排山倒海似得压来，随时都有可能将船掀翻，你\n时而不得不紧紧抱住船杆，以免落海。\n"NOR; break;
                        default: desc += BLU"四周是辽阔的海面，海风在你耳边轻轻吹过，海浪一个接一个向船泼打过来。\n"NOR;  break;
                }
        return desc;
}

void init()
{
        add_action("do_start", "start");
        add_action("do_go", "go");
        add_action("do_stop", "stop");
        add_action("do_lookout", "lookout");
        add_action("do_locate", "locate");
        add_action("do_start", "1");
        add_action("do_go", "3");
        add_action("do_stop", "2");
        add_action("do_lookout", "4");
        add_action("do_locate", "5");
}

int do_start()
{
        mixed inv;
        object shipside, me = this_player();

        inv = filter_array(all_inventory(this_object()), "is_owner", this_object(), me);
        if( sizeof(inv) > 0 )
                return notify_fail("长这么大连一点江湖规矩都不懂？\n");

        if( !query("exits/out") )
                return notify_fail("船已经出海了。\n");

        if( !(shipside = find_object(query("exits/out"))) )
                shipside = load_object(query("exits/out"));

        switch((string)shipside->query("short")) {
                case "舟山":
                        set_temp("navigate/locx", 0);
                        set_temp("navigate/locy", 0);
                        break;
                case "港湾":
                        set_temp("navigate/locx", 35);
                        set_temp("navigate/locy", 35);
                        break;
        	case "海滩":
                        set_temp("navigate/locx", 35);
                        set_temp("navigate/locy", 35);
                        break;
	}

        message("vision", "渔船离了岸，驶向茫茫的大海。\n", shipside);
        shipside->delete("exits/enter");

	message_vision("$N大喝一声“开船”，于是船便离了岸。\n", me);
        delete("exits/out");

        call_out("shipweather", 1);
        call_out("navigate", 1);
        set_temp("navigate/control", 1);

        return 1;
}

int navigate()
{
        object dest, *inv, *invofusr;
        string dir;
        int i, m, locx, locy, step;

        if( !random(40) && !query("exist/out")
        &&  query_temp("navigate/weather") == 2 ) {
                tell_room(this_object(), HIR"\n突然间狂风大作，不一会儿船就翻了！\n\n"NOR);
                do_drop();
                return 1;
        }

	if( query_temp("navigate/locx") > 100 + random(50)
	|| query_temp("navigate/locy") > 100 + random(50) ){
                tell_room(this_object(), HIR"\n突然间狂风大作，不一会儿船就翻了！\n\n"NOR);
                do_drop();
                return 1;
	}

        if( !(dir = (string)query_temp("navigate/dir")) ) {
                if( !random(40) ) {
                        add_temp("navigate/wait", 1);
                        if( query_temp("navigate/wait") > 5 ) {
                                tell_room(this_object(), "船夫们把大家都扔进了海里。\n");
                                do_drop();
                                return 1;
                        }
                        tell_room(this_object(),"水手们正等着你下令启航．\n");
                }                        
                call_out("navigate", 1);
                return 1;
        }       

	step = 1 + random(2);
        switch(dir) {
                case "东":
                        add_temp("navigate/locx", step);
                        break;
                case "南":
                        add_temp("navigate/locy", -step);
                        break;
                case "西":
                        add_temp("navigate/locx", -step);
                        break;
		case "北":
                        add_temp("navigate/locy", step);
                        break;
                default:
                        call_out("navigate", 1);
                        return 1;
        }

        locx = query_temp("navigate/locx");
        if( locx < 0 ) {
                tell_room(this_object(),"你只觉脚下一沉，船似乎已经碰到了陆地。\n");
                set("exits/out", __DIR__"zhoushan");

                delete_temp("navigate");
                call_out("do_ready", 20 + random(10));

                dest = find_object(__DIR__"zhoushan");
                dest->set("exits/enter", __DIR__"seaboat");
                message("vision", "一条渔船驶了过来。\n", dest);
                return 1;
        }

        locy = query_temp("navigate/locy");
        if( locx >= 38 && locx <= 43 
	&&  locy >= 38 && locy <=43 ) {
                tell_room(this_object(),"船夫说：“桃花岛到啦，快上岸吧，我可不愿意在这鬼地方多待！”。\n");
                set("exits/out", __DIR__"haitan");

                delete_temp("navigate");
                call_out("do_ready", 20 + random(10));

                  dest = find_object(__DIR__"haitan");
//                dest->set("exits/enter", __DIR__"seaboat");
//                message("vision", "一条渔船驶了过来。\n", dest);
		tell_room(dest, "一条渔船驶了过来。\n");
                return 1;
        }

	if( !random(3) )
                tell_room(this_object(), "船正往" + dir + "方向前进。\n");
        call_out("navigate", 1);

        return 1;
}

int do_go(string arg)
{
        string dir;
        object me = this_player();
        mixed inv;

        if( query("exits/out") )
                return notify_fail("船还没开呢。\n");

        if( !query_temp("navigate/control") ) {
                call_out("shipweather", 1);
                call_out("navigate", 1);
                set_temp("navigate/control", 1);
        }

        inv = filter_array(all_inventory(this_object()), "is_owner", this_object(), me);
        if( sizeof(inv) > 0 )
                return notify_fail("长这么大连一点江湖规矩都不懂？\n");

        switch(arg) {
                case "e":
                case "east": 
                        dir = "东";
                        break;
                case "s": 
                case "south": 
                        dir = "南";
                        break;
                case "w": 
                case "west": 
                        dir = "西";
                        break;
                case "n": 
                case "north": 
                        dir = "北";
                        break;
                default:
                        return notify_fail("你要船往哪个方向开？\n");
        }

        set_temp("navigate/dir", dir);
        message_vision("$N对船夫示意朝" + dir + "开。\n", me);
        return 1;
}

int do_stop()
{
        object me = this_player();
        mixed inv;

        inv = filter_array(all_inventory(this_object()), "is_owner", this_object(), me);
        if( sizeof(inv) > 0 )
                return notify_fail("长这么大连一点江湖规矩都不懂？\n");

        if( !query_temp("navigate/dir") )
                return notify_fail("船已经停了。\n");

        message_vision("$N叫船夫们把船停一停。\n", me);
        delete_temp("navigate/dir");

        return 1;
}

int do_lookout()
{
        string dir;
        int locx, locy;

        if( query("exits/out") ) {
                tell_object(this_player(), "船还没开呢。\n");
                return 1;
        }

        locx = (int)query_temp("navigate/locx");

        if( locx < 0 ) {
                tell_object(this_player(), "你已经在大陆岸边了。\n");
                return 1;
        }

        if( locx < 6 ) {
                tell_object(this_player(), "你极目远眺，发现西面不远处就是大陆。\n");
                return 1;
        }

        locy = (int)query_temp("navigate/locy");

        if( locx >= 38 && locx <= 43
	&& locy >=38 && locy >= 43 ) {
                tell_object(this_player(), "你已经在桃花岛岸边了。\n");
                return 1;
        }

        if( (locy > 20 && locy < 40) && (locx > 20 && locx < 40) )
                dir = "东北";
        else if( (locy > 20 && locy < 40) && locx == 40 )
                dir = "北";
        else if( (locy > 20 && locy < 40) && (locx > 40 && locx < 60) )
                dir = "西北";
        else if( locy == 40 && (locx > 20 && locx < 40) )
                dir = "东";
        else if( locy == 40 && (locx > 40 && locx < 60) )
                dir = "西";
        else if( (locy > 40 && locy < 60) && (locx > 20 && locx < 40) )
                dir = "东南";
        else if( (locy > 40 && locy < 60) && locx == 40 )
                dir = "南";
        else if( (locy > 40 && locy < 60) && (locx > 40 && locx < 60) )
                dir = "西南";

        if( dir )
                tell_object(this_player(), "你极目远眺，发现桃花岛就在" +dir + "方向。\n");
        else    tell_object(this_player(), "你极目远眺，只觉大海茫茫。\n");

        return 1;
}

int do_locate()
{
        string dir;
        int locx, locy;

        if( query("exits/out") ) {
                tell_object(this_player(), "船还没开呢。\n");
                return 1;
        }

        locx = (int)query_temp("navigate/locx");

        if( locx < 0 ) {
                tell_object(this_player(), "你已经在大陆岸边了。\n");
                return 1;
        }

        locy = (int)query_temp("navigate/locy");

        if( locx >= 38 && locx <= 43 
	&& locy >= 38 && locy <=43 ) {
                tell_object(this_player(), "你已经在桃花岛岸边了。\n");
                return 1;
        }

        locx = (locx * 9 + random(locx * 2 ))/10;
        locy = (locy * 9 + random(locy * 2 ))/10;

        if( locy > 0 ) 
                dir = "东" + chinese_number(locx) + "海哩" + "北约" + chinese_number(locy) + "海哩";
        else if( locy < 0 )
                dir = "东约" + chinese_number(locx) + "海哩" + "南约" + chinese_number(-locy) + "海哩";
        else    dir = "正东约" + chinese_number(locx) + "海哩";

        tell_object(this_player(), "你现在在舟山" + dir + "处。\n");

        return 1;
}

private is_owner(object ob, object me)
{
        if( living(ob) && userp(ob) && ob != me
        &&  (int)ob->query("combat_exp") > (int)me->query("combat_exp") )
                return 1;

        return 0;
}

void shipweather()
{
        if( !filter_array(all_inventory(this_object()), (:userp:)) )
                return;

        if( query("exits/out") ) return;
//        if( !mapp(query_temp("navigate")) ) return;

        if( !query_temp("navigate/weather") ) {
                if( !random(6) ) {
                        set_temp("navigate/weather", 1);
                        remove_call_out("niceweather");
                        call_out("niceweather", 5 + random(10));
                } else  if( !random(24) ) {
                        set_temp("navigate/weather", 2);
                        remove_call_out("niceweather");
                        call_out("niceweather", 5 + random(10));
                }
        }

        if( !query_temp("navigate/weather") )
                call_out("shipweather", 1);
}

void niceweather()
{
        set_temp("navigate/weather", 0);
        call_out("shipweather", 1);
}

void do_drop()
{
        object *inv, *invofusr;
        int i, m;

        inv = all_inventory(this_object());
        for( i = 0; i < sizeof(inv); i++ ) {
                if( userp(inv[i]) ) {
                        inv[i]->unconcious();
                        invofusr = all_inventory(inv[i]);
                        for(m = 0; m < sizeof(invofusr); m++)
                                destruct(invofusr[m]);
                        if( random(8) == 1 )
                                inv[i]->move("/d/taohua/haitan");
                        else    inv[i]->move("/d/taohua/zhoushan");
                        message("vision",
                        "你发现一个浑身水淋淋的家伙被海水冲上岸来，不由得走近一看，原来是" + inv[i]->query("name") +"。\n", environment(inv[i]), ({inv[i]}));
                } else  destruct(inv[i]);
        }

        delete_temp("navigate");
        delete_temp("trigger");
}

void do_ready()
{
        object shipside;

        if( !query_temp("trigger") || !query("exits/out") )
                return;

        if( !(shipside = find_object(query("exits/out"))) )
                shipside = load_object(query("exits/out"));

        switch((string)shipside->query("short")) {
                case "舟山":
                        set_temp("navigate/locx", 0);
                        set_temp("navigate/locy", 0);
                        break;
                case "港湾":
                        set_temp("navigate/locx", 35);
                        set_temp("navigate/locy", 35);
                        break;
        	case "海滩":
                        set_temp("navigate/locx", 35);
                        set_temp("navigate/locy", 35);
                        break;
	}

        message("vision", "渔船离了岸，驶向茫茫的大海。\n", shipside);
        shipside->delete("exits/enter");

        delete_temp("trigger");
        delete("exits/out");
        message("vision", "船夫们收锚扬帆，于是船便离了岸。\n",this_object());
}

void reset()
{
        object shipside;

        ::reset();

        if( !(shipside = find_object(__DIR__"zhoushan")) )
                shipside = load_object(__DIR__"zhoushan");

        if( shipside->query("exits/enter") )
                shipside->delete("exits/enter");

        if( !(shipside = find_object(__DIR__"harbor")) )
                shipside = load_object(__DIR__"harbor");

        if( shipside->query("exits/enter") )
                shipside->delete("exits/enter");
}
