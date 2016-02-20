//Cracked by Roath
//yushan
//Ssy

#include <ansi.h>

inherit F_SAVE;
inherit F_AUTOLOAD;
inherit ITEM;

int query_autoload() { return 1; }

int sortexp1(string arg1, string arg2);
string WIZ_DIR = "/wiz/clone/";

void create()
{
    set_name(HIY"玩家型鹅毛扇"NOR, ({ "fan", "yushan", "shan" }));
    set_weight(5);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "把");
        set("long", "这是一把鹅毛扇，相传是三国时期诸葛亮的遗物。\n");
//		set("value", 2000000000);
    }
    setup();
}

void init()
{
    add_action("do_sort","sort");
    add_action("do_readlist", "readlist");
    add_action("do_makelist", "makelist");
}

int do_makelist(string arg)
{
	object ob;
	object me = this_player();
	object ob1 = this_object();
	if( !ob1->query("data") ) return notify_fail("你还没有 sort 呢？\n");
	ob = new( WIZ_DIR + "xkx_list.c" );
	ob->set("data", this_object()->query("data") );
	ob->move(me);
	message_vision(HIY"$N把扇子摇了摇，摇出了一张侠客行风云榜。\n"NOR, me);
	return 1;
}

int do_readlist(string arg)
{
	mapping *lists;
	int k, num;
		
	lists = this_object()->query("data");
	
	if( !lists ) return notify_fail("你还没有 sort 呢？\n");
	
	num = sizeof(lists);
	if ( num > 101 ) num = 101;
	
	write("侠客行风云榜：\n");
	
	for(int i = 0; i < num; i++)
	{
		k = i+1;
		write("第"+ chinese_number(k) + "名：" + lists[i]["name"] + "(" + lists[i]["id"] + "): 经验 " + lists[i]["exp"] + "。年龄：" + chinese_number(lists[i]["age"]) + "岁\n");
	}
	return 1;
}



