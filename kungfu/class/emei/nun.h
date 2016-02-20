//Cracked by Roath
//kungfu/class/emei/nun.h for 出家，还俗
// Date: shan 96/11/20
// xQin 8/00

#include <ansi.h>
string ask_for_huansu()
{
        object me;
        object ob;
	ob = this_object();
        me = this_player();

        if( (string)me->query("class") != "bonze" )
                return "阿弥陀佛！施主何出此言？我看施主不是出家人吧？\n";

        if( (string)me->query("gender") != "女性" )
        return "阿弥陀佛！大师啊，这等事如何问我？\n";

        if (me->query("family/family_name") != "峨嵋派" )
        {
        return "阿弥陀佛！"+RANK_D->query_respect(me)+"非我派中人，这事如何问贫尼。";
	}
	if (me->query("family/master_id") == ob->query("id"))
	{
	add_action("do_jueding", "想清楚了");
	me->set_temp("pending/quit_bonze", 1);
	command("sigh "+me->query("id"));
	me->set("quit/bonze", 1);
	return "阿弥陀佛！既然你尘缘未了，为师也不强留你，但是你我师徒缘份也将尽，\n"
	       "你想清楚了在告诉我吧，(type 想清楚了)\n";
	}
	else {
	command("hmm");
	return "阿弥陀佛！"+RANK_D->query_respect(me)+"还是和你师傅说去吧。";
	}
}

int do_jueding()
{
	object ob, me;
	me=this_player();
	ob=this_object();
	
	if (!me->query_temp("pending/quit_bonze"))
	return 0;
	
	message_vision("$N恭恭敬敬跪了下来，低声说道：“请恕徒儿不肖。”\n\n",me);
	message_vision("$N对$n叹了口气，扶了$N起来，又给了$N一件布衣。\n\n",ob,me);
	command("say 阿弥陀佛！施主保重。");
	ob=new("clone/misc/cloth.c");
	ob->move(me);
	command("expell "+me->query("id"));
	me->delete("class", "bonze");
	me->delete_temp("pending/quit_bonze");
	return 1;
}
      
string ask_for_join()
{
        object me;
        mapping fam;

        me = this_player();

	if (me->query("quit/bonze"))
	{
		return "阿弥陀佛！施主既以还俗又为何在问贫尼出家之事？";
	}
        if( (string)me->query("class")=="bonze" 
            || (string)me->query("class")=="bonze" )
                return "阿弥陀佛！你我同是出家人，何故跟贫尼开这等玩笑？\n";

        if( (string)me->query("gender") != "女性" )
        return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，何不去嵩山少林寺修行。\n";

	if( mapp(fam = me->query("family")) && (fam["family_name"] != "峨嵋派")
	&& (me->query("combat_exp") > 10000)) 
		return "阿弥陀佛！施主已是武林高手，本庵不敢收留。施主何不多捐些香火钱呢？\n";

	if( mapp(fam = me->query("family")) && (fam["family_name"] != "峨嵋派")
	&& (me->query("combat_exp") <= 10000)) 
		command("say 在本庵出家修行，一定要入峨嵋派，你可不要后悔。\n");

        if( (string)me->query("spouse/id") ) 
        	command("say 施主真的要离开丈夫和家庭，皈依我佛吗？\n");

       	command("say 阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下(kneel)受戒。\n");
	
        me->set_temp("pending/join_bonze", 1);
		return	"记住，一旦出了家，是不能还俗的，否则将会受到惩罚。\n";

}

int do_kneel()
{
        object me = this_player();

        string *prename =
         ({ "文", "妙", "灵", "如" });
        string name, sujia_name, nun_name;

        if( !me->query_temp("pending/join_bonze") )
                return 0;

        message_vision(
                "$N双手合十，恭恭敬敬地跪了下来。\n\n"
                "$n看着$N说道：好吧，你就在本庵修行吧。\n\n"
                "$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n\n",
                me, this_object() );
        name = me->query("name");
        nun_name = prename[random(sizeof(prename))] + name[0..1];
        command("say 从今以后你的法名就叫做" + nun_name + "。");
        command("chat " + name + "削发为尼，在峨嵋山修行，取法名" + nun_name + "。");
        command("smile");
	me->set("title", "峨嵋派学戒女");
        me->delete_temp("pending/join_bonze");
	me->set("sujia_name", name);
        me->set("name", nun_name);
        me->set("class", "bonze");
        me->delete("family");
	MARRY_D->break_marriage(me);
        me->set("K_record", me->query("PKS") + me->query("MKS"));

        return 1;
}

