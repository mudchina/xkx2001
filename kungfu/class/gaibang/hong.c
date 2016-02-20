//Cracked by Roath
// Modified by xbc; add quests 06/21/97
// Modified by xuy; fixed crashing bugs in quests 08/11/97
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

int auto_perform();
int improve_gbskill(string arg);

void create()
{
        set_name("洪七公", ({"hong qigong", "hong", "qigong"}));
        set("nickname", "九指神丐");
        set("gender", "男性");
        set("age", 75);
        set("long", 
"他一张长方脸，颌下微须，粗手大脚，身上衣服东一块西一块的打满了补丁，
却洗得干干净净，背上负着个朱红漆的大葫芦。\n");
        set("attitude", "peaceful");
        
        set("str", 35);
        set("int", 24);
        set("con", 30);
        set("dex", 30);

        set("rank", 10);

        set("chat_chance", 1);
        set("chat_msg", ({
                "洪七公摸着肚皮叹道：“唉，好久没吃到蓉儿烧的小菜了……”\n",
                "洪七公往地下角落一躺，开始睡觉，边睡边喃喃道：“啊，叫化鸡……好香！好香！”\n",
                "洪七公说道：“俗话说「吃在江南」，所以老叫化特地跑来扬州看看。”\n",
                "洪七公摇头叹道：“如今这帮小叫化怎么好像都不会烧菜了？”\n",
                "洪七公喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”\n",
//              (: random_move :),
        }));
        set("inquiry", ([
                "青竹令" : "老叫花可没功夫管这么多闲事，你去扬州找小左吧！\n",
                "青竹林" : "东北西北东西北。\n",
                "丐帮" : "东北西北东西北。\n",
                "小菜" : "最想吃的是蓉儿烧的叫化鸡，牛肉条，好逑汤，炒白菜，蒸豆腐……唉！\n",
                "好吃的" : "最想吃的是蓉儿烧的叫化鸡，牛肉条，好逑汤，炒白菜，蒸豆腐……唉！\n",
                "做饭" : "你会烧菜？你去西北处的竹林里烧些好吃的来吧。\n",
                "烧菜" : "你会烧菜？你去西北处的竹林里烧些好吃的来吧。\n",
                "黄蓉" : "这小娃娃烧的叫化鸡，牛肉条，好逑汤，炒白菜，蒸豆腐最好吃。\n",
                "蓉儿" : "这小娃娃烧的叫化鸡，牛肉条，好逑汤，炒白菜，蒸豆腐最好吃。\n",
//              "拜师" : "你可以去东城门的我帮总舵拜鲁有脚。\n",
        ]));

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

//      set("qi", 4000);
        set("max_qi", 4000);
//      set("jing", 3000);
        set("max_jing", 3000);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 300);
        
        set("combat_exp", 3600000);
        set("score", 200000);
        set("death_times",180);

        set_skill("force", 400);             // 基本内功
        set_skill("huntian-qigong", 400);    // 混天气功
        set_skill("strike", 400);            // 基本掌法
        set_skill("xianglong-zhang", 400);   // 降龙十八掌
        set_skill("hand", 360);              // 基本手法
        set_skill("shexing-diaoshou", 400);  // 蛇形刁手 
        set_skill("dodge", 400);             // 基本躲闪
        set_skill("xiaoyaoyou", 400);        // 逍遥游
        set_skill("parry", 400);             // 基本招架
        set_skill("stick", 400);             // 基本棍杖
        set_skill("dagou-bang", 400);        // 打狗棒法
        set_skill("begging", 200);           // 叫化绝活
        set_skill("checking", 200);          // 道听途说
        set_skill("training", 240);          // 驭兽术
        set_skill("digging", 200);  
        
        map_skill("force", "huntian-qigong");
        map_skill("strike","xianglong-zhang");
        map_skill("hand",  "shexing-diaoshou");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("stick", "dagou-bang");
        
        prepare_skill("strike", "xianglong-zhang");

        create_family("丐帮", 17, "帮主");
        setup();
        
        if (clonep()) carry_object("/clone/unique/yuzhu-zhang"); //->wield(); 
        carry_object("/d/gaibang/obj/budai")->set_amount(9);
        carry_object("/d/gaibang/obj/budai")->wear();
        if (clonep()) carry_object("/d/gaibang/obj/dahulu"); 
}

