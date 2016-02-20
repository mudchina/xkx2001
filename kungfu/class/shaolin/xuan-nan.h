//Cracked by Roath
// xuan-nan.h for fight and get letter from Xuan

#include <ansi.h>

string* names = ({
	"chengxin luohan",
	"chengyi luohan",
	"chengsi luohan",
	"chengshi luohan",
	"chengzhi luohan",
	"chengxin luohan",
	"chengling luohan",
	"chengyu luohan",
	"chengshang luohan",
});

string ask_me()
{
        object fighter, room, monk;
	int j;

	fighter = this_player();

        if( !fighter->query_temp("xuanku-ready") )
                return RANK_D->query_respect(fighter) + 
                "必须先征求罗汉堂首座玄苦大师的同意。";

        if( stringp(query_temp("busyfor")) ) {
                if( (string)query_temp("busyfor") != fighter->query("id") )
                return RANK_D->query_respect(fighter) + 
                "，今日已有人挑战罗汉大阵，你过一段时间再来吧。";
                else
                return RANK_D->query_respect(fighter) +
                "，般若堂已经准备就绪。";
        }

        say("\n玄难说道：好吧，我来召集般若堂长老们于西练武场集合，我稍候在中央练武场上等你。\n");

        message_vision("\n玄难大师往南离开。\n\n", fighter);

        for(j=1; j<10; j++) {
                if(!( room = find_object("/d/shaolin/banruo" + j)) )
                room = load_object("/d/shaolin/banruo" + j);
                
  		move(room);           
		if( !objectp(monk = present(names[j-1], room)) ) {
	        	move("/d/shaolin/banruo5");
        	        message_vision("\n玄难大师走了过来。\n\n", fighter);
			return "真是对不起，般若堂中有人不在，无法举行罗汉大阵。";	
		}

                if( monk->query("jing")*10 < monk->query("max_jing")*8
                ||  monk->query("qi")*10 < monk->query("max_qi")*8
                ||  monk->query("neili")*10 < monk->query("max_neili")*5 ) {
                        move("/d/shaolin/banruo5");
        	        message_vision("\n玄难大师走了过来。\n\n", fighter);
                        return "真是对不起，般若堂中有位长老身体不适，无法举行罗汉大阵。";
                }

                message("vision", "\n玄难大师走了过来，跟" + monk->query("name") + "俯耳轻声说了几句。\n", room, monk);
                message("vision", monk->query("name") + "罗汉点了点头，快步走了出去。\n", room, monk);
                monk->move("/d/shaolin/wuchang1");
	}

        move("/d/shaolin/banruo5");
        message_vision("\n玄苦大师走了过来，跟$N说道：般若堂长老已经集合在西练武场。\n", fighter);
        message_vision("\n玄难大师往东离开。\n\n", fighter);
        move("/d/shaolin/wuchang");
        message_vision("\n玄难大师走了过来。\n\n", this_object());

        if( objectp(monk = present("xuanku dashi", environment())) )
        message_vision("\n玄难大师朝玄苦大师点了点头。\n\n", this_object());

        fighter->set_temp("xuannan-ready", 1);
        set_temp("busyfor", fighter->query("id"));
	return "好！大家都出来了。\n";
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
		return;
	}

	if ( ob_fam["generation"] < my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

	if ( (ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "澄") 
	||   (ob_fam["generation"] >=  my_fam["generation"]      && name[0..1] == "玄") )
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎麽跑到我这儿来了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query("luohan_winner") )
		{
			command("say 老衲垂死之年，又得一可塑之才，真是可喜可贺 !");

			name = ob->query("name");
			new_name = "澄" + name[2..3];
			ob->set("name", new_name);
	
			command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为少林派澄字辈罗汉之一 !");
			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "，你没有闯过十八罗汉大阵，不能越级拜师。");
			return;
		}
	}

	return;
}
