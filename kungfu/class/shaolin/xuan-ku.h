//Cracked by Roath
// xuan-ku.h for fight and get letter from Xuan
// modified by aln  4 / 98

#include <ansi.h>

string* names = ({
	"chengguan luohan",
	"chengzhi luohan",
	"chengming luohan",
	"chengjing luohan",
	"chengjian luohan",
	"chengxing luohan",
	"chengji luohan",
	"chengmie luohan",
	"chenghe luohan",

        "chengxin luohan",
        "chengyi luohan",
        "chengsi luohan",
        "chengshi luohan",
        "chengzhi luohan",
        "chengxin luohan",
        "chengling luohan",
        "chengyu luohan",
        "chengshang luohan",
});

string ask_me()
{
	mapping fam, my_fam, skl; 
        object fighter, me, room, monk;
	string *sname;
	int i,j, right_time;

	fighter = this_player();

        if( fighter->query("luohan_winner") )
		return RANK_D->query_respect(fighter) + 
		"已然闯过罗汉大阵，可不要拿老衲开这等玩笑。";

        right_time = uptime() % 1800;
//        if( right_time < 180 || right_time > 1380
//        ||  ( right_time > 480 && right_time < 1080 ) )
//                return RANK_D->query_respect(fighter) + 
//                "来得不凑巧，改日再来闯罗汉大阵吧。";

//        if( time() < (int)fighter->query("try_lhz") + 86400 )
//                return RANK_D->query_respect(fighter) +
//                "不久前闯罗汉大阵失败而归，你现在的功力一定也还不够吧。";

	skl = fighter->query_skills();
	sname  = keys(skl);  

	for(i=0; i<sizeof(skl); i++) {
		if (skl[sname[i]] < 90)
		return RANK_D->query_respect(fighter) + 
		"功力不够，不够资格闯罗汉大阵。";
	}

        me = this_object();
	my_fam  = me->query("family");

	if ( mapp(fam = fighter->query("family")) 
	&& fam["family_name"] == "少林派"
	&& fam["generation"] != (my_fam["generation"] + 2))
		return RANK_D->query_respect(fighter) + 
		"辈份不合，不够资格闯罗汉大阵。";

        if ( (int)fighter->query("guilty") > 0 )
		return RANK_D->query_respect(fighter) + 
		"你累犯数戒，身带重罪，我如何能准许你闯罗汉大阵！";

        if( base_name(environment()) != "/d/shaolin/luohan5" )
                return RANK_D->query_respect(fighter) + 
                "还是等老衲回到罗汉堂再说吧。";

	if ( stringp(me->query_temp("busyfor")) ) {
                if( me->query_temp("busyfor") != fighter->query("id") )
		return RANK_D->query_respect(fighter) + 
		"，今日已有人挑战罗汉大阵，你过一段时间再来吧。";
                else
                return RANK_D->query_respect(fighter) +
                "，罗汉堂已经准备就绪。\n";
        }

        say("\n玄苦说道：好吧，我来召集罗汉堂长老们于东练武场集合，我稍候在中央练武场上等你。\n");
        message_vision("\n玄苦大师往南离开。\n\n", fighter);

        for(j=1; j<10; j++) 
        {
                if(!( room = find_object("/d/shaolin/luohan" + j)) )
                room = load_object("/d/shaolin/luohan" + j);

                me->move(room);
                if( !objectp(monk = present(names[j-1], room) )) {
                        me->move("/d/shaolin/luohan5");
                        message_vision("\n玄苦大师走了过来。\n\n", fighter);
                        return "真是对不起，罗汉堂中有人不在，无法举行罗汉大阵。";
                }

                if( monk->query("jing")*10 < monk->query("max_jing")*8
                ||  monk->query("qi")*10 < monk->query("max_qi")*8
                ||  monk->query("neili")*10 < monk->query("max_neili")*5 ) {
                        me->move("/d/shaolin/luohan5");
                        message_vision("\n玄苦大师走了过来。\n\n", fighter);
                        return "真是对不起，罗汉堂中有位长老身体不适，无法举行罗汉大阵。";
                }

                message("vision", "\n玄苦大师走了过来，跟" + monk->query("name") + "俯耳轻声说了几句。\n", room, monk);
                message("vision", monk->query("name") + "罗汉点了点头，快步走了出去。\n", room, monk);
                monk->move("/d/shaolin/wuchang2");
        }

        me->move("/d/shaolin/luohan5");
        message_vision("\n玄苦大师走了过来，跟$N说道：罗汉堂长老已经集合在东练武场。\n", fighter);
        say("\n玄苦又道：请你速去告知般若堂玄难大师，请他即刻招集般若堂诸罗汉于髁肺涑〖稀n");

        message_vision("\n玄苦大师往西离开。\n\n", fighter);
        me->move("/d/shaolin/wuchang");
        message_vision("\n玄苦大师走了过来。\n\n", me);

        fighter->set_temp("xuanku-ready", 1);
        me->set_temp("busyfor", fighter->query("id"));
        me->set_temp("waiting_time", 0);
        call_out("waiting", 1, fighter);
        return "好！大家都出来了。\n";
}