void init(){ set_heart_beat(1);}
void attempt_apprentice(object ob)
{

        if (!ob->query_temp("hong_recr")){
        if ((int)ob->query_str() < 28 && (int)ob->query_con() < 28) {
                command("say 当叫化子需要能吃苦耐劳，依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合当叫化子？");
                return;
        }

        if ((string)ob->query("family/family_name") != "丐帮") {
                command("say 你师父这般大的本事，你又何必要我来教你武功？");
                return;
        }

        if( ob->query("rank") >= 6 ) {
                ob->set_temp("title", ob->query("title"));
                command("say 好，看你在本帮勤奋练功，任劳任怨，我就收下你了！"); 
                command("recruit " + ob->query("id"));
                ob->set("title", ob->query_temp("title"));
                ob->delete_temp("title");
        } 
        else    command("say 我看你在本帮待的时间不长。等你升到六袋以上再来找我吧。");
        }

        ob->set_temp("title", ob->query("title"));
        command("recruit " + ob->query("id"));
        ob->set("title", ob->query_temp("title"));
        ob->delete_temp("title");
        ob->delete_temp("hong_recr");
}

int accept_object(object me, object ob)
{
        string myid = me->query("id");
        string name = ob->query("name");
        object dish = this_object()->query_temp("eatting");

// 洪不能一天到黑不停地吃。
        if (this_object()->query("food") >= this_object()->max_food_capacity()){
                command("stuff");
                message_vision("$N拍了拍$n的头，说道：娃娃，老叫化我的肚子已经吃得圆鼓鼓的啦。\n", this_object(), me);
                return 0;
        }

// 除了吃的，什么东西也不收。
        if (ob->query("food_supply") <= 0) {
                say((string)me->query("name") + "给洪七公一" + (string)ob->query("unit") + (string)ob->query("name") + "。\n");
                message_vision("$N拍了拍$n的头，说道：娃娃，老叫化我不要这个，你自己拿回去吧。\n", this_object(), me);
                return 0;
        }

        if( objectp(dish) ) {
                return notify_fail("洪七公正在品尝"+dish->query("name")+"，最好不要打扰他。\n");
        }

// 给他叫化鸡．．．
        if (name == "叫化鸡") 
                message_vision("洪七公叫道：啊……这正是我想吃的叫化鸡呀！\n", me);
        else if (name == "牛肉条" || name == "好逑汤" || name == "炒白菜")
                message_vision("洪七公叫道：啊……这不是蓉儿做过的" + name + "吗？\n", me);
//      不能老吃豆腐 
        else if (name == "蒸豆腐" ) {
                say((string)me->query("name") + "给洪七公一" + (string)ob->query("unit") + name + "。\n");
                message_vision("洪七公皱着眉头说：怎么又是蒸豆腐？\n", me);
                return 0;
        }
        else {
// 其他食物，不要！
                say((string)me->query("name") + "给洪七公一" + (string)ob->query("unit") + name + "。\n");
                command( "say 咦？" + name + "！哪里买的？");
                command("hehehe " + myid);
                command( "say 嗯，这" + name + "不新鲜啊。" + (string)me->query("name") + "娃娃会自己烧小菜吗？");
                return 0;
        }

        this_object()->set_temp("eatting", ob);
        call_out("eatting", 1, me);

        return 1;
}

