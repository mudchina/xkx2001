//Cracked by Roath
// /d/bwdh/sjsz/eting.c
// 演武厅
// by sdong 08/8/99

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

string long_desc();
int do_get(string arg);
string look_jia();
int do_get(string arg);
string look_jia();
int do_withdraw(string arg);
int do_plant(string arg);


void create()
{
	set("short", HIW"演武厅"NOR);
	set("long", (: long_desc :));


	set("exits", ([
		"west" : "/d/bwdh/sjsz/etower2",
	]));

        set("item_desc", ([
                "jia": (: look_jia :),
        ]));
	create_room();
	setup();
}

void init()
{
	init_room();
	add_action("do_get", "get");
	add_action("do_withdraw", "ba");
	add_action("do_withdraw", "withdraw");
	add_action("do_plant", "plant");	
}


string long_desc()
{
  	string desc,temp;
	int nRank,i,j;

	if( !query("flag") )
	  	desc  = HIW"
	           /I____________I\\               
	         //||||||||||||||||\\\\            
	     T\\//IIIIIIIIIIIIIIIIIIII\\\\/T       
	    ^^^^"+HIG"||"NOR+HIY"^^^"+HIW"[ 演武厅 ]"NOR+HIY"^^^"+HIG"||"+HIY"^^^^         "+HIY"
                "+HIG"||"NOR+HIY"________________"+HIG"||"NOR+HIY"             "+HIC"
	 []__|[]___[]___||___[]___[]|__[]___[]
	 |_________|_|________|_|____________|"+HIB"
               ||                  ||
               ||                  ||
               ||                  ||
               ||                  ||
               ||                  ||
               ||__________________||\n
	       "+HIC"正前方竖着一排兵器架(jia)\n"NOR;
	else		
  		desc  = HIW"
	           /I____________I\\         "+HIR"★"+HIW"
	         //||||||||||||||||\\\\       "+HIY"||"+HIR"~~~~~~~~/"+HIW"
	     T\\//IIIIIIIIIIIIIIIIIIII\\\\/T   "+HIY"||   武   "+HIR"{"+HIW"
	    ^^^^"+HIG"||"NOR+HIY"^^^"+HIW"[ 演武厅 ]"NOR+HIY"^^^"+HIG"||"+HIY"^^^^    "+HIY"||         "+HIR"\\"+HIY"
                "+HIG"||"NOR+HIY"________________"+HIG"||"NOR+HIY"        ||"+HIR"~~~~~~~~~~~"+HIC"
	 []__|[]___[]___||___[]___[]|__[]___[]
	 |_________|_|________|_|____________|"+HIB"
               ||                  ||
               ||                  ||
               ||                  ||
               ||                  ||
               ||                  ||
               ||__________________||\n
	       "+HIC"正前方竖着一排兵器架(jia)\n"NOR;

  	return desc;
}


int do_get(string arg) {
    object weapon, me=this_player(), *temp, env;
    string type;
    int i;

    if(!arg) return 0;
    if(me->is_busy()) return 0;
    if (sscanf(arg, "%s from jia", type) != 1) return 0;

    switch (type) {
    case "sword":   if(this_player()->query("gender") == "无性")
                        weapon = new("/clone/test/xiuhua");
                    else
                        weapon = new("/clone/weapon/gangjian");
                    break;
    case "blade":   weapon = new("/clone/weapon/gangdao");
                    break;
    case "xiao" :   weapon = new("/d/taohua/obj/tiexiao");
                    break;
    case "stick":   weapon = new("/clone/weapon/gangbang");
                    break;
    case "staff":   weapon = new("/clone/weapon/shezhang");
                    break;
    case "falun":   weapon = new("clone/weapon/falun");
                    break;
    case "whip" :   weapon = new("/clone/weapon/changbian");
                    break;
    case "club" :   weapon = new("/clone/weapon/panguanbi");
                    break;
    case "armor":   weapon = new("/clone/armor/tiejia");
                    break;
    case "stone":   weapon = new("/d/city/obj/stone");
                    break;
    case "xiang":   weapon = new("/d/foshan/obj/tihu-xiang");
                    break;
    case "lubo" :   weapon = new("/d/xueshan/obj/lubo");
                    break;
    case "lian" :   weapon = new("/d/xueshan/obj/rtlian");
                    break;
    case "guan" :   weapon = new("/d/xueshan/obj/klguan");
                    break;
    case "bagua" :   weapon = new("/d/taohua/obj/bagua");
                    break;
    case "walkie-talkie" : 
                    temp = all_inventory(me);
                    for (i = 0; i < sizeof(temp); i++) {
                        if (temp[i]->query("id") == "walkie-talkie") {
                            write("你已经拿了对讲机了。\n");
                            return 1;
                        }
                    }
                    weapon = new(__DIR__"obj/walkie-talkie");
                    env = environment(me);
                    if ( me->query("sjsz/white") )
                        weapon->set("channel", 1);
                    else if (me->query("sjsz/red") )
                        weapon->set("channel", 2);
                    break;
    default:        write("找不到"+type+"。\n");
                    return 1;
    }

    if(weapon->move(me)) {
        message_vision("$N从兵器架上取下一"+weapon->query("unit")+weapon->name()+"。\n", me);
    } else {
        destruct(weapon);
    }
    return 1;
}


