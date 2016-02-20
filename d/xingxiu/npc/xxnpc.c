//Cracked by Roath
#include <ansi.h>
#include <room.h>

inherit NPC;
int auto_perform();
int do_move();

void create()
{
        switch( random(10) )
        {
        case 0:
        set_name("高克新", ({ "gao kexin", "gao", "kexin" }) );

        set("long","他是华山派高手，视恶如仇，在他手下丧生的邪叫人士不计其数。\n");
        set("gender", "男性");
        set("age", 20+random(32));
        set("menpai", "huashan");
                break;

        case 1:
        set_name("觉兴", ({ "jue xing", "jue", "xing" }) );

        set("long","似乎是少林旁支，武功高强，曾向佛祖发誓要扫尽江湖邪魔。\n");
        set("gender", "男性");
        set("age", 60 + random(4));
        set("int", 30);
        set("menpai", "shaolin");
        break;

        case 2:
        set_name("刘志修", ({ "liu zhixiu","liu" }) );
        set("gender", "男性");
        set("age", 30+random(20));
        set("long","他是一个双目炯炯的壮年道士，出身全真。\n");
        set("menpai", "quanzhen");
        break;
        
        case 3:
        set_name("静慈", ({ "jing ci", "jing", "ci" }) );
        set("long","一个身材修长，容颜美丽的小尼姑，据说武艺高强。\n");
        set("gender", "女性");
        set("age", 20 + random(4));
        set("int", 30);
        set("con", 30);
        set("menpai", "emei");
        break;
 
        case 4:
        set_name("静慈", ({ "jing ci", "jing", "ci" }) );
        set("long","一个身材修长，容颜美丽的小尼姑，据说武艺高强。\n");
        set("gender", "女性");
        set("age", 20 + random(4));
        set("int", 30);
        set("con", 30);
        set("menpai", "emei");
        break;

        case 5:
        set_name("觉欲", ({ "jue yu", "jue"}) );

        set("long","似乎是少林旁支，武功高强，曾向佛祖发誓要扫尽江湖邪魔。\n");
        set("gender", "男性");
        set("age", 60 + random(4));
        set("int", 30);
        set("menpai", "shaolin");
        apply_condition("drunk",20);
                break;
        case 7:
        set_name("觉慈", ({ "jue ci", "jue", "ci" }) );
        set("long","似乎是少林旁支，武功高强，曾向佛祖发誓要扫尽江湖邪魔。\n");
        set("gender", "男性");
        set("age", 60 + random(4));
        set("int", 30);
        set("menpai", "shaolin");
        apply_condition("drunk",20);
        break;
        
        case  8:
        set_name("白衫怪客", ({ "guaike", "ke", "baishan guaike" }) );
        set("long","一个身着白衫的怪客。\n");
        set("gender", "男性");
        set("age", 30 + random(4));
        set("int", 30);
        set("con", 30);
        set("menpai","mingjiao");
        break;
        
        case  9:
        set_name("叶三山", ({ "ye sanshan", "ye", "sanshan" }) );
        set("long","武当派侠客，曾独自一人地横扫三山，以此为名。\n");
        set("gender", "男性");
        set("age", 30 + random(4));
        set("int", 30);
        set("con", 30);
        set("menpai", "wudang");
        break;
        
        case  10:        
        set_name("叶三山", ({ "ye sanshan", "ye", "sanshan" }) );
        set("long","武当派侠客，曾独自一人地横扫三山，以此为名。\n");
        set("gender", "男性");
        set("age", 30 + random(4));
        set("int", 30);
        set("con", 30);
        set("menpai", "wudang");
        break;
        
        default:
        set_name("白衫怪客", ({ "guaike", "ke", "baishan guaike" }) );
        set("long","一个身着白衫的怪客。\n");
        set("gender", "男性");
        set("age", 30 + random(4));
        set("int", 30);
        set("con", 30);
        set("menpai", "mingjiao");
        break;
        }

        set("attitude", "peaceful");
        set("combat_exp", 20000);
        set("xxtarget",1);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
               (: auto_perform :),
        }) ); 
        
        set("inquiry", ([ 
                "战斗"   : (: do_move :),
                "challenge"  : (: do_move :),
        ]) );

        setup();
        carry_object("/clone/armor/tiejia")->wear();
}



int accept_fight()
{
        object npc = this_object();
        object me  = this_player();
        
        mapping myfam;

        myfam= me->query("family"); 

        if (myfam["family_name"] == "星宿派"){
                command("say 不用比试了，你拿命来吧！");
                if( !npc->is_killing(me) ) npc->kill_ob(me);    
        }
        else {
                command("shake");
                command("say 大家都是江湖同道，无故动武岂不是伤了和气？");
                return 0;
        }
        return 1;
        
}

/*
void die()
{
      
    //string doer = query("xxtarget");
    
    object ling;
    //object killer = (object)find_player((string)doer);
        
    //if ((string)doer == query_temp("last_eff_damage_from")  ) {
    //                    killer->delete("xxnpc");
    //                    killer->add("kills",1);
    //}
    
    ::die();
    
    ling=new("/d/xingxiu/lingpai");	
    message_vision("只听见啪的一声，从"+query("name")+"身上掉下来一件物事。\n");
    ling->set("player",this_player()->query("id"));
    ling->move(environment(this_player()));
    
    
}
*/

void die()
{
        object ob, corpse, killer;

        if( !living(this_object()) ) revive(1);
        clear_condition();

        if( objectp(killer = query_temp("last_damage_from")) ) 
        {
        	if( !(killer->query("xbiao/dest")) )
        	{
                //if(killer->query("id")==this_object()->query("player")){
                	ob = new("/d/xingxiu/obj/lingpai");
                	ob->move(environment());
                	message_vision("只听见啪的一声，从"+query("name")+"身上掉下来一件物事。\n", this_player());
                	ob->set("player", killer->query("id"));
                	ob->set("menpai", query("menpai"));
                //}
            }
        }
    
        COMBAT_D->announce(this_object(), "dead");
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());
        remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());
        dismiss_team();
        destruct(this_object());
}



void destroying(object me)
{
        message_vision("$N看了看周遭，若无其事地离开了。\n",me);
        destruct(me);
        return;
}


int auto_perform(){
                object npc=this_object();
                
                if (npc->query("menpai")=="huashan"){
                        if (npc->query_temp("weapon")) command("perform jianzhang");
                                else command("perform leidong");
                }       else if(npc->query("menpai")=="quanzhen"){
                        if (npc->query_temp("weapon")) command("perform riyue");
                                else command("perform sanhua");
                }       else if(npc->query("menpai")=="shaolin"){
                        if (npc->query_temp("weapon")) {
                        	command("yun jingang");
                        	command("perform zuida");
                        } else command("yun jingang");
                }       else if(npc->query("menpai")=="emei"){
                        if (npc->query_temp("weapon")) command("perform mie");
                }	else if(npc->query("menpai")=="wudang"){
                            command("jiali 0");
                            command("perform nian");
                            command("jiali 50");
                }	else command("perform xiaoyao");
                
                
                
                return 1;
}

string do_move()
{
    object player, room;
    mapping exits;
    string  *dirs;

    player = this_player();
    if (query("player_name") == player->query("id")) {
        room = environment(this_object());
        exits = room->query("exits");
        dirs = keys(exits);
        command("go "+dirs[random(sizeof(dirs))]);
        return "出去就出去，有什么不敢？";
    }else {
        return 0;
    }
}

