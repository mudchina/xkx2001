//Cracked by Roath
inherit ITEM;

int do_write(string);
string do_look(string);
string do_tear(string);

void create()
{
    set_name("白纸", ({"paper"}));
    set_weight(30);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", "一张刚从书店买来的宣纸。\n");
	set("unit", "张");
	set("material", "paper");
	set("value", 30);
	set("create_time", time());
	set("freshness", "刚从书店买来的宣纸");
    }
    remove_call_out("aging");
    call_out("aging", 600);
}

int init()
{
    add_action("do_write", "write");
    add_action("do_look",  "look");
    add_action("do_tear",  "tear");
}

int do_tear(string arg)
{
    object me = this_object(), player = this_player();

    if (arg != "paper") return 0;
    if (player->is_busy()) return notify_fail("你正忙着呢。\n");
    message_vision("$N一把将纸撕的稀烂。\n", player);
    destruct(me);
    return 1;
}

int do_write(string arg)
{
    object me = this_object(), player = this_player();

    if (arg != "paper") return 0;
    if (player->is_busy())
	return notify_fail("你正忙着呢。\n");
    if (me->query("content"))
	return notify_fail("这张纸上已经写满了字，你找不到地方下笔。\n");

    message_vision("$N在纸上写起东西来。。。\n", player);

    me->set("writer", player->query("name"));
    write("纸上可以写好几行，写完了用 . 表示结束。\n");
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

int do_look(string arg)
{
    object me = this_object();
    int age = time() - me->query("create_time");

    if (arg != "paper") return 0;

    if(! me->query("content")) {
	write("这是一张"+query("freshness")+"，上面什么也没写。\n");
	return 1;
    }
    
    write("这是一张"+me->query("freshness")+"，上面" + 
	(age<36000?"写着":"隐约可辨地有些字迹") + "：\n\n");
    write(me->query("content")+"\n");
    write("\n从字迹来看似乎是"+me->query("writer")+"的亲笔。\n");
    return 1;
}

int aging()
{
    int age;

    remove_call_out("aging");
    call_out("aging", 600);
    
    age = time() - query("create_time");
    if (age > 600 && age < 3600) {
	set("freshness", "还留这纸香的宣纸");
    }else if (age < 7200) {
	set("freshness", "雪白的宣纸");
    }else if (age < 21600) { // 5 hours
	set("freshness", "有点发黄的宣纸");
    }else if (age < 36000) { // 10 hours
	set("freshness", "有点发霉的宣纸");
    }else if (age < 72000) { // 20 hours
	set("freshness", "已经发霉的宣纸");
    }else if (age < 144000) { // 40 hours
	set("freshness", "被虫蛀了些洞的宣纸");
    }else{
        message("vision", "一阵风吹来，把"+query("name")+
		"吹散不见了。\n", environment());
	destruct(this_object());
    }
    return 1;
}
