//Cracked by Roath
// Include file: daozhang.h
// Marz@XKX, 11/11/96

#include <ansi.h>

int do_yes();

void attempt_apprentice(object ob)
{
	int i;
	mapping fam,skill_status;
	string *sname; 
	string *wudang_skills = ({
		"cuff", "taiji-quan", 
		"sword", "taiji-jian",   
		"force", "taiji-shengong",
		"dodge", "tiyunzong",
		"literate", "taoism", 
		"parry",
		"strike", "mian-zhang",
	});

        if (ob->query("class")=="bonze") {
                command ("say 佛家道家所信不同，你既然已经已经出了家，来我们这里做什么呢？");
                return;
        }

	if ((int)ob->query("shen") < 0) {
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	
	if ( (string)ob->query("gender") == "无性" )
	{
		command("say 道家内功练天地正气，讲阴阳调合。");
		command("say 公公无根无性，恐怕修之不宜！");
		return;
	}

	if( mapp(fam = ob->query("family")) && (fam["family_name"] != "武当派")
		&& (skill_status = ob->query_skills()) )
	{
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) 
		if (member_array(sname[i], wudang_skills) == -1)
		{
		
		message_vision("道长哈哈一笑："+ RANK_D->query_respect(ob) +
			"已经入了" + fam["family_name"]+ "了，怎么却来投奔武当？\n", ob);
		message_vision("道长顿了顿，正色道：我武当乃堂堂大派，从不拒天下英雄。\n", ob);
		command("say 你若诚心投奔武当，须放弃所有杂派功夫，以示诚意！");
			
		ob->delete_temp("pending/apprentice");
		return;
		}
	}

	if ( ob->query("title") != "武当道童" 
		&& ob->query("family/family_name") != "武当派" )
 	{
		command("say 我武当之所以能在武林中兴不衰，全靠各弟子自觉效力。");
		command("say 入门习武以前，" + RANK_D->query_respect(ob)
			 + "是否愿意为武当主动做些事情？");

		tell_object(ob, HIY"如果你答应的话，键入＂愿意＂二字。\n"NOR);
		add_action("do_yes", "愿意");

		return;
	} else if ((int)ob->query("wudang/offerring") < (int)ob->query("age"))
	{
		command("say 未练武，先学做人。在为武当自觉效力方面，");
		command("say " + RANK_D->query_respect(ob) + "是否还不够勤勉？");
		ob->delete_temp("pending/apprentice");
		return;
	}

	if( mapp(fam = ob->query("family")) && (fam["family_name"] == "武当派"))
		command("say 你我本是同门，贫道就收下你了！");
	else
	{	
		command("say 精诚所至，玉石为开！你为武当勤勉效力，众道长早已是有口皆碑！");
		command("say "+RANK_D->query_respect(ob)+"实乃我辈中人也！");
	}

	command("recruit " + ob->query("id"));
	ob->delete("class");
}


int do_yes()
{
	object me, ob;

	me = this_object();
	ob = this_player();
	
	ob->set("wudang/offerring", 1);
	message_vision("$N大声说道：愿意！\n", ob);
	ob->set("title", "武当道童");
	ob->delete_temp("pending/apprentice");
	command("haha "); 
	command("say 很好！很好！从今日起，你就是武当一名见习学徒。");
	command("say 希望"+ RANK_D->query_respect(ob) +"勤加努力，早日入我正门中。");

	return 1;	
}


// End of File