string look_jia() {
    string msg;
    msg = "
可以拿的兵器有剑(sword)，刀(blade)，棒(stick)，杖(staff)，轮(falun)，
鞭(whip)，棍(club)。还有铁甲(armor)，石块(stone)，醍醐香(xiang)，颅钵
(lubo)，人头链(lian)，骷髅冠(guan)，对讲机(walkie-talkie)，箫(xiao)，
铁八卦(bagua)。\n\n";
    return msg;
}

int do_withdraw(string arg) {
    object flag, me=this_player(), *obj;
    string type;
    int i, bGuarded = 0;

    if(!arg) return 0;
    if(me->is_busy()) return 0;
    if ( arg != "flag" && arg != "qi") return 0;

	if ( query("flag") <= 0 ) return notify_fail("没旗可拔。\n");
	if ( me->query("sjsz/white") > 0 ) return notify_fail("偷自己的旗？\n");
	
	message_vision(HIY"$N向旗杆跃起，想一把拔下旗子。\n"NOR, me);

	obj = all_inventory(environment(me));
	for(i=0;i<sizeof(obj);i++)	 {
			if( living(obj[i]) &&
			obj[i]->query("sjsz/team_name") != me->query("sjsz/team_name") 
			&& obj[i]->query("env/invisibility") < 1
				)
			{
				obj[i]->kill_ob(me);
				message_vision(HIR"$N急对$n喝道：“$n竟敢偷旗，看招！”\n"NOR, obj[i],me,me);
				me->kill_ob(obj[i]);
				bGuarded = 1;
			}
	 }

	 if( !bGuarded )
	 {
	    flag = new("/d/bwdh/sjsz/obj/flag");
	    flag->set_name(query("flag_name"), ({ "flag" }) );
	    if(flag->move(me)) {
        	message_vision(HIG"$N一把扯下了大旗，高高举起。\n"NOR, me);
		set("flag",0);
	    } else {
        	destruct(flag);
	    }
	   CHANNEL_D->do_channel(this_object(), "rumor",
		"听说"+me->name()+"夺走了"+query("flag_name")+"！" );		

	}
	

    return 1;
}

int do_plant(string arg) {
    object flag, me=this_player(), *obj;
    string type;
    int i, bGuarded = 0;
    object board;
    mapping entryA, entryB;
    int scoreA,scoreB;

	 board =  find_object(BOARD);
	 if (!objectp(board)) {
		  board = load_object(BOARD);
		  if (!objectp(board))
				return notify_fail("找不到团体赛成绩版。\n");
	 }
	 entryA = board->query("team/" + board->query("east"));
	 entryB = board->query("team/" + board->query("west"));
	 if(!entryA || !entryB )return notify_fail("现在没有比赛。\n");
	 scoreA = entryA["this_score"];
	 scoreB = entryB["this_score"];

    if(!arg) return 0;
    if(me->is_busy()) return 0;
    if ( arg != "flag" && arg != "qi") return 0;

	if ( query("flag") > 0 ) return notify_fail("旗杆上已有旗了。\n");
	if ( !me->query("sjsz/white") ) return notify_fail("这可不是你的地盘。\n");

	flag= present("flag",me );
	if(!flag)return notify_fail("你手中没旗可以插。\n");

	if( flag->query("name") == query("team_name")+"大旗"  ) 
		return notify_fail("自己的队旗应该插在大本营才是。\n");

	
	message_vision(HIY"$N把大旗哗啦啦展开，插上了旗杆。\n"NOR, me);


	set("flag",1);

	CHANNEL_D->do_channel(this_object(), "rumor",
		"听说"+me->name()+"将"+flag->query("name")+"插到了演武厅！" );		
	set("flag_name",flag->query("name"));

	destruct(flag);

	me->add("sjsz/flag",1);
	me->add("sjsz/bw_score",1000);
	me->add("sjsz/this_flag",1);
	me->add("sjsz/this_score",1000);
	if( me->query("sjsz/white") )scoreA += 1000;
	else if( me->query("sjsz/red") )scoreB += 1000;
	entryA["this_score"]=scoreA;
 	entryB["this_score"]=scoreB;
	board->set("team/" + board->query("east"),entryA);
	board->set("team/" + board->query("west"),entryB);
	board->save();

    return 1;
}

