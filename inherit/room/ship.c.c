//Cracked by Roath
// ship.c 海船
// by ALN@XKX
// modified by sdong to fix boat out bug, 8/2/1999

inherit F_CLEAN_UP;
inherit ROOM;

#include <ansi.h>
#include "/clone/ship/harbor.h"
#include "/clone/ship/seashape.h"

string long_desc();
void do_ready();
void do_drop();
int is_owner(object, object);
void time_out();

void reset() // set ships to no_reset
{}

string long_desc()
{
		  string desc;

		  desc = "这是一艘很普通的渔船，几名渔夫摆弄着帆篷，篙桨，绳索，和船尾木舵。\n";
		  desc += "以下指令有助于你的航行：(1)start, (2)stop, (3)go, (4)lookout, (5)locate。\n\n";

		  if( !this_object()->query("exits/out") )
					 switch((int)this_object()->query_temp("navigate/weather")) {
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
		  call_out( "time_out", 500+random(600) );
}

void time_out()
{
	 tell_room(this_object(), HIR"\n突然间狂风大作，不一会儿船就翻了！\n\n"NOR);
	 do_drop();
}

int valid_leave(object me, string dir)
{
		  object *inv, harbor;

		  if( dir == "out" ) {
					 inv = all_inventory(this_object());
					 for(int i = 0; i < sizeof(inv); i++) {
								if( inv[i] != this_player() && userp(inv[i]) )
								return ::valid_leave(me, dir);
					 }

					 remove_call_out("do_ready");
					 call_out("do_ready", 5);
		  }

		  return ::valid_leave(me, dir);
}

int do_start()
{
		  mixed inv;
		  object harbor, me = this_player();
		  string filename, argg;
		  int num;

		  inv = filter_array(all_inventory(this_object()), "is_owner", this_object(), me);
		  if( sizeof(inv) > 0 )
					 return notify_fail("长这么大连一点江湖规矩都不懂？\n");

        if( !stringp(filename = this_object()->query("exits/out")) )
					 return notify_fail("船已经出海了。\n");

        if( !(harbor = find_object(filename)) )
                harbor = load_object(filename);

		  message("vision", "渔船离了岸，驶向茫茫的大海。\n", harbor);
		  filename = base_name(this_object());
		  if( sscanf(filename, "%s%d", argg, num) == 2 )
		  harbor->delete("exits/enter" + num);

		  message_vision("$N大喝一声“开船”，于是船便离了岸。\n", me);
		  this_object()->delete("exits/out");

		  this_object()->delete_temp("navigate");

		  this_object()->set_temp("navigate/locx", (int)harbor->query("navigate/locx"));
		  this_object()->set_temp("navigate/locy", (int)harbor->query("navigate/locy"));

		  remove_call_out("shipweather");
		  call_out("shipweather", 1);
		  remove_call_out("navigate");
		  call_out("navigate", 2);
		  remove_call_out("do_ready");

		  return 1;
}

int navigate()
{
		  object harbor;
		  string dir, *filenames, filename, argg;
		  int i, num, locx, locy, *pos, drop_factor;

		  locx = (int)this_object()->query_temp("navigate/locx");
		  locy = (int)this_object()->query_temp("navigate/locy");
	if( locx > 50 || locy > 50 )
		drop_factor = 1;
	else drop_factor = 0;

		  remove_call_out("navigate");

		  for(i = 0; i < sizeof(jiaos); i++) {
					 pos = jiaos[i];
					 if( this_object()->query_temp("navigate/locx") == pos[0]+random(3)-1 && this_object()->query_temp("navigate/locy") == pos[1]+random(3)-1 ) {
								tell_room(this_object(), HIR"突然间船身激烈地震了一下，触礁了！船沉了！\n\n"NOR);
								do_drop();
								return 1;
					 }
		  }

		  if( !random(100) && !this_object()->query("exist/out")
		  &&  this_object()->query_temp("navigate/weather") == 2
	&& drop_factor) {
					 tell_room(this_object(), HIR"\n突然间狂风大作，不一会儿船就翻了！\n\n"NOR);
					 do_drop();
					 return 1;
		  }

		  if( !random(40) && !this_object()->query("exist/out") ) {
		switch(random(10)) {
		case 0 : /* monster 海怪*/
			break;
		case 1 : /* treasure 财宝*/
			break;
		case 2 : /* corsair 海盗*/
			break;
		case 3 :
			tell_room(this_object(), HIC
			"你看见桅杆上闪着青白色的光，哇！神迹！！！\n"NOR);
			break;
					 case 4 :
								tell_room(this_object(), HIW
			"大雾迷漫，一艘破旧的大船开了过来，一会儿又消失了，船上传来隐隐的叹息声，\n"+
			"你依稀记得船上有几个怪字＂Titanic＂！！！\n"NOR);
								break;
					 case 5 :
								tell_room(this_object(), HIR
			"你看见一只燃烧着的大鸟向船冲过来，糟糕，要撞上了！！！\n"NOR);
								break;
					 case 6 :
								tell_room(this_object(), HIM
			"海面上传来一阵美妙的歌声，你顿时有一种按捺不住跳下海的冲动！！！\n"NOR);
								break;
					 case 7 :
								tell_room(this_object(), HIG
			"你突然发现海中有一只青色大眼睛正瞪着你，过一会儿就不见了，你吓得魂不附体！！！\n"NOR);
								break;
					 case 8 :
								tell_room(this_object(), HIY
			"你看见远处一个人身鱼尾的美丽少女跃出海面，哇噻！美人鱼咧！！！\n"NOR);
								break;
		case 9 :
			tell_room(this_object(), HIG
			"你眼前一亮，北方映出一片奇异莫可名状的光彩，"+HIM"无数奇丽绝伦的光色，在黑暗中\n"+
			"忽伸忽缩，"+YEL"大片橙黄之中"+MAG"夹着丝丝淡紫，忽而紫色愈深愈长，紫色之中，迸射出一\n"+
			"条条"+HIY"金光、"+HIB"蓝光、"+HIG"绿光、"+HIR"红光。\n"NOR);
			break;
		}
	}

		  if( !stringp(dir = this_object()->query_temp("navigate/dir")) ) {
					 if( !random(100) ) {
                        this_object()->add_temp("navigate/wait", 1);
                        if( this_object()->query_temp("navigate/wait") > 5 ) {
                                tell_room(this_object(), "船夫们把大家都扔进了海里。\n");
                                do_drop();
                                return 1;
                        }
                        tell_room(this_object(), "船夫们不耐烦地说：你到底走不走啊？\n");
                }                   
                call_out("navigate", 2);
                return 1;
        }

        if( this_object()->query_temp("navigate/wait") )
        this_object()->delete_temp("navigate/wait");

		  switch(dir) {
                case "东":
                        this_object()->add_temp("navigate/locx", 1);
                        break;
                case "南":
                        this_object()->add_temp("navigate/locy", -1);
								break;
					 case "西":
                        this_object()->add_temp("navigate/locx", -1);
                        break;
		case "北":
                        this_object()->add_temp("navigate/locy", 1);
                        break;
                default:
                        call_out("navigate", 2);
                        return 1;
        }

        locx = this_object()->query_temp("navigate/locx");
        locy = this_object()->query_temp("navigate/locy");

		  if( locx < 1 ) {
                filenames = keys(harbors);
	        for(i = 0; i < sizeof(filenames); i++) {
                        if( locy == harbors[filenames[i]] ) break;
                }

                if( i >= sizeof(filenames) ) {
                        tell_room(this_object(), "船夫说：叹！漂到了一荒岛，还是赶紧离开吧。\n");
                        this_object()->delete_temp("navigate/dir");
                        call_out("navigate", 2);
                        return 1;
                }

                if( !(harbor = find_object(filenames[i])) )
                        harbor = load_object(filenames[i]);

                tell_room(this_object(), "船夫说：“" + harbor->query("short") + "到啦，上岸吧”。\n");

					 this_object()->set("exits/out", filenames[i]);
                this_object()->delete_temp("navigate");
                remove_call_out("shipweather");
                remove_call_out("do_ready");
                call_out("do_ready", 20);
 
					 filename = base_name(this_object());
					 if( sscanf(filename, "%s%d", argg, num) == 2 )
                harbor->set("exits/enter" + num, filename);
                message("vision", "一条渔船驶了过来。\n", harbor);
                return 1;
        }

        filenames = keys(islands);
        for(i = 0; i < sizeof(filenames); i++) {
                pos = islands[filenames[i]];
                if( locx == pos[0] && locy == pos[1] ) {
                this_object()->set("exits/out", filenames[i]);
                this_object()->delete_temp("navigate");
                remove_call_out("shipweather");
                remove_call_out("do_ready");
					 call_out("do_ready", 20);

                if( !(harbor = find_object(filenames[i])) )
                        harbor = load_object(filenames[i]);
                
                filename = base_name(this_object());
                if( sscanf(filename, "%s%d", argg, num) == 2 )
                harbor->set("exits/enter" + num, filename); 

                tell_room(this_object(), "船夫说：“" + harbor->query("island") + "到啦，上岸吧”。\n");
                message("vision", "一条渔船驶了过来。\n", harbor);
                return 1;
	        }
	}

	if( !random(3) )
                tell_room(this_object(), "船正往" + dir + "方向前进。\n");
        call_out("navigate", 2);

        return 1;
}

int do_go(string arg)
{
		  string dir;
		  object me = this_player();
        mixed inv;

        if( this_object()->query("exits/out") )
                return notify_fail("船还没开呢。\n");

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

        this_object()->set_temp("navigate/dir", dir);
		  message_vision("$N对船夫说：船老大，请朝" + dir + "开。\n", me);
        return 1;
}

int do_stop()
{
		  object me = this_player();
		  mixed inv;

        inv = filter_array(all_inventory(this_object()), "is_owner", this_object(), me);
        if( sizeof(inv) > 0 )
                return notify_fail("长这么大连一点江湖规矩都不懂？\n");

        if( !this_object()->query_temp("navigate/dir") )
                return notify_fail("船已经停了。\n");

        message_vision("$N叫船夫们把船停一停。\n", me);
        this_object()->delete_temp("navigate/dir");

        return 1;
}

int do_lookout()
{
        object harbor;
        string dir, *filenames;
        int i, m, locx, locy, tot, dist, *pos;

        if( this_object()->query("exits/out") ) {
                tell_object(this_player(), "船还没开呢。\n");
                return 1;
        }

        locx = (int)this_object()->query_temp("navigate/locx");

        if( locx <= 0 ) {
                tell_object(this_player(), "你已经在岸边了。\n");
                return 1;
        }

        if( locx < 6 ) {
                tell_object(this_player(), "你极目远眺，发现西面不远处就是岸边。\n");
                return 1;
        }

		  locy = (int)this_object()->query_temp("navigate/locy");

        filenames = keys(islands);
        for(i = 0; i < sizeof(filenames); i++) {
                pos = islands[filenames[i]];
                if( !(harbor = find_object(filenames[i])) )
                        harbor = load_object(filenames[i]);
                if( locx == pos[0] && locy == pos[1] ) {
                tell_object(this_player(), "你已经在" +  harbor->query("island") + "岸边了。\n");
                return 1;
                }
        }

        tot = 10000000;
        m = 10000;
		  for(i = 0; i < sizeof(filenames); i++) {
                pos = islands[filenames[i]];
                dist = (locx - pos[0]) * (locx - pos[0]) +
                       (locy - pos[1]) * (locy - pos[1]);
                if( dist < tot ) { tot = dist; m = i; }
        }

        if( tot > 72 ) {
                tell_object(this_player(), "你极目远眺，只觉大海茫茫。\n");
                return 1;
        }

        pos = islands[filenames[m]];

        if( (locy >= pos[1] - 6 && locy < pos[1])
            && (locx >= pos[0] - 6 && locx < pos[0] ) )
                dir = "东北";
        else if( (locy >= pos[1] - 6 && locy < pos[1]) && locx == pos[0] )
					 dir = "北";
        else if( (locy >= pos[1] - 6 && locy < pos[1])
            && (locx > pos[0] && locx <= pos[0] + 6) )
                dir = "西北";
        else if( locy == pos[1] && (locx >= pos[0] - 6 && locx < pos[0]) )
                dir = "东";
		  else if( locy == pos[1] && (locx > pos[0] && locx <= pos[0] + 6) )
					 dir = "西";
        else if( (locy > pos[1] && locy <= pos[1] + 6)
            && (locx >= pos[0] - 6 && locx < pos[0]) )
                dir = "东南";
        else if( (locy > pos[1] && locy <= pos[1] + 6) && locx == pos[0] )
                dir = "南";
        else if( (locy > pos[1] && locy <= pos[1] + 6)
            && (locx > pos[0] && locx <= pos[0] + 6) )
                dir = "西南";

        if( dir ) {
                if( !(harbor = find_object(filenames[m])) )
                        harbor = load_object(filenames[m]);
                tell_object(this_player(), "你极目远眺，发现" + dir + "方向" + harbor->query("shape") + "\n");
		  } else  tell_object(this_player(), "你极目远眺，只觉大海茫茫。\n");

        return 1;
}

int do_locate()
{
        string dir, *filenames;
        int tot, dist, m, i, locx, locy;
        object harbor;

        if( this_object()->query("exits/out") ) {
                tell_object(this_player(), "船还没开呢。\n");
                return 1;
        }

        locx = (int)this_object()->query_temp("navigate/locx");
        locy = (int)this_object()->query_temp("navigate/locy");

        tot = 10000000;
        m = 10000;
        filenames = keys(harbors);
        for(i = 0; i < sizeof(filenames); i++) {
                dist = locx * locx + (locy - harbors[filenames[i]]) * 
							  (locy - harbors[filenames[i]]);
					 if( dist < tot ) { tot = dist; m = i; }
        }

        locy = locy - harbors[filenames[m]];
        if( !wizardp(this_player()) ) {
        locx = (locx * 9 + random(2 * locx))/10;
        locy = (locy * 9 + random(2 * locy))/10;
        }

        if( !(harbor = find_object(filenames[m])) )
                harbor = load_object(filenames[m]);

        if( locx < 1 ) {
                if( locy > 0 ) 
					 dir = "正北约" + chinese_number(locy) + "海哩";
					 else if( locy < 0 )
					 dir = "正南约" + chinese_number(-locy) + "海哩";
					 else dir = "";
		  } else {
					 if( locy > 0 )
					 dir = "东约" + chinese_number(locx) + "海哩" + "北约" + chinese_number(locy) + "海哩";
					 else if( locy < 0 )
					 dir = "东约" + chinese_number(locx) + "海哩" + "南约" + chinese_number(-locy) + "海哩";
					 else
					 dir = "正东约" + chinese_number(locx) + "海哩";
		  }

		  tell_object(this_player(), "你现在在" + harbor->query("short") + dir + "。\n");

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

        if(this_object()-> query("exits/out") ) return;

        if( !this_object()->query_temp("navigate/weather") ) {
                if( !random(6) ) {
                        this_object()->set_temp("navigate/weather", 1);
                        remove_call_out("niceweather");
                        call_out("niceweather", 5 + random(10));
					 } else  if( !random(24) ) {
                        this_object()->set_temp("navigate/weather", 2);
                        remove_call_out("niceweather");
                        call_out("niceweather", 5 + random(10));
                }
        }

        if( !this_object()->query_temp("navigate/weather") )
                call_out("shipweather", 1);
}

void niceweather()
{
        this_object()->set_temp("navigate/weather", 0);
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
								for(m = 0; m < sizeof(invofusr); m++) {
			if(invofusr[m]->query("id") == "tie lian")
										  continue;
								else    destruct(invofusr[m]);
								}
								inv[i]->move(keys(harbors)[random(sizeof(harbors))]);
								message("vision",
								"你发现一个浑身水淋淋的家伙被海水冲上岸来，不由得走近一看，原来是" + inv[i]->query("name") +"。\n", environment(inv[i]), ({inv[i]}));
					 } else  destruct(inv[i]);
		  }

		  remove_call_out("shipweather");
		  this_object()->delete_temp("navigate");
		  this_object()->delete_temp("trigger");
}

