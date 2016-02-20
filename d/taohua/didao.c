//Cracked by Roath
//kane

#include <ansi.h>
#include <mudlib.h>
#include "localtime.h"

inherit ROOM;


string* dirs = ({
        "谦", "乾", "坤", "屯", "蒙", "需", "讼", "师", "比", "小畜", "履", 
	"泰", "否", "同人", "大有"
});


void create() {
	set("short", "地道");
	set("long", @LONG
这是一条石砌的甬道，直通向黄药师夫人冯氏灵柩所在之处。甬道两侧每隔
约莫五六步就有一盏盛满清油的绿玉灯静静燃烧。甬道中光线十分昏暗，但勉强
也可见物。甬道尽头有一扇石门(men)，门边嵌着一块铁板(tieban)。
LONG
	);
	set("cost", 1);
        
	set("item_desc", ([
        "men" :
"\n门上刻着数十个卦像，排成整整齐齐的一个方阵，
你凑近仔细一看，原来上面尽是明夷，市，困，家人
等易经卦名，但却又不按寻常卦序排列，显得有些古
怪；每一个卦像都略微凸起，似乎可以按(press)进去。

旁边注着一行小字：天地定位，山泽通气，雷风相薄，
水火不相射。
\n",
        "tieban" : 
"\n九宫之图，法以灵龟，二四为肩，六八为足，
左三右七，戴九履一，五居中央。

数一至九乃先天之数，循环不息，人不能测，欲
以此为本，求诸九宫图中，岂不谬哉！须知天行
有常，以定者求其变者，方为正道。
\n"
	]));


        set("exits", ([
                "out" : __DIR__"xiangzhong",
	]));	
	
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_push", "press");
	add_action("do_help", "sos"); 
}

int do_help(string arg)
{
	object me = this_player();
	int n;
	mixed *local;
	
	if (!wizardp(me)) {
		tell_object(me, HIB"南宫浪告诉你： 你悔悟吧!!!\n"NOR);
		me->move("/d/death/blkbot");
		return 1;
	}

	local = localtime(time());
	n = (int)query_temp("number");
        log_file("Taohua",sprintf("%s(%s) used SOS in didao.c on %s\n",
		me->name(), getuid(me)), ctime(time()));

	tell_object(me, HIB"南宫浪告诉你： "+dirs[n]+"!!!\n"NOR);
	return 1;
}

int do_push(string arg)
{
	object me = this_player();
//	object room = load_object(__DIR__"grave");
	object ob;
	int m,n,i,j,k;
	string str;

	me->add_temp("push_time", 1);
	message_vision("$N伸手向石门按去...\n", me);
	if (me->query_temp("push_time") >= 3 ) {
		tell_object(me,HIR"你脚下一虚，心中暗叫“不好！”，只觉一阵天旋地转......\n"NOR);
		me->unconcious();
		me->delete_temp("push_time");
		me->move(__DIR__"xiangzhong");
		return 1;
	}

	m = random(105);
	n = m%15;
	i=m%3; j=m%5; k=m%7;
	str = "今有物不知其数，三三数之剩"+chinese_number(i)+"，五五数之剩"+chinese_number(j)+"，七七数之剩"+chinese_number(k)+"，问物几何？\n";

//	if (!arg) return notify_fail("什麽？\n");
	 
	if (arg == "谦") {
		write("石门突然“咯咯”轻响了几声。\n");
		write("\n甬道顶部忽然飘落一束薄卷轴，\n");
		ob = new(__DIR__"obj/paper3");
		ob->set("long", str);
		set_temp("number", n);
		ob->move(me);
		set_temp("th_tomb_pass1",1);
		me->start_busy(2);
	}

	if ((arg == dirs[query_temp("number")]) && (query_temp("th_tomb_pass1"))) {
                write("石门突然“咯咯”轻响了几声。\n");
                set_temp("th_tomb_pass2",1);
	} 

	if (query_temp("th_tomb_pass1") && query_temp("th_tomb_pass2")) {
		write("只听得“隆隆”几声大响，石门缓缓向一侧划开...\n\n\n");
		set("exits/enter", __DIR__"grave");
		remove_call_out("close_door");
		call_out("close_door", 10, me);
	        log_file("Taohua",sprintf("%s(%s) entered Taohua Tomb on %s. \n",
                		me->name(), getuid(me)), ctime(time()));
		me->start_busy(2);
	} else return notify_fail("你按下其中一个卦象，但石门却纹丝不动。\n");

	return 1;
}

void close_door()
{
//        object room = load_object(__DIR__"secret_path1");

        if( !query_temp("th_tomb_pass1") || !query_temp("th_tomb_pass2")) 
		return;

        message("vision", "过了一会儿，石门轻轻地关上了，一切又恢复到从前的样子。\n", this_object() );
        delete("exits/enter");
//        room->delete("exits/up");
//        tell_room(room, "过了一会儿，暗门轻轻地关上了。\n");
        delete_temp("th_tomb_pass1");
	delete_temp("number");
	delete_temp("th_tomb_pass2");
}
