//Cracked by Roath
// Based on Jay 10/7/96
// 侠客岛，峨眉弟子
// Ssy

inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
          峨嵋派的创派祖师是郭襄女侠。郭女侠在她四十岁那年，
    忽然大彻大悟，出家为尼，后来开创了峨嵋一派。峨嵋派半数是
    尼姑，其余的有男有女。灭绝师太是现任第三代掌门。
          峨嵋弟子崇信大乘佛教，讲究渡人渡己，可通过劝服战斗
    中的玩家或ＮＰＣ罢斗，在实用中增长修为，并取得实战经验。
    峨嵋派不喜与人争斗，弟子门人常常闭门修炼以增长人体潜能。
    峨嵋派内功临济十二庄，讲动静功修练，其排列顺序是：天地之
    心、龙鹤风云、大小幽冥。若能贯通幽冥二庄（１８０级）更可
    到达武林人士梦寐以求的龙虎交会、水火既济的境界、并熟通采
    制灵丹之妙法。此外还可拜周芷若学习九阴白骨爪。",
});

int ask_menpai(string* message);

void create()
{
	set_name("静师", ({ "emei dizi", "dizi", "jingshi" }));
	set("long", "一位十来岁的少年女尼，长得清秀绝俗，表情冷峻，令人丝毫不敢有亵渎之意。\n");

	set("gender", "女性");
	set("age", 18);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 140);

	set("attitude", "peaceful");
	set("shen_type", 1);

	create_family("峨眉派", 5, "弟子");
	set("inquiry", ([
			"峨眉"   :  (: ask_menpai, menpai:),
		]));

	set("chat_chance", 6);
        set("chat_msg", ({
	             "静师道: 想吃椰子吗？请小僮帮你打开吧。\n",
                     "静师道: 想吃椰子吗？你找个石块试着砸一砸它吧。\n",
                     "静师道: 其实有水喝就行了，椰子的用处大着呢。嘻嘻。\n",
                     "静师道: 听说有位医生最爱吃椰子，你若是给他椰子，他可以帮你疗伤。\n",
	}) );
	
	setup();
        carry_object("/d/emei/npc/obj/nun-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();

}
void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	
        if (me->query_temp(this_object()->query("id")) == 0 )
	{	
	        command("hi " + me->query("id"));
		command("say 这位" + RANK_D->query_respect(me) + "若有兴致来峨眉山一游，我们欢迎之至。\n"+
	     "你有什麽问题问我就好啦。"+HBRED+HIW"(ask jingshi about 峨眉) (help emei)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