int sortexp1(mixed arg1, mixed arg2)
{
  int exp1,exp2;
  object ob;
  
  exp1=arg1["exp"];
    exp2=arg2["exp"];
  if (exp1<exp2) return 1;
  else if (exp1>exp2) return -1;
  else return 0;
}
int do_sortallexp(int day)
{
    int i, j, ppl_cnt, count, rank;
    string *dir, *ppls, name;
    mapping *ob_list;
    mixed info;
    object ob,ob1, this_ob;
	string err;
	int rc;

	rank = 0;
	this_ob = this_object();
	
    seteuid(getuid());
    write("sortall...\n");
    count = 0;
    ppl_cnt = 0;
    dir = get_dir(DATA_DIR + "login/");
	for(i=0; i<sizeof(dir); i++) {
         reset_eval_cost();
//         write(dir[i]+"\n");
         ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
         ppl_cnt += sizeof(ppls);
//         printf("number is: %d \n",sizeof(ppls));
         for(j=0; j<sizeof(ppls); j++) {
             if( sscanf(ppls[j], "%s.o", name)==1 )
             if( (string)SECURITY_D->get_status(name)!="(player)" )
             continue;
             info = stat(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
			 
			 if((sizeof(info)>1)&&((time()-(int)info[1])/86400 <= day)) 
			 {
			    ob = new(USER_OB);
			    if (!ob) printf("ob = null!\n");
			    ob->set("id", name);
			    err = catch(rc = ob->restore());
			    if (err) {
			      printf("error here!!!");
			      continue;
			    }
			    if(!rc) {
                    printf("没有这个人。(%s)\n",name);
			      destruct(ob);
			      continue;
			    }
			    if (ob->query("combat_exp") > 550000) {
			    	if( rank == 0 ) {
			    		this_ob->set("data/", ({ 
						 ([	"id" : name,
							"name" : ob->query("name"),
							"exp" : ob->query("combat_exp"),
							"age" : ob->query("age"),
						]) }) );
						rank = 1;
					}
					else {
			    		this_ob->add("data/", ({ 
						 ([	"id" : name,
							"name" : ob->query("name"),
							"exp" : ob->query("combat_exp"),
							"age" : ob->query("age"),
						]) }) );
				    	
			    	}
	//		    	printf("name is: %s %s %d\n",name,ob->query("name"),ob->query("combat_exp"));
				}
			       call_out("destroy_ob", 1, ob);
			    }
			  
            }
        }
    
	        ob_list = this_ob->query("data");    
//		    max=sizeof(ob_list_old);
	    	ob_list = sort_array(ob_list, (: sortexp1 :));
		    this_ob->set("data", ob_list);
	
//		else return notify_fail("no data loaded!\n");*/
        return 1;
}

void destroy_ob(object ob)
{
    if( ob ) destruct(ob);
}

int sortper(object obj1, object obj2)
{
  int per1,per2;
  per1=obj1->query("per");
  per2=obj2->query("per");
  if (per1>per2) return -1;
  else if (per1<per2) return 1;
  else return 0;
}
int sortage(object obj1, object obj2)
{
  int age1,age2;
  age1=obj1->query("age");
  age2=obj2->query("age");
  if (age1>age2) return -1;
  else if (age1<age2) return 1;
  else return 0;
}

int sortexp(object obj1, object obj2)
{
  int exp1,exp2;
  exp1=obj1->query("combat_exp");
  exp2=obj2->query("combat_exp");
  if (exp1>exp2) return -1;
  else if (exp1<exp2) return 1;
  else return 0;
}


int filtdata(object obj1)
{
  object where;
  if(wizardp(obj1))
    return 0;
  where = environment(obj1);
  if(!where) 
    return 0;
  else return 1;
}
   
int do_sort(string arg)
{
    int max;
	int i, sorttime;
	string name;
	object obj1;
	object me = this_player();
	
	object this_ob = this_object();
	
	sorttime = this_ob->query("sorttime");
	if(sorttime > 2) return notify_fail("还 sort, 再 sort 侠客行要变 lag 了。\n");
	else {
		sorttime += 1;
		this_ob->set("sorttime", sorttime);
	}
	
	if (!arg)
	  return notify_fail("sort what?\n");
    if (arg=="exp")
	{
	    object where, ob,*ob_list,*ob_list_old;
	    ob_list_old = users();
	    ob_list_old = filter(ob_list_old, (: filtdata :));
	    max=sizeof(ob_list_old);
	    ob_list = sort_array(ob_list_old, (: sortexp :));
	    
	    for (i=max-1;i>=0;i--)
	      {
		obj1 = ob_list[i];
		name = obj1->query("name")+"("+obj1->query("id")+")"+" exp: "+obj1->query("combat_exp");
		printf("No. %d: %s\n",i+1,name);
	      }
	    return 1;
	  }
        else if (arg=="per")
	  {
	    object where, ob,*ob_list,*ob_list_old;
	    ob_list_old = users();
	    ob_list_old = filter(ob_list_old, (: filtdata :));
	    max=sizeof(ob_list_old);
	    ob_list = sort_array(ob_list_old, (: sortper :));
	    
	    for (i=max-1;i>=0;i--)
	      {
		obj1 = ob_list[i];
		name = obj1->query("name")+"("+obj1->query("id")+")"+" per: "+obj1->query("per");
		printf("No. %d: %s\n",i+1,name);
	      }
	    return 1;
	  }
        else if (arg=="age")
	  {
	    object where, ob,*ob_list,*ob_list_old;
	    ob_list_old = users();
	    ob_list_old = filter(ob_list_old, (: filtdata :));
	    max=sizeof(ob_list_old);
	    ob_list = sort_array(ob_list_old, (: sortage :));
	    
	    for (i=max-1;i>=0;i--)
	      {
		obj1 = ob_list[i];
		name = obj1->query("name")+"("+obj1->query("id")+")"+" age: "+obj1->query("age");
		printf("No. %d: %s\n",i+1,name);
	      }
	    return 1;
	  }
	else if (arg=="expall")
	  return do_sortallexp(7);
	else return notify_fail("sort what?\n");
	return 1;
}