void waiting(object fighter)
{
        add_temp("waiting_time", 1);
        if( (int)query_temp("waiting_time") >= 300 ) {
		say("玄苦大师说道：看来今日的罗汉大阵是没戏了，我们回去罢！\n\n");
		call_out("do_back", 0);
                return;
	}

        if( !fighter ) {
                say("玄苦说道：看来他不会来了，我们回去罢！\n\n");
                call_out("do_back", 0);
                return;
        }

        if( !fighter->query_temp("xuannan-ready") ) {
                if( !random(10) )
                say("\n玄苦说道：" + "般若堂长老还没有集合好，再等一会儿。\n");
                call_out("waiting", 1, fighter);
                return;
        }

        if( environment(fighter) != environment() ) {
                if( !random(10) )
                say( "\n玄苦说道：闯罗汉大阵的人还没准备好，再等一会儿吧。\n");
                call_out("waiting", 1, fighter);
                return;
        }

        fighter->delete_temp("xuanku-ready");
        fighter->delete_temp("xuannan-ready");
        fighter->set("try_lhz", time());

        call_out("preparing", 1, fighter);
}

void preparing(object fighter)
{
	object monk1, monk, room1, room;

        if( !fighter ) {
                say("玄苦大师说道：看来今日的罗汉大阵是没戏了，我们回去罢！\n\n");
                call_out("do_back", 0);
                return;
        }

        room = environment();
        if( !objectp(monk = present("xuannan dashi", room)) ) {
                say("玄苦大师说道：看来今日的罗汉大阵是没戏了，我们回去罢！\n\n");
                call_out("do_back", 0);
                return;
        }

        say("玄苦大师朝玄难大师点了点头，玄难大师点了点头。\n");

        say( "玄难说道：不相干的人，如不欲现场观摩罗汉大阵，请即刻离开此处。\n");

	if(!( room1 = find_object("/d/shaolin/wuchang2")) )
	room1 = load_object("/d/shaolin/wuchang2");
	monk1 = present("mu ren", room1);
	monk1->move("/d/shaolin/houdian");

	if(!( room1 = find_object("/d/shaolin/wuchang1")) )
	room1 = load_object("/d/shaolin/wuchang1");
	monk1 = present("mu ren", room1);
	monk1->move("/d/shaolin/houdian");

        if( objectp(monk1 = present("daojue chanshi", room)) ) {
                message("vision", "玄苦大师跟道觉禅师俯耳轻声说了几句。\n", room, monk1 );
                message("vision", monk1->query("name") + "禅师点了点头，快步往北离开。\n", room);
                monk1->move("/d/shaolin/houdian");
        }

        message("vision", HIY "\n玄苦大师大声宣布：东罗汉大阵合围！\n" NOR, room);
        message("vision", HIY "\n玄难大师大声宣布：西罗汉大阵合围！\n\n" NOR, room);

        command("chat " + fighter->query("title") + fighter->query("name") + 
                "于今日" + NATURE_D->game_time() + "挑战少林十八罗汉大阵！");

	message("vision", "\n只听四周响起沙沙的脚步声，东西十八位罗汉们个个神情肃杀，\n"
		"或赤手空拳，或手持兵器，慢慢地围了上来，堵住了通路。\n\n", room);
        room->set("store", room->query("exits"));
	room->delete("exits");

	say( "玄苦又道：准备，罗汉大阵即刻发动！\n\n");
	call_out("fighting", 3, fighter, 0);
        remove_call_out("do_back");
        call_out("do_back", 50);
	return;
}

