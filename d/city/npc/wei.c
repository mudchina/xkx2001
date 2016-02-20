//Change by server (5/25/2001)
// npc: /d/city/npc/wei.c
// modified by aln  2 / 98
// modified by kane 4 / 98

inherit NPC;

string ask_book();
string ask_beauty();
int env_cmp(object o1, object o2);

void create()
{
        set_name("韦春芳", ({ "wei chunfang", "chunfang", "wei" }) );
        set("gender", "女性" );
	set("title", "丽春院老板娘");
//	set("nickname", "鹿鼎公");
        set("age", 52);
        set("long", 
            "韦春芳是当朝鹿鼎公兼红花会总舵主韦小宝他娘，虽是徐"
	    "娘半老，但风韵尤存。\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("shen_type", 1);

        set_skill("unarmed", 20);
	set_skill("force", 20);
        set_skill("dodge", 35);
	set_skill("beauty",60);

        set("combat_exp", 25000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

	set("hooker", 1);
        set("attitude", "friendly");
        set("inquiry", ([
            "name" : "老娘我就是韦春芳。",
            "韦小宝" : "那是我的乖儿子，长得就像你。",
            "丽春院" : "我们丽春院可是扬州城里头一份的找乐子去处。",
            "here" : "我们丽春院可是扬州城里头一份的找乐子去处。",
            "长春经"  : (: ask_book :),
	    "beauty" : (: ask_beauty :),
       ]) );

        setup();
        set("amount", 1);
        set("chat_chance", 15);
        set("chat_msg", ({
                "韦春芳得意地说道：当年老娘我标致得很，每天有好几个客人。\n",
                "韦春芳怒骂道：辣块妈妈，要是罗刹鬼、红毛鬼子到丽春院来，老娘用大扫帚拍了出去?。\n",
                "韦春芳对你说道：你一双眼睛贼忒嘻嘻的，真像那个喇嘛！\n",
        }) );
        carry_object("/d/city/obj/flower_shoe")->wear();

        carry_object("/d/city/obj/pink_cloth")->wear();
}
private void go_home()
{
	if( !living(this_object()) ) return;
		message_vision("$N说到:这是什么鬼地方，我还要去接客做生意呢。\n", this_object());
        message_vision("$N神色慌张地离开了。\n", this_object());
        this_object()->move("/d/city/lichunyuan");
	message_vision("$N快步走了过来。\n", this_object());
}
	


void init()
{
        object ob;

        ::init();
        if( environment() != load_object("/d/city/lichunyuan") ) {
		remove_call_out("go_home");
		call_out("go_home", 1);
	}
		else

        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query("hooker"))
	return 1;
}

void greeting(object me)
{
    command("look " + me->query("id"));

    if (me->query("gender")=="无性") {
       command("say 你当老娘是烂婊子吗？辣块妈妈，老娘满汉蒙藏回都接，就是不伺候太监！");
       command("kick " + me->query("id"));
       message("vision", me->name() +"被韦春芳一脚踢出门外。\n",
                environment(me), ({me}));
       me->move("/d/city/nandajie3");
       message("vision", me->name() +"被人从丽春院里踢了出来，栽倒在地上，磕掉两颗门牙。\n", 
                environment(me), ({me}));

    }
    else {
    if (me->query("class") =="bonze") {
       command("say 呦，" + RANK_D->query_respect(me) 
                +"也来光顾我们丽春院啊。");
       command("say 想当年我接过一个西藏喇嘛，他上床前一定要念经，一面念经，眼珠子就骨溜溜的瞧着我。");
    }
    if (me->query("gender")=="女性") {
       command("say 哎呀，这年月大姑娘也逛窑子，成何体同。");
       command("sigh");
       command("say 可惜我儿子不在，不然让他伺候你。");
    }
    command("say 楼上楼下的姑娘们，客人来了！");
    }
    return ;
}

string ask_book()
{
       object obj, ob = this_player();

       if( !ob->query("hooker") )
              return "滚！这是老娘做大辈子生意得来的东西岂能给你这" + RANK_D->query_rude(ob) + "！";

       if( !query("amount") )
              return "已经给人借走了。";

       obj = new("/d/city/obj/changchun");
       obj->move(ob);
       add("amount", -1);
       message_vision("$N从衣兜里掏出一" + obj->query("unit") + obj->name() + "递给$n。\n", this_object(), ob);
       return "看在姐妹份上借给你看看，不过你一定要赶紧还呀。";
}

int env_cmp(object o1, object o2)
{
        string env1, env2;
        object where;
        env1 = (where = environment(o1)) ? base_name(where) : "none";
        env2 = (where = environment(o2)) ? base_name(where) : "none";
        return strcmp(env1, env2);
}

string ask_beauty()
{
	object where,ob,obj,*ob_list;
	string msg, name;
	int i, per = 0;

//	ob_list = sort_array(users(), (: env_cmp :));
	ob_list = users();

	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("per") > per 
		&& ob_list[i]->query("gender") == "女性"
		&& !ob_list[i]->query("hooker")
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			per = obj->query("per");
		}
	}

	if ( !obj ) {
	msg ="天哪，现在居然一个姑娘家都没有，肯定都被你们这帮臭流氓吓跑了！\n";
	return msg;
	}

	obj->set_temp("top_girl",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	switch( per/5 )
	{
	case 0:
	case 1:
	case 2:
		msg ="现在侠客行里居然数"+name+"这样三分象人，七分象鬼的母夜叉最漂亮，这还有天理吗？\n";
		break;
	case 3:
		msg =name+"的相貌还不到中人之资，怎么就排上她了呢，大概是山中无老虎，猴子称霸王吧！\n";
		break;
	case 4:
		msg =name+"的相貌不差，泥巴里现在就数她了，赶快帮她找个老公嫁了吧！\n";
		break;
	case 5:
		msg =name+"长得那个美啊，如果到我们丽春院来接客，乖乖龙的东韭菜炒大葱，保管客人踏破门坎子！\n";
		break;
	case 6 :
		msg =name+"别不是仙女下凡吧，如果到咱这院子，恐怕连神仙也是这里的常客呢！\n";
		break;
	}

	return msg;
}
