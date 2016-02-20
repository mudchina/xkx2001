//Cracked by Roath
// Kane
// maco
/*
shendiao 15
这一年她武功初成，禀明师父，北上找寻表妹，在关陕道上与杨过及陆无双相遇，途中示警、夜半救人，便都是她的手笔了。众少年合斗李莫愁後，她带同陆无双到这荒山中来结庐疗伤。
她所穿青袍虽是布质 ，但缝工精巧，裁剪合身，穿在身上更衬得她身形苗条，婀娜多姿，实是远胜锦衣绣服 ，而乾粮、水壶等物，无一不安排妥善，处处显得她心细如发。
*/
/*
那少女在一张矮几上放了饭菜，端到他床上，服侍他吃饭。竹筷陶碗，虽是粗器，却都是全新的，纵然一物之微，看来也均用了一番心思。那菜肴也只平常的青菜豆腐、鸡蛋小鱼，但烹饪得甚是鲜美可口。
当晚那少女果然裹了几只粽子给他作点心，甜的是猪油豆沙，咸的是火腿鲜肉，端的是美味无比，杨过一面吃，一面喝采不迭。
*/

inherit NPC;
#include <ansi.h>
#include "/d/REGIONS.h";
//int auto_perform();
string ask_bagua();

void create()
{
        set_name("程英", ({ "cheng ying", "cheng", "ying" }));
        set("long",
"她是黄药师晚年收的小弟子，她面色晶莹，肤光如雪，鹅蛋脸儿上\n"
"有一个小小酒窝，微现腼腆，是个极美的姑娘。\n");
        set("gender", "女性");	
        set("title", "桃花岛第二代弟子");
	set("age", 19);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 23);
	set("int", 23);
	set("con", 20);
	set("dex", 25);
	
	set("max_qi", 1100);
	set("max_jing", 800);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 60);
	set("combat_exp", 90000);
/*
	set_temp("apply/armor", 50);
	set_temp("apply/attack", 80);
	set_temp("apply/dodge", 80);
*/
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("finger", 90);
	set_skill("parry", 90);
        set_skill("sword", 90);
	set_skill("qimen-dunjia", 90);
	set_skill("music", 90);
	set_skill("kick", 90);
	set_skill("bitao-xuangong", 90);
	set_skill("luoying-shenfa", 90);
	set_skill("tanzhi-shentong", 90);
	set_skill("xuanfeng-saoye", 90);
	set_skill("hand", 90);
	set_skill("lanhua-fuxue", 90);
	set_skill("strike", 90);
	set_skill("luoying-shenjian", 90);
	set_skill("yuxiao-jian", 90);
	
	map_skill("force", "bitao-xuangong");
	map_skill("dodge", "luoying-shenfa");
	map_skill("finger", "tanzhi-shentong");
	map_skill("kick", "xuanfeng-saoye");
	map_skill("strike", "luoying-shenjian");
	map_skill("sword", "yuxiao-jian");

	prepare_skill("strike", "luoying-shenjian");
	prepare_skill("kick", "xuanfeng-saoye");
/*	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );
*/

	set("family",([
	"generation" : 2,
	"family_name" : "桃花岛",
	"enter_time" : 999999999,
	"title" : "弟子",
	"master_name" : "黄药师",
])) ;

//	create_family("桃花岛", 2, "弟子");
        set("inquiry", ([
		"陆无双" : "她是我的表妹。",
		"李莫愁" : "那是害死我姨丈、姨妈的女魔头。",
		"黄药师" : "小女子入门日浅，功夫低微，不能为师父争一口气，实是惭愧。",
		"占卜" : "本派弟子在对奇门遁甲有所了解後，可以用铁八卦进行占卜。",
		"杨过" : (: command(":(") :),
		"桃花岛" : "似小女子这等年幼末学，实不敢说是桃花岛弟子，况且迄今小女子连桃花岛也没缘法踏上一步。",
		"铁八卦" : (: ask_bagua :),
		"bagua" : (: ask_bagua :),
        ]));

	setup();
	carry_object("/d/xixia/obj/robe")->wear();
	carry_object("/d/taohua/obj/zhuxiao")->wield();
}

void init()
{
        ::init();
	add_action("do_divine", "divine");
	add_action("do_divine", "zhanbu");
}


