//Cracked by Roath
// su quan 苏荃

#include <ansi.h>
inherit NPC;
//inherit F_MASTER;

int do_song(string);
//int do_bai();
string ask_wan();
string ask_miji1();

void create()
{
	set_name("苏荃", ({ "su quan","su", "furen" }));
	set("title", "神龙教教主夫人");
	set("long",
		"美貌少妇，看模样不过二十三四岁年纪，微微一笑，媚态横生，艳丽无比。\n");
	set("gender", "女性");
	set("age", 23);
	set("attitude", "peaceful");
	set("shen_type", -1);

	set("str", 23);
	set("int", 28);
	set("con", 24);
	set("dex", 24);
	set("max_qi", 800);
	set("max_jing", 600);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 20);
	set("combat_exp", 50000);
	set("score", 5000);
	set("shen", -8000);

	set_skill("force", 50);
	set_skill("dulong-dafa", 50);
	set_skill("dodge", 55);
	set_skill("lingshe-shenfa", 55);
 	set_skill("strike", 54);
        set_skill("huagu-mianzhang", 80);
	set_skill("parry", 56);
	set_skill("sword", 58);
	set_skill("meiren-sanzhao", 65);
	set_skill("kick", 55);
	set_skill("jueming-tui", 55);
	set_skill("literate", 80);
	set_skill("medicine", 80);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
        map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "meiren-sanzhao");
	map_skill("sword", "meiren-sanzhao");
	map_skill("kick", "jueming-tui");

	prepare_skill("kick", "jueming-tui");

        create_family("神龙教", 3, "弟子");

        set("chat_chance", 5);
        set("chat_msg", ({
                "苏荃幽幽地说道：教主去年送给我的那根金项链不知弄哪儿去了。\n",
        }) );

	set("inquiry", ([
	//	"百涎丸" : (: ask_wan :),
	//	"神龙秘籍" : (: ask_miji1 :),
	]));

	setup();

	carry_object("/clone/weapon/duanjian")->wield();
	carry_object("/d/city/obj/pink_cloth")->wear();
	carry_object("/d/city/obj/flower_shoe")->wear();
}

void init()
{
        add_action("do_learn", "learn");
        add_action("do_learn", "xue");
}

int accept_object(object who, object ob)
{
        int sg_exp;
        string chname = "", name;

        if( !who->query("sg/spy") ) {
                command("consider " + who->query("id"));
                return notify_fail("苏荃大怒道：不要脸！滚！谁要你讨好我？！\n");
        }

        name = ob->name();
        for(int i = 0; i < strlen(name); i++)
                if(name[i] > 160 && name[i] < 255) chname += name[i..i];

        if( chname != "金项链" ) {
                command("sigh " + who->query("id"));
                return notify_fail("苏荃幽幽地说道：你怎么就不懂我的心？\n");
        }

        if( (int)query("amount") > 3 )
                return notify_fail("苏荃叹口气,说道：多谢你啦，不过我已经有好多了。\n");

        command("say 多谢这位"+ RANK_D->query_respect(who) + "了，我好喜欢耶。");
        add("amount", 1);
        call_out("destroy", 1, ob);

        if( (sg_exp = (int)who->query("sg/exp")) < 100 )
                who->add("sg/exp", 1);

        if( who->query("gender") != "女性" ) {
                say("苏荃叹口气,说道：你要是女孩子就好了。\n");
                return 1;
        }

        if( sg_exp < 200 ) {
                say("苏荃叹口气,说道：可惜你的功劳不够大，否则我就教你「美人三招」。\n");
                return 1;
        }

        if( (int)who->query_skill("meiren-sanzhao") > 30 ) {
                say("苏荃说道：你已经不用我教你了。\n");
                return 1;
        }

        message_vision("苏荃同意教$N几些「美人三招」的技巧。\n", who);

        who->set_temp("su/nod", 1);
        return 1;
}

void destroy(object ob)
{
        destruct(ob);
}   

int do_learn(string arg)
{
        object ob, me = this_player();
        string skill, who;
        int gin_cost, my_skill;

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if(!arg || (sscanf(arg, "%s %s", who, skill)!=2 ))
                return notify_fail("指令格式：learn|xue <某人> <技能>\n");

        if( me->is_fighting() )
                return notify_fail("临阵磨枪？来不及啦。\n");

        if( !(ob = present(who, environment(me))) || ob != this_object() )
                return notify_fail("你要向谁求教？\n");

        if( !living(this_object()) )
                return notify_fail("嗯....你得先把" + name() + "弄醒再说。\n");

        if( is_busy() || is_fighting() )
                return notify_fail(name() + "现在正忙着呢。\n");

        if( skill != "meiren-sanzhao" )
                return notify_fail("这项技能你恐怕必须找别人学了。\n");

        if( (my_skill = (int)me->query_skill(skill, 1)) > 30 )
                return notify_fail("你已经不用苏荃再教你了。\n");

        if( !me->query_temp("su/nod") )
                return notify_fail(name() + "看起来不大愿意教你。\n");

        gin_cost = 150 / (int)me->query("int");
        if( !my_skill ) {
                gin_cost *= 2;
                me->set_skill(skill,0);
        }

        if( (int)me->query("potential") <= 0 )
                return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");

        printf("你向%s请教有关「%s」的疑问。\n", name(), to_chinese(skill));

        tell_object(this_object(), sprintf("%s向你请教有关「%s」的问题。\n",
                me->name(), to_chinese(skill)));

        if( (int)me->query("jing") > gin_cost ) {
                printf("你听了%s的指导，对%s似乎有些心得。\n",
                        name(), to_chinese(skill));
                me->improve_skill(skill, random(me->query_int()));
        } else {
                gin_cost = me->query("jing") > 0 ? (int)me->query("jing") : 0;
                write("你今天太累了，结果什么也没有学到。\n");
        }

        me->receive_damage("jing", gin_cost);
        return 1;
}