void fighting(object fighter, int count)
{
	object monk, room1, room;

        if( !fighter ) {
                 say("玄苦摇了摇头，说道：想不到 ... 唉！\n\n");
                 command("sigh");
                 remove_call_out("do_back");
                 call_out("do_back", 1);
                 return;
        }

        room = environment();
        if( environment(fighter) != room ) {
                 say("玄苦摇了摇头，说道：想不到 ... 唉！\n\n");
                 command("sigh");
                 remove_call_out("do_back");
                 call_out("do_back", 1);
                 return;
        }

        if( !living(fighter) || fighter->query("qi") <= 1
        ||  fighter->query_temp("apply/armor") >= 100 ) {
                 say("玄苦摇了摇头，说道：想不到 ... 唉！\n\n");
                 command("comfort " + fighter->query("id"));     
                 remove_call_out("do_back");
                 call_out("do_back", 1);
                 return;
        }

        if( (count % 2) == 0 )
        message("vision", "\n罗汉大阵急速地旋转着，一层层地向内收紧！\n" NOR, room);

        if( count <= 8 ) {
                 if(!( room1 = find_object("/d/shaolin/wuchang2")) )
                 room1 = load_object("/d/shaolin/wuchang2");

                 if( !objectp(monk = present(names[count], room1)) ) {
                         command("sorry " + fighter->query("id"));
                         command("say 有一名长老身体不适，罗汉大阵不得不解散。");
                         remove_call_out("do_back");
                         call_out("do_back", 1);
                         return;
                 }
        } else if( count <= 17 ) {
                 if(!( room1 = find_object("/d/shaolin/wuchang1")) )
                 room1 = load_object("/d/shaolin/wuchang1");

                 if( !objectp(monk = present(names[count], room1)) ) {
                         command("sorry " + fighter->query("id"));
                         command("say 有一名长老身体不适，罗汉大阵不得不解散。");
                         remove_call_out("do_back");
                         call_out("do_back", 1);
                         return;
                 }
        } else {
                 call_out("do_recruit", 1, fighter);
                 return;
        }

        monk->move(room);
        if( fighter->query("family/family_name") != "少林派" ) {
                 monk->add_temp("apply/attack", 20);
                 monk->add_temp("apply/damage", 20);
                 fighter->add_temp("apply/defense", -20);
               COMBAT_D->do_attack(monk, fighter, monk->query_temp("weapon"));
                 monk->add_temp("apply/attack", -20);
                 monk->add_temp("apply/damage", -20);
                 fighter->add_temp("apply/defense", 20);
        } else 
               COMBAT_D->do_attack(monk, fighter, monk->query_temp("weapon"));

        monk->move(room1);
        
        count++;
        if( (count % 2) > 0 )  fighting(fighter, count);
        else call_out("fighting", 1, fighter, count);
}

void do_recruit(object fighter)
{
	mapping ft_fam, my_fam;

        if( (int)fighter->query("combat_exp") < 300000 )
	fighter->add("combat_exp", 20000000 / (100000 + (int)fighter->query("combat_exp")) * 100);
        fighter->delete("try_lhz");
	fighter->set("luohan_winner", 1);

	if (!(ft_fam = fighter->query("family")) || ft_fam["family_name"] != "少林派")
	{
		command("bow");
		say("玄苦说道：" + RANK_D->query_respect(fighter) + "此番过阵，当对本身修行大有助益，百尺竿头，更进一步，老衲就此别过！\n");
                remove_call_out("do_back");
		call_out("do_back", 5);
	}
	else
	{
		say("\n玄苦说道：恭喜你闯过了十八罗汉大阵！ 本寺有此等杰出弟子，届时必当为武林放一异彩！\n");
                remove_call_out("do_back");
		call_out("do_back", 20);
        }
}

void do_back()
{
        object monk, room, room1, room2, room3;
	int i;

        room = environment();
	message("vision", "\n玄苦大师挥了挥手， 罗汉堂长老们随即鱼贯离开练武场。\n", room );
        if( !mapp(room->query("exits")) && mapp(room->query("store")) )
        room->set("exits", room->query("store"));

        if(!( room1 = find_object("/d/shaolin/houdian")) )
        room1 = load_object("/d/shaolin/houdian");

        if( objectp(monk = present("daojue chanshi", room1)) )
        monk->move("/d/shaolin/wuchang");

        if( objectp(monk = present("mu ren", room1)) )
        monk->move("/d/shaolin/wuchang1");

        if( objectp(monk = present("mu ren", room1)) )
        monk->move("/d/shaolin/wuchang2");

	for(i = 1; i < 10; i++) {
                if( !( room2 = find_object("/d/shaolin/wuchang2")) )
		room2 = load_object("/d/shaolin/wuchang2");

                if( objectp(monk = present(names[i-1], room2)) )
	        monk->move("/d/shaolin/luohan" + i);
	}

        if( objectp(monk = present("xuannan dashi", room)) ) {
                message("vision", "\n玄难大师也挥了挥手， 般若堂长老们随即也离开练武场。\n", room );
                monk->delete_temp("busyfor");
                monk->move("/d/shaolin/banruo5");

                for(i = 10; i < 19; i++) {
                if( !( room3 = find_object("/d/shaolin/wuchang1")) )
		room3 = load_object("/d/shaolin/wuchang1");
     
                if( objectp(monk = present(names[i-1], room3)) )
	        monk->move("/d/shaolin/banruo" + (i - 9));
                }
	}

        delete_temp("busyfor");
	move("/d/shaolin/luohan5");
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
		return;
	}

	if ( ob_fam["generation"] < my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

	if ( (ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "澄") 
	||   (ob_fam["generation"] >=  my_fam["generation"]      && name[0..1] == "玄") )
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎麽跑到我这儿来了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query("luohan_winner") )
		{	
			command("say 老衲垂死之年，又得一可塑之才，真是可喜可贺 !");

			name = ob->query("name");
			new_name = "澄" + name[2..3];
			ob->set("name", new_name);
	
			command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为少林派澄字辈罗汉之一 !");
			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "，你没有闯过十八罗汉大阵，不能越级拜师。");
			return;
		}
	}

	return;
}
