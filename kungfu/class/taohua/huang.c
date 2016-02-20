//Cracked by Roath
// Kane,
// maco
// mantian 

inherit NPC;
#include <ansi.h>
int auto_perform();
int ask_shagu();
int ask_chengfeng();
int ask_fenfu();
string* xuedao = ({
	"风池穴", "风府穴", "强间穴", "大椎穴", "至阳穴",
	"百会穴", "灵台穴", "太阳穴", "膻中穴", "命门穴",
	});

void create()
{
	set_name("黄药师", ({ "huang yaoshi", "huang" }));
	set("title", "桃花岛主");
	set("nickname", "东邪");
	set("long",
		"他就是名震天下的桃花岛主「东邪」黄药师，但见他形相清癯，\n"
		"丰资秀爽，湛然若神。一袭青袍，领后插着一支玉箫，神色之间\n"
		"大有一股落拓山林的逸气。\n");
	set("gender", "男性");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 35);

	set("max_qi", 4500);
	set("max_jing", 4500);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 200);
	set("combat_exp", 3600000);
	set("score", 5000);
	set_temp("apply/armor", 50);
	set_temp("apply/attack", 50);
	set_temp("apply/dodge", 50);	
	set("th_jianyi", 6);

	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("parry", 360);
	set_skill("sword", 400);
	set_skill("whip", 360);
	set_skill("qimen-dunjia", 400);
	set_skill("strike", 360);
	set_skill("hand",360);
	set_skill("finger", 400);
	set_skill("yuxiao-jian", 400);
	set_skill("canglang-bian", 360);
	set_skill("bitao-xuangong", 400);
	set_skill("luoying-shenjian",400);
	set_skill("luoying-shenfa", 400);
	set_skill("kick", 360);
	set_skill("xuanfeng-saoye", 360);
	set_skill("lanhua-fuxue", 360);
	set_skill("tanzhi-shentong", 400);
	set_skill("throwing", 400);
	set_skill("literate", 400);
	set_skill("music", 400);

	map_skill("force", "bitao-xuangong");
	map_skill("parry", "tanzhi-shentong");
	map_skill("sword", "yuxiao-jian");
	map_skill("finger", "tanzhi-shentong");
	map_skill("strike", "luoying-shenjian");
	map_skill("dodge", "luoying-shenfa");
	map_skill("kick", "xuanfeng-saoye");
	map_skill("hand", "lanhua-fuxue");

	if (random(2) == 1) {
		prepare_skill("strike", "luoying-shenjian");
		prepare_skill("kick", "xuanfeng-saoye");
	} 
	else prepare_skill("finger", "tanzhi-shentong");
