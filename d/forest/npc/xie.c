//Cracked by Roath
// Jay 5/7/97
#include <ansi.h>

inherit NPC;

int waiting(object me);
int checking(object me);
int do_chase(object me);
int do_kill(object me, object dest);

void create()
{
	set_name("谢烟客", ({ "xie yanke", "xie" }));
	set("nickname", "摩天居士");
	set("long", 
	"他是个身形高大，相貌清矍的老者。一袭青袍在内力激荡下鼓鼓做响。\n"+
	"颌下一副短须，脸上泛出淡淡的青色。\n");
	set("gender", "男性");
	set("age", 55);
	set("attitude", "heroism");
	set("shen_type", 0);
	set("str", 37);
	set("int", 37);
	set("con", 40);
	set("dex", 35);
	
	set("max_qi", 1800);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 1500000);

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
        set_skill("qimen-dunjia", 150);
	set_skill("strike", 150);
	set_skill("hand",150);
	set_skill("finger", 150);
	set_skill("yuxiao-jian", 150);
	set_skill("tianji-xuangong", 150);
	set_skill("luoying-shenjian",150);
	set_skill("luoying-shenfa", 150);
	set_skill("kick", 150);
	set_skill("xuanfeng-saoye", 150);
	set_skill("lanhua-fuxue", 150);
	set_skill("tanzhi-shentong", 150);

	map_skill("force", "tianji-xuangong");
	map_skill("parry", "yuxiao-jian");
	map_skill("finger", "tanzhi-shentong");
	map_skill("strike", "luoying-shenjian");
	map_skill("dodge", "luoying-shenfa");
	map_skill("kick", "xuanfeng-saoye");
	map_skill("hand", "lanhua-fuxue");
	
	prepare_skill("finger", "tanzhi-shentong");

	setup();
	carry_object("/d/xixia/obj/robe")->wear();
}


void init()
{
        object me, ob;

        me = this_object();
        ob = this_player();

        ::init();

        if( !me->query("waiting_target") && ob->query_temp("fee_paid") ) 
                ob->delete_temp("fee_paid");

        add_action("do_name","杀");
	add_action("do_zao","要");

}

int do_zao(string target)
{
	object me, who, date;
	
	who = this_player();
	me = this_object();

	if (!who->query_temp("ling_paid")) return 0;
	
	command ("say 好，老伯伯这就给你摘。");
	date = new(__DIR__"obj/zao");
	date->move(who);
	message_vision("$N纵身上树，给$n摘了一粒大红枣。\n", me, who);
	command("say 好了，这下咱们谁也不欠谁的了。");
	command("jump");
	who->delete_temp("ling_paid");
	return 1;
}

int do_name(string target)
{
        object me, dest, *all;
        int i;
 
        me = this_object();
        all = users();

/*
        if( me->query("sg/spy") )
                return notify_fail("谢烟客哈哈大笑道：神龙教杀个人还要老夫出马？！\n");
*/

        if( me->query("waiting_target") )
                return notify_fail("谢烟客抱歉地说道：我现在正忙着哪，您呆会儿在来吧！\n");

        if( !this_player()->query_temp("fee_paid") ) 
                return notify_fail("谢烟客说道：要杀你自己去杀好了！\n");

        if( !target || target==" ") 
                return notify_fail("谢烟客不耐烦地说道：快告诉我那家伙的名字，我可没功夫听你闲聊！\n");

        for(i=0; i<sizeof(all); i++) 
        {
                if( target == all[i]->name() || target == all[i]->query("id") )
                        dest = all[i];
	}

        if( !dest )
                return notify_fail("谢烟客一声冷笑：他现在不在游戏中，过会再来吧。\n");

        if (dest->is_ghost())
                return notify_fail("谢烟客很不高兴地说道：他已经是个死鬼了，你还来找我干什么！\n");

/*
        if( dest->query("sg/spy") )
                return notify_fail("谢烟客吓了一跳，说道：神龙教的人我惹不起！\n");
*/

        me->set("waiting_target", dest->query("id"));
        me->set("target_name", target);
        log_file("Playing", sprintf("%s(%s) attempted to let Xie Yanke to kill %s(%s)\n",
                        this_player()->query("name"), getuid(this_player()),
                        dest->query("name"), dest->query("id")) );

        message("vision",
                HIY "谢烟客嘿嘿嘿地干笑了几声，说道：幸好你没让我自残身体。\n"NOR,
                environment(), me );

//        me->set("pursuer", 1);

        message_vision("$N走了出去。\n" NOR, me);

        call_out("do_chase", 1, me);

        return 1;
}

