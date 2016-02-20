//Cracked by Roath
// Room: /d/dali/dinganfu1.c
#include <login.h>
#include <ansi.h>

inherit ROOM;
string Point1="";
string Point2="";

void create()
{
	set("short", "法堂");
	set("long", @LONG
定安府的法堂内气氛肃穆，堂的上首摆的是一排五个长案，案后坐的是五个
不同族裔的官员。长案下首有两个通译，有赐座。此外，法堂两边还各站了四五
衙役。
LONG);
	set("objects", ([
		"kungfu/class/dali/wujiang1" : 1,
		__DIR__"npc/duanjin" : 1,
		__DIR__"npc/bypanguan" : 1,
       ]));
	set("exits", ([
		"south" : __DIR__"dinganfu",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
}
void init()
{
	add_action("do_cant", "kill");
	add_action("do_cant", "perform");
	add_action("do_cant", "forcekill");
	add_action("do_cant", "yun");
	add_action("do_cant", "exert");
	add_action("do_cant", "throw");
}
int do_cant(string arg)
{
	object ob, item, me=this_player();
	string what, who;

	if (me->query_temp("dali/investigation"))
	{
		write("\n已经升堂了还不安分一点？\n");
		return 1;
	}
	if (query_verb()=="exert" || query_verb()=="yun")
	{
		if (arg == "roar")
		{
			write("\n公堂之上禁止喧哗。\n");
			return 1;
		}
		if (arg == "sing")
		{
			write("\n公堂之上禁止喧哗。\n");
			return 1;
		}
		return 0;
	}
	if (query_verb()=="perform")
	{
		if( sscanf(arg, "%s %s", what, arg))
		{
			if( what !="tuxi") return 0;
			if( (int)me->query_skill("qianzhu-wandu", 1) < 120 ) return 0;
			if (arg == "duan jin" || arg == "duan")
			{
				if (!ob=present(arg, environment(me))) return 0;
				message_vision("$N趁$n不备, 悄然错步转身, 从背后出指突袭。\n\n\n", me, ob);
				message_vision(CYN "$N怒道：「大胆可恶！公堂之上竟敢偷袭本官！来人啊！」\n\n\n"NOR, ob, me);
				me->start_busy(30);    
				Point1="意图于公堂上偷袭";
				Point2="竟欲偷袭本官";
				me->set_temp("dali/investigation",1);
				remove_call_out("processing");
				call_out("processing", 5, ob);
				return 1;
			}
		}
	}
	if (query_verb()=="forcekill")
	{
		if( sscanf(arg, "%s with %s", arg, who))
		{
			if (who == arg) return 0;
			if (who == me->query("id")) return 0;
			if (arg == me->query("id")) return 0;
			if (me->query_skill("necromancy", 1) < 90) return 0;
	        item = present(who, environment(me));
			if (me->query("id") != item->query("xueshan/necromancy_singer")) return 0;
			if (arg == "duan jin" || arg == "duan")
			{
				if (!ob=present(arg, environment(me))) return 0;
                message_vision(HIR "$N诡笑中对着$n念了几句密咒，又伸手指了指"+ob->name()+"。\n\n\n", me, item);
				message_vision(CYN "$N一声大喝一声道：「大胆！竟敢在公堂之上教唆杀人！来人啊！」\n\n\n"NOR, ob, me);
				me->start_busy(30);    
				Point1="教唆行凶";
				Point2="竟教唆行凶谋害本官";
				me->set_temp("dali/investigation",1);
				remove_call_out("processing");
				call_out("processing", 5, ob);
				return 1;
			}
		}
	}
	if (query_verb()=="throw")
	{
		if(sscanf(arg,"%s at %s", what, arg))
		{
			if (arg == "duan jin" || arg == "duan")
			{
				if (!ob=present(arg, environment(me))) return 0;
				item = present(what, me);
				if (!item) return 0;
				message_vision("$N手一扬，将"+item->name()+"对准$n掷去。\n\n\n", me, ob);
				message_vision(CYN "$N怒道：「大胆可恶！公堂之上竟敢偷袭本官！来人啊！」\n\n\n"NOR, ob, me);
				me->start_busy(30);    
				Point1="意图于公堂上偷袭";
				Point2="竟以利器袭击本官";
				me->set_temp("dali/investigation",1);
				remove_call_out("processing");
				call_out("processing", 5, ob);
				return 1;
			}
		}
	}
	if (query_verb()=="kill")
	{
		if (arg == "duan jin" || arg == "duan")
		{
			if (!ob=present(arg, environment(me))) return 0;
			message_vision("$N对著$n喝道：「臭贼！今日不是你死就是我活！」\n\n\n", me, ob);
			message_vision(CYN "$N一声大喝一声道：「大胆！公堂之上竟敢行凶！来人啊！」\n\n\n"NOR, ob, me);
			me->start_busy(30);    
			Point1="试图在公堂上行凶";
			Point2="还敢妄图行凶";
			me->set_temp("dali/investigation",1);
			remove_call_out("processing");
			call_out("processing", 5, ob);
			return 1;
		}
	}
	return 0;
}
void processing(object ob)
{
	message_vision(HIR "衙役齐声喊道：威～～～～武～～～～！\n" NOR, ob);
	write(HIW "\n你双腿一软，跪在了地上，抬头细看，只见数十位卫士手持刀枪将你团团围起，\n其中一人更挥动手中铁链向你颈中套来。\n\n\n" NOR);
	message_vision(HIY "\n\n段陉喝道：「在我大理公堂之中"+Point2+"，该当何罪！」\n\n\n" NOR, ob);
	call_out("jailing", 5, ob, 5);
}
void jailing(object ob)
{
	object me=this_player();
	message_vision(HIY "\n\n$N又道：「今判$n收监六个月，以惩后效！如有再犯罪加一等！」\n\n\n" NOR, ob, me);
	message_vision(HIR "那手执铁链之人用力一拽，$N只觉呼吸不顺，昏了过去......\n\n" NOR, me);
	me->delete_temp("dali/investigation");
	me->set("startroom", "/d/dali/laoyu");
	me->move(__DIR__"laoyu");
	me->unconcious();
	CHANNEL_D->do_channel(ob, "chat", sprintf("由于" + me->name()+"("+me->query("id")+")"+Point1+"，目前已由大理定安府收监！"));
}
