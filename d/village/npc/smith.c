//Cracked by Roath
// smith.c
// Ryu, modified on 3/20/97
//Kane, modified on 6/98

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
int ask_me();
int do_sell(string);
int do_hit(string);
void create()
{
	set_name("冯铁匠", ({ "feng", "smith" }) );
	set("gender", "男性" );
	set("age", 53);
	set("long", 
"冯铁匠想是常年弯腰打铁，背已驼了，双眼被烟火薰的又红又细，\n"
"左腿残废，肩窝下撑著一根拐杖。\n");
	set("combat_exp", 500000);

        set("str", 33);
        set("dex", 17);
        set("con", 28);
        set("int", 27);
	set("shen_type", 1);
	set("neili", 1000);
        set("max_neili", 1000);
	set("max_qi", 1800);
        set("max_jing", 800);
        set("jiali", 50);
        set("score", 5000);
        set_temp("apply/armor", 100);

        set("attitude", "friendly");
        set_skill("dodge", 80);
	set_skill("hammer", 150);
	set_skill("parry", 80);
        set_skill("force", 80);
	set_skill("bitao-xuangong", 80);
	set_skill("luoying-shenfa", 80);
	set_skill("strike", 80);
	set_skill("luoying-shenjian", 80);
	set_skill("qimen-dunjia", 80);

	map_skill("force", "bitao-xuangong");
        map_skill("parry", "luoying-shenjian");
/*
        map_skill("strike", "luoying-shenjian");
        map_skill("dodge", "luoying-shenfa");

        prepare_skill("strike", "luoying-shenjian");
*/

        set("vendor_goods", ({
                __DIR__"obj/hammer",
		"/clone/weapon/caidao",
        }));
//        set("chat_chance", 50);
//	set("chat_msg_combat", (: add_hammer :));
	set("inquiry", ([
		"name": "小人姓冯，村里人都叫我冯铁匠。",
		"here": "这里是小人糊口的铺子，小人就住在後边的屋子。",
		"锄头": "锄头... 抱歉，锄头已经卖光了...",
		"铁锤": "铁锤？小人做的铁锤坚固又耐用，一把只要三百文钱。",
		"剑"  : 
"哦，那是给华山派岳掌门打的，小人用了三个月，总算没浪费那块好铁。\n"
"嗯，岳掌门前不久率门徒下山去了，不知什麽时候才会派人来取剑。",
		"取剑": "小人一定要见了岳掌门的手信才能给剑。",
		"冯默风" : "唉～，这个名字小人已经好久没有听到过了...",
		"奇门遁甲" : "那都是小时候学的，平时没事解解闷罢了。",
		"工作" : (: ask_me :),
		"打铁" : (: ask_me :),
	]) );
//	create_family("桃花岛", 2, "弟子");
	setup();
	carry_object(__DIR__"obj/hothammer")->wield();
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
	add_action("do_list", "list");
	add_action("do_sell", "sell");
	add_action("do_hit", "hit");
	add_action("do_hit", "da");
}
int ask_me()
{
	say("冯铁匠咳了一声，说道：想干活？好！不过我这里废铁不够了，你先去找几十斤废铁来吧。\n");
	this_player()->set_temp("marks/铁", 1);
	return 1;
}	


int accept_object(object who, object ob)
{
	object sword;
        if ((string)ob->query("name")=="手信" && (string)ob->query("id")=="letter" && !userp(ob)) {
              if(!query("yl_trigger")) {
	sword = new(__DIR__"obj/youlong");
        if (!sword){
        say("冯铁匠说道：那剑早被拿走了，怎麽又来一封信，一定是假的。\n");
	call_out("destroy", 1, ob);
	return 1;
	}
		say(
"冯铁匠说道：这把剑虽不起眼，可也是小人的心血，总算对得起岳掌门。\n"
"冯铁匠把" + sword->query("name") + "交给了" + who->query("name") + "。\n");
		sword->move(who);
		command ("rumor "+who->query("name")+"弄到了一柄游龙剑。");
                set("yl_trigger", 1);
              }
           else say("冯铁匠眼也不抬，说道：要剑自己进去拿。\n");
        call_out("destroy", 1, ob);
	return 1;
	}

        if( (string)ob->query("name")=="铁八卦") {
		if( !query("accept_bagua") ) return 0;
		call_out("accept_obj", 2, who, ob);
		return 1;
	}
	return 0;
}

