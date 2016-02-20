//Cracked by Roath

inherit NPC;

void create()
{
        set_name("土匪", ({ "tu fei", "fei"}));
        set("long", 

"他看上去膀大腰粗，横眉怒目，满面横肉。看来手下倒也有点功夫。\n");
        set("gender", "男性");
        set("age", 30+random(15));
	set("attitude", "aggressive");
        set("combat_exp", 14000+random(4000));
        set_skill("unarmed", 50);
        set_skill("blade", 45);
        set_skill("dodge", 55);
        set_skill("ding-unarmed", 30+random(10));
	set_skill("parry", 55+random(10));
	 set_skill("luan-blade", 40+random(5));
	 map_skill("blade", "luan-blade");
	 map_skill("parry", "luan-blade");
        map_skill("unarmed", "ding-unarmed");
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 40);
        set("shen_type", -1);
        setup();
        add_money("silver", random(30));
         carry_object("/clone/armor/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();

}
/*
void die()
{
object me = this_player();
object ob = this_object();
say("土匪大喊一声：我死也不要进大理的大牢！\n"
   "只见土匪掏出一包化尸粉撒在自己的伤口上，不一会就化成了一滩脓水！\n");
destruct(ob);
if(me->query_temp("marks/差事1"))
{
me->add("差事done1",1);
}
}
*/
