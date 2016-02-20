//Cracked by Roath
string look_jia() {
    string msg;
    msg = "
可以拿的兵器有剑(sword)，刀(blade)，棒(stick)，杖(staff)，轮(falun)，
鞭(whip)，棍(club)。还有铁甲(armor)，石块(stone)，醍醐香(xiang)，颅钵
(lubo)，人头链(lian)，骷髅冠(guan)，对讲机(walkie-talkie)，箫(xiao)。\n\n";
    return msg;
}

int do_get(string arg) {
    object weapon, me=this_player(), *temp, env;
    string type;
    int i;

    if(!arg) return 0;
    if(me->is_busy()) return 0;
    if (sscanf(arg, "%s from jia", type) != 1) return 0;

    switch (type) {
    case "sword":   if(this_player()->query("gender") == "无性")
                        weapon = new("/clone/test/xiuhua");
                    else
                        weapon = new("/clone/weapon/gangjian");
                    break;
    case "blade":   weapon = new("/clone/weapon/gangdao");
                    break;
    case "xiao" :   weapon = new("/d/taohua/obj/tiexiao");
                    break;
    case "stick":   weapon = new("/clone/weapon/gangbang");
                    break;
    case "staff":   weapon = new("/clone/weapon/shezhang");
                    break;
    case "falun":   weapon = new("clone/weapon/falun");
                    break;
    case "whip" :   weapon = new("/clone/weapon/changbian");
                    break;
    case "club" :   weapon = new("/clone/weapon/panguanbi");
                    break;
    case "armor":   weapon = new("/clone/armor/tiejia");
                    break;
    case "stone":   weapon = new("/d/city/obj/stone");
                    break;
    case "xiang":   weapon = new("/d/foshan/obj/tihu-xiang");
                    break;
    case "lubo" :   weapon = new("/d/xueshan/obj/lubo");
                    break;
    case "lian" :   weapon = new("/d/xueshan/obj/rtlian");
                    break;
    case "guan" :   weapon = new("/d/xueshan/obj/klguan");
                    break;
    case "walkie-talkie" : 
                    temp = all_inventory(me);
                    for (i = 0; i < sizeof(temp); i++) {
                        if (temp[i]->query("id") == "walkie-talkie") {
                            write("你已经拿了对讲机了。\n");
                            return 1;
                        }
                    }
                    weapon = new(__DIR__"obj/walkie-talkie");
                    env = environment(me);
                    if ( env->query("short") == "东厢房" )
                        weapon->set("channel", 1);
                    else if (env->query("short") == "西厢房" )
                        weapon->set("channel", 2);
                    break;
    default:        write("找不到"+type+"。\n");
                    return 1;
    }

    if(weapon->move(me)) {
        message_vision("$N从兵器架上取下一"+weapon->query("unit")+weapon->name()+"。\n", me);
    } else {
        destruct(weapon);
    }
    return 1;
}

void create_xiangfang() {
    set("item_desc", ([
        "jia" : (: look_jia :),
    ]));
}

void init_xiangfang() {
    add_action("do_get", "get");
    add_action("do_open", "open");
}
