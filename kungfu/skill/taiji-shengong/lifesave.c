//Cracked by Roath
// lifesave.c
// by Marz@XKX
// Ryu modified neilidrop for self lifesave.
//(the higher the lvl should cost more max_neili)
// Fixed the bug in death count, sdong, 12/25/1999

#include <ansi.h>
#include <login.h>

int exert(object me, object target)
{
		  string name, *sname;
		  object deadman, *list;
		  mapping skill_status, learned_status;
		  int i, j, tao_level, tjsg_level, new_exp, neili_drop, sneili_drop, skill_amount;

		  if( !target )
					 return notify_fail("你想要救谁的命？\n");

		  if( me->is_fighting() || me->is_busy() )
					 return notify_fail("你正忙着呢！\n");

		  if ( (tao_level = me->query_skill("taoism", 1)) < 120)
					 return notify_fail("你的道学心法还没修到起死回生的程度！\n");

		  if ( (tjsg_level = me->query_skill("taiji-shengong", 1)) < 120)
					 return notify_fail("你的太极神功还不够高！\n");

		  if ( me == target && !me->is_ghost() )
					 return notify_fail("你还没死，用不着自救！\n");
		  else if ( me != target && !target->id("corpse") )
					 return notify_fail("要先找着一具尸体才能运功救命！\n");
		  else if ( target->id("corpse") && !target->is_character() )
					 return notify_fail("这具尸体已经腐烂，无法救转了！\n");

		  neili_drop = 150 - tjsg_level/2;
		  sneili_drop = 300 - tjsg_level; // this is where the bug from. if tjsg>300, can gain max_neil from lifesave self.
		  if (neili_drop <= 30) neili_drop = 30;

		  if (sneili_drop <= 100) sneili_drop = 100; // add this line to fix the bug, sdong, 8/6/1999

		  if (target == me)
		  {
					 if (tao_level < 140)
								return notify_fail("你的道学心法还没修到能走出鬼门关的程度！\n");

					 if (tjsg_level < 140)
								return notify_fail("你的太极神功还不够高！\n");

					 message_vision( HIW"$N盘膝坐下，默运太极神功，开始聚阴化阳....\n"NOR, me);
					 tell_object(me, HIW"功行两圈，丹田一股阳气若隐若现....\n\n"NOR);

					 if ( me->query("neili") < 1000 || random(tao_level+tjsg_level) < 24 )
					 {
								me->set("neili", 0);
								me->add("max_neili", -10);

								message_vision( HIY"$N突然停顿下来，显然内力受到极大损伤！\n"NOR, me);

								return notify_fail( HIY"可惜你内力不济，无法坚持下去了！\n"NOR );
					 }

					 tell_object(me, HIY"行满九个周天，你觉得丹田中的天罡阳气越来越盛....\n"NOR);
					 tell_object(me, HIY"一股罡气自丹田涌出，直冲天灵，你痛得几乎晕死过去！\n"NOR);
					 message("vision",
								HIY ""+me->name(1)+"化作一道天罡阳气消失了！\n"NOR,
								environment(me), me);

					 me->reincarnate();
					 me->add("neili", -1000);
					 me->add("max_neili", - sneili_drop );

					 learned_status = me->query_learned();

					 if ( mapp(skill_status = me->query_skills()) )
					 {
								sname = keys(skill_status);
								for(i=0; i<sizeof(skill_status); i++) {
										  skill_amount = (skill_status[sname[i]]+1) * (skill_status[sname[i]]+1) / 2;

										  if( !mapp(learned_status) ) learned_status = ([ sname[i] : skill_amount ]);
										  else {
													 if( learned_status[sname[i]]  < skill_amount )
																learned_status[sname[i]] += skill_amount;
													 else {
																learned_status[sname[i]] -= skill_amount;                                                                    - (skill_status[sname[i]]) * (skill_status[sname[i]]);
																me->set_skill(sname[i], skill_status[sname[i]]+1);
													 }
										  }
                        }
                }

                new_exp = (int)me->query("combat_exp") / 99;
                new_exp = new_exp > 5000 ? 5000 : new_exp;
                me->add("combat_exp", new_exp);
                me->set("qi",1); 
                me->set("eff_qi",1); 
                me->set("jing",1); 
                me->set("eff_jing",1); 
                me->set("jingli", 1);
                me->add("death_count", -1);
                me->add("death_times",-1);
                        
                me->move(REVIVE_ROOM);
                message("vision",
                        "你忽然前面多了一个人，面色惨白，就象是刚从棺材里爬出来似的。\n",
                         environment(me), me);

                me->unconcious();

        return 1;       
        
        } else // target is a corpse 
        {
                name = target->query("victim_name"); 
                
                list = users();
                for ( i = 0; i < sizeof(list); i++)
                if ( name == list[i]->name(1) ) break;
        
                if (i == sizeof(list)) 
                        return notify_fail(name+"的鬼魂不在。\n");
                        
                deadman = list[i];      
                if ( !deadman->is_ghost() )
                        return notify_fail(name+"已经活过来了,用不着你救。\n");
                        
                message_vision(
                        HIW "$N运起太极神功，手掌拍按"+target->name(1)+"的命门大穴。\n"
								"$N一边徐徐地将真气输入尸体内，口中一边凄惨地唤着"+name+"的名字。\n\n"
								"不一会，$N额头上冒出豆大汗珠，"+target->name(1)+"也似乎动了一下…\n\n"NOR, me);

					 if ( me->query("neili") < 1000 || random(tao_level+tjsg_level) < 24 )
					 {
								me->set("neili", 0);
								me->add("max_neili", -10);
                        
                        message_vision( HIY"$N突然停顿下来，显然内力受到极大损伤！\n"NOR, me);
                        return notify_fail( HIY"可惜你内力不济，无法坚持下去了！\n"NOR );
                } 
                
                me->add("neili", -1000); 
                me->add("max_neili", - neili_drop ); 
                me->receive_damage("qi", 3*neili_drop, "内力输出过度而死了。"); 
                me->receive_wound("qi", 2*neili_drop, "内力输出过度而死了。"); 

                message_vision( HIY"$N突然突然大吼一声，将余下真力全力送出！\n"
                        + "一缕魂魄归到尸体上，" + name +"的尸体竟然晃晃悠悠地站起来！"NOR, me);

                tell_object(deadman, HIY "一道天罡阳气击中你，痛得你几乎晕死过去！\n" NOR);

                message("vision",  
                        HIY"一道天罡阳气划过，"+name+"消失了！\n"NOR, 
                        environment(deadman), deadman );

                deadman->reincarnate();
                learned_status = deadman->query_learned();

                if ( mapp(skill_status = deadman->query_skills()) )
                {
                        sname = keys(skill_status);
                        for(i=0; i<sizeof(skill_status); i++) {
                                skill_amount = (skill_status[sname[i]]+1) * (skill_status[sname[i]]+1) / 2;

                                if( !mapp(learned_status) ) learned_status = ([ sname[i] : skill_amount ]);
                                else {
                                        if( learned_status[sname[i]]  < skill_amount )
                                                learned_status[sname[i]] += skill_amount;
                                        else {
                                                learned_status[sname[i]] -= skill_amount;                                                                    - (skill_status[sname[i]]) * (skill_status[sname[i]]);
                                                deadman->set_skill(sname[i], skill_status[sname[i]]+1);
                                        }
                                }
                        }
                }

                new_exp = (int)deadman->query("combat_exp") / 99;
                new_exp = new_exp > 5000 ? 5000 : new_exp;
                deadman->add("combat_exp", new_exp);
                deadman->set("qi",1); 
                deadman->set("eff_qi",1); 
                deadman->set("jing",1); 
                deadman->set("eff_jing",1); 
                deadman->set("jingli",1); 
                deadman->add("death_count", -1);
                deadman->add("death_times",-1);

                deadman->move(environment(me));
                destruct(target);
                deadman->unconcious();

        return 1;       
        }
        

        return 1;
}



// End of File
