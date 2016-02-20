//Cracked by Roath
#include <ansi.h>
void init()
{
	object me = this_player();
	int score, skill, age;

	if ( me->query("age") >= 30 || random(me->query_kar()) < 30)
		return 0;
	if ( me->query("family/master_id") != "lu chengfeng" 
         && me->query("family/master_id") != "qu lingfeng")
		return 0;


	age = me->query("age") - 14;
	skill = (me->query_skill("force") + me->query_skill("dodge") 
		+ me->query_skill("strike") + me->query_skill("qimen-dunjia"))/4;
	skill *= me->query("combat_exp")/1000;
	score = skill/age;

	if (score < 1000) return 0;
	
	remove_call_out("recruit_ob");
	call_out("recruit_ob", 150, me);
	tell_object(me, CYN"你觉得身后有点古怪，似乎有人跟随？\n"NOR);
	log_file("Taohua", sprintf("%s(%s)于%s triggered Huang to recruit。\n",
                me->query("name"), getuid(me), ctime(time())));
	add_action("check_score", "check_score");
}

void recruit_ob(object me)
{
	object ob, *obj;
	int i, j = 0;

	obj = all_inventory(environment(me));
        for(i=0; i<sizeof(obj); i++)
        {
                if ((string)obj[i]->query("race") == "人类")
		j++;
	}
	if (j > 1) return;

	if (!me) return;

	ob = new(CLASS_D("taohua/huang"));
	me->start_busy(1);
	ob->move(environment(me));

	message_vision("$N前面突然出现了一人，身材高瘦，身穿青色布袍，脸色古怪之极，两颗眼珠似乎尚能
微微转动，除此之外，肌肉口鼻，尽皆僵硬如木石，直是一个死人头装在活人的躯体上。\n\n", me);
	message_vision("$N一见之下，登时一阵凉气从背脊上直冷下来，目光与这张脸孔相触，便都不敢再看，立时将
头转开，心中怦然而动：莫非这就是祖师爷爷，江湖中传闻的桃花岛主？ 忙上前恭恭敬敬
的磕了四个头，说道：“孙儿叩见师祖。”黄药师道：“罢了！”并不俯身相扶，却伸左手
抓住$N后心一提，右掌便向$N肩头拍下。。。\n", me);
	message_vision("$N一见不妙，来不及细想，赶紧身形疾闪，使出一招“海燕腾空”，身体如同为海风所激，向后飘开一丈有余。\n\n", me);
	message_vision("黄药师微一愣，哼了一声道："+RANK_D->query_rude(me)+"却有几分资质，我就成全你吧。\n", me);
	
	message_vision("\n$N想要收$n为弟子。\n", ob, me);
        tell_object(me, YEL "如果你愿意拜" + me->name() + "为师父，用 apprentice 指令。\n" NOR);
	me->set_temp("huang_recr", 1);
	log_file("Taohua", sprintf("%s(%s)于%s be attempted to recruit by Huang。\n",
                me->query("name"), getuid(me), ctime(time())));
	call_out("finish_recr", 30, me, ob);
}
void finish_recr(object me, object ob)
{
	if (me->query("family/master_id") != "huang yaoshi"){
	message_vision("$N冷笑一声："+RANK_D->query_rude(me)+"居然有几分臭架子。说完飘然而去。\n", ob);
	me->delete_temp("huang_recr");
	destruct(ob);
	}
	return;
}
//You can call this function to check a player's score.
int check_score(string who)
{
	object player,me;
	int age, skill, score;	

	player = this_player();
	if (!wizardp(player))
		return notify_fail("什么？\n");
	me = find_player(who);

	if (!me) return 0;

	age = me->query("age") - 14;
        skill = (me->query_skill("force") + me->query_skill("dodge")
                + me->query_skill("strike") + me->query_skill("qimen-dunjia"))/3;
        skill *= me->query("combat_exp")/1000;
        score = skill/age;
	return score;
}
