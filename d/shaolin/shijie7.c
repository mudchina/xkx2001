//Cracked by Roath
// Room: /d/shaolin/shijie7.c
// Modified by Apache

#include <ansi.h>
void arguing(object me, object ob, int question);
inherit ROOM;

void create() {
    set("short", "石阶");
	
	set("long", @LONG
石级继续向上延伸，瀑布在脚下越来越小，水声也渐行远去
几位身着灰黄色僧衣的僧人擦肩而过，看他们下山的时後脚步沉
稳，好象是个会家子。往上远眺，似乎可以看到石檐一角。
LONG
	);
	
	set("exits", ([
		"southdown" : __DIR__"shijie6",
		"east" : __DIR__"shanmen",
	]));

	set("outdoors", "shaolin");
	set("cost", 2);
	setup();
}

void init() {
    object challenger, me = this_player();

    if ( me->query("family/family_name") == "少林派" && me->query("family/generation") < 38
         && random(5) == 2 && !present("sengren", environment(me)) ) {
        message_vision(HIR "石级旁边的草丛中忽然跃起一个身影，挡住了$N！\n" NOR, me);
        challenger = new(__DIR__"npc/challenger");
        challenger->move(environment(me));
        me->set_temp("challenged", 1);
        me->set_temp("challenger", challenger);
    }

    add_action("do_argue", "argue");
    add_action("do_giveup", "giveup");
}

int do_argue(string arg) {
    object ob, me = this_player();
    int count;

	if( me->query("family/family_name") != "少林派" )
	    return notify_fail("少林山门前，不许喧哗滋事！\n");

    if( !arg )
        return notify_fail("你想说服谁？\n");

    if( !(ob = present(arg, environment(me))) )
        return notify_fail("这儿没有你要说服的人。\n");

    if( me->query("family/generation") > 37 )
        return notify_fail("你的辈份还不够。\n");

    if( !me->query_temp("challenged") )
        return notify_fail("少林弟子岂可以多取胜！\n");

    if( me->is_fighting() || me->is_busy() )
        return notify_fail("你正忙着。\n");

    if( ob->query("race") != "人类" )
        return notify_fail(ob->name() + "听不懂人话！\n");

    if( ob->is_fighting() || ob->is_busy() )
        return notify_fail(ob->name() + "正忙着。\n");

    if( userp(ob) )
        return notify_fail("还是用闲聊频道跟别的玩家说理吧。\n");

    if( ob->query_temp("opponent") != me )
        return notify_fail("人家不想理你！\n");

    if ( !(me->query_temp("argued")) ) {
        me->set_temp("argued", 1);
        message_vision("\n$N说道：“阿弭佗佛！出家人慈悲为怀，习武只是强身健体。”\n", me);
        message_vision("$N说道：“小僧想讨教一些佛法，不知大师是否愿意指点一二？”\n", me);
        call_out("arguing", 1, me, ob, 0);
        me->start_busy(2);
    }
    else {
        count = me->query_temp("argued");
        if (count > 3)
            return notify_fail("看来你没有什么问题能难倒他。还是另想办法吧。\n");
        if (count == 1) {
            switch (random(5)+1) {
            case 1:
                message_vision("\n$N问道：“「顿悟」何解？”\n", me);
                call_out("arguing", 3, me, ob, 11);
                break;
            case 2:
                message_vision("\n$N问道：“「渐悟」何解？”\n", me);
                call_out("arguing", 3, me, ob, 12);
                break;
            case 3:
                message_vision("\n$N问道：“为佛弟子，常於昼夜，至心诵念八大人觉。何为第一觉悟？”\n", me);
                call_out("arguing", 3, me, ob, 13);
                break;
            case 4:
                message_vision("\n$N问道：“为佛弟子，常於昼夜，至心诵念八大人觉。何为第二觉知？”\n", me);
                call_out("arguing", 3, me, ob, 14);
                break;
            case 5:
                message_vision("\n$N问道：“为佛弟子，常於昼夜，至心诵念八大人觉。何为第三觉知？”\n", me);
                call_out("arguing", 3, me, ob, 15);
                break;
            }
        }
        if (count == 2) {
            switch (random(5)+1) {
            case 1:
                message_vision("\n$N问道：“为佛弟子，常於昼夜，至心诵念八大人觉。何为第四觉知？”\n", me);
                call_out("arguing", 3, me, ob, 21);
                break;
            case 2:
                message_vision("\n$N问道：“为佛弟子，常於昼夜，至心诵念八大人觉。何为第五觉悟？”\n", me);
                call_out("arguing", 3, me, ob, 22);
                break;
            case 3:
                message_vision("\n$N问道：“为佛弟子，常於昼夜，至心诵念八大人觉。何为第六觉知？”\n", me);
                call_out("arguing", 3, me, ob, 23);
                break;
            case 4:
                message_vision("\n$N问道：“众生以十事为恶，何等为十？”\n", me);
                call_out("arguing", 3, me, ob, 24);
                break;
            case 5:
                message_vision("\n$N问道：“吾辈弟子，当奉六度，何为六度？”\n", me);
                call_out("arguing", 3, me, ob, 25);
                break;
            }
        }
        if (count == 3) {
            switch (random(5)+1) {
            case 1:
                message_vision("\n$N问道：“为佛弟子，常於昼夜，至心诵念八大人觉。何为第七觉悟？”\n", me);
                call_out("arguing", 3, me, ob, 31);
                break;
            case 2:
                message_vision("\n$N问道：“为佛弟子，常於昼夜，至心诵念八大人觉。何为第八觉知？”\n", me);
                call_out("arguing", 3, me, ob, 32);
                break;
            case 3:
                message_vision("\n$N问道：“何为无常？”\n", me);
                call_out("arguing", 3, me, ob, 33);
                break;
            case 4:
                message_vision("\n$N问道：“以何因缘，得知宿命？会其至道？”\n", me);
                call_out("arguing", 3, me, ob, 34);
                break;
            case 5:
                message_vision("\n$N问道：“何者为善？何者最大？”\n", me);
                call_out("arguing", 3, me, ob, 35);
                break;
            }
        }
        me->add("jing", -200+random(30));
        me->add("jingli", -200+random(30));
        me->start_busy(3+random(2));
        count++;
        me->set_temp("argued", count);
    }

    return 1;
}

