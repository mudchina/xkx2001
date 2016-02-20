//Cracked by Roath
// shugan.c 树干
// zhangchi 7/00


inherit ITEM;

void create()
{
        set_name("树干", ({ "shu gan","trunk"}) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一根刚刚砍下来的树干。\n");
                set("unit", "根");
		set("no_get", "这么大的树干，你能拿起来吗？");
		set("value",1);
        }
}

void init()
{
	add_action("do_give","give");
	add_action("do_carry","carry");
	add_action("do_carry","kang");
	if (wizardp(this_player()))
		add_action("set_owner","setowner");
}

int set_owner(string arg)
{
	if (!arg) return notify_fail("指令格式：setowner <xxx>\n");
	set("owner",arg);
	write("OK!\n");
		
	return 1;
}

int do_give()
{
	return notify_fail("你正扛着大木头呢，怎么给人？\n");
}

int do_carry(string arg)
{
	object owner;
	object me=this_player();

	if (!arg) return 0;

	if (me->is_busy() || me->is_fighting() )
		return notify_fail("你正忙着呢。\n");

	if (arg != "shu gan" && arg != "trunk")
		return notify_fail("你要扛什么？\n");

	if (query("owner")!=me->query("id"))
		if (present(query("owner"),environment(me)) )
		{
			owner=find_player(query("owner"));
			message_vision("$N偷偷地想把树干抬起来，突然$n瞪了$N一眼，吓地$N赶紧缩手。\n",me,owner);
			return 1;
		}
		else
		{
			message_vision("$N瞧了瞧旁边没人，偷偷摸摸地把树干扛到肩上。\n",me);
			this_object()->move(me);
			me->set_temp("apply/short",({(me->query("title")+" "+me->query("name")+" 扛着一根树干")}));

			return 1;
		}
	
	message_vision("$N使劲一抬，将刚砍下来的树干扛到肩上\n",me);
	this_object()->move(me);
	me->set_temp("apply/short",({(me->query("title")+" "+me->query("name")+" 扛着一根树干")}));


	return 1;
}