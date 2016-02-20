//Cracked by Roath
// /d/emei/npc/bat.c 蝙蝠
// Shan 6/24/96

inherit NPC;

void create()
{
        set_name("蝙蝠", ({ "bianfu", "bat" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", "黑暗中隐约见到一只黑色的蝙蝠。\n");
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "身体", "翅膀", "爪子", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 300);
        set_temp("apply/attack", 3);
        set_temp("apply/defense", 5);
        set_temp("apply/armor", 1);

        setup();

        set("chat_chance", 2);
        set("chat_msg", ({
                "一只蝙蝠从你身边飞过。\n",
                "一只蝙蝠忽然停在你肩头。\n",
                "有一只蝙蝠停在你左边的岩石上。\n",
                "黑暗中一只蝙蝠停在你右边的岩石上。\n",
                "黑暗中一只蝙蝠停在你前面的岩石上。\n",
                "好象有一只蝙蝠停在你身后的岩石上。\n",
        }) );
}

int is_grpfight()
{
        object me=this_object();
        object ob;
        int i;

        message_vision("周围的"+me->name()+"一起向$n飞扑过来！！\n\n", me, this_player());
        for (i=0;i<sizeof(all_inventory(environment(me)));i++)
                if (objectp(ob=present("bianfu "+(i+1), environment(me))))
                        ob->kill_ob(this_player());
        return 1;
}

