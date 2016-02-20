//Cracked by Roath
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	object ob;

        set("short", "石阵中枢");
        set("long", @LONG
这是桃花岛石阵中枢所在地，四壁(wall)上绘着二十八星宿图，地上
密密麻麻刻着诸般卦象。地上一个太极图(tu)，周围分别环绕先天八卦与
后天八卦，外圈则是推演而出的六十四卦。一缕天光悄然注下，映得室中
忽明忽暗，似乎万籁俱寂，又似乎诸声杂陈，动静之间，不可琢磨。
LONG
        );

        set("exits", ([
                "up" : "/d/taohua/neidong",
        ]));
//        set("objects", ([
//                "/d/taohua/obj/guwen" : 1,
//        ]));
        set("no_fight", 1);
        set("item_desc", ([
                "tu" : "太极图上阴(yin)鱼与阳(yang)鱼分列左右。\n",
		"wall" :
"青龙七宿：角木蛟、亢金龙、氐土貉、房月狐、心日兔、尾火虎、箕水豹\n"
"白虎七宿：奎木狼、娄金狗、胃土雉、昂日鸡、毕月鸟、觜火猴、参水猿\n"
"朱雀七宿：井木犴、鬼金羊、柳土獐、星日马、张月鹿、翼水蛇、轸火蚓\n"
"玄武七宿：斗木獬、牛金羊、女土蝠、虚日鼠、危月燕、室火猪、壁水＜犭俞＞\n",
        ]));

	set("cost", 1);

        setup();
}

void init()
{
        add_action("do_sit", "sit");
	add_action("do_stand", "stand");
	add_action("do_leave", "leave");
	add_action("do_understand", "understand");
		  add_action("do_understand", "lingwu");
	/* comment out by sdong, 7/28/1999.
	add_action("do_thinking", "think");
	add_action("do_thinking", "mingxiang");
	*/
}

int do_thinking()
{
	object me = this_player();
	int qmdj = me->query_skill("qimen-dunjia",1);

		  if ( me->query_skill("qimen-dunjia", 1) < 170 &&
		  !present("he tu", me) && !present("luo shu", me) ) {
		tell_object(me,MAG"你只觉气血翻涌，无数异像怪声向你袭来！\n"NOR);
					 me->unconcious();
					 return 1;
		  }

	if( !me->query("taohua_maze") ) {
					 tell_object(me,MAG"你只觉气血翻涌，无数异像怪声向你袭来！\n"NOR);
					 me->unconcious();
					 return 1;
	}

	if( me->query("jing") < 100 )
					 return notify_fail("你现在精神不佳，无法定下心来思考！\n");

		  if( (int)me->query("potential") <= 1 )
					 return notify_fail("你的潜能不足，无法领悟基本武功！\n");

		  me->receive_damage("jing", random(qmdj));
		  if( me->query("potential") < 0) me->set("potential", 0);

		  if(random(20) == 0) {
		  me->add("potential", -2);
					 me->improve_skill("qimen-dunjia", qmdj/2 + random(qmdj*2));
					 write( "只觉脑中豁然开朗，你对奇门遁甲的领悟又进了一层！\n" );
		  }
		  else if(random(10) == 0) {
					 me->add("potential", -1);
					 me->improve_skill("qimen-dunjia", qmdj/5 + random(qmdj*2));
					 write( "你冥思苦想，对奇门遁甲渐渐加深一层体会！\n" );
	}
        else if(random(2) == 0) {
                me->improve_skill("qimen-dunjia", qmdj/10 + random(qmdj/2));
                write( "你坐立不安，潜心苦思奇门遁甲上的难解之处。\n" );
        }
	else {
                write( "你坐立不安，潜心苦思奇门遁甲上的难解之处。\n" ); 
	}

	return 1;
}

int do_sit(string arg)
{
        mapping skl;
        object me=this_player();
        string *sname;
        int i,j;

        if( !arg || arg!="yin" ) return 0;

	if( me->query_temp("sitted"))
		return notify_fail("你已经坐在上面了！\n");

        if( me->query_temp("standed"))
                return notify_fail("你已经站在上面了！\n");

	if( query("yin")){
		write(query("yin")->name()+"已经坐在上面了！\n");
		tell_object(query("yin"),"看起来"+me->query("name")+"也想坐上来。\n");
		return 1;
	}
/*
        skl = me->query_skills();
        sname  = keys(skl);
*/
        if( arg == "yin"){
	message_vision("$N盘膝坐上左面阴鱼图。\n", me);

	if ( me->query_skill("qimen-dunjia", 1) < 150 &&
	!present("he tu", me) && !present("luo shu", me) ){
		tell_object(me,MAG"你只觉气血翻涌，无数异像怪声向你袭来！\n"NOR);
					 me->unconcious();
		return 1;
		  }
		message_vision(HIG"$N眼观鼻，鼻观心，由制心止自体真止，顷刻之间已神游物外。\n"NOR, me);
		me->set_temp("sitted", 1);
			set("yin", me);
		return 1;
		  }
	return 1;
}

