//Cracked by Roath
// yangxin.c 养心丸

inherit PILL;
#include <ansi.h>
void setup()
{}
void init();
void wear(int);

int worn;
int cure_ob(string);
void create()
{
	set_name("养心丸", ({"yangxin wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗暗红发亮的养心丸。\n");
		set("value", 5000);
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
        message_vision(HIR "$N吃下一棵养心丹，只觉得头重脚轻，火气翻腾，原来服食过猛，药效适得其反！\n" NOR, this_player());
	this_player()->add("jingli", -200);
	this_player()->apply_condition("bonze_drug", 
		this_player()->query_condition("bonze_drug")+10);
	destruct(this_object());
	return 1;
}

void init()
{
//        worn = 0;
 //       call_out("wear", 1200, 1);
	add_action("do_pour", "drop");
}



void wear(int phase)
{
        worn = phase;
        switch(phase) {
        case 1:
                set("long", "这是一粒搁了很长时间的养心丸。\n");
                call_out("wear", 300, phase+1);
                break;
        case 2:
                set("long", "这是一粒已经不太成形的养心丸，快被风化了。\n");
                call_out("wear", 100, phase+1);
                break;
        case 3:
                destruct(this_object());
                break;
        }
}
int effect_in_liquid(object ob)
{
	if (ob->query("liquid/type") == "alcohol"){
        tell_object(this_player(), HIG"你只觉得一股热气自丹田冒出，混身上下有说不出的通泰。\n"NOR);
	this_player()->add("jingli", random(10)+10*ob->query("liquid/drunk_apply"));
	if (this_player()->query("neili") > this_player()->query("max_neili")*2)
        this_player()->set("neili", this_player()->query("max_neili") *2-1);
	}
        return 0;
}
