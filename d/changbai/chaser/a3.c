//Cracked by Roath
// /d/changbai/npc/a3.c 阿三
// by ALN  1/98

#include <ansi.h>
#include <room.h>
#include <command.h>

inherit NPC;

void create()
{
        set_name("阿三", ({ "a san", "san" }));
        set("long",
"这人精壮结实，虎虎有威，脸上、手上、项颈之中，凡是可见到肌肉处，\n"
"尽皆盘根虬结，似乎周身都是精力，胀得要爆炸出来，\n"
"他左颊上有颗黑痣，黑痣上生着一丛长毛。\n");
        set("gender", "男性");
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 1500);
        set("max_jing", 800);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 30);
        set("combat_exp", 500000);
        set("score", 2000);

        set_temp("apply/armor", 80);
        set_temp("apply/defense", 60);
        set_temp("apply/damage", 30);

        set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("cuff", 120);
        set_skill("finger", 120);

        set_skill("hunyuan-yiqi", 120);
        set_skill("shaolin-shenfa", 120);
        set_skill("jingang-quan", 120);
        set_skill("nianhua-zhi", 120);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "jingang-quan");
        map_skill("cuff", "jingang-quan");
        map_skill("finger", "nianhua-zhi");

        prepare_skill("cuff", "jingang-quan");
        prepare_skill("finger", "nianhua-zhi");

        setup();

        call_out("chaser_check", 1);

        carry_object("/clone/misc/cloth")->wear();
}

#include "/d/changbai/chaser/chaser.h";