int do_stand(string arg)
{
		  mapping skl;
		  object me=this_player();
        string *sname;
        int i,j;

        if( !arg || arg!="yang" ) return 0;

        if( me->query_temp("standed"))
                return notify_fail("你已经站在上面了！\n");

        if( me->query_temp("sitted"))
                return notify_fail("你已经坐在上面了！\n");

        if( query("yang")){
                write(query("yang")->name()+"已经站在上面了！\n");
		tell_object(query("yang"),"看起来"+me->query("name")+"也想站上来。\n");
                return 1;
        }
/*
        skl = me->query_skills();
        sname  = keys(skl);
*/
        if( arg == "yang"){
        message_vision("$N缓步站上右面的阳鱼图。\n", me);

        if ( me->query_skill("qimen-dunjia", 1) < 150 &&
        !present("he tu", me) && !present("luo shu", me) ){		
		tell_object(me,MAG"你只觉气血翻涌，无数异像怪声向你袭来！\n"NOR);                
		me->unconcious();
                return 1;
        }
		message_vision(HIY"$N足下虚步先后天八卦方位，自先天而后天，片刻间已万物不萦于怀。\n"NOR,me);
		me->set_temp("standed", 1);
		set("yang", me);
		return 1;
        }
        return 1;
}

int do_leave()
{
	object me;

	me = this_player();
	if (me->query_temp("sitted")) {
		me->delete_temp("sitted");
		delete("yin");
		message_vision("$N长吁一口气，收摄心神，站起身来。\n",me);
	}

        if (me->query_temp("standed")) {
                me->delete_temp("standed");
                delete("yang");
		message_vision("$N调息片刻，停住步伐，看上去有点疲倦。\n",me);
		  }

	return 1;
}

int valid_leave(object me, string dir)
{
		  if (me->query_temp("sitted") || me->query_temp("standed"))
		  return notify_fail("你周天搬运未毕，起身恐受内伤！\n");
		  return ::valid_leave(me, dir);
}

int do_understand(string arg)
{
		  object me;
		  string skillname;
		  int skill_special, skill_basic;

		  me = this_player();

	if (!me->query_temp("sitted") && !me->query_temp("standed") )
		return 0;

	if( !query("yin") || !query("yang") )
		return notify_fail("你还需要一位同伴协助运功。\n");

	if( !arg )
					 return notify_fail("你要研究何种基本武技？");

		  if( arg == "force" )
					 return notify_fail("你不能自行修炼基本内功！\n");

		  if (me->is_busy())
					 return notify_fail("你现在正忙着呢。\n");

		  if( me->is_fighting() )
					 return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

		  if( !stringp(skillname = me->query_skill_mapped(arg)) )
					 return notify_fail("你必须有特殊武功方能与基本武技参照领悟！\n");

	skill_basic = me->query_skill(arg, 1);
		  skill_special = me->query_skill(skillname, 1);

		  if( skill_special < 1 )
					 return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");
		  if( skill_basic > skill_special )
					 return notify_fail("你" + to_chinese(skillname) + "功力不够，无法继续领悟" + to_chinese(arg) + "！\n");
		  if( skill_basic < 1 )
					 return notify_fail("你好像还没有学过这项基本技能吧？ 最好先去请教别人。\n");

		  if ( me->query("jing") < 100 )
					 return notify_fail("你现在精神不佳，无法定下心来思考！\n");

		  if( (int)me->query("potential") <= 1 )
					 return notify_fail("你的潜能不足，无法领悟基本武功！\n");

		  me->receive_damage("jing", random(skill_basic));
		  if( me->query("potential") < 0) me->set("potential", 0);

	if(random(20) == 0) {
		me->add("potential", -2);
		me->improve_skill(arg, skill_special + random(skill_special*2));
		write( "只觉脑中豁然开朗，你对" + to_chinese(arg) + "的领悟又进了一层！\n" );
	}
	else if(random(10) == 0) {
		me->add("potential", -1);
		me->improve_skill(arg, skill_special/2 + random(skill_special/1));
		write( "你冥思苦想，对" + to_chinese(arg) + "渐渐加深一层体会！\n" );
	}
	else if(random(5) == 0) {
		me->add("potential", 0);
		me->improve_skill(arg, skill_special/4 + random(skill_special/2));
		write( "你拿手比划着，似乎对" + to_chinese(arg) + "中的几个招数有所体会。\n" );
	}
	else if(random(2) == 0) {
		me->improve_skill(arg, skill_special/8 + random(skill_special/4));
		write( "你坐立不安，潜心苦思" + to_chinese(arg) + "上的难解之处。\n" );
	}
	else if(random(5) == 0) {
		write( "你心中说不出的烦燥，对" + to_chinese(arg) + "始终不得一解。\n" );
	}
	else if(random(10) == 0) {
		me->improve_skill(arg, - (skill_special/10 + random(skill_special/5)));
		write( "你只觉得体内真气乱窜，" + to_chinese(arg) + "中的招式象走马灯一般在面前显现！\n" );
	}
	else if(random(20) == 0) {
		me->improve_skill(arg, - (skill_special/6 + random(skill_special/3)));
		write( "你的大脑中一片空白。对" + to_chinese(arg) + "是越想越糊涂。\n" );
	}
	else {
		write( "你坐立不安，潜心苦思" + to_chinese(arg) + "上的难解之处。\n" );
	}

		  return 1;

}