private int eatting(object me) 
{
        int ime;
        string name, myid;
        object ob = this_object()->query_temp("eatting");

        if(!objectp(ob) ) return 0;

        name = ob->query("name");
        myid = me->query("id");
        ime = (int)((me->query("kar")-10)/5);
//   做得不好吃
        if( name == "叫化鸡" ) {
                if (ob->query("fake")) {
                        if (ob->query("undercook")) 
                                message_vision( "洪七公皱了皱眉，道：这叫化鸡的味道好象……嗯，火候还不够。\n", me);
                        else if (ob->query("overcook")) 
                                message_vision( "洪七公皱了皱眉，道：这叫化鸡烤得太老了，吃不得。\n", me);
                        else 
                                message_vision( "洪七公皱了皱眉，道：这叫化鸡的味道不对。\n", me);
                        command( "shake "+ myid);
                        command( "say 唉，难道除了蓉儿以外，没有人会烧了吗？");
                        command("drop " + ob->query("id"));
                        if( objectp(ob) ) destruct(ob);
                        return 1;
                }
                        
//   好吃的叫化鸡. 收徒
                command("eat " + ob->query("id"));
                if(objectp(ob)) destruct(ob);
                command("taste");
                command("stuff");
                command("haha " + myid);
                command("look " + myid);
                command("say " + (string)me->query("name") + "娃娃会烧叫化鸡，哈哈哈！\n");
                if( me->query("rank") > 1 &&
                    me->query("family/family_name") != "丐帮" )
                        return 1;

                message_vision("\n$N想要收$n为弟子。\n", this_object(), me);
                tell_object(me, YEL "如果你愿意拜洪七公为师父，用 apprentice指令。\n" NOR);
                me->set_temp("hong_recr", 1);

                return 1;
        }

// 其他好吃的东西...

//   做的不好吃（少原料）
        if (ob->query("fake")) {
                message_vision( "洪七公皱了皱眉，道：这" + name + "的味道不对。还是蓉儿烧的" + name +"好吃。\n", me);
                command( "shake "+ myid);
                command("drop " + ob->query("id"));
                if( objectp(ob) ) destruct(ob);
                return 1;
        }

//   好吃的小菜. 加少许潜能和经验
        command("eat " + ob->query("id"));
        if(objectp(ob)) destruct(ob);
        command("taste");
        command("stuff");
        command("look " + myid);
        command("say " + (string)me->query("name") + "娃娃烧的" + name + "味道实在不坏。");
        if ( me->query("family/family_name") == "丐帮" ) {
                me->add("potential", 2+random(5));
//              me->add("combat_exp", 3+random(5));
                if (me->query("potential") > me->query("max_potential"))
                me->set("potential", me->query("max_potential"));
        }

//     如果没教过功夫，四样菜中做好一样的（depends on kar），教任意一功夫，每人只能学一次
//      暂时改成三样，不要豆腐了。
        if ( ((int)me->query("hong_taught")) != 1) {
                switch(ime) {
                case 1:
                        if ( name != "好逑汤" ) return 1;
                        break;
                case 2:
                        if ( name != "炒白菜" ) return 1;
                        break;
                case 3:
                        if ( name != "好逑汤") return 1;
                        break;
                default:
                        if ( name != "牛肉条" )  return 1;
                        break;
                }

                command("thumb " + myid);
                remove_call_out( "improve_gbskill" );
                call_out( "improve_gbskill", 2, me );
                me->set("hong_taught", 1);
                return 1;
        }
        command( "hehehe " + myid);
        command( "say 小娃娃会烧菜，不简单啊。可要想我再教，那是难上加难。");
        return 1;

}

int improve_gbskill(object me)
{
        string *hong_skill = ({
                "dagou-bang", "huntian-qigong",  "shexing-diaoshou", 
                "xianglong-zhang",  "xiaoyaoyou" });
        string my_skill = hong_skill[random(sizeof(hong_skill))];
        string skill_name = to_chinese(my_skill);

        int my_level = me->query_skill(my_skill, 1)+1;
        int points;

        message_vision( "洪七公对$N说道：小娃娃，来，我指点你几招功夫吧。\n\n", me);

// 聪明的学生学得快而多，如黄蓉。每人大约学 30k 点
        points = my_level*my_level + (int)me->query_int()*1000;
        if ( my_level < 180 ) {
                message_vision( "洪七公一言方毕，人已跃起，大袖飞舞，东纵西跃，将一套" + skill_name + "使将出来。\n", me);
                message_vision( "之后，洪七公又细细为$N点拨" + skill_name + "的用功心法。\n", me);
        }

        else {
                command( "ah " + (string)me->query("id"));
                command( "say " + (string)me->query("name") + "娃娃的" + skill_name + "不错啊，老叫化我没什么好教你的了。\n");
                message_vision( "洪七公细细为$N点拨了一下" + skill_name + "的用功心法。\n", me);
        }

        me->set("hong_taught", 1);
        me->save();
        log_file("QUESTS", sprintf("hong taught %s(%s) %s by %d points.\n", 
                  me->query("name"), getuid(me), skill_name, points));

        while ( points > 0 ) {
                me->improve_skill(my_skill, my_level*my_level+1);
                points -= my_level*my_level+1;
                ++my_level;
        }

        me->add("quest_exp", 20);

        return 1;
}
#include "/kungfu/class/gaibang/auto_perform.h"

