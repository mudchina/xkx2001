//Cracked by Roath
// wzfeng, 12/28/98
//注意，阴历的年份算法我没有做，生加上去的，请在每一年的头一天
//修改string chinese_time(int date)函数



#include <ansi.h>
#include <localtime.h>
inherit ITEM;
inherit F_SAVE;
mapping *letters;
mapping letter;
static string *sym_di = ({ "子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥" });
int set_owner(string id)
{
        set("owner_id", id);
        return restore();
}

string chinese_time(int date)
{
	mixed *local;
	int i;

	local = localtime(date);
	i = (local[LT_HOUR]+1) % 2 * 2 + local[LT_MIN] / 30;
	return sprintf("戊寅年%s月%s日%s时%s",
                chinese_number(local[LT_MON] + 1),
                chinese_number(local[LT_MDAY]),
                sym_di[((local[LT_HOUR] + 1) % 24) / 2],
		i?chinese_number((local[LT_HOUR]+1) % 2 * 2 + 
		local[LT_MIN] / 30 ) + "刻":"正");
}




string query_save_file()
{
        string id;

        if( !stringp(id = query("owner_id")) ) return 0;

        return DATA_DIR + "letter/" + id[0..0] + "/" + id;
}

void send_letter(mapping letter)
{
        if( !pointerp(letters) )
        {
         letters = ({ letter });
        }
        else letters += ({ letter });

}

void modify_letter(mapping letter)
{
        if( !pointerp(letters) )
        {
         letters = ({ letter });
        }
        else letters -= ({ letter });

}


void add_send_level(int a)
{
        int i;
        if(!i=sizeof(letters))
         return;
        letters[i-1]["send_level"]=a;
        return;


}
void add_send_time(int a)
{
        int i;
        if(!i=sizeof(letters))
         return;
        letters[i-1]["send_time"]=a;
        return;


}



void check(object me,object obj)
{
        object ob;
        int i,k;
		string str_time;
        string name_id;
        name_id=me->query("id");

         for(i=0;i<sizeof(letters);i++)
         {

		 ob=new("/d/city/obj/letter");
         ob->set("letter",letters[i]);
		 str_time=chinese_time(ob->query("letter/time"));

         switch( ob->query("letter/send_level"))
                {
                                case 1:
                                {
                                        
										ob->set("long", 
"这是一封已经封好的信函。上面写着：\n"
+me->query("name")+"      亲启。\n"+
ob->query("letter/from")+"托扬州驿站转。\n"
"扬州驿站签发于"+str_time+"。\n"
"你可拆(chai or open)开上面的封漆，取出书函。\n");
										ob->set_name("信函", ({"xin han","letter"}));
                                        ob->set("send_level_time",600);
                                }

                                                  break;
                                case 2:
                                        {
                                        
                                        ob->set_name(YEL"信函"NOR, ({"xin han","letter"}));
										ob->set("long",
"这是一封已经封好的信函。其背面沾着三根羽毛。上面写着\n"
+me->query("name")+"      亲启。\n"+
ob->query("letter/from")+"托扬州驿站转。\n"
"扬州驿站签发于"+str_time+"。\n"
"你可拆(chai or open)开上面的封漆，取出书函。\n");
										ob->set("send_level_time",300);

                                }

                                                  break;
                                case 3:
									{
                                        ob->set_name(HIR"信函"NOR, ({"xin han","letter"}));
                                       	ob->set("long", 
"这是一个已经封好的帛囊，里面装有书函。其背面沾着五根羽\n"
"毛。上面写着：\n"
+me->query("name")+"      亲启。\n"+
ob->query("letter/from")+"托扬州驿站转。\n"
"扬州驿站签发于"+str_time+"。\n"
"你可拆(chai or open)开上面的封漆，取出书函。\n");
										ob->set("send_level_time",0);
									}
                                                  break;

                }
                if(ob->query("letter/send_time")+ob->query("send_level_time")<time())
                 {
                 //可以发信
                 ob->move(me);
                 modify_letter(letters[i]);
                 save();
                 k++;
                 }
                 else
                 {
                         //时间未到.
                         destruct(ob);
                 }
        }

        if(k)
        {

                obj->do_emote(ob->query("letter/to"));
                tell_object(me,CYN"一个驿使走了过来。\n"NOR);
                tell_object(me,CYN"驿使向你报拳说道：“这里有您的信件，您小心收好”。\n"NOR);
                tell_object(me,CYN"驿使从身上拿出一个包裹交到你手里。\n"NOR);
                tell_object(me,CYN"驿使对你说到：“驿使送到，在下还有公务在身，先行告退。\n"NOR);
                tell_object(me,CYN"驿使走了出去。\n"NOR);
        }

}

void create()
{
        set_name("信", ({"xin", "letter"}));
        set_weight(1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一封已经写好的信，你可用读(read letter)来看它的内容。\n");
                set("unit", "封");
                
		        set("can_read_letter",1);

                }
}

void init ()
{
        add_action("do_read", "read");
        add_action("do_read", "读");
}

int do_read(string arg)
{
     object ob,ob_letter;
      int i;
     ob=this_object();
     
	 if(!arg) return notify_fail("你要读什么信件？\n");
	 
	 ob_letter = present(arg, this_player());
	 
	 if(!ob_letter)
            return notify_fail("你身上好像并没有这封信件？\n");
        if(!ob_letter->query("can_read_letter"))
                return notify_fail("对不起！你无法从这里面读到任何东西。\n");
		


        if(!i=sizeof(letters))
                return notify_fail("读取失败。\n");
		
        printf("【书信标题】：%s\n【收信人】：%s\n【信件内容】：\n%s\n\t\t%s写于%s\n\n\n",
        letters[i-1]["title"],
		letters[i-1]["to"],
        letters[i-1]["text"],
		letters[i-1]["from"],
		chinese_time((letters[i-1]["time"]))
		);

        return 1;
}

