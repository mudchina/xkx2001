//Cracked by Roath
// Summer, 10/16/96. 

inherit NPC;

string ask_me_1();
string ask_me_2();
string ask_me_3();

void create()
{
	set_name("店老板", ({"dian laoban", "laoban"}));
	set("long",
		"他是一位身型矮小的中年商人。正坐在柜台後拨弄着算盘。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");

	set("age", 40);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp", 4000);
	set("score", 100);

	set("inquiry", ([
		"千年首乌" :    (: ask_me_1 :),
		"老山叁" :    (: ask_me_2 :),
		"灵芝" :   (: ask_me_3 :),
	]));

	set("wu_count", 10);
	set("shan_count",  10);
	set("ling_count", 1);
	setup();
}

string ask_me_1()
{
	object ob;

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return "对不起，本处现在无货。";

	if (  present("heshou wu", this_player()) )
		return "我不是刚卖给你了吗？";

	if (query("wu_count") < 1) return "对不起，本处现在无货。";

	say("店老板抬起头，把你上上下下打量了一番，「嘿嘿嘿」的干笑了几声...\n");
        
	this_player()->set_temp("marks/首", 1);
	return "千年的首乌我这里暂时还没有，却有一支初具人形的，只要一两黄金，不二价。\n";
}
string ask_me_2()
{
	object ob;

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
	return "对不起，本处现在无货。";	

	if (  present("lao shanshen", this_player()) )
	return "我不是刚卖给你了吗？";
		
	if (query("shan_count") < 1) return "对不起，本处现在无货";
	this_player()->set_temp("marks/山", 1);
	say("店老板抬起头，把你上上下下打量了一番，「嘿嘿嘿」的干笑了几声...\n");
	return "老山叁嘛，我这里倒有一支，只要五十两银子，不二价。\n";
}
string ask_me_3()
{
	object ob;
	
	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return  "灵芝可是神药，很难采到，我这现在没有。";

	if (  present("ling zhi", this_player()) )
		return  "灵芝可是神药，很难采到，我这现在没有。";

	if (query("ling_count") < 1) return  "灵芝可是神药，很难采到，我这现在没有。";
	this_player()->set_temp("marks/灵", 1);
	say("店老板抬起头，把你上上下下打量了一番，「嘿嘿嘿」的干笑了几声...\n");
	return "灵芝可是很贵重的唷，就怕你买不起，要二两黄金，不二价。\n";
}
int accept_object(object me, object ob)
{
	object wu, shan, ling;
	if(ob->query("money_id") && ob->value() >= 5000
        && me->query_temp("marks/山") ){ 
	shan = new("/d/qilian/obj/shanshen");
        shan->move(me);
        add("shan_count", -1);
	me->delete_temp("marks/山");
        message_vision("$N从店老板处卖下一棵老山叁。\n",me);
	return 1;
	}


	if(ob->query("money_id") && ob->value() >= 10000
        && me->query_temp("marks/首") ) {
        wu = new("/d/qilian/obj/shanshen");
        wu->move(me);
        add("wu_count", -1);
	me->delete_temp("marks/首");
	message_vision("$N从店老板处卖下一棵何首乌。\n",me);
	return 1;
	}
	
	if(ob->query("money_id") && ob->value() >= 20000
        && me->query_temp("marks/灵") ) {
        ling = new("/d/qilian/obj/lingzhi");
        ling->move(this_player());
	me->delete_temp("marks/灵");
        message_vision("$N从店老板处卖下一支灵芝。\n",this_player());
        return 1;
	}

          
	say(
	"店老板一面急忙把钱收起来，一面笑嘻嘻说道：" + RANK_D->query_respect(ob) + "想买甚麽药，尽管说，小的没有弄不到的。\n");
	return 1;
}
void unconcious()
{
        message_vision("\n突然，只见店老板闪身拉开柜台下一道暗门，钻了进去，咔嚓从里
边把门锁上了。\n",
                this_object());
        destruct(this_object());
}
void destroy (object ob)
{
        destruct(ob);
        return;
}