void destroy(object ob)
{
        destruct(ob);
        return;
}
// void add_hammer()
// {
//	if (this_object()->is_fighting() )
//             carry_object(__DIR__"obj/hammer")->wield();
// }
int do_sell(string arg)
{
    object ob;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("你要卖什么？\n");

        if (ob->query("material") != "steel" && ob->query("material") != "iron")
                return notify_fail("我这里只收废铁。\n");

                 else {
                message_vision("$N卖掉了一" + ob->query("unit") +
                ob->query("name") + "给$n。\n", this_player(), this_object());
                MONEY_D->pay_player(this_player(), ob->query_weight()/70);
                        destruct(ob);
        }
	return 1;
}
int do_hit(string arg)
{
	object ob, weapon,  me = this_player();
	string file;
	if (!arg || !(ob = present(arg, this_player()))
	|| me->query_temp("marks/铁") < 1)
                return notify_fail("你要干什么？\n");
	if (ob->query("material") != "steel" && ob->query("material") != "iron"
	|| ob->query("value") > 0) 
                return notify_fail("你还是找一块废铁来打吧。\n");
	if ( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("没有合适的家伙，你怎麽打铁？\n");

	if (ob->weight() < 300){
	file = resolve_path(this_object()->query("cwd"), arg);
	file = base_name(ob) + ".c";
	destruct(ob);
                ob = new(file);
	message_vision("不一会儿，你便打好了一" +ob->query("unit") + ob->query("name")+
	"交给冯铁匠。\n", me);
	command("thumb "+me->query("id"));
	command("say " +RANK_D->query_respect(me) + "如此勤勉，日後必成一位大铁匠。");	
	message_vision("冯铁匠给$N几文铜板工钱。\n", me);
	MONEY_D->pay_player(this_player(), ob->query_weight()/100);
	destruct(ob);
	return 1;
	}

	message_vision("$N把一" + ob->query("unit") + ob->query("name") + 
	"扔进火炉烧红了箝了出来。\n", me);
	message_vision("$N然後高高举起"+ weapon->query("name") +"热火朝天地打起铁来。\n", me);
	me->add("jingli", -30, "打铁时走神，一锤把自己打死了");
        if ((int)me->query_skill("hammer",1) <= 100 ) {
             me->improve_skill("hammer", 1);
             write( "你的基本锤法进步了。\n");
	     ob->set_weight(ob->weight() -10 * me->query("str"));
        if((string)weapon->query("id") == "liuxing chui") 	
	     me->improve_skill("hammer", me->query("int"));
	return 1;
	}
}

void unconcious()
{
	object obj;

	if( !query("revived") )  {
        set("eff_jing", (int)query("max_jing"));
        set("jing", (int)query("max_jing"));
        set("jingli", (int)query("max_jingli"));
        set("eff_qi", (int)query("max_qi"));
        set("qi", (int)query("max_qi"));
        set("neili", (int)query("max_neili"));	
        map_skill("strike", "luoying-shenjian");
        map_skill("dodge", "luoying-shenfa");
        prepare_skill("strike", "luoying-shenjian");
	set("revived",1);
	message_vision(HIW"$N大喝一声，身形突然变得灵动异常，出手招式也大不相同！\n"NOR,this_object());
	
	if ( objectp(obj = this_object()->query_temp("last_damage_from"))) {
		if( present(obj->query("id"),environment(this_object())) ) {
		this_object()->fight_ob(obj);
		if( obj->query("family/family_name") == "桃花岛" )
		call_out("halt_fight",5+random(10),obj);
		}
	}
	return 0;
	} else ::unconcious();
}

void halt_fight(object me)
{
	
        if (this_object()->is_fighting()) {
        	this_object()->remove_all_enemy();
		me->remove_all_enemy();
	}
	message_vision(CYN"$N哈哈大笑道：冯默风，你所用功夫全是我桃花一派，难道你还要装下去吗？！\n"NOR,me);
	message_vision(CYN"$N一楞，手下不由得慢了下来，向后一跃，跳出战圈不打了。\n"NOR,this_object());
	message_vision(CYN"$N长叹一声，道：不想我冯默风有生之年还能见到桃花同门，不知恩师他老人家近来可好？\n",this_object());
	this_object()->set("accept_bagua",1);
}

/*
int accept_object(object me, object obj)
{
	if( !query("accept_bagua") ) return 0; 
       call_out("accept_obj", 2, me, obj);
        return 1;
}

*/

int accept_obj(object me, object obj)
{
        if( obj->query("name") == "铁八卦" ) {
	message_vision(CYN"$N摩挲着铁八卦，渐渐热泪盈眶！\n"NOR,this_object());
	command("cry");
	command("say 默风不肖，累师傅担忧，同门牵挂，有劳"+RANK_D->query_respect(me) +"了。\n");
	me->set("help_mofeng",1);
	}
	return 1;
}
