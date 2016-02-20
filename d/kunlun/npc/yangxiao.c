//Cracked by Roath

#include "mingjiao_npc.c"
#include <ansi.h>


int rujiao(object player);
int rujiao1(object player);
void create()
{
		mapping S_skills= ([ ]);
		mapping I_inquiry=([ ]);
		mixed Skill_name;
        set_name("杨逍",({"yang xiao","yang","xiao"}));
        set("title", "明教光明左使");

        set("long", "
他就是明教的光明左使，和范遥合称逍遥二仙的杨逍。
他身着一身白衫，虽然已是中年，但看上去还十分英俊潇洒。\n");
        set("gender", "男性");
        set("age", 43);
        set("attitude", "peaceful");
        set("shen", 3000000);
        create_family("明教",34,"使者");
		
		I_inquiry["name"]="在下就是明教光明左使杨逍，不知阁下有何指教。";

	Skill_name=({"shenghuo-xuanming","xiaoyao-piaopiao","xiaoyao-zhangfa",
		     "xiaoyao-jianfa","riyue-shenzhang","shenghuo-quan","guangming-xinfa"});
		Set_Inquiry(I_inquiry,Skill_name);

		Set_Npcattrib(27,5,5000,300,7000,400,9000,300,5000,1000,3000000,100000);

//	S_skills["dodge"]="xiaoyao-piaopiao";
//	S_skills["parry"]="qiankun-danuoyi";
	S_skills["sword"]="xiaoyao-jianfa";
//	S_skills["force"]="shenghuo-xuanming";
//	S_skills["cuff"]="shenghuo-quan";
//	S_skills["strike"]="xiaoyao-zhangfa";
//	set_skill("riyue-shenzhang",300+random(20));
//	set_skill("guangming-xinfa",380+random(20));
	set_skill("literate",300+random(20));
	
	Set_Npcskills(300,20,S_skills);
	
	prepare_skill("strike","xiaoyao-zhangfa");
	

        setup();

	carry_object(OBJ_PATH"/changpao")->wear();
	carry_object(OBJ_PATH"/sword")->wield();
}

int rujiao(object player)
{
	
	command("hi"+" "+player->query("id"));
	command("look"+" "+player->query("id"));
	player->start_busy(4);

    remove_call_out("rujiao1");
    call_out("rujiao1", 3, player);



}
int rujiao1(object player)
{
	object ling;
	command("say "+"好！既然这位"+RANK_D->query_respect(player)+"想加入我光明圣火教，那么从今天起，你就是我明教信徒！\n");
	player->create_family("明教",38,"教众");
	set_title(player,38);
	tell_object(player,HIC"恭喜您成为明教教众！\n"NOR);

	
	command("say "+"这位"+RANK_D->query_respect(player)+"请随我来。\n");
	message_vision("$N往里走去。\n$n跟着杨逍往里走去。\n",this_object(),player);
	move(MINGJIAO"/daguangchang");
	player->move(MINGJIAO"/daguangchang");
	message_vision("$N走来过来。\n$n跟着杨逍走来过来。\n",this_object(),player);	
	//here need add later
	message_vision("$N对$n说到：这里就是我明教重地光明顶。\n",this_object(),player);	
    if(objectp(ling = present("tieyan ling", player)) )
	{
		message_vision("$N对$n说到：你刚入我教，怎可能有我教的铁焰令？如果是什么bug请汇报给wzfeng。\n",this_object(),player);	
		return 1;
	}
	ling = new(OBJ_PATH"/tieyanling");
	ling->move(player);
	tell_object(player,"杨逍从怀中取出一块状似火焰的令牌。\n");
	tell_object(player,"杨逍对你说到：这是我教信物<铁焰令>，你需要随身携带，不可丢失。\n");
	tell_object(player,"杨逍给你一块铁焰令。\n");
	command("say "+"你刚入我教，可以随便走走，看我明教声威比齐江湖其它各派如何。\n");
	command("say "+"你可先去五行旗，向旗主们学些入门的功夫。\n");
	command("say "+"我还有要务在身，先行告退。\n");
	move(MINGJIAO"/shting");
	message_vision("$N走了过来。\n",this_object());
	return 1;
	

}