void do_ready()
{
		  object harbor, *inv, carbin;
		  string filename, argg;
		  int i, num;

        if( !this_object()->query_temp("trigger") 
         || !stringp(filename = this_object()->query("exits/out")) )
                return;

        if( member_array(filename, wildharbors) != -1 ) {
        if( !this_object()->query_temp("waited") ) {
                this_object()->set_temp("waited", 1);
					 remove_call_out("do_ready");
					 call_out("do_ready", 100);
                return;
        } else  this_object()->delete_temp("waited");
        }

        if( !(harbor = find_object(filename)) )
                harbor = load_object(filename);

        inv = all_inventory(this_object());
        for(i = 0; i < sizeof(inv); i++) {
                if( userp(inv[i]) ) {
                        inv[i]->move(harbor);
                        message_vision("只听「砰！」的一声，$N被船夫踢下船来狼狈不堪。\n", inv[i]);
                }
        }

        if( stringp(filename = this_object()->query("exits/down")) ) {
        if( carbin = find_object(filename) ) {
        inv = all_inventory(carbin);
        for(i = 0; i < sizeof(inv); i++) {
                if( userp(inv[i]) ) {
                        inv[i]->move(harbor);
                        message_vision("只听「砰！」的一声，$N被船夫踢下船来狼狈不堪。\n", inv[i]);
                }
        }
        }
        }

        message("vision", "渔船离了岸，驶向茫茫的大海。\n", harbor);
        filename = base_name(this_object());
        if( sscanf(filename, "%s%d", argg, num) == 2 )
        harbor->delete("exits/enter" + num);

        this_object()->delete_temp("trigger");
        this_object()->delete("exits/out");

        message("vision", "船夫们收锚扬帆，于是船便离了岸。\n", this_object());
}

