//Cracked by Roath
inherit NPC;
string ask_me(object who);

void create()
{
        set_name("蓝凤凰", ({ "lan guniang", "lan" }));
        set("shen_type", 0);

        set("str", 20);
        set("con", 20);
        set("dex", 22);
        set("gender", "女性");
        set("age", 20);
        set("long",
                "她就是云南五毒教教主蓝凤凰，一生守身如玉，从来不对任何男子假以辞色。\n");
        set("combat_exp", 30000);
        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 20);
        set_skill("poison", 80);
        set_skill("force", 80);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_temp("apply/attack", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/damage", 40);

        set("attitude", "friendly");
        set("inquiry", ([
                "五毒教" : "哼！就凭你也来打听本教？\n",
                "蓝凤凰" : "你瞎了眼啦？\n",
                "药方" : "我五毒教祖传众多古怪药方，但向来秘而不宣。\n",
                "五仙药酒" : (: ask_me :),
        ]));

        setup();
        carry_object("/d/city/obj/necklace")->wear();
        carry_object("/d/city/obj/heyeli")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();
}

string ask_me(object who)
{
        object me = this_player();
        string myid = me->query("id");

        if( me->query("combat_exp") < 100000 ) {
                command("laugh " + myid);
                command("kick " + myid);
                return "还不快滚！本教主不杀无名小卒。\n";}

        say("蓝凤凰顿时脸色一变，怒斥道：这五仙大补药酒，乃当世最神奇的补药，岂能落在你辈手中！\n");
        set("attitude", "aggressive");
        kill_ob(me);
        return "蓝凤凰大喝一声，叫道：“本教主今天豁出去，跟你拼了。”\n";
}

/*
void unconcious()
{
        object ob;

        say("\n突然蓝凤凰一声长叹，掏出一瓶药酒扔入舟外。\n");
        say("随即惨淡一笑，正欲再摸出什么物事，但终究无力动弹不得。\n");
        ob = new("/d/shenlong/obj/yaofang");
        ob->move(this_object());
        this_object()->unconcious();
}
*/

void die()
{
        object ob;

        say("\n突然，只见船身一晃蓝凤凰一脚踩空掉入河里。\n");
        if( ob = present("yaofang", this_object()) ) destruct(ob);
        destruct(this_object());
}