//	prepare_skill("hand", "lanhua-fuxue");

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	create_family("桃花岛", 1, "掌门人");
	set("inquiry", ([
		"桃花岛" : "你不就在桃花岛上吗？！",
		"九花玉露丸" : "那是本门第一灵丹妙药，采九种奇花清晨露水配合其它珍奇药材制成，功效灵验无比。",
		"奇门遁甲" : "这门学问博大精深，非片言只语所能尽诉。",
		"五音" : "宫、商、角、徵、羽为五音。",
		"十二律" : "律有十二，阳六为律，阴六为吕。律以统气类物，分别为黄锺、太蔟、姑洗、蕤宾、夷则、无射。吕以旅阳宣气，分别为林钟、南吕、应钟、大吕、夹钟、中吕。",
		"黄蓉" : "这鬼丫头不知到又疯哪去了，成天不见人影。",
		"郭靖" : "这傻小子一提起来我就气！！",
		"女婿" : "想我黄老邪平生所交尽是才子名士，最后却收了个傻女婿，真是气死我了！",
		"陈玄风" : "别在我面前提这个孽徒的名字！",
		"梅超风" : "别在我面前提这个孽徒的名字！",
		"曲灵风" : "灵风本来是我武功最强的弟子，但现在腿一断，一身武功可就......", 
		"陆乘风" : (:ask_chengfeng:),//"乘风天性不适习武，造诣也就有限。",
		"冯默风" : "默风年纪虽小，却已得了师门真传。",
		"武眠风" : "眠风寡言少语，但却用功最勤。",
		"程瑛" : "瑛儿天资虽不如我那女儿，但跟我日久，也学到不少东西，千万不要以为她年纪小而小瞧了她。",
		"程英" : "瑛儿天资虽不如我那女儿，但跟我日久，也学到不少东西，千万不要以为她年纪小而小瞧了她。",
		"洪七公" : "老叫化好久不见，不知近况如何，听说被一帮小叫化灌吃豆腐吃得坏了肚子。",
		"老叫化" : "老叫化好久不见，不知近况如何，听说被一帮小叫化灌吃豆腐吃得坏了肚子。",
		"北丐" : "北丐就是丐帮帮主，老叫化洪七公。",
		"欧阳锋" : "老毒物成天缩在白驼山不露面，是在调教新弟子吧。",
		"老毒物" : "老毒物成天缩在白驼山不露面，是在调教新弟子吧。",
		"西毒" : "那就是西域白驼山庄庄主，老毒物欧阳锋。",
		"南帝" : "他就是当今大理国一国之君，大理段氏一阳指的嫡系传人段智兴。",
		"段皇爷" : "段皇爷已经好久没听到他消息了。",
		"段智兴" : "段智兴不就是段皇爷吗？",
		"黄老邪" : "黄老邪就是我，我就是黄老邪！",
		"东邪" : "东邪黄药师就是我，我就是东邪黄药师！",
		"黄药师" : "东邪黄药师就是我，我就是东邪黄药师！",
		"name" : "东邪黄药师就是我，我就是东邪黄药师！",
		"南宫浪" : "他是天字第二号大傻瓜，第一号是郭靖。",
		"文" : "文是流通货币中最小的单位，约要一百文铜钱才值得一两白银。",
		"华山论剑" : "三十年前我与老毒物，老叫化，段皇爷和王重阳在华山之巅论剑三日三夜，最后公推王重阳为天下第一。",
		"妻子": "阿蘅，阿蘅，我夜夜为你吹箫，你听得见麽？啊，对不起，老朽失态了。",
		"老婆" : "阿蘅，阿蘅，我夜夜为你吹箫，你听得见麽？啊，对不起，老朽失态了。",
		"夫人" : "阿蘅，阿蘅，我夜夜为你吹箫，你听得见麽？啊，对不起，老朽失态了。",
		"阿蘅" : "你胆敢直呼我夫人的名字？",
		"老顽童" : "老玩童就是周伯通，这有啥好问的？",
		"周伯通" : "周伯通是中神通王重阳的师弟，全真门下有这样的活宝也算是个异数。",
		"软猬甲" : "那是桃花岛镇岛之宝，你再问会招来杀身之祸！",
		"中神通" : "那就是全真教主王重阳。",
		"王重阳" : "他就是五绝中的中神通，也是全真教开山祖师。",
		"九阴真经" : "那是天下第一武学密籍，没本事别乱问！",
		"哑仆" : "黄某并非正人君子，江湖上号称“东邪”，自然也不屑与正人君子为伍。手下仆役，越是邪恶，越是称我心意。",
		"rumors" : "没有。",
		"傻姑" : (: ask_shagu :),
	]));
	setup();
	carry_object("/d/xixia/obj/robe")->wear();
	if (clonep()) carry_object("/clone/unique/yuxiao", "/d/taohua/obj/tiexiao")->wield(); 
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob=this_player()))
	{
		if (ob->query_temp("th_tomb_thief"))
		{
			command("say "+RANK_D->query_rude(ob)+"，胆敢私闯我夫人墓室，纳命来！\n");
			start_busy(1);
//			command("follow " + ob->query("id"));
			kill_ob(ob);
		}
		if (ob->query("th_killer") || ob->query_temp("th_killer"))
		{
			command("sneer "+ob->query("id"));
			command("say 孽徒好大胆子，居然同门弟子手足相残！");
			message_vision(HIR"黄药师说完一抬手，一指戳在$N的"+xuedao[random(sizeof(xuedao))]+"上。\n"NOR, ob);	
			call_out("move_it", 1, ob);
		}
// change to if player 叛师 meet huang he'll auto kill him once
// mantian may/09/2001 
		if( ob->query("gender") == "无性" && ob->query("family/family_name") == "桃花岛" && ob->query("family/master_id") == "huang yaoshi")
		{
			command("say "+ob->query("name")+"你好大胆子！堂堂桃花弟子居然去做东厂走狗。");
			command("expell " + ob->query("id"));
			command("say 滚！别再让我见到！");
		}
		else if ( ob->query("kill_th_traitor") 
			&& ob->query("help_chengfeng")
			&& ob->query("help_lingfeng")
			&& ob->query("help_mofeng")
			&& ob->query("family/family_name") != "桃花岛" )
		{
			command("say "+ob->query("name")+"你背叛师门还有脸回来见我，好大胆子！");
			ob->delete("kill_th_traitor");
			ob->delete("help_chengfeng");
			ob->delete("help_lingfeng");
			ob->delete("help_mofeng");
			kill_ob(ob);
			ob->start_busy(10);
		}
		else if ( ob->query("kill_th_traitor") 
			&& ob->query("help_chengfeng")
			&& ob->query("help_lingfeng")
			&& ob->query("help_mofeng")
			&& ob->query("family/family_name") == "桃花岛" )
		{
			ob->set_temp("huang_recr",1);
			command("smile " + ob->query("id"));
		}
	}
	add_action("do_looko","kick");
	add_action("do_looko","papaya");
	add_action("do_looko","slap");
	add_action("do_looko","slogan");
	add_action("do_looko","cut");
	add_action("do_looko","shutup");
	add_action("do_looko","slash");
	add_action("do_looko","knife");
	add_action("do_looko","nofear");
	add_action("do_looko","points");
	add_action("do_looko","admit");
	add_action("do_looko","loveshoe");

	add_action("do_fearo","hug");
	add_action("do_fearo","kiss");
	add_action("do_fearo","mo97");
	add_action("do_fearo","lovelook");
	add_action("do_fearo","rose");
	add_action("do_fearo","deadlove");
	add_action("do_fearo","joycup");
}
void move_it(object ob)
{
	object *inv;
	int k;

	if(ob)
	{
		ob->set("eff_qi", 10);
		ob->set("eff_jing", 10);
		ob->set("water", 0);
		ob->set("jingli", 0);
		ob->delete("th_killer");
		ob->delete_temp("th_killer");
		inv = all_inventory(ob);
		for(k=0; k<sizeof(inv); k++)
		{
			if(( inv[k]->query("armor_prop") && inv[k]->query("equipped"))
			|| inv[k]->query("no_get")) continue;
			destruct(inv[k]);
		}
		ob->unconcious();
		ob->move("/d/taohua/maze/maze"+(random(63)+1));
	}
}

