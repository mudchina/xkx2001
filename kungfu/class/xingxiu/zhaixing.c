//Cracked by Roath
// zhaixing.c 摘星子
// Ryu. 1997.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "/kungfu/class/xingxiu/auto_perform.h"
string ask_me();
int ask_dan();
int auto_perform();
void create()
{
        set_name("摘星子", ({ "zhaixing zi", "zhaixing" }));
        set("nickname", "星宿派大师兄");
        set("long", 
                "他就是丁春秋的大弟子、星宿派大师兄摘星子。\n"
                "他脸庞瘦削，眼光中透出一丝乖戾之气。他年纪\n"
                "是师门中最轻的，武功却是最高的。\n");
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 28);
        set("con", 26);
        set("dex", 26);
        
        set("max_qi", 700);
        set("max_jing", 700);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 80);
        set("combat_exp", 500000);
        set("score", 40000);

        set_skill("force", 140);
        set_skill("huagong-dafa", 140);
        set_skill("dodge", 140);
        set_skill("zhaixinggong", 140);
        set_skill("strike", 140);
        set_skill("poison", 140);
        set_skill("chousui-zhang", 140);
        set_skill("feixing-shu", 140);
        set_skill("parry", 140);
        set_skill("claw", 140);
        set_skill("sanyin-zhua", 140);
        set_skill("staff", 140);
        set_skill("tianshan-zhang", 140);
        set_skill("literate", 100);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("claw", "sanyin-zhua");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");

        prepare_skill("strike", "chousui-zhang");
        prepare_skill("claw", "sanyin-zhua");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
        create_family("星宿派", 2, "弟子");

        set("inquiry", ([
                "天山器法" : (: ask_me :),
                "秘籍" : (: ask_me :),
                "秘笈" : (: ask_me :),
                "炼心弹" : (: ask_dan :),
        ]));

        set("book_count", 1);

        setup();
        carry_object("/d/xingxiu/obj/blzhen");
        carry_object("/d/xingxiu/obj/lianxin");
        carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
}

string ask_me()
{
        mapping fam; 
        object ob, *obs, me=this_object();

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
                return RANK_D->query_respect(this_player())+"尚未拜见老仙，怎么倒开口向我要密笈吗？";

        if (query("book_count") < 1)
                return "天山器法秘笈已被他人借走了，下次再给你留着吧。";

        add("book_count", -1);

        obs = filter_array(children("/d/xingxiu/obj/throwing_book.c"), (: clonep :));
        if (sizeof(obs) > 2)
                return "天山器法秘笈已被他人借走了，下次再给你留着吧。";

        ob = new("/d/xingxiu/obj/throwing_book");
        ob->move(this_player());
        return "咱们星宿的暗器名闻天下，这本秘笈你拿去好好研读，别给星宿丢脸！";
}

