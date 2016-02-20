//Cracked by Roath
// moslem.c

inherit NPC;

void create()
{
	set_name("穆斯林", ({ "moslem", "musilin" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "一位虔诚的回族穆斯林。\n");
	set("shen_type", 1);
	set("combat_exp", 10000);
	set("str", 22);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
	set("attitude", "peaceful");
	set("inquiry", ([
		"阿拉" : "奉至仁慈的阿拉之名，一切赞颂，全归阿拉，全世界的主，至仁至慈的主，报应日的君主。",
		"真主" : "奉至仁慈的阿拉之名，一切赞颂，全归阿拉，全世界的主，至仁至慈的主，报应日的君主。",
	]));
	
       	set("chat_chance", 4);
	set("chat_msg", ({
	(: command("say 顺从真主和使者的人，与真主所恩惠的诸先知、笃信的人、殉道的人、善良的人同在。这等人是很好的伙伴。") :),
	(: command("say 我们的主啊！你没有徒然的创造这个世界！我们赞你超绝万物！求您保护我们，免受火狱的刑罚！") :),
	(: command("say 真主是信道的人的保佑者，使他们从重重黑暗走入光明。") :),
	(: command("say 愿真主阿拉保佑你。") :),
	}) );

	setup();
}
