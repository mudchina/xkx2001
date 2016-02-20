//Cracked by Roath
// npc.c

#include <room.h>
#include <command.h>

inherit CHARACTER;
inherit F_CLEAN_UP;

varargs object carry_object(string file, string alternative)
{
        object ob;

        ob = new(file);
        if( !objectp(ob) && stringp(alternative) ) ob = new(alternative);
        if( !objectp(ob) ) return 0;
        ob->move(this_object());
        return ob;
}

object add_money(string type, int amount)
{
        object ob;

        ob = carry_object("/clone/money/" + type);
        if( !ob ) return 0;
        ob->set_amount(amount);
}

int accept_fight(object who)
{
        string att;

        att = query("attitude");

        if( is_fighting() )     switch(att) {
                case "heroism":
                        command("say 哼！出招吧！\n");
                        break;
                default:
                        command("say 想倚多为胜，这不是欺人太甚吗！\n");
                        return 0;
        }

        if( (int)query("jing") * 100 / (int)query("max_jing") >= 90
        &&      (int)query("qi") * 100 / (int)query("max_qi") >= 90
        &&      (int)query("jingli") * 100 / (int)query("max_jingli") >= 90 ) {
                switch(att) {
                        case "friendly":
                                command("say " + RANK_D->query_self(this_object())
                                        + "怎么可能是" + RANK_D->query_respect(who)
                                        + "的对手？\n");
                                return 0;
                        case "aggressive":
                        case "killer":
                                command("say 哼！出招吧！\n");
                                break;
                        default:
                                if( !is_fighting() )
                                        command("say 既然" + RANK_D->query_respect(who)
                                                + "赐教，" + RANK_D->query_self(this_object())
                                                + "只好奉陪。\n");
                }
                return 1;
        } else
                return 0;
}

int accept_kill(object who)
{
        return 1;
}

// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int return_home(object home)
{
        // Are we at home already?
        if( !environment()
        ||      environment()==home )
                return 1;

        // Are we able to leave?
        if( !living(this_object())
        ||      is_fighting())
//      ||      !mapp(environment()->query("exits")) ) 
        return 0;

        // Leave for home now.
        message("vision", this_object()->name() + "急急忙忙地离开了。\n",
                environment(), this_object());
        return move(home);
}

// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int chat()
{
        string *msg;
        int chance, rnd;

        if( !environment() || !living(this_object())) return 0;

        if ( query("neili") > 100 && living(this_object()) ) {
                if( (int)query("jingli")*100/(int)query("max_jingli") < 90 )
                        SKILL_D("force")->exert_function(this_object(), "refresh");
                if( (int)query("qi")*100/((int)query("eff_qi")+2) < 80 )
                        SKILL_D("force")->exert_function(this_object(), "recover");
                if( (int)query("jing")*100/((int)query("eff_jing")+2) < 70 )
                        SKILL_D("force")->exert_function(this_object(), "regenerate");
        }

        if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
                return 0;

        if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
                if( random(100) < chance && sizeof(msg) ) {
                        rnd = random(sizeof(msg));
                        if( stringp(msg[rnd]) )
                                say(msg[rnd]);
                        else if( functionp(msg[rnd]) )
                                return evaluate(msg[rnd]);
                }
                return 1;
        }
}

// Default chat function: Let the npc random move to another room.
int random_move()
{
        mapping exits, doors;
        string *dirs, dir;

        if( !objectp(environment()) 
        || !mapp(exits = environment()->query("exits")) 
        || query("jingli") < query("max_jingli") / 2 ) return 0;
        dirs = keys(exits);
        if( this_object()->query("race") == "人类"
         && mapp(doors = environment()->query_doors()) ) {
                dirs += keys(doors);
        }
        if( sizeof(dirs) == 0 ) return 0;
        dir = dirs[random(sizeof(dirs))];
        if ( mapp(doors) && !undefinedp(doors[dir])
          && (doors[dir]["status"] & DOOR_CLOSED) )
                command("open " + dir);
        command("go " + dir);
        return 1;
        
}

// Default chat function: Let the npc cast his/her enabled spells
void cast_spell(string spell)
{
        string spell_skill;

        if( stringp(spell_skill = query_skill_mapped("spells")))
                SKILL_D(spell_skill)->cast_spell(this_object(), spell);
}

// Default chat function: Let the npc exert his/her enabled force
int exert_function(string func)
{
        string force_skill;

        if( stringp(force_skill = query_skill_mapped("force")))
                return SKILL_D(force_skill)->exert_function(this_object(), func);
        else return SKILL_D("force")->exert_function(this_object(), func);
}

// Default chat function: Let the npc perform special action with 
// his/her enabled martial art
int perform_action(string action)
{
        object weapon;
        string martial_skill, act;
        if( query_temp("feng")) return 0; // for pfm feng
        if( sscanf(action, "%s.%s", martial_skill, act) != 2 )
                return 0;
        martial_skill = query_skill_mapped(martial_skill);
        if( stringp(martial_skill) )
                return SKILL_D(martial_skill)->perform_action(this_object(), act);              
}