void attempt_apprentice(object ob)
{
        string tongmen,ttt;

	if (ob->query("gender") == "男性") tongmen = "师兄";
	else  if (ob->query("gender") == "女性") tongmen = "师姐";


	if (ob->query("class") 
	&& (ob->query("class") != "beggar" && ob->query("class") != "officer") 
	|| (ob->query("family/family_name") != "桃花岛" && ob->query("combat_exp") >= 10000) ) {
                command("say " + RANK_D->query_respect(ob) 
                + "是它方高士，何必开小女子这个玩笑？\n");
                return;
        } 
	if( ob->query("family/family_name") != "桃花岛"
	&& ob->query("combat_exp") >= 10000 ) {
		command ("say " + RANK_D->query_respect(this_player()) + "是"
		+ob->query("family/family_name")+"高手，小女子本领低微，焉敢妄为人师？");
		return;
	}
	
	if (this_player()->query("gender") == "无性") {
		command ("say " + RANK_D->query_respect(this_player()) + "身在东厂，恐怕难以见容於家师。");
		return;
	}
	
	if( ob->query("family/family_name") == "桃花岛"
        && ob->query("family/master_name") == "黄药师" ) {
	        command ("smile");
                command ("say " + tongmen + "，你跟小妹开玩笑麽？");
                return;
        }
	if( ob->query("family/family_name") == "桃花岛"
        && ob->query("family/master_name") == "陆乘风" ) {
	if (this_player()->query("gender") == "男性") ttt = "门生";
	else  if (this_player()->query("gender") == "女性") ttt = "青衣"; 

	command("smile "+ ob->query("id"));
	command("say 既然你是陆师兄的弟子，我收了你也不妨，祗是我本领低微，万万比不上陆师兄。");
	command("say 这样罢，平日你还是继续待在归云庄做"+ttt+"，在本门学艺上有什麽疑难，再来找我好了。");
	command("recruit " + ob->query("id"));
	ob->set("title", "归云庄" + ttt);
	}
	else 
	command("say 小女子那有这个资格呢，" + RANK_D->query_respect(ob) + "还是另投名师的好。");
}

int accept_kill(object me)
{
        if (me->query("family/family_name") == "桃花岛"){
	command(":( "+getuid(me));
        me->set("th_killer", 1);
        kill_ob(me);
        return 1;
        }
        return 0;
}

int do_divine(string arg)
{
        object ob, where, env, me = this_player();
        string region;
	
	if (!me->query_temp("zhanbu_bagua"))
		return 0;

        if( !living(this_object()) )
                return notify_fail("嗯....你得先把程英弄醒再说。\n");

        if( this_object()->is_busy() )
                return notify_fail("程英说道：请稍等一下。\n");

	if(this_object()->query("jing") < 50)
                return notify_fail("程英现在的精神状况无法占卜。\n");

	if (!arg) return notify_fail("你要占卜谁的位置？\n");

        if( !(ob = find_player(arg)) )
        if( !(ob = find_living(arg)) )
	        return notify_fail("程英告诉你：现在没这个人。\n");
	        
        if( ob == me )
	        return notify_fail("占卜自己的位置？没这个必要吧。\n");
	        
        if( ob == this_object() )
	        return notify_fail("要程英占卜程英？没道理吧。\n");

	        write("\n你悄声对程英说道：麻烦姑娘替我占卜"+ob->name()+"的所在。\n\n");
        tell_room( environment(me), "\n"+me->name() + "低声对程英说了些话。\n", ({ me, this_object() }) );

	message_vision(CYN"程英拿起一只铁八卦屏心凝气，拇指依次掐向铁八卦上子、、寅、卯、辰、巳、午、未、申、酉、戌、亥\n各个方位，细心推算起来……\n\n"NOR, me);
	me->start_busy(1);

	if( !(where = environment(ob)) ) {
		command("consider");
	        return notify_fail("程英告诉你：这个人现在无法找到。\n");
		}
        if( !wizardp(me) && wizardp(ob) ) {
		command("consider");
		return notify_fail("程英说道：这人是位巫师，小女子占卜不来的。\n");
		}
        if( strsrch(file_name(where), "/d/") != 0
        ||  undefinedp(region = region_names[explode(file_name(where), "/")[1]]) ) {
        	command("doubt xiang shi");
                return notify_fail("程英告诉你：这个人现在无法找到。\n");
		}

	env = environment(me);

	if( me->query_kar() > ob->query_kar()/3 + random(ob->query_kar()*2/3) ) {
	
	command("whisper "+me->query("id")+" "+ob->name()+"("+ob->query("id")+")现在在"+region+""+where->query("short")+"。");
		if( random(me->query("kar")) < ob->query("kar") )
                tell_object(ob, HIB"你感觉心神不定，似乎有人在暗中窥视着你......好像是"+me->query("name")+"("+me->query("id")+")！\n"NOR);
	} 
	
	else if( me->query_kar() > random(ob->query_kar()/2) ) {
	command("whisper "+me->query("id")+" "+ob->name()+"("+ob->query("id")+")现在在"+region+"一带。");
	 	if( random(me->query("kar")) < ob->query("kar"))
                tell_object(ob, HIB"你感觉心神不定，似乎有人在暗中窥视着你......好像是"+me->query("name")+"("+me->query("id")+")！\n"NOR);

	} else {
	command("blush");
	command("say 对不起……小女子学艺粗浅，"+ RANK_D->query_respect(me) +"的福缘又不是很好，所以算不出来……");
	}
	
	add("jing",-50);
	me->delete_temp("zhanbu_bagua");
        set("zhanbu_done/"+me->query("id"),1);
        call_out("wait_zhanbu", 900, me);
	return 1;
}

