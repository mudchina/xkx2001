//Cracked by Roath
// 擂台
// sdong 09/28/98

#include <ansi.h>

inherit ROOM;

int do_disable(string arg);
string look_jia();
int do_kickout(string arg);
int do_get(string arg);

void create()
{
	set("short",HIG"擂台"NOR);
	set("long", HIY"

     		      /I______________I\\               "+HIC"|"+HIR"=====|"+HIY"
		    //||||||||||||||||||\\\\             "+HIC"|"+HIR" 武   |"+HIY"
	        T\\//IIIIIIIIIIIIIIIIIIIIII\\\\/T         "+HIC"|"+HIR"=====|"+HIY"
 		^^^^"+HIG"||"NOR+HIY"^^^"+HIR"【比武擂台】"NOR+HIY"^^^"+HIG"||"+HIY"^^^^         "+HIC"|"+HIY"
                    "+HIG"||"NOR+HIY"__________________"+HIG"||"NOR+HIY"             "+HIC"|"+HIY"
                   /||||||||||||||||||||||\\            "+HIC"|"+HIY"
               T\\//IIIIIIIIIIIIIIIIIIIIIIII\\\\/T        "+HIC"|"+HIY"
	       ^^^^"+HIG"||"+HIY"^^^^^^^^^^^^^^^^^^^^"+HIG"||"+HIY"^^^^        "+HIC"|"+HIG"
		   ||                    ||            "+HIC"|"+HIG"
		   ||                    ||            "+HIC"|"+HIG"
		   ||                    ||            "+HIC"|"+HIG"
		   ||                    ||            "+HIC"|"+HIG"
		   ||                    ||            "+HIC"|"+HIG"
		   ||                    ||            "+HIC"|"+HIW"
     []___[]___[]__|[]___[]___||___[]___[]|__[]___[]___[]
     |__________________|_|________|_|__________________|
	       ||                            ||
	       ||                            ||

"+HIC"正前方竖着一排兵器架(jia)，台下围满了看热闹的人。\n"NOR
	);
	set("invalid_startroom", 1);
	set("no_death", 1);


		  set("exits", ([
					 "down":KANTAI,
					 "northdown":KANTAI2,
		  ]));

	set("item_desc", ([
		"jia": (: look_jia :),
	]));

		  set("objects", ([
					 __DIR__"obj/live" : 1,
		  ]));

		setup();
}

int do_disable(string arg)
{
	tell_object(this_player(), "不能在擂台上这样。\n");
	return 1;//notify_fail("不允许在擂台上这样！\n");;
}


void init()
{
	add_action("do_get", "get");
	add_action("do_disable", "save");
	add_action("do_disable", "kill");
	add_action("do_disable", "hit");
	add_action("do_disable", "steal");
	add_action("do_disable", "fight");
	add_action("do_disable", "sleep");
	add_action("do_disable", "throw");
	add_action("do_disable", "halt");
	add_action("do_disable", "quit");
	add_action("do_kickout", "kickout");

}



int do_kickout(string arg)
{
	object ob,me = this_player();
	string id;
	
	if (!wizardp(me)) {
					 tell_object(me,"你不是巫师，不能赶人家下去！\n");
					 return 1;
		  }

	if (!arg || sscanf(arg, "%s", id)!=1)
		  {
					 tell_object(me,"usage: kickout someone\n");
					 return 1;
		  }

	ob = present(arg);
	if( !ob )
		{
					 tell_object(me,"这个人不在这儿。\n");
					 return 1;
		 }


	message_vision("$N把$n踢出擂台！\n",me,ob);
	ob->move(KANTAI);

	return 1;
}



int do_get(string arg)
{
	object weapon, me=this_player();
	string type;
	if(!arg) return 0;
	if(me->is_busy()) return 0;
	if (sscanf(arg, "%s from jia", type) != 1) return 0;
	switch (type) {
	case "sword":	if(this_player()->query("gender") == "无性")
				weapon = new("/clone/test/xiuhua");
			else    weapon = new("/clone/weapon/gangjian");
			break;
	case "xiao":	weapon = new("/d/taohua/obj/tiexiao");
			break;
	case "blade":	weapon = new("/clone/weapon/gangdao");
			break;
	case "stick":	weapon = new("/clone/weapon/gangbang");
			break;
	case "staff":	weapon = new("/clone/weapon/shezhang");
			break;
	case "falun":	weapon = new("clone/weapon/falun");
			break;
	case "whip" :	weapon = new("/clone/weapon/changbian");
			break;
	case "armor":	weapon = new("/clone/armor/tiejia");
			break;
	default:	return notify_fail("找不到"+type+"\n");
	}
	if(weapon->move(me)) {
		message_vision("$N从兵器架上取下一"+weapon->query("unit")+weapon->name()+"。\n", me);
		if (me->is_fighting()) me->start_busy(2);
	} else {
		destruct(weapon);
	}
	return 1;
}


string look_jia()
{
	string msg;
	msg = "这是一个兵器架，十八般武器是应有尽有。\n";
	msg+= "目前存放有剑(sword)，刀(blade)，棒(stick)，杖(staff)，轮(falun)，\n鞭(whip)，萧(xiao)。还有一些铁甲(armor)。\n";
	msg+= "请用指令“get 种类 from jia”拿取你称手的兵器或甲胄。\n";
	return msg;
}


int valid_leave(object me, string dir)
{
	if( !wizardp(me) ) return notify_fail("不准溜！\n");
	return ::valid_leave(me, dir);
}
