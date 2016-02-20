//Cracked by Roath
// /d/huanghe/npc/guanjia.h
// by aln 2 / 98

string ask_job()
{
        object me = this_player(), leader, ling, ob, *obj, dest, room;
        string myfam, *files, file, region, biaoju, ob_bang;
        int i, temp, myexp;
        mapping job;

        string *levels = ({
                "3000",
                "5000",
               "10000",
               "20000",
               "50000",
              "100000",
              "300000",
              "500000",
        });

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "莫非是想打听我帮的秘密吧。";  

        if( time() < (int)me->query("bangs/asktime") + 60 )
                return RANK_D->query_rude(me) + "不是刚问过我吗？";

        if( objectp(leader = me->query_leader()) ) {
                if( leader != this_object() )
                         return RANK_D->query_rude(me) + "！入了帮还三心二意跟别人？！";
        }

        me->set("bangs/asktime", time());

        if( !(ling = present("bang ling", me)) ) {
                ling = new(BANGLING);
                ling->set("owner", me->query("id"));
                ling->set("fam", myfam);
                ling->set("combat_exp", query("combat_exp"));
                ling->move(me);
                message_vision("$N把一" + ling->query("unit") + ling->name() + "扔给$n。\n", this_object(), me);
        }

        myexp = (int)me->query("combat_exp");
        myexp = (4 * myexp + random(2 * myexp)) / 5;

        temp = sizeof(levels);
        for( i = 0; i < temp; i++ ) 
                if( myexp < atoi(levels[i]) ) break;

        if( i >= temp )
                return "最近没有适合你的帮务。";

        job = (BANGJOB + levels[i])->query_job();

        if( mapp(ling->query("job")) )
                ling->delete("job");
        ling->set("job", job);

        if( ob = present("caili", me) )
                destruct(ob);

        switch(job["type"]) {
        case "寻":
                command("nod");
                ling->set("job/max", atoi(levels[i]));
                return "你去把" + job["name"] + "找来。";
                break;

        case "杀":
                command("nod");
                ling->set("job/max", atoi(levels[i]));
                return "你去把" + job["area"] + "的" + job["name"] + "杀了。";
                break;

        case "摊费":
                command("nod");
                job = info_store[random(sizeof(info_store))];
                ling->set("job/name", job["name"]);
                ling->set("job/boss", job["boss"]);
                ling->set("job/place", job["place"]);
                return  job["name"] + "这个月还没有交摊费，快去要来！";
                break;

        case "截镖":
                obj = filter_array(children(BIAOTOU), (: clonep :));
                if( sizeof(obj) < 10 ) {
                        ob = new(BIAOTOU);
                        file = biao_places[random(sizeof(biao_places))];
                        ob->move(file);
                        dest = environment(ob);            
                        message("vision",
                        ob->name() + "押着镖车走了过来。\n",
                        dest, ({ob}));
                        region = explode(file, "/")[1];
                        ling->set("job/name", ob->query("nickname"));
                        return "去踩盘的弟兄们回来讲，" + 
                        ob->query("nickname") + 
                        "的镖车将经过" + 
                        region_names[region] + dest->query("short") + "。";
                } else {
                        ob = obj[random(sizeof(obj))];
                        dest = environment(ob);
                        biaoju = (string)ob->query("nickname");

                        if( !dest || !biaoju ) {
                                destruct(ob);
                                command("shake");
                                return "你歇着吧，最近没有要紧的帮务。";
                        }

                        file = base_name(dest);
                        if( strsrch(file, "/d/") != 0
                        || !mapp(dest->query("exits")) ) {
                                destruct(ob);
                                command("shake");
                                return "你歇着吧，最近没有要紧的帮务。";
                        }

                        command("nod");
                        region = explode(file, "/")[1];
                        ling->set("job/name", biaoju);
                        return "去踩盘的弟兄们回来讲，" + biaoju + 
                        "的镖车将经过" + 
                        region_names[region] + dest->query("short") + "。";
                }
                break;

        case "示威":
                obj = filter_array(children(BANGZHONG), (: clonep :));
                if( sizeof(obj) ) {
                obj = filter_array(obj, "is_victim", this_object(), myfam);
                if( sizeof(obj) ) {
                        command("nod");
                        ob = obj[random(sizeof(obj))];
                        ob_bang = (string)ob->query("title");
                        me->set_temp("bangs/victim", ob_bang);
                        ling->set("job/name", ob_bang);
                        return "最近" + ob_bang + "经常跟我们过不去，你去杀一个示示威！";
                }
                }
                break;

        case "送礼":
                command("nod");

                job = info_guest[random(sizeof(info_guest))];
                region = explode(job["file"], "/")[1];

                ob = new(CAILI);
                ob->set("job", job);
                ob->set("owner", me);
                ling->set("job/title", job["title"]);
                ling->set("job/area", job["area"]);
                ob->set("long",
"这是一份" + myfam + "帮主送给" + "「" + job["title"] + "」" + "的彩礼。\n");
                ob->move(me);
                message_vision("$N将一" + ob->query("unit") + ob->name() + "交给$n。\n", this_object(), me);
                return "你把这份彩礼送给" + job["area"] + "的" + "「" + job["title"] + "」" + "。";
                break;

        case "买卖":
                command("nod");
                files = get_dir(BANGGOOD);
                if( !sizeof(files) ) {
                         command("shake");
                         return "你歇着吧，最近没有要紧的帮务。";
                }
                file = BANGGOOD + files[random(sizeof(files))];
                ob = new(file);
                ob->move(me);
                message_vision("$N将一" + ob->query("unit") + ob->name() + "交给$n。\n", this_object(), me);
                ling->set("job/name", ob->name());
                ling->set("job/good", ob->query("id"));
                ling->set("job/prices", info_business[ob->name()]);
                return "你把这" + ob->query("unit") + ob->name() + "拿去卖个好价钱。";
                break;

        case "伙计":
                command("nod");
                ling->set("job/name", "伙计");
                return "你去天宝阁当差吧。";
                break;
        }

        command("shake");
        return "你歇着吧，最近没有要紧的帮务。";
}

