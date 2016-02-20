//Cracked by Roath
// pregnant.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	object ob; 
	string result;
	int dura;
	dura = me->query_condition("pregnant");
	if(dura > 1000 && random(6) == 1){
		tell_object(me,HIY"你觉得身体不适，只想找些梅子之类的酸东西吃。\n"NOR);
	}
	if(dura > 700 && dura < 1000 && random(6) == 1){
		tell_object(me,HIY"你呕出一口酸水，只觉心中一阵烦恶。\n"NOR);
	}
	if(dura > 400 && dura < 700 && random(6) == 1){
		tell_object(me,HIY"你觉得腰身渐渐粗大，行动甚不方便。\n"NOR);
	}
	if(dura > 300 && dura < 400 && random(6) == 1){
		tell_object(me,HIY"你觉得腹中有物蠕蠕而动，心中又是羞涩又是甜蜜。\n"NOR);
	}
	if(dura > 100 && dura < 300 && random(6) == 1){
		tell_object(me,HIY"你觉得腹中的小生命用力的踢着你的肚子，暗骂：小冤家，急死你了？\n"NOR);
	}
	if(dura > 50 && dura < 100 && random(6) == 1){
		tell_object(me,HIY"你腹中一阵剧痛，啊！快要生了！\n"NOR);
	}
	if(dura > 10 && dura < 50){
		switch(3)
		{	
			case 1:
			case 2:
			case 3:
				
message_vision(HIR"$N只觉腹中阵阵疼痛，再也支持不住，伏倒在地，就此晕了过去。\n"NOR,me);
				ob = new("/u/kane/baby");
				break;
		}
		me->apply_condition("pregnant",1);
	}
	printf("%d\t%d\n",duration,dura);
	me->apply_condition("pregnant", duration - 1);
	if( !duration ) return 0;

	return CND_CONTINUE;
}

void create() {
	seteuid(getuid());
}
