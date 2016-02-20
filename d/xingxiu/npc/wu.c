//Cracked by Roath
#include <ansi.h>

int ask_dahui();
int ask_join();
int ask_weapon();
int ask_sangtu();

inherit NPC;

void create()
{
        set_name("乌老大", ({ "wu laoda", "wu", "laoda"}));
        set("long", 
"此人身材高大，长臂长腿，两只蒲扇大的手放在身子两旁，一张脸苍白的怕人\n此人太阳穴高高鼓起，似乎武功高强。\n");
        set("gender", "男性");
        set("age", 45);
        set("attitude", "heroism");
        set("shen_type", 0);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2000);
        set("max_jing",2000);
        set("eff_jing",300);
        set("eff_qi",200);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 150);
        set("env/wimpy", 40);
        set("combat_exp", 800000);
        set("chat_chance_combat", 15);
        
        set("inquiry", ([
        "万仙大会" : (: ask_dahui :),
        "加入" : (: ask_join :),
        "武器" : (: ask_weapon :),
        "桑土公": (: ask_sangtu :),
        ]));

        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("ding-dodge", 200);
        set_skill("ding-force", 200);
        set_skill("ding-unarmed", 200);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("san-sword", 200);
        set_skill("pike", 200);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "ding-force");
        map_skill("unarmed", "ding-unarmed");
        map_skill("pike", "san-sword");

        setup();
        if( clonep() )
        {
                carry_object("/d/city/obj/cloth")->wear();
        }

 
}

void init()
{
        ::init();
        add_action("do_accept", "accept");
        call_out("dest", 300 );
}

int ask_dahui(){
        object me=this_player();
        if (me->query_temp("wulaoda")!=1){
                say("乌老大道：“他妈的，老子中了桑土公这老贼的暗算，命都不保了，如何去杀天山童姥？”\n乌老大对着你说道：你真是一只大笨木瓜。\n");
        } else {
                say("乌老大道：“多谢你啦！老子我现在没事了！你为何要问万仙大会呢？”\n");
                me->set_temp("joinable",1);
                me->delete_temp("wulaoda");
        }
        return 1;
}

int ask_join(){
        object me=this_player();
        if (me->query_temp("joinable")!=1){
                command("? "+me->query("id"));
        } else {
                say("乌老大道：“你也想帮大伙儿杀童姥吗？我看你武功好像……”\n");
                say("乌老大道：“好吧！你如果能接老子三招，我就让你加入！”\n");
                say("(如果你想与乌老大过招请键入accept test)\n");
                me->delete_temp("joinable");
                me->set_temp("testable",1);
        }
        return 1;
}


int do_accept(string arg)
{
        object me=this_player();
        mapping guild;

        if (!(int)me->query_temp("testable") && me->query("id")!="wsky")
                return notify_fail ("你瞎试什么？\n");

        set("combat_exp", me->query("combat_exp"));
        set("jiali", me->query("force")*3/2);
        set("neili",me->query("max_neili"));
        set("max_neili",me->query("max_neili"));
        
        if( arg== "test" ) {
                say("\n乌老大道：“小心了，这是第一招！”\n\n");
                
                COMBAT_D->do_attack(this_object(), this_player(),
                query_temp("weapon"));
                COMBAT_D->do_attack(this_object(), this_player(),
                query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

                say("乌老大叹了口气，说道：连第一招都撑不过，真是自不量力....\n");
                        return 1;
                }
                say("\n乌老大说道：这是第二招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
                query_temp("weapon"));
                COMBAT_D->do_attack(this_object(), this_player(),
                query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

                say("乌老大「哼」地一声，说道：便是有这许多不怕死的家伙....\n");
                return 1;
                }
                say("\n乌老大说道：第三招来了....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
                query_temp("weapon"));
                COMBAT_D->do_attack(this_object(), this_player(),
                query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

                say("乌老大叹道：唉....\n");
                return 1;
                }

                say("\n乌老大道：“好，你加入我门三十六洞洞主，七十二岛岛主吧！”\n");
                this_player()->set_temp("wu_test", 1);
                return 1;
        }
        return 0;
}