void arguing(object me, object ob, int question) {
    int my_bud, ob_bud, bonus;
    mapping learned;

    if( !objectp(ob) ) return;

    if( question == 0) {
        message_vision("\n$N点头道：“不错，当与大师印证佛法。”\n", ob);
        return;
    }

    my_bud = me->query_skill("buddhism", 1);
    ob_bud = ob->query_skill("buddhism", 1);
    learned = me->query_learned();

    if ( (my_bud > ob_bud) && ((my_bud - ob_bud) > random(40)) ) { /* bonus for 120 < bud_lvl < 160 */
        learned["buddhism"] += 200 + random(50);
		if(my_bud > 400) /*higher buddhism can gain more*/
		learned["buddhism"] += 100 + random(60);
        bonus = 40 - (my_bud - ob_bud);
        if (bonus < 0) bonus = 0; /* any one with buddhism > 160 can not get bonus at all. */
        bonus = bonus/2 + random(bonus/2);
        //message("info", sprintf("bonus %d\n", bonus), environment(me), 0);
        me->add("combat_exp", bonus);
        me->add("potential", bonus/2);
        if ( me->query("potential",1) > me->query("max_potential",1) )
            me->set("potential", me->query("max_potential",1) );
        message_vision("\n$N默不做声，忽然面带愧色，一声不响地离开了。\n", ob);
        destruct(ob);
        me->delete_temp("challenged");
        me->delete_temp("challenger");
        me->delete_temp("argued");
        return;
    }
    else if ( (my_bud < ob_bud) && (random(40) > (ob_bud - my_bud)) ) { /* bonus for bud_lvl < 120*/
        learned["buddhism"] += 200 + random(50);
        bonus = ob_bud - my_bud;
        if (bonus == 0) bonus = random(20); /* for bud_lvl = 120 */
        bonus = bonus/2 + random(bonus/2);
        //message("info", sprintf("bonus %d\n", bonus), environment(me), 0);
        me->add("combat_exp", bonus);
        me->add("potential", bonus/2);
        if ( me->query("potential",1) > me->query("max_potential",1) )
            me->set("potential", me->query("max_potential",1) );
        message_vision("\n$N默不做声，忽然面带愧色，一声不响地离开了。\n", ob);
        destruct(ob);
        me->delete_temp("challenged");
        me->delete_temp("challenger");
        me->delete_temp("argued");
        return;
    }

    switch(question) {
    case 11:
        message_vision("\n$N应声道：“一闻法，即知五蕴本空，六尘非有，立即开悟，而明大道。”\n", ob);
        break;
    case 12:
        message_vision("\n$N应声道：“由信而解，解而行，行而证，次第渐修，也可悟入。”\n", ob);
        break;
    case 13:
        message_vision("\n$N应声道：“世间无常，国土危脆，四大苦空，五阴无我，生灭变异，虚伪无主，  心是恶源，形为罪薮，如是观察，渐离生死。”\n", ob);
        break;
    case 14:
        message_vision("\n$N应声道：“多欲为苦，生死疲劳，从贪欲起，少欲无为，身心自在。”\n", ob);
        break;
    case 15:
        message_vision("\n$N应声道：“心无厌足，惟得多求，增长罪恶，菩萨不尔，常念知足，安贫守道，惟慧是业。”\n", ob);
        break;
    case 21:
        message_vision("\n$N略一沉思，微笑道：“懈怠坠落，常行精进，破烦恼恶，摧伏四魔，出阴界狱。教化一切，悉以大乐。”\n", ob);
        break;
    case 22:
        message_vision("\n$N略一沉思，微笑道：“愚痴生死，菩萨常念，广学多问，增长智慧，成就辩才，教化一切，悉以大乐。”\n", ob);
        break;
    case 23:
        message_vision("\n$N略一沉思，微笑道：“贫苦多怨，横结恶缘；菩萨布施，等念怨亲，不念旧恶，不憎恶人。”\n", ob);
        break;
    case 24:
        message_vision("\n$N略一沉思，微笑道：“身三：杀、盗、淫；口四：两舌、恶口、妄言、绮语；意三：嫉、恚、痴。”\n", ob);
        break;
    case 25:
        message_vision("\n$N略一沉思，微笑道：“布施、持戒、忍辱、精进、一心、智慧。”\n", ob);
        break;
    case 31:
        message_vision("\n$N苦思良久，道：“五欲过患，虽为俗人，不染世乐，常念三衣，瓦钵法器，  志愿出家，守道清白，梵行高远，慈悲一切。”\n", ob);
        break;
    case 32:
        message_vision("\n$N苦思良久，道：“生死炽然，苦恼无量，发大乘心，普济一切，愿代众生，受无量苦，令诸众生，毕竟大乐。”\n", ob);
        break;
    case 33:
        message_vision("\n$N苦思良久，道：“色、痛、想、行、识，皆为无常。”\n", ob);
        break;
    case 34:
        message_vision("\n$N苦思良久，道：“净心守志，可会至道；譬如磨镜，垢去明存；断欲无求，当得宿命。”\n", ob);
        break;
    case 35:
        message_vision("\n$N苦思良久，道：“行道守真者善。志与道合者大。”\n", ob);
        break;
    default:
        ;
    }

    return;
}


int do_giveup() {
    object ob, me = this_player();

    if ( me->query_temp("challenged") && present(me->query_temp("challenger"), environment(me)) ) {
        ob = me->query_temp("challenger");
        if ( !ob->query_temp("fought") ) {
            message_vision("\n$N冷笑道：“少林和尚个个都是贪生怕死之辈！”\n", ob);
            me->add("combat_exp", -random(20));
        }
        me->delete_temp("challenger");
        me->delete_temp("challenged");
        message_vision("\n$N离开了。\n", ob);
        destruct (ob);
    }
    else
        return notify_fail("什么？");

    return 1;
}            
        
int valid_leave(object me, string dir) {
    object ob;

    ob = me->query_temp("challenger");


    if ( me->query_temp("challenged") && objectp(ob) && me == ob->query_temp("opponent") )
        return notify_fail("少林弟子岂可贪生怕死，以坠本派声名！\n");
    else { 
        me->delete_temp("challenged");
        me->delete_temp("challenger");
        me->delete_temp("argued");
    }
        return ::valid_leave(me, dir);
}