int attempt_apprentice(object ob)
{
	object obj;
	string name, new_name, str;
	string* m_names = ({
		"浩", "烈", "战", "神", "天", "英", "玉", "剑", "星", "蛟",
		"海", "寒", "流", "鹤", "朝", "空", "洛", "朗", "阳", "清",
		"梦", "闲", "苍", "朔", "幽", "灭", "若", "翔", "幻", "冥",
		"潜", "劫", "旭", "秋", "凯", "乐", "廷", "道", "阴", "御",
		"望", "狂", "穹", "定", "晴", "淳", "旋", "腾", "凰", "寻",
		"云",}); 

	string* f_names = ({
		"兰", "月", "采", "泠", "碧", "星", "虹", "雪", "海", "寒",
		"柔", "霜", "流", "鹤", "雁", "朝", "如", "清", "梦", "闲",
		"慧", "幽", "若", "幻", "冥", "馨", "沐", "秋", "乐", "岚",
		"御", "凝", "盼", "望", "湘", "盈", "慕", "琼", "纯", "扬",
		"舞", "凰", "诗", "飘", "韵", "琳", "涵", "云", "迎", "画",
		"遥",}); 

	if ( !ob->query_temp("huang_recr") )
		return notify_fail("黄药师对你睬也不睬。\n");	

	name = this_player()->query("name");
	
	if( this_player()->query("gender") == "男性") str = m_names[random(sizeof(m_names))];
	else str = f_names[random(sizeof(f_names))];
	new_name = name[0..01] + str + "风";

	this_player()->set("name", new_name);
	command("recruit " + ob->query("id"));
	obj=new("/d/taohua/obj/bagua");
	obj->move(this_object());
	command("give "+this_player()->query("id")+" bagua");
	command("say 从今以后你的名字叫做"+new_name+"。");
	this_player()->delete_temp("huang_recr");
	
	if ( environment(this_object())->query("short") != "黄药师居处" )
	{
		write("说完，黄药师飘然而去。\n");
		destruct(this_object());
	}
	return 1;
}

