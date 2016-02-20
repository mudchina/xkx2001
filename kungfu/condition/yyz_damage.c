//Cracked by Roath
// by oyxb
// by acep

#include <ansi.h>
string* xuedao = ({
        "巨骨穴",
        "地仓穴",
        "肩井穴",
        "颊车穴",
        "承泣穴",
        "风池穴",
        "章门穴",
        "风府穴",
        "精促穴",
        "陶道穴",
        "强间穴",
        "少海穴",
        "犊鼻穴",
        "神门穴",
        "华盖穴",
        "大椎穴",
        "凤尾穴",
        "至阳穴",
        "劳宫穴",
        "百会穴",
        "灵台穴",
        "太阳穴",
        "膻中穴",
        "命门穴",
        "鸠尾穴",
        "三阴交",
        "天柱穴"
});


int update_condition(object me, int duration)
{
	object ob;
	if (!living(me)) {
		message("vision", me->name() + "闷哼了一声。\n", environment(me), me);
	}
	if (me->query("family/family_name")=="大理段家"
		&& me->query_skill("kurong-changong")) return 1;
	if (me->query_temp("yyzenemy")) {
		tell_object(me,HIR"你感到"+xuedao[random(sizeof(xuedao))]+"一阵酸麻，血气不畅，顿时动弹不得！\n"NOR);
		me->start_busy(random(3));
		if (duration>=200) {
			if (ob = LOGIN_D->find_body(me->query_temp("yyzenemy")))
				me->receive_damage("qi", duration, ob);
			else me->receive_damage("qi", duration, "遭一阳指劲不治而死");
		}
	}
	else me->receive_damage("qi", duration/3, "遭一阳指劲不治而死");
	if (me->query_condition("yyz_damage")>(5+me->query_skill("force",1)/10))
		me->apply_condition("yyz_damage", duration - 5 - me->query_skill("force",1)/10);
	else return 0;
	return 1;
}
