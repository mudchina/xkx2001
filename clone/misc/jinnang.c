//Cracked by Roath
// /clone/misc/jinnang.c
// Wzfeng 4/1/1998
//程序功能说明:锦囊,可存放玩家的信函。具有读，添加，丢弃信件的功能。

#include <ansi.h>

inherit ITEM;

inherit F_SAVE;
mapping *letters;
mapping letter;



int set_owner(string id)
{
        set("owner_id", id);
        return restore();
}
//设置存盘的文件路径和名称。
string query_save_file()
{
        string id;

        if( !stringp(id = query("owner_id")) ) return 0;

        return DATA_DIR + "letter/" + id[0..0] + "/" + id+"_jin";
}

//添加信件的函数
void add_letter(mapping letter)
{
        if( !pointerp(letters) )
        {
         letters = ({ letter });
        }
        else letters += ({ letter });

}

//删除信件的函数。
void cut_letter(mapping letter)
{
        if( !pointerp(letters) )
        {
         letters = ({ letter });
        }
        else letters -= ({ letter });

}



void create()
{
	set_name(CYN "锦囊" NOR, ({ "jin nang", "nang" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("material", "silk");
		set("no_get",1);
		set("no_drop","锦囊是随身物品，你不能随便丢下它");
		set("no_insert", 1);
	}
	setup();
	
}

int query_autoload()
{
	return 1;
}
//初始化物品，设定锦囊的描述等
void init()
{
	int letter_num,i;
	object ob,me;
	string letter_msg="";
	ob=this_object();
    me=this_player();
	set("master_id",this_player()->query("id"));
    set_owner(ob->query("master_id"));
	letter_num=sizeof(letters);

	for(i=0;i<letter_num;i++)
	{
		letter_msg+="第"+chinese_number(i+1)+"封信函\t";
		letter_msg+="【书信标题】："+letters[i]["title"]+"\t";
		letter_msg+=letters[i]["from"]+"写于"+letters[i]["time"]+"\n";
	}
if(letter_num)
{	
	set("long", "
这是一个可以用来装信的锦囊。\n"
"你可用(read)来读信，用(add)往里面放信,用(discard)来丢弃某一封信。\n"
"目前里面装着"+chinese_number(letter_num)+"封信函。\n"
""+letter_msg+"\n"
);
}else
{
		set("long", "
这是一个可以用来装信的锦囊。\n"
"你可用(read)来读信，用(add)往里面放信,用(discard)来丢弃某一封信。\n"
"目前里面没有装任何信函。\n");
}

    add_action("do_add", "add");
	add_action("do_read", "read");
	add_action("do_cut", "discard");

}

//丢弃信件的函数
int do_cut(string arg)
{
        object ob;
        int i,num;

        ob=this_object();
		
    	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("你要丢弃哪一封信？\n");

        if( !pointerp(letters) || num < 1 || num > sizeof(letters) )
		return notify_fail("没有这个编号的信件。\n");
		num --;
		write("你从锦囊中拿出一封信函,丢在一边。\n");
        cut_letter(letters[num]);
		save();
		init();
		
        return 1;
}


//添加信件的函数
int do_add(string arg)
{
    object ob,ob_letter;
    int i;
    mapping letter;
    
	if(!arg) return notify_fail("你要将什么放进锦囊里？\n");
	ob_letter = present(arg, this_player());
	if(!ob_letter)
        return notify_fail("你身上好像并没有样物品？\n");
	if(!ob_letter->query("can_add_jinnang"))
        return notify_fail("对不起！你无法将这件物品放进锦囊里。\n");
    if(!ob_letter->query("be_read"))
		return notify_fail("你还没有读过这封信呢？请先读一遍再放进锦囊不迟。\n");

	if(sizeof(letters)>9)
	{
		return notify_fail("锦囊已被装满，没有地方放这封信了。\n");
	}

	letter=ob_letter->query("letter");
	add_letter(letter);
	save();
	init();
	destruct(ob_letter);
	write("你将一封信函放进锦囊中。\n");
	return 1;
}

//读信件的函数。
int do_read(string arg)
{
        object ob;
        int i,num;

        ob=this_object();
		
    	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("你要读哪一封信？\n");

        if( !pointerp(letters) || num < 1 || num > sizeof(letters) )
		return notify_fail("没有这个编号的信件。\n");
		num --;

        printf("【书信标题】：%s\n【收信人】：%s\n【信件内容】：\n%s\n\t\t%s写于%s\n\n\n",
        letters[num]["title"],
		letters[num]["to"],
        letters[num]["text"],
		letters[num]["from"],
		letters[num]["time"]
		);
		
        return 1;
}