int do_looko(string target)
{
	call_out("do_look", 1, target);
}

int do_fearo(string target)
{
	call_out("do_fear", 1, target);
}

int do_look(string target)
{
	object me;

	me = this_player();
	if (target=="huang" || target=="huang yaoshi" || target=="yaoshi" )
	{
		if (!me->query_temp("abuse_huang"))
		{
			command("sneer "+getuid(me));
			command("say "+RANK_D->query_rude(me)+"再做一次试试？！\n");
			me->set_temp("abuse_huang", 1);
		} 
		else
		{
			command("stare "+getuid(me));
			command("say "+"老虎不发威，你当是病猫！桃花岛岂是你撒野的地方！\n");
			command("hit "+getuid(me));
			me->delete_temp("abuse_huang");
		}
	}
}

int do_fear(string target)
{
	object me;

	me = this_player();
	if (target=="huang" || target=="huang yaoshi" || target=="yaoshi" )
	if ((string)me->query("gender") != "女性")
	{
		command("fear " + getuid(me));
		command("say "+RANK_D->query_respect(me)+"居然有这种特殊的兴趣爱好，老夫可不敢奉陪。\n");
		if (random(2) > 0) command("kick " + getuid(me));
		else command("slap " + getuid(me));
	} 
	else
	{
		command("smile " + getuid(me));
		command("say "+"老夫自拙荆去后，早已心如止水，"+RANK_D->query_respect(me)+"还是请检点一下。");
		command("sigh");
		write(CYN"黄药师仰首向天，目中似乎有几点精光闪动。\n"NOR);
	}
}

int ask_shagu()
{
	object me, obj;

	me = this_player();

	command("say 这孩子是我在打听灵风下落时找到的，很可能是灵风之女，可惜不知受了什麽惊吓，变成这种样子。");
	if ( (present("amulet" , me) || me->query_temp("play_with_shagu") > 10 ) 
		&& !me->query_temp("ask_huang_about_shagu") )
	{
		command("say 这孩子脑筋不太好，难得你和她如此投缘，我给你书信一封，如果你见到她爹灵风，烦请转交。");
		obj = new("/d/taohua/obj/shouyu");
		obj->move(me);
		me->set_temp("ask_huang_about_shagu", 1);
		message_vision("$N递给$n一封书信。\n", this_object(), me);
	}
	command("sigh");
	return 1;
}

int ask_chengfeng()
{
	object me, obj;
	
	me = this_player();
	command("say 当年我性子太急，错怪了乘风．．．");
	command("sigh");
	if (!query("xfsy_xinfa_given")) {
	command("say 我如今有一套心法，相烦"+RANK_D->query_respect(me)+"交与乘风，照着我这功诀去做，和常人一般慢慢行走却是不难，唉，……");

	obj = new("/d/taohua/obj/xfsy_xinfa");
	obj->move(me);
	set("xfsy_xinfa_given", 1);
	message_vision("$N递给$n一张薄纸。\n", this_object(), me);
	}
	return 1;
}

int accept_kill(object me)
{
	kill_ob(me);
	command("exert wuzhuan");
	return 1;
}

#include "/kungfu/class/taohua/auto_perform.h"