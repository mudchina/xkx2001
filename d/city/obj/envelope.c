//Cracked by Roath
inherit ITEM;

int do_write(string);
string do_look(string);
string do_seal(string);
string do_open(string);
string do_tear(string);

void create()
{
    set_name("信封", ({"envelope", "xin feng", "feng"}));
    set_weight(30);
    set_max_encumbrance(100);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", "一只普通的信封。\n");
	set("unit", "只");
	set("material", "paper");
	set("value", 50);
	set("sealed", 0);
	set("opened", 0);
    }
}

int init()
{
    add_action("do_write", "write");
    add_action("do_look",  "look");
    add_action("do_seal",  "seal");
    add_action("do_open",  "open");
    add_action("do_tear",  "tear");
}

int is_container() {return 1;}

int reject(object ob)
{
    object me = this_object();

    if (me->query("sealed")) {
	if (me->query("opened")) {
	    notify_fail("信封已经破了，没法再装东西了。\n");
	}else{
	    notify_fail("信封封着呢，怎么往里装东西？\n");
	}
	return 1;
    }
    if (ob->query("material") != "paper") {
	notify_fail("信封里只能装纸。\n");
	return 1;
    }
    if (sizeof(all_inventory(me)) >= 3) {
	notify_fail("信封里已经塞满了东西。\n");
	return 1;
    }
    return 0;
}


int do_write(string arg)
{
    object me = this_object(), player = this_player();

    if (arg != "envelope" && arg != "xin feng" && arg != "feng") return 0;
    if (player->is_busy())
	return notify_fail("你正忙着呢。\n");
    if (me->query("content"))
	return notify_fail("信封上已经写满了字，你找不到地方下笔。\n");

    message_vision("$N在信封上写起东西来。。。\n", player);

    me->set("writer", player->query("name"));
    write("信封上可以写好几行，写完了用 . 表示结束。\n");
    write("－－－－－－－－－－－－－－－－－－－－－－－－－－\n");
    input_to("get_msg");
    return 1;
}

int get_msg(string msg)
{
    object me = this_object();
    string old_content = me->query("content");

    if (msg == ".") {
	write("\n");
	return 1;
    }

    if (old_content) 
	me->set("content", old_content + msg + "\n");
    else 
	me->set("content", msg+"\n");
    input_to("get_msg");
    return 1;
}

int do_tear(string arg)
{
    object me = this_object(), player=this_player();
    object *inv;

    if (arg != "envelope" && arg != "xin feng" && arg != "feng") return 0;
    message_vision("$N一把将信封撕得稀烂。\n", player);
    destruct(me);
    return 1;
}

int do_open(string arg)
{
    object me = this_object(), player=this_player();
    object *inv;

    if (arg != "envelope" && arg != "xin feng" && arg != "feng") return 0;
    if (!me->query("sealed")) 
	return notify_fail("这只信封从来就没封起来。\n");
    if (me->query("opened")) 
	return notify_fail("这只信封已经被撕开了。\n");
    me->set("opened", 1);
    message_vision("$N把信封撕开。\n", player);
    // set("value", 0);
    inv = all_inventory(me);
    if (sizeof(inv)) map_array(inv, "unlock", me);
    return 1;
}

int do_seal(string arg)
{
    object me = this_object(), player=this_player();
    object *inv;

    if (arg != "envelope" && arg != "xin feng" && arg != "feng") 
	return notify_fail("你要封什么？\n");
    if (me->query("sealed")) 
	return notify_fail("这只信封已经是封着的了。\n");
    if (me->query("opened")) 
	return notify_fail("这只信封已经被撕破了，你无法再把它封起来。\n");
    me->set("sealed", 1);
    message_vision("$N小心翼翼地把信封封上口。\n", player);
    inv = all_inventory(me);
    if (sizeof(inv)) map_array(inv, "lock", me);
    return 1;
}

int do_look(string arg)
{
    object me = this_object(); 
    mixed *inv;

    if (arg != "envelope" && arg != "xin feng" && arg != "feng") return 0;

    if (me->query("sealed")) {
	if (me->query("opened") == 0) {
	    write("这是一只封着的信封");
	}else {
	    write("这是一只被打开了的信封");
	}
    } else {
	write("这是一只崭新的信封");
    }

    if(! me->query("content")) {
	write("，上面什么也没写。\n");
    }else{
	write("，上面写着：\n\n");
	write(me->query("content")+"\n");
	write("\n从字迹来看似乎是"+me->query("writer")+"的亲笔。\n");
    }

    if (!me->query("sealed") || me->query("opened")) {
	inv = all_inventory(me);
	if (sizeof(inv)) {
	    inv = map_array(inv, "inventory_look", this_object());
	    write("里面有：\n  "+implode(inv, "\n  ") +"\n");
	}
    }
    return 1;
}

void lock(object obj, int flag) { obj->set("no_get", 1); } 
void unlock(object obj, int flag) { obj->delete("no_get"); } 

string inventory_look(object obj, int flag)
{
    return "    " + obj->short();
}
