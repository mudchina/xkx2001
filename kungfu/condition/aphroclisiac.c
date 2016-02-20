//Cracked by Roath
// EMOTE_D->main("xxx", xxx);
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

string* ra = ({
 	"$N大叫一声，一把抓住$n，狠狠的扑了过去！\n", 
	"$N哼了一声，对$n说道：我，我，我受不了啦！\n", 
	"$N两眼通红，喘着粗气，直勾勾的盯着$n！\n", 
	"$N不住的呻吟道：好热啊，好热啊；说着在肌肤上抓出道道血痕！\n", 
	"$N贼忒嘻嘻地盯着$n，一边走过去挨挨蹭蹭，一边嘴里乱叫：我的亲亲小宝贝儿哟！\n", 
	"$N觉得一股热气从小腹冒上，浑身火热，尤如身在熔炉，只想抓住$n搂在怀里。\n", 
	"$N口中“荷荷”低哼，紧盯着$n，野兽般的目光似乎把$n的衣服一层层剥去。\n", 
});

int update_condition(object me, int duration)
{
	object *ob;
	int i;
	string msg;

	if (me->query("gender") == "男性") msg = "气喘吁吁，喉咙里发出野兽一般的“嗬嗬”之声";
		else msg = "媚眼如丝，轻轻哼了几声，充满了销魂蚀骨的意味";

   	if( !living(me) ) {
      		message("vision", me->name() + "痛苦地呻吟了一声。\n", environment(me), me);
   	}
   	else {
      		tell_object(me, HIM"你只觉身上一片火热，不由自主的撕扯起身上的衣服起来！\n" NOR );
      		message_vision(HIM"$N面上一片潮红，衣衫半解，"+msg+"。\n"NOR, me);
   	}
//      	me->receive_wound("jing", 10, "");
      	
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me || !me->visible(ob[i]) ) 
			continue;
		message_vision(CYN""+ra[random(sizeof(ra))]+""NOR, me, ob[i]);
		break;
	}

	me->apply_condition("aphroclisiac", duration - 1);
	
   	if( duration < 1 ) return 0;
   	return CND_CONTINUE;
}