void attempt_apprentice(object me)
{
        if( me->query("family/family_name") == "丐帮"
        && me->query("combat_exp") >= 10000 ) {
                command ("say 我们老仙最恨叫化子，我可不敢收你。");
                return;
        }
        command("say 好吧，我就收下你了。");
        command("recruit " + me->query("id"));
}
int ask_dan()
{
        if( this_player()->query("family/family_name") != "星宿派"){
        say("摘星子哼了一声说：这东西可不是给你用的。\n");
        return 1;
        }
        if (this_player()->query_temp("marks/丝1")||
        this_player()->query_temp("marks/胆1")||
        this_player()->query_temp("marks/蚣1")||
        this_player()->query_temp("marks/沙1")||
        this_player()->query_temp("marks/蝎1")) {
        say("摘星子不耐烦地说道：我不是叫你去找东西了吗？东西找来就给你。\n");
        return 1;
        }
        switch( random(5) )
        {

            case 0:
        say("摘星子发出一阵阴笑，说道：你给我找五个蛇胆来，我就给你。\n");
        this_player()->set_temp("marks/胆1", 1);
        break;
        case 1:
        say("摘星子发出一阵阴笑，说道：你给我找三个蜈蚣壳来，我就给你。\n");
        this_player()->set_temp("marks/蚣1", 1);
        break;
        case 2:
        say("摘星子发出一阵阴笑，说道：你给我找三个蝎子壳来，我就给你。\n");
        this_player()->set_temp("marks/蝎1", 1);
        break;
        case 3:
        say("摘星子发出一阵阴笑，说道：你给我找三个沙虫壳来，我就给你。\n");
        this_player()->set_temp("marks/沙1", 1);
        break;
        case 4:
        say("摘星子发出一阵阴笑，说道：你给我找三卷来毒蛛丝来，我就给你。\n");
        this_player()->set_temp("marks/丝1", 1);
        break;
        }
        return 1;
}
int accept_object(object who, object ob)
{
        object obj;
        if ((string)ob->query("name")=="毒蛛丝" &&
        this_player()->query_temp("marks/丝1" ) ) {
        command( "grin");
        this_player()->add("zhai", 1);
        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("zhai")>=3){
        command( "say 辛苦这位"+RANK_D->query_respect(who)+"了。");
        command( "say 这几颗炼心弹好好琢磨着用吧。");
        obj = new("/d/xingxiu/obj/lianxin");
        obj->set_amount(5);
        obj->move(this_player());
        this_player()->delete("zhai");
        this_player()->set_temp("marks/丝1", 0);
        return 1;
        }
    }
        if ((string)ob->query("name")=="毒蛇胆" &&
        this_player()->query_temp("marks/胆1") ) {
        command( "grin");
        this_player()->add("zhai", 1);
        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("zhai")>=5){
        command( "say 辛苦这位"+RANK_D->query_respect(who)+"了。");
        command( "say 这几颗炼心弹好好琢磨着用吧。");
        obj = new("/d/xingxiu/obj/lianxin");
        obj->set_amount(5);
        obj->move(this_player());
        this_player()->delete("zhai");
        this_player()->set_temp("marks/胆1", 0);
        return 1;
        }
    }
        if ((string)ob->query("name")=="蜈蚣壳" &&
        this_player()->query_temp("marks/蚣1") ) {
        command( "grin");
        this_player()->add("zhai", 1);
        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("zhai")>=3){
        command( "say 辛苦这位"+RANK_D->query_respect(who)+"了。");
        command( "say 这几颗炼心弹好好琢磨着用吧。");
        obj = new("/d/xingxiu/obj/lianxin");
        obj->set_amount(5);
        obj->move(this_player());
        this_player()->delete("zhai");
        this_player()->set_temp("marks/蚣1", 0);
        return 1;
        }
    }
        if ((string)ob->query("name")=="蝎子壳" &&
        this_player()->query_temp("marks/蝎1") ) {
        command( "grin");
        this_player()->add("zhai", 1);
        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("zhai")>=3){
        command( "say 辛苦这位"+RANK_D->query_respect(who)+"了。");
        command( "say 这几颗炼心弹好好琢磨着用吧。");
        obj = new("/d/xingxiu/obj/lianxin");
        obj->set_amount(5);
        obj->move(this_player());
        this_player()->delete("zhai");
        this_player()->set_temp("marks/蝎1", 0);
        return 1;
        }
    }
        if ((string)ob->query("name")=="沙虫壳" &&
        this_player()->query_temp("marks/沙1") ) {
        command( "grin");
        this_player()->add("zhai", 1);
        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("zhai")>=3){
        command( "say 辛苦这位"+RANK_D->query_respect(who)+"了。");
        command( "say 这几颗炼心弹好好拿去用吧。");
        obj = new("/d/xingxiu/obj/lianxin");
        obj->set_amount(5);
        obj->move(this_player());
        this_player()->delete("zhai");
        this_player()->set_temp("marks/沙1", 0);
        return 1;
        }
    }
         return 1;
}
void destroy_it(object ob)
{
        if(ob)
        destruct (ob);
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob=this_player()) && !this_object()->is_killing(ob)
        && present("shenmu wangding",ob)) {
           message_vision(
           HIY "$N一见到$n，怒道：大胆鼠辈！尽敢窃走师门宝物。拿命来！\n"NOR, this_object(), ob);
        command("follow "+ob->query("id"));
        kill_ob(ob);
        ob->start_busy(1+random(3));
        }
}