int accept_object(object who, object ob)
{

        if (ob->query("id")=="xuantie ling" 
                && !this_object()->query("waiting_target")) 
        {

        if ((int)this_player()->query("age") < 16
        || this_player()->query("combat_exp") < 10000){
                tell_object(who, "谢烟客轻蔑地瞧了你一眼，不屑地说道：小毛孩子算不得数。\n");
                return 1;
                }

                tell_object(who, "谢烟客高兴地问你："+RANK_D->query_respect(who)+
			"，你饿了吧，要不要吃枣？\n");
                tell_object(who, "请键入：要\n");
                who->set_temp("ling_paid",1);
                return 1;
        }
        else if (ob->query("money_id")) 
        {
                tell_object(who, "谢烟客嘿嘿一笑，说道：给我这么多钱？ 将来我可没法还你啊。\n");
                return 1;
        }
	else if(ob->query("id")=="zao") {
		command("say 想不到老夫纵横江湖多年，还要你请客。");
		if (who->query_temp("ling_paid")) {
                	tell_object(who, "谢烟客沉下脸来：要不然这样吧，我帮你杀个仇家。\n");
                	tell_object(who, "请键入：杀 目标中文名字\n");
                	who->set_temp("fee_paid",1);
			who->delete_temp("ling_paid");
		}
                return 1;
	}

        return 0;
}

int do_chase(object me)
{
        object dest;
        dest = find_player(me->query("waiting_target"));

        if( !objectp(dest) || !environment(dest) )
        {
                call_out("waiting", 0, me);
                return 1;
        }

        me->move(environment(dest));
        message_vision("$N走了过来。\n" NOR, me);
        me->set_leader(dest);
        command("look " + dest->query("id"));

        if ( !environment(me)->query("no_fight"))
        {
                call_out("do_kill", 1, me, dest);
                return 1;
        }
        else
        {
                call_out("waiting", 0, me);
                return 1;
        }

        return 1;
}

int do_kill(object me, object dest)
{

        if( objectp(dest) && present(dest, environment(me))
                 && !environment(me)->query("no_fight"))
        {
                message_vision(HIR "$N对$n说道：当年我把玄铁令交给三个对我有恩的朋友，发誓会帮把玄铁令给我的人做任何事，现在有人要我杀了你。\n"
                        +RANK_D->query_respect(dest)+"，你认命吧！\n" NOR, me, dest);
                me->set_leader(dest);
                me->kill_ob(dest);
                dest->fight_ob(me);

                call_out("checking", 0,  me); 
        }
        else  
                call_out("waiting", 1, me); 

        return 1;
}

int waiting(object me)
{
        object dest;
        dest = find_player(me->query("waiting_target"));

        if ( objectp(dest) )
        {
                if (dest->is_ghost())
                {
                        me->delete("waiting_target");
                        call_out("do_back", 1, me);
                        return 1;
                }else if (me->is_fighting() && present(dest, environment(me)))
                {
                        call_out("checking", 0, me);
                        return 1;
                }else if (living(me) && !environment(dest)->query("no_fight"))
                {
                        call_out("do_chase", 0, me);
                        return 1;
                }
        }

        remove_call_out("waiting");
        call_out("waiting", 60, me);
    return 1;
}

int checking(object me)
{
        object ob;

        if (me->is_fighting()) 
        {
                call_out("checking", 1, me);
        return 1;
        }

        if( objectp(ob = present("corpse", environment(me)))
                 && ob->query("victim_name") == me->query("target_name") )
        {
                me->delete("waiting_target");
                call_out("do_back", 1, me);
        return 1;
        }

        call_out("waiting", 0, me);
        return 1;
}

int do_back(object me)
{

        me->move("/d/forest/mty1");
        message("vision", "谢烟客走了进来，拍了拍身上的尘土，\n"
                "笑道：老天爷保佑，你只是让我杀个人。\n", 
                environment(), me );
        return 1;
}

