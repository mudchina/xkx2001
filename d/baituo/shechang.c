//Cracked by Roath
// shechang.c 蛇场
// 白驼弟子用以培养新蛇的地方。
// maco 4/15/2000

#include <ansi.h>
inherit ROOM;

int POISON = 0;
int AMOUNT = 0;
int MANAGE = 0;

int do_count();

void create()
{
	set("short", "蛇场");
	set("long", @LONG
这是白驼山庄所建的蛇场，从蛇谷捕捉来的毒蛇都在此饲养，四
周围以丈许来高的灰色圆墙，墙脚砌成圆弧形，光滑无缝。场里建了
许多蛇窝，由白驼山庄中的蛇奴负责管理，许多剧毒的怪蛇就是在此
杂交而得。
LONG
	);

	set("exits", ([ 
	    "west" : __DIR__"road5",
	]));
	set("no_fight", 1);
	set("objects", ([ 
	    "/d/baituo/npc/shenu" : 1,
	 ]) );
	set("cost", 2);
	setup();
}

void init()
{
	add_action( "do_count", "count" );
	add_action( "do_manage", "manage" );
	add_action( "do_check", "check" );
	add_action( "do_return", "return");
}

int do_manage()
{
	object me = this_player();
	int asp;

	if( me->query("family/family_name") != "白驼山" )
		return notify_fail("管别人家的闲事干嘛？\n");

	if( me->query("family/master_name") != "欧阳锋")
		return notify_fail("你还没有资格养育自己的蛇群。\n");

	if( (int)me->query_skill("poison",1) < 100 )
		return notify_fail("你对毒技了解不够透彻，还没有办法培养毒蛇。\n");

	if( me->query("baituo/new_breed_time") )
		return notify_fail("先等上回培养怪蛇的成果出来吧。\n");

	MANAGE = 1;
	asp = do_count();
	MANAGE = 0;

	if(! asp || asp == 0 )
		return notify_fail("");

	message_vision("\n$N将蛇群赶进蛇窝，吩咐蛇奴好好培育。\n", me);
	if( wizardp(me) ) write("这些蛇培育出的蛇种，预期可拥有"+asp+"的毒性。\n");

	me->set("baituo/new_breed", asp);
	me->set("baituo/new_breed_time", time());
	me->add("baituo/manage", 1);
	me->delete("baituo/checked_snake");
	return 1;
}

int do_count()
{
	mapping snakes;
	string *names, str;
	int flag, average, i, num, sort, sort2, per;
	object me, obj; 
	mixed *inv;

	me = this_player();
	obj = this_object();
	inv = all_inventory(obj);

	if( me->query("family/family_name") != "白驼山" )
		return notify_fail("管别人家的闲事干嘛？\n");

	if( (wizardp(me) && me->query("env/snake_test") == "YES" )|| me->query_temp("test")) 
		flag = 1;

	inv = map_array(inv, "snake_list", this_object() );

	str = sprintf("《蛇场管理》\n%s\n", implode(inv, "") );

	if(flag) write(str);

	str = "";

	if( mapp(snakes = obj->query("snakes")) ) {
		names = keys(snakes);
		for(i=0; i<sizeof(names); i++)
		names -= ({ 0 });

		if( !sizeof(names) || sizeof(names)==0 ) {
		write("现在蛇场里面没有你捕来的蛇。\n");
		return notify_fail("");
		}

		else if( sizeof(names)==1 )
			str += "蛇场里唯一由你捕捉到的蛇种是" + names[0] + NOR + "。\n";

		else str += sprintf("蛇场里由你捕捉到的蛇有%s种，分别是%s和%s。\n", 
			chinese_number(sizeof(names)),
			implode(names[0..sizeof(names)-2], "、"), 
			names[sizeof(names)-1]);

		//计算每种蛇的数量
		for (i = 0; i < sizeof(names); i++) {
			num = query("snakes/"+names[i]);
			sort = query("snakes_poison/"+names[i]);
			per = 110-num*5;
			sort2 = sort*per/100;

			if(flag) printf("%s总共有%s条，蛇毒总值%d，乘以%d%%之後等於%d。\n", 
			names[i], chinese_number(num), sort, per, sort*per/100 );

			POISON += sort2;
		}

		average = POISON / AMOUNT;
		
		if(flag)
		str += sprintf("共有%s条蛇，蛇毒总和：%d 蛇毒平均值：%d。\n"NOR,
		chinese_number(AMOUNT), POISON, average);


		if ( MANAGE == 0 ) write(str);
	}
	else {
		write("现在蛇场里面没有你捕来的蛇。\n");
		return notify_fail("");
	}

	if(average < 100) {
		write("这些蛇种繁殖出来的蛇，毒性或许薄弱了点。\n");
		return notify_fail("");
	}

	if ( sizeof(names) < 3 ) { 
		write("要培育怪蛇，起码要取三种不同的蛇来繁殖。\n");
		return notify_fail("");
	}
	else if ( MANAGE == 1 ) {  //由manage指令读取时，一边计算一边让蛇消失
		inv = all_inventory(obj);
		for (i = 0; i < sizeof(inv); i++) 
		if (inv[i]->query("race") == "蛇类" 
		&& inv[i]->query("caught") == me->query("id") ) destruct(inv[i]);
	}

	if( MANAGE == 0 && average > me->query("baituo/breed") 
	&& me->query("baituo/breed") > 100 )
		write(HIB"你暗自思量：若是用这些蛇，也许可以培养出毒性更胜以往的怪蛇。\n"NOR);

	POISON = 0;
	AMOUNT = 0;
	delete("snakes");
	delete("snakes_poison");

	return average;

}

string snake_list(object obj, int flag)
{
	int sp = obj->query("snake_poison");
	string str;

	if ( obj->query("race") == "蛇类" 
	&& obj->query("caught") == this_player()->query("id") ) {
		str = sprintf("%-24s： 经验：%-10d  蛇毒：%3d  \n" NOR,
		obj->name() +"("+obj->query("id")+")", obj->query("combat_exp"), sp);

		AMOUNT += 1;
		add("snakes/"+obj->name(), 1);
		add("snakes_poison/"+obj->name(), sp);

		if ( !flag )
			str = "  " + str;
		else
			return 0;
	}
	else str = "";

	return str;
}

int do_check()
{
	object me = this_player();
	
	if( !wizardp(me) )return 0;

	write( sprintf( 
	"breed: %d, new_breed: %d, new_breed_time: %d, checked_snake: %d \n"
	"passed time: %d, manage: %d, snake_amount: %d \n" ,
	me->query("baituo/breed") ,
	me->query("baituo/new_breed") , 
	me->query("baituo/new_breed_time"), 
	me->query("baituo/checked_snake"), 
	time() - me->query("baituo/new_breed_time"), 
	me->query("baituo/manage"), 
	me->query("baituo/snake_amount")  ) );
	return 1;
}

int do_return(string arg)
{
	object me, snake; 
	
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( !objectp(snake = present(arg, me)) && !objectp(snake = present(arg, environment(me)))) 
		return notify_fail("你要让哪条蛇回蛇窝？\n" );

	if( snake->query("race") != "蛇类" ) 
		return notify_fail(snake->name()+"是"+snake->query("race")+"，可不是蛇类！\n");

	if( snake->query("who_breed") != me->query("id") )
		return notify_fail("这条"+snake->name()+"不是你培养出来的。\n" );

	message_vision("$N将$n赶回了蛇窝里。\n", me, snake);

	if(snake->name() == "小怪蛇")
	me->add("baituo/snake_amount", 1);

	destruct(snake);
	return 1;
}