void do_start(object me, object ob)
{
        ob->move(environment());
        destruct(this_object());
}

int accept_object(object who, object ob)
{
        object obj;
        int bonus, record;
        string name, chname = "";
        mapping job;

        if( who->query_temp("bangs/fam") != query("fam") ) 
                return notify_fail(name() + "大怒道：大胆！想谋害本总管！！！\n");

        if( !(obj = present("bang ling", who)) )
                return notify_fail(name() + "大怒道：没有用的东西，连帮令都会搞丢？！\n");

        if( !mapp(job = obj->query("job")) )
                return notify_fail(name() + "大怒道：没有用的东西，连自己的帮务都记不住？！\n");

        switch(job["type"]) {
        case "寻":
                name = ob->name();
                for(int i = 0; i < strlen(name); i++)
                        if(name[i] > 160 && name[i] < 255) 
                                chname += name[i..i];
                if( chname != job["name"] )
                        return notify_fail(name() + "大怒道：没有用的东西，连自己的帮务都记不住？！\n");
                bonus = job["bonus"] * job["max"] / ((int)who->query("combat_exp") + 1000);
                record = bonus / 2 + random(bonus);
                log_file("BangJob", sprintf("%s于%s时找到%s得%s经验点\n", who->query("name"), ctime(time()), chname, chinese_number(record)));
                bonus = job["score"];
                break;

        case "截镖":
                if( base_name(ob) != BIAOHUO )
                        return notify_fail(name() + "大怒道：没有用的东西，连一枝镖都搞不定！\n");
                if( ob->query("my_killer") != who->query("id") )
                        return notify_fail(name() + "大怒道：江湖中最讲究的就是信用，再欺世盗名就宰了你！\n");
                break;  
        }

        command("nod");
        obj->delete("job");

        who->add("combat_exp", record);
        who->add("shen", -bonus);
        obj->add("score", bonus);

        remove_call_out("store");
        call_out("store", 1, ob);
        return 1;
}

void store(object ob)
{
        ob->move("/d/shenlong/cangku");
}

private is_victim(object ob, string arg)
{
        string fam;

        if( !stringp(fam = ob->query("title")) ) return 0;
        if( fam == arg ) return 0;

        return 1;
}