void wait_zhanbu(object me)
{
        delete("zhanbu_done/"+me->query("id"));
}

int accept_object(object who, object ob)
{
        object me = this_player();
        string tongmen;
	if (me->query("gender") == "男性") tongmen = "师兄";
	else  if (me->query("gender") == "女性") tongmen = "师姐";

        if (ob->query("name") !="铁八卦" ) 
		return 0;
	if (query("zhanbu_done/"+me->query("id")))
                return notify_fail("你刚才已经找程英占卜过了。\n");

        if(me->query("combat_exp") < 10000)
                return notify_fail("你的经验太低了，无法请人占卜。\n");
		
        if (ob->query("name") =="铁八卦" && (int)me->query_skill("qimen-dunjia",1) > 90 && me->query("family/master_name") == "黄药师"){
                tell_object(who, "程英微笑道："+tongmen+"本事胜於小妹，何必多此一举呢。\n");
                return 0;
                }
        if (ob->query("name") =="铁八卦" && me->query("family/master_name") == "金轮法王"){
                tell_object(who, "程英说道：你是金轮法王的弟子……我绝不会帮你占卜的。\n");
                return 0;
                }


        call_out("accept_obj", 1, who, ob);
        return 1;
}

int accept_obj(object who, object ob)
{
        object me = this_player();
        string tongmen;

	if (me->query("gender") == "男性") tongmen = "师兄";
	else  if (me->query("gender") == "女性") tongmen = "师姐";
	
        if(me->query("combat_exp") < 10000)
                return notify_fail("你的经验太低了，无法请人占卜。\n");

	if (query("zhanbu_done/"+me->query("id")))
                return notify_fail("你刚才已经找程英占卜过了。\n");
        if (ob->query("name") !="铁八卦" ) 
		return 0;
        if (ob->query("name") =="铁八卦" && (int)me->query_skill("qimen-dunjia",1) > 90 && me->query("family/master_name") == "黄药师"){
                tell_object(who, "程英微笑道："+tongmen+"本事胜於小妹，何必多此一举呢。\n");
                return 0;
                }
        if (ob->query("name") =="铁八卦" && me->query("family/master_name") == "金轮法王"){
                tell_object(who, "程英说道：你是金轮法王的弟子……我绝不会帮你占卜的。\n");
                return 0;
                }

        if (ob->query("name") =="铁八卦" ) 
        {		
		command("oh "+me->query("id"));
		command("say "+ RANK_D->query_respect(me) +"既然有本门信物，小女子尽力一试就是。但不知"+ RANK_D->query_respect(me) +"要占卜什麽？");
                who->set_temp("zhanbu_bagua",1);
                add("bagua_count",1);
//                call_out("destory", 1, ob);
		destruct(ob);

                return 1;
        }

        return 0;
}

string ask_bagua()
{
        string tongmen;
       	object me = this_player();
	if (me->query("gender") == "男性") tongmen = "师兄";
	else  if (me->query("gender") == "女性") tongmen = "师姐";

        if (me->query("family/family_name") != "桃花岛")
                return "铁八卦是本门信物，可以用于奇门遁甲之术。";
                
        if (  present("tie bagua", me) || me->query_temp("cy_bagua"))
                return "嗯……你应该有铁八卦了吧？";
                
        if (me->query_skill("qimen-dunjia", 1) < 60 || me->query_skill("bitao-xuangong", 1) < 60)
                return "我想你还不是很需要铁八卦吧？";

        if (query("bagua_count") < 1){
		command("consider");
                return "我这里没有铁八卦。";
	}


	add("bagua_count", -1);
        new("/d/taohua/obj/bagua")->move(me);
        me->set_temp("cy_bagua",1);
	command("nod");
        message_vision("程英给$N一枚铁八卦。\n", me);
        if (query("bagua_count") < 1){
		if (me->query("family/master_name") == "黄药师") 
		command ("say "+tongmen+"，这是最後一枚铁八卦了哦。");
		else  command("say "+ RANK_D->query_respect(me) +"，这是最後一枚铁八卦了哦。");
	}

	return "陆师兄那里也有几枚铁八卦，平常也可以找他拿。";

}