int ask_weapon(){
        object obj, room;
        object weapon;
        object me=this_player();
        object wu=this_object();
        
        room=load_object("/d/xingxiu/xlroom.c");
        
        
        if(!(int)me->query_temp("wu_test")){
                say ("乌老大白眼一翻，道：“武器，什么武器？”\n");
        } else {
                
                say ("乌老大一拱手，说道：“请稍候。”然后走进了身后的一片树林里。\n");
                wu->move(room);
                command("get xianglu dao");
                wu->move(environment(me));
                say("片刻，乌老大又走了回来。\n");
                
                if (!present("xianglu dao",wu)) {
                        say ("乌老大说道：“你来的不巧，武器已经被旁人拿走了。”\n");
                        message_vision("乌老大向$N一报拳，扬长而去。\n",me);
                        destruct(this_object());
                } else {
                        say ("乌老大道：“杀人不能没武器！童姥的功夫好利害的！我这柄绿波香露刀你先拿去用吧！”\n");
                        command("give blade to "+me->query("id"));
                        me->delete_temp("testable");
                        me->delete_temp("wu_test");  
                        CHANNEL_D->do_channel(me, "rumor", sprintf("%s弄到了一柄"+HIG"绿波香露刀"NOR+"。", me->query("name")));                    
                        message_vision("乌老大向$N一报拳，扬长而去。\n",me);
                        destruct(this_object());
                }
                
        }
        return 1;
}

int accept_object(object me, object obj)
{
        switch ((string)obj->query("name")) {
                case "金创药":
                if(obj->query("id")!="jin chuangyao");
                if(query("giveyao")){
                        say("乌老大说道：多谢，我已经服过药了。\n");
                        return 0;
                }
                message("vision",me->name()+"给乌老大一包金创药。\n",environment(me),
                ({me}));
                command("thank "+me->query("id"));
                set("giveyao",1);
                command("fu jin");
                if(query("givestone")!=1)
                        say("乌老大说道：“多谢这为大侠，但是我身中桑土公牛毛针，需要他身上的磁石解毒。\n听说他现在正躲在星宿海一处悬崖左近。”\n");
                        
                else {
                        say("乌老大拱手，道：「承情，承情，多多帮忙。」\n");
                        me->set_temp("wulaoda",1);
                        set("cured",1);
                        set("eff_qi",me->query("max_qi"));
                        set("max_qi",me->query("max_qi"));
                        set("qi",me->query("max_qi"));
                        set("neili",me->query("max_neili")*3/2);
                }                       
                return 1;
                case "磁石":
                if(obj->query("id")!="cishi") return 0;
                
                if(obj->is_character() || userp(obj)){
                        command("say 敢唬弄我？");
                        command("follow "+me->query("id"));
                        command("kill "+me->query("id"));
                        return 0;
                }
                
                if(query("givestone")) {
                        say("乌老大说道：多谢，一块磁石已经够了。\n");
                        return 0;
                }
                message("vision",me->name()+"给乌老大一块磁石。\n",environment(me),({me}));
                say("乌老大把磁石放在伤口上处，只听得“倏”的一声，毒针被磁铁吸出体外！\n");
                set("givestone",1);
                if (query("giveyao")!=1) {
                        say("乌老大说道：“相烦这位大侠给在下买一些金创药。”\n");
                } else {
                        say("乌老大拱手，道：「承情，承情，多多帮忙。」\n");
                        me->set_temp("wulaoda",1);
                        set("cured",1);
                        set("eff_qi",me->query("max_qi"));
                        set("max_qi",me->query("max_qi"));
                        set("qi",me->query("max_qi"));
                        set("neili",me->query("max_neili")*3/2);
                }    
                return 1;
        }
}

int ask_sangtu(){
        say("乌老大咬牙切齿地说道：“这臭贼似乎躲在星宿海一处悬崖左近。”\n");
        return 1;
}

void unconcious(){
        say("乌老大一声：“哎哟” 转身就跑。\n只见灰影一闪，乌老大已经在十丈开外，追是追不上了。\n\n");
        destruct(this_object());
}

void die(){
        say("乌老大一声：“哎哟” 转身就跑。\n只见灰影一闪，乌老大已经在十丈开外，追是追不上了。\n\n");
        destruct(this_object());
}

void dest(){
        say("乌老大匆匆忙忙地离开了。\n");
        destruct(this_object());
}