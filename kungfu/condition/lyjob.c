//Cracked by Roath
// by aln 2 / 98
// modified by aln 4 / 98

inherit F_CLEAN_UP;

#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
        object room, obj;
        string str;
        int lvl, cost, bonus;
        mapping learned;

        if( !(room = environment(me)) ) return 0;

        if( base_name(room) != "/d/hangzhou/lingyin3" ) 
		{
			tell_object(me,"你不在灵隐寺大雄宝殿，不能诵经！");
			return 0;
		}

        lvl = (int)me->query_skill("buddhism", 1);
        cost = 60000 / (30 + lvl);

		if( me->query("jing",1) < cost *2)
		{
			tell_object(me,"你诵经过度，精力不足，无法继续！");
			return 1;
		}

		//me->receive_damage("jing", cost + random(cost), "精力透支过度死了");

        me->receive_damage("jing", cost + random(cost));

        if( me->is_fighting() || me->is_busy() || !living(me) )
                return 1;

        if( duration < 1 ) {
                message_vision(HIR"\n一名小僧过来对$N说道：大师辛苦了，您休息一下吧。\n"NOR, me);
                me->add_temp("lypoint", 1);
                return 0;
        }

        bonus = lvl * (int)me->query("int") / 2;
        bonus = bonus * 4/(5 + sizeof(me->query_skills()));
        learned = me->query_learned();
        if( undefinedp(learned["buddhism"]) )  learned["buddhism"] = 0;
        learned["buddhism"] += bonus/3 + random(bonus/3);

        if( (int)me->query("potential") < (int)me->query("max_potential") )
                me->add( "potential", lvl * 4/(5 + sizeof(me->query_skills()))/3 );

        switch(random(13)) {
              case 0:
	        str = "一切诸如来，从於本因地，皆以智慧觉，了达於无明。";
                break;
	      case 1:
		str = "知彼如空华，即能免流转。又如梦中人，醒时不可得。";
                break;
              case 2:
		str = "觉者如虚空，平等不转动。觉遍十方界，即得成佛道。";
                break;
              case 3:
		str = "众幻灭无处，成道亦无得。本性圆满故，菩萨於此中，能发菩提心。末世诸众生， 修此免邪见。";
                break;
              case 4:
		str = "普贤汝当知，一切诸众生，无始幻无明。皆从诸如来，圆觉心建立。";
                break;
              case 5:
		str = "犹如虚空华，依空而有相。空华若复灭，虚空本不动。幻从诸觉生";
                break;
              case 6:
		str = "幻灭觉圆满，觉心不动故。若彼诸菩萨，及末世众生，常应远离幻。";
                break;
              case 7:
		str = "诸幻悉皆离。如木中生火，木尽火还灭。觉则无渐次，方便亦如是。";
                break;
              case 8:
		str = "净业汝当知，一切诸众生，皆由执我爱。无始妄流转，";
                break;
              case 9:
		str = "未除四种相，不得成菩提。爱憎生於心，谗曲存诸念。";
                break;
              case 10:
		str = "是故多迷闷，不能入觉城。若能归悟刹，先去贪嗔痴，";
                break;
              case 11:
		str = "法爱不存心，渐次可成就。我身本不有，憎爱何由生？";
                break;
              case 12:
		str = "此人求善友，终不堕邪见。所求别生心，究竟非成就。";
                break;
	}

        message_vision(HIY"\n$N敲击木鱼高声诵吟：" + str + "\n\n"NOR, me);
        me->start_busy(5 + random(cost/15));

        me->apply_condition("lyjob", duration - 1);
        return 1;
}

	
